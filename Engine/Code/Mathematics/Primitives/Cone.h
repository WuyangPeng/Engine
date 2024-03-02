///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/29 09:54)

#ifndef MATHEMATICS_PRIMITIVES_CONE_H
#define MATHEMATICS_PRIMITIVES_CONE_H

#include "Mathematics/MathematicsDll.h"

#include "Ray.h"
#include "Mathematics/Algebra/Vector/Vector2.h"
#include "Mathematics/Algebra/Vector/Vector3.h"
#include "Mathematics/Base/Math.h"

/// 无限圆锥体由顶点V、单位长度方向D和角度a定义，
/// 其中0 < A < pi/2。当
///  Dot(D, X - V) = |X - V| * cos(A)
/// 实心圆锥体包括圆锥体上和包含圆锥体光线V + h * D的区域中的点，其中h >= 0。它由定义
/// Dot(D, X - V) >= |X - V| * cos(A)
/// 空间中任意点Y相对于圆锥体的高度由h = Dot(D, Y - V)定义，
/// 这是X-V投影到圆锥体轴上的带符号长度。
/// 观察到我们已经将锥的定义限制为锐角A，所以 |X - V| * cos(A) >= 0；
/// 因此，圆锥上或圆锥内的点具有非负高度：Dot(D, X - V) >= 0。
/// 我将把无限实心圆锥体称为“正圆锥体”，这意味着圆锥体内的非顶点具有正高度。
/// 尽管在计算机图形学中很少见，但人们可能也想考虑“负锥体”，它由
///  -Dot(D, X - V) <= -|X - V| * cos(A)
/// 此圆锥体内的非顶点具有负高度。
///
/// 对于许多涉及锥的几何查询，我们可以避免|X - V|所隐含的平方根计算。正锥体由定义
/// Dot(D, X - V)^2 >= |X - V|^2 * cos(A)^2,
/// 这是一个二次不等式，但项的平方导致包括负锥中的点X的不等式。
/// 当对正锥使用二次不等式时，我们还需要包括约束Dot(D, X - V) >= 0。
///
/// 我定义了四种不同类型的圆锥体。
/// 它们都涉及V、D和A。差异是基于对锥点高度的限制。
/// 高度范围被定义为可能高度的间隔，
/// [hMin,hMax] with 0 <= hMin < hMax <= +infinity.
///     1. 无限圆锥体: hMin = 0, hMax = +infinity
///     2. 无限截锥:  hMin > 0, hMax = +infinity
///     3. 有限锥:  hMin >= 0, hMax < +infinity
///     4. 圆锥截头体:  hMin > 0, hMax < +infinity
/// 无限截锥被截断为h-minimum；
/// 圆盘在h最小值处的半径为rMin = hMin * tan(A)。
/// 有限锥被截断为h最大值；
/// 圆盘在h最大值处的半径为rMax = hMax * tan(A)。
/// 圆锥的截头体在h最小值和h最大值时都被截断。
///
/// 创建表示圆锥体的数据结构时的一个技术问题是决定如何表示高度范围内的+infinity。
/// 当模板类型T是“float”或“double”时，我们可以将其表示为std::numeric_limits<T>::infinity()。
/// 几何查询的结构必须正确，以符合与浮点无穷大相关的语义。
/// 我们还可以使用最大的有限浮点数std::numeric_limits<T>::max()。
/// 当T是一个没有无穷大表示的任意精度类型时，这两种选择都是有问题的；
/// 类型BSNumber<T> 和 BSRational<T>, 就是这种情况，其中T是 UIntegerAP 或 UIntegerFP<N>.
///
/// 为任意精度类型引入无穷大的表示将需要修改算术运算，以测试数字是有限的还是无限的。
/// 这导致所有查询的计算成本更高，即使这些查询不需要操作无穷大。
/// 在圆锥体的情况下，高度操作几乎总是用于比较高度。
/// 我选择通过将maxHeight成员设置为-1来表示+infinity。
/// 成员函数IsFinite()和IsInfinite()将maxHeight与-1进行比较，并报告正确的状态。
///
/// 我选择的表达方式的主要后果是，高度之间的比较需要额外的逻辑。
/// 这可能会使几何查询难以实现。例如，使用二次不等式的锥点测试如伪代码所示
///   Vector point = <some point>;
///   Cone cone = <some cone>;
///   Vector delta = point - cone.V;
///   T h = Dot(cone.D, delta);
///   bool pointInCone =
///       cone.hMin <= h &&
///       h <= cone.hMax &&
///       h * h >= Dot(delta, delta) * cone.cosAngleSqr;
/// 如果圆锥体是无限的，并且我们选择cone.hMax=-1来表示它，则必须修改测试'h <= cone.hMax'，
///   bool pointInCone =
///       cone.hMin <= h &&
///       (cone.hMax == -1 ? true : (h <= cone.hMax)) &&
///       h * h >= Dot(delta, delta) * cone.cosAngleSqr;
///  要封装与高度极值的比较，请使用成员函数HeightInRange(h)，那就是
///   bool pointInCone =
///       cone.HeightInRange(h) &&
///       h * h >= Dot(delta, delta) * cone.cosAngleSqr;
/// 这里的修改并没有那么复杂，而是考虑一个更复杂的查询，
/// 例如确定两个高度区间[h0,h1]和[cone.hMin,cone.hMax]的相交区间。
/// 文件IntrIntervals.h提供了计算两个区间的交集的实现，
/// 其中一个区间或两个区间都是半无限的。
namespace Mathematics
{
    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    class Cone
    {
    public:
        using ClassType = Cone<N, Real>;

        using Math = Math<Real>;
        using Vector = Algebra::Vector<N, Real>;
        using Ray = Ray<N, Real>;
        using Vector2 = Algebra::Vector<2, Real>;
        using Vector3 = Algebra::Vector<3, Real>;
        using Vector2Container = std::vector<Vector2>;
        using Vector3Container = std::vector<Vector3>;
        using IndicesContainer = std::vector<int>;

    public:
        /// 使用创建无限圆锥体
        ///   vertex = (0,...,0)
        ///   axis = (0,...,0,1)
        ///   angle = pi/4
        ///   minimum height = 0
        ///   maximum height = +infinity
        Cone() noexcept requires(N == 3);

        /// 创建一个具有指定顶点、轴方向、角度和高度地无限圆锥体
        Cone(const Ray& ray, Real angle) noexcept;

        /// 创建一个具有指定顶点、轴方向、角度和正最小高度地无限截锥。
        /// 最大高度为+infinity。如果指定的最小高度为0，则相当于调用无限圆锥体的构造函数。
        Cone(const Ray& ray, Real angle, Real minHeight) noexcept;

        /// 使用指定的所有参数创建有限圆锥体或圆锥体的截头体。
        /// 如果指定最小高度为0，则会得到一个有限的圆锥体。
        /// 如果指定一个正的最小高度，则会得到一个圆锥体的截头体。
        Cone(const Ray& ray, Real angle, Real minHeight, Real maxHeight) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Ray GetRay() const noexcept;
        void SetRay(const Ray& aRay) noexcept;

        NODISCARD Real GetAngle() const noexcept;

        /// 角度必须在(0,pi/2)内。
        /// 该函数设置'angle'并计算'cosAngle', 'sinAngle', 'tanAngle', 'cosAngleSqr', 'sinAngleSqr' 和 'invSinAngle'。
        void SetAngle(Real aAngle);

        NODISCARD Real GetCosAngle() const noexcept;
        NODISCARD Real GetSinAngle() const noexcept;
        NODISCARD Real GetTanAngle() const noexcept;
        NODISCARD Real GetCosAngleSqr() const noexcept;
        NODISCARD Real GetSinAngleSqr() const noexcept;
        NODISCARD Real GetInvSinAngle() const noexcept;

        /// 设置高度以获得四种类型的圆锥体之一。
        /// 请注意，无限圆锥体的maxHeight设置为-1。
        /// 注意不要在不理解此解释的情况下使用maxHeight。
        void MakeInfiniteCone() noexcept;

        void MakeInfiniteTruncatedCone(Real aMinHeight);
        void MakeFiniteCone(Real aMaxHeight);
        void MakeConeFrustum(Real aMinHeight, Real aMaxHeight);

        /// 达到极限高度。
        /// 对于无限圆锥体，maxHeight设置为-1。
        /// 对于有限圆锥体，maxHeight设置为正数。
        /// 注意不要在不理解此解释的情况下使用maxHeight。
        NODISCARD Real GetMinHeight() const noexcept;
        NODISCARD Real GetMaxHeight() const noexcept;
        NODISCARD bool HeightInRange(Real h) const noexcept(gAssert < 3 || gMathematicsAssert < 3);
        NODISCARD bool HeightLessThanMin(Real h) const noexcept;
        NODISCARD bool HeightGreaterThanMax(Real h) const noexcept(gAssert < 3 || gMathematicsAssert < 3);
        NODISCARD bool IsFinite() const noexcept(gAssert < 3 || gMathematicsAssert < 3);
        NODISCARD bool IsInfinite() const noexcept(gAssert < 3 || gMathematicsAssert < 3);

        /// 支持可视化。
        void CreateMesh(int numMinVertices, bool inscribed, Vector3Container& vertices, IndicesContainer& indices) requires(N == 3);

    private:
        void GenerateInscribed(int numVertices, Real radius, Vector2Container& polygon) requires(N == 3);

        void GenerateCircumscribed(int numVertices, Real radius, Vector2Container& polygon) requires(N == 3);

        void CreateConeFrustumMesh(int numMinVertices,
                                   int numMaxVertices,
                                   int numExtra,
                                   Real hMin,
                                   Real hMax,
                                   const Vector2Container& polygonMin,
                                   const Vector2Container& polygonMax,
                                   Vector3Container& vertices,
                                   IndicesContainer& indices) requires(N == 3);

    private:
        /// 圆锥体轴方向（射线方向）必须是单位长度。
        Ray ray;

        /// 角度必须在(0,pi/2).内。其他成员是从角度派生的，
        /// 以避免在几何查询中调用三角函数（为了速度）。
        /// 您可以通过调用SetAngle(aAngle)来设置角度并计算这些角度。
        Real angle;
        Real cosAngle;
        Real sinAngle;
        Real tanAngle;
        Real cosAngleSqr;
        Real sinAngleSqr;
        Real invSinAngle;

    private:
        /// 高度必须满足0 <= minHeight < maxHeight <= +infinity对于无限圆锥体，maxHeight设置为-1。
        /// 对于有限圆锥体，maxHeight设置为正数。
        /// 注意不要在不理解此解释的情况下使用maxHeight。
        Real minHeight;
        Real maxHeight;
    };

    /// 与支持排序容器的比较。
    /// 这些仅基于“射线”、“角度”、“最小高度”和“最大高度”。
    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator==(const Cone<N, Real>& lhs, const Cone<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator!=(const Cone<N, Real>& lhs, const Cone<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator<(const Cone<N, Real>& lhs, const Cone<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator<=(const Cone<N, Real>& lhs, const Cone<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator>(const Cone<N, Real>& lhs, const Cone<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator>=(const Cone<N, Real>& lhs, const Cone<N, Real>& rhs);

    namespace Algebra
    {
        /// 为方便起见，模板别名。
        template <typename Real>
        using Cone3 = Cone<3, Real>;
    }
}

#endif  // MATHEMATICS_PRIMITIVES_CONE_H
