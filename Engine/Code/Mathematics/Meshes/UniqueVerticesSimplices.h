///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/28 14:41)

#ifndef MATHEMATICS_MESHES_UNIQUE_VERTICES_SIMPLICES_H
#define MATHEMATICS_MESHES_UNIQUE_VERTICES_SIMPLICES_H

#include "Mathematics/MathematicsDll.h"

#include <map>
#include <set>
#include <vector>

/// 无限圆锥由顶点V、单位长度方向D和角度A定义，其中0 < A < pi/2。
/// 当点X在圆锥上时，有
///   Dot(D, X - V) = |X - V| * cos(A)
/// 实心圆锥包括圆锥上的点和包含圆锥射线 V + h * D （其中 h >= 0）的区域。  它由
///   Dot(D, X - V) >= |X - V| * cos(A)
///   定义。
/// 相对于圆锥，空间中任意点Y的高度定义为h = Dot(D, Y - V),
/// 它是X - V在圆锥轴上的投影的有符号长度。
/// 请注意，我们将圆锥定义限制为锐角A，因此|X - V| * cos(A) >= 0；
/// 因此，圆锥上或内部的点具有非负高度: Dot(D, X - V) >= 0.
/// 我将无限实心圆锥称为“正圆锥”，这意味着圆锥内的非顶点点具有正高度。
/// 尽管在计算机图形中很少见，但也可能需要考虑“负圆锥”，它由
///   -Dot(D, X - V) <= -|X - V| * cos(A)
/// 定义。
/// 该圆锥内的非顶点点具有负高度。
///
/// 对于涉及圆锥的许多几何查询，我们可以避免 |X - V|所暗示的平方根计算。
/// 正圆锥由
///   Dot(D, X - V)^2 >= |X - V|^2 * cos(A)^2,
/// 定义，
/// 这是一个二次不等式，但是平方项的平方导致了包括负圆锥中的点X的不等式。
/// 当使用正圆锥的二次不等式时，我们还需要包括约束 Dot(D, X - V) >= 0.
///
/// 我定义了四种不同类型的圆锥。它们都涉及V、D和A。
/// 差异基于圆锥点的高度限制。高度范围定义为可能高度的区间，例如
/// [hMin,hMax] 其中 0 <= hMin < hMax <= +infinity.
///     1. 无限圆锥: hMin = 0, hMax = +infinity
///     2. 无限截断圆锥:  hMin > 0, hMax = +infinity
///     3. 有限圆锥:  hMin >= 0, hMax < +infinity
///     4. 圆锥的截头锥体:  hMin > 0, hMax < +infinity
/// 无限截锥被截断为h-minimum；
/// 圆盘在h最小值处的半径为rMin = hMin * tan(A)。
/// 有限锥被截断为h最大值；
/// 圆盘在h最大值处的半径为rMax = hMax * tan(A)
/// 圆锥的截头体在h最小值和h最大值时都被截断。
/// 在创建表示圆锥的数据结构时，一个技术问题是决定如何表示高度范围中的+infinity。
/// 当模板类型T为 'float'或 'double'时，我们可以将其表示为std::numeric_limits<T>::infinity()。
/// 几何查询必须正确结构化，以符合与浮点无穷大相关的语义。
/// 我们也可以使用最大的有限浮点数std::numeric_limits<T>::max()。
///  无论哪种选择，在T是没有表示无穷大的任意精度类型（例如BSNumber<T> 和BSRational<T>，其中T是UIntegerAP或UIntegerFP<N>）的情况下都存在问题。
/// 引入表示任意精度类型的无穷大的表示需要修改算术运算，以测试数字是否有限或无限。
/// 这会导致所有查询的计算成本增加，即使这些查询不需要操作无穷大。
/// 在圆锥的情况下，高度操作几乎总是用于高度比较。
/// 我选择通过将maxHeight成员设置为 -1来表示+infinity。
/// 成员函数IsFinite()和IsInfinite()将maxHeight与-1进行比较并报告正确的状态。
/// 我选择的表示方法的主要后果是在高度之间进行比较需要额外的逻辑。
/// 这可能使得几何查询的实现变得复杂。
/// 例如，使用二次不等式进行点在圆锥内的测试的伪代码如下：
///   Vector point = <some point>;
///   Cone cone = <some cone>;
///   Vector delta = point - cone.V;
///   T h = Dot(cone.D, delta);
///   bool pointInCone =
///       cone.hMin <= h &&
///       h <= cone.hMax &&
///       h * h >= Dot(delta, delta) * cone.cosAngleSqr;
/// 如果圆锥是无限的，并且我们选择cone.hMax = -1 来表示这一点，
/// 则测试'h <= cone.hMax'必须进行修改：
///   bool pointInCone =
///       cone.hMin <= h &&
///       (cone.hMax == -1 ? true : (h <= cone.hMax)) &&
///       h * h >= Dot(delta, delta) * cone.cosAngleSqr;
/// 为了封装对高度极值的比较，请使用成员函数 HeightInRange(h)，即：
///   bool pointInCone =
///       cone.HeightInRange(h) &&
///       h * h >= Dot(delta, delta) * cone.cosAngleSqr;
/// 这个修改在这里并不复杂，但是考虑一个更复杂的查询，
/// 比如确定两个高度区间 [h0,h1]和[cone.hMin,cone.hMax]的交集的区间。
/// 文件IntrIntervals.h提供了计算两个区间的交集的实现，其中一个或两个区间是半无穷的。
namespace Mathematics
{
    /// 索引类型必须是不包含布尔的整数类型。
    template <typename VertexType, typename IndexType, int Dimension>
    requires(std::is_integral_v<IndexType> && !std::is_same_v<IndexType, bool>)
    class UniqueVerticesSimplices
    {
    public:
        using ClassType = UniqueVerticesSimplices<VertexType, IndexType, Dimension>;

        using VertexContainer = std::vector<VertexType>;
        using IndexContainer = std::vector<IndexType>;
        using IndexDimension = std::array<IndexType, Dimension>;
        using IndexDimensionContainer = std::vector<IndexDimension>;

    public:
        UniqueVerticesSimplices() noexcept;

        CLASS_INVARIANT_DECLARE;

        /// 请参阅本文件开头注释中的#1。先决条件是
        ///   1. inVertices.size() 是D的正倍数
        /// 后置条件为
        ///   1. outVertices 具有唯一的顶点
        ///   2. outIndices.size() = inVertices.size()
        ///   3. 0 <= outIndices[i] < outVertices.size()
        static void GenerateIndexedSimplices(const VertexContainer& inVertices,
                                             VertexContainer& outVertices,
                                             IndexContainer& outIndices);

        /// 请参阅本文件开头注释中的#1。先决条件是
        ///   1. inVertices.size() 是Dimension的正倍数
        /// 后置条件为
        //   1. outVertices 具有唯一的顶点
        //   2. outSimplices.size() = inVertices.size() / Dimension
        //   3. 0 <= outSimplices[s][d] < outVertices.size()
        static void GenerateIndexedSimplices(const VertexContainer& inVertices,
                                             VertexContainer& outVertices,
                                             IndexDimensionContainer& outSimplices);

        /// 请参阅本文件开头注释中的#2。
        /// 先决条件是
        ///   1. inVertices.size() 为正
        ///   2. inIndices.size() 是Dimension的正倍数
        ///   3. 0 <= inIndices[i] < inVertices.size()
        /// 后置条件为
        ///   1. outVertices 具有唯一的顶点
        ///   2. outIndices.size() = inIndices.size()
        ///   3. 0 <= outIndices[i] < outVertices.size()
        static void RemoveDuplicateVertices(const VertexContainer& inVertices,
                                            const IndexContainer& inIndices,
                                            VertexContainer& outVertices,
                                            IndexContainer& outIndices);

        /// 请参阅本文件开头注释中的#2。
        /// 先决条件是
        ///   1. inVertices.size() 为正
        ///   2. inSimplices.size() 为正
        ///   3. 0 <= inSimplices[s][d] < inVertices.size()
        /// 后置条件为
        ///   1. outVertices 具有唯一的顶点
        ///   2. outSimplices.size() = inSimplices.size()
        ///   3. 0 <= outSimplices[s][d] < outVertices.size()
        static void RemoveDuplicateVertices(const VertexContainer& inVertices,
                                            const IndexDimensionContainer& inSimplices,
                                            VertexContainer& outVertices,
                                            IndexDimensionContainer& outSimplices);

        /// 请参阅本文件开头注释中的#3。
        /// 先决条件是
        ///   1. inVertices.size() 为正
        ///   2. inIndices.size() 是Dimension的正倍数
        ///   3. 0 <= inIndices[i] < inVertices.size()
        /// 后置条件为
        ///   1. outVertices.size() 为正
        ///   2. outIndices.size() = inIndices.size()
        ///   3. 0 <= outIndices[i] < outVertices.size()
        ///   4. 每个outVertices[v]在outIndices[]中至少出现一次
        static void RemoveUnusedVertices(const VertexContainer& inVertices,
                                         const IndexContainer& inIndices,
                                         VertexContainer& outVertices,
                                         IndexContainer& outIndices);

        /// 请参阅本文件开头注释中的#3。
        /// 先决条件是
        ///   1. inVertices.size() 为正
        ///   2. inSimplices.size() 为正
        ///   3. 0 <= inSimplices[s][d] < inVertices.size()
        /// 后置条件为
        //   1. outVertices.size() is positive
        //   2. outSimplices.size() = inSimplices.size()
        //   3. 0 <= outSimplices[s][d] < outVertices.size()
        //   4.  每个outVertices[v]在outSimplices[][]中至少出现一次
        static void RemoveUnusedVertices(const VertexContainer& inVertices,
                                         const IndexDimensionContainer& inSimplices,
                                         VertexContainer& outVertices,
                                         IndexDimensionContainer& outSimplices);

        /// 请参阅#4以及RemoveDuplicateVertices和RemoveUnusedVertices的先决条件。
        static void RemoveDuplicateAndUnusedVertices(const VertexContainer& inVertices,
                                                     const IndexContainer& inIndices,
                                                     VertexContainer& outVertices,
                                                     IndexContainer& outIndices);

        /// 请参阅#4以及RemoveDuplicateVertices和RemoveUnusedVertices的先决条件。
        static void RemoveDuplicateAndUnusedVertices(const VertexContainer& inVertices,
                                                     const IndexDimensionContainer& inSimplices,
                                                     VertexContainer& outVertices,
                                                     IndexDimensionContainer& outSimplices);

    private:
        static void RemoveDuplicates(const VertexContainer& inVertices,
                                     VertexContainer& outVertices,
                                     IndexContainer& inToOutMapping);

        static void RemoveUnused(const VertexContainer& inVertices,
                                 int numInIndices,
                                 const IndexContainer& inIndices,
                                 VertexContainer& outVertices,
                                 IndexContainer& outIndices);
    };
}

#endif  // MATHEMATICS_MESHES_UNIQUE_VERTICES_SIMPLICES_H
