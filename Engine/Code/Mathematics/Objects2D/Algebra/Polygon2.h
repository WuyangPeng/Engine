/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/22 09:44)

#ifndef MATHEMATICS_OBJECTS_2D_ALGEBRA_POLYGON2_H
#define MATHEMATICS_OBJECTS_2D_ALGEBRA_POLYGON2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector/Vector2.h"

#include <set>

namespace Mathematics::Algebra
{
    /// Polygon2对象表示一个简单的多边形：
    /// 没有重复的顶点，闭合的（每个顶点正好由两条边共享），内部边点没有自相交。
    /// “顶点池”数组可以包含比定义多边形所需的点更多的点，这允许顶点池具有与其关联的多个多边形。
    /// 因此，程序员必须确保只要存在依赖于顶点池的任何Polygon2对象，顶点池就一直存在。
    /// 多边形顶点的数量为“numIndices”，并且必须大于或等于3。
    /// “indexes”数组引用顶点池中的点，这些点是多边形的一部分，并且必须具有“numIndices”唯一元素。
    /// 多边形的边是“顶点池”的成对索引，
    ///   edge[0] = (indices[0], indices[1])
    ///   :
    ///   edge[numIndices-2] = (indices[numIndices-2], indices[numIndices-1])
    ///   edge[numIndices-1] = (indices[numIndices-1], indices[0])
    /// 程序员应确保多边形是简单的。无论多边形是顺时针方向还是逆时针方向，几何查询都是有效的。
    ///
    /// 注：不提供比较运算符。相等多边形的语义很复杂，（目前）没有用处。
    /// 顶点池可以不同，索引也不匹配，但它们引用的顶点可以匹配。
    /// 即使使用共享顶点池，索引也可以“旋转”，抽象地导致相同的多边形，但数据结构不匹配。
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class Polygon2
    {
    public:
        using ClassType = Polygon2;

        using Vector2 = Vector2<Real>;
        using VertexPool = std::vector<Vector2>;
        using VertexPoolSharedPtr = std::shared_ptr<VertexPool>;
        using VertexPoolWeakPtr = std::weak_ptr<VertexPool>;

        using VerticesType = std::set<int>;
        using IndicesType = std::vector<int>;

        using Math = Math<Real>;

    public:
        /// 构造当'numIndices' >= 3且“vertexPool”和“indices”不为空时，构造函数成功；
        /// 我们测试输入数组中是否有有效数量的元素。
        /// 副本由“索引”组成，但不复制“顶点池”。
        /// 如果构造函数失败，则抛出异常。
        Polygon2(const VertexPoolSharedPtr& vertexPool,
                 int numIndices,
                 const IndicesType& indices,
                 bool counterClockwise);

        CLASS_INVARIANT_DECLARE;

        /// 成员访问。
        NODISCARD VertexPoolSharedPtr GetVertexPool() const;
        NODISCARD VerticesType GetVertices() const;
        NODISCARD IndicesType GetIndices() const;
        NODISCARD bool CounterClockwise() const noexcept;

        /// 几何查询。
        NODISCARD Vector2 ComputeVertexAverage() const;

        NODISCARD Real ComputePerimeterLength() const;

        NODISCARD Real ComputeArea() const;

        /// 简单多边形在边的内部点处没有自相交。
        /// 该测试是一种针对边的详尽的全对相交测试，
        /// 对于具有大量顶点的多边形来说效率低下。
        /// 提供一个高效的算法，该算法使用类RectangleManager.h的算法。
        NODISCARD bool IsSimple() const;

        /// 凸多边形是指连续边之间的角度小于或等于pi弧度的简单多边形。
        NODISCARD bool IsConvex() const;

    private:
        /// 这些调用具有前提条件，
        /// 即vertexPool不为null并且indices.size.size() > 3。
        /// 算法的核心在这里实现。
        NODISCARD bool IsSimpleInternal() const;

        NODISCARD bool IsConvexInternal() const;

    private:
        VertexPoolWeakPtr vertexPool;
        VerticesType vertices;
        IndicesType indices;
        bool counterClockwise;
    };

}

#endif  // MATHEMATICS_OBJECTS_2D_ALGEBRA_POLYGON2_H
