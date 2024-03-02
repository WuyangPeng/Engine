/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/20 19:13)

#ifndef MATHEMATICS_OBJECTS_2D_ARC2_H
#define MATHEMATICS_OBJECTS_2D_ARC2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector/Vector2.h"
#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Algebra/Vector2Tools.h"
#include "Mathematics/Base/Math.h"

#include <iosfwd>
#include <type_traits>

namespace Mathematics
{
    /// 包含圆弧的圆表示为|X-C| = r，其中C是中心，r是半径。
    /// 圆弧是定义在圆上的两点end0和end1，
    /// 以便end1通过end0逆时针方向遍历获得。
    /// 应用程序负责确保end0和end1在圆环上，和他们正确的排序。
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Arc2 final
    {
    public:
        using ClassType = Arc2<Real>;

        using Math = Math<Real>;
        using Vector2 = Vector2<Real>;
        using Vector2Tools = Vector2Tools<Real>;
        using AlgebraVector2 = Algebra::Vector2<Real>;

    public:
        /// 默认构造函数将中心设置为(0,0)，将半径设置为1，将端点0设置为(1,0)，将端点1设置为 (0,1)。
        Arc2() noexcept;

        Arc2(const Vector2& center, Real radius, const Vector2& end0, const Vector2& end1, Real epsilon = Math::GetZeroTolerance()) noexcept;
        Arc2(const AlgebraVector2& center, Real radius, const AlgebraVector2& end0, const AlgebraVector2& end1, Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        /// 检验point是否在弧上。
        ///
        /// 对于实数运算，|P-C| - r = 0是P在弧的圆上的必要条件。
        /// 如果P在圆上，则当P在包含E0的线的边上时，P在从E0到E1的弧上，其中Perp(u,v) = (v,-u)。
        /// 该测试适用于E0-C和E1-C之间的任何角度，即使该角度大于或等于pi弧度。
        ///
        /// 对于浮点或有理类型，舍入错误会导致当P在圆上（或在数字上靠近）时|P-C| - r很少为0。
        /// 考虑到这一点，选择一个小的非负公差epsilon。
        /// 如果P在圆上（在epsilon公差意义上），则||P-C| - r| <= epsilon。
        /// 否则，P不在圆上。
        /// 则应用前一段/段落的线侧测试。
        NODISCARD bool Contains(const Vector2& point) const;
        NODISCARD bool Contains(const AlgebraVector2& point) const;

        /// 此函数假定P位于包含圆弧的圆上（可能存在少量浮点舍入误差）。
        NODISCARD bool CircleContains(const Vector2& point) const;
        NODISCARD bool CircleContains(const AlgebraVector2& point) const;

        NODISCARD Vector2 GetCenter() const noexcept;
        NODISCARD Real GetRadius() const noexcept;
        NODISCARD Vector2 GetEnd0() const noexcept;
        NODISCARD Vector2 GetEnd1() const noexcept;

    private:
        Vector2 center;
        Real radius;
        Vector2 end0;
        Vector2 end1;
        Real epsilon;
    };

    using Arc2F = Arc2<float>;
    using Arc2D = Arc2<double>;

    // STL
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator==(const Arc2<Real>& lhs, const Arc2<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator!=(const Arc2<Real>& lhs, const Arc2<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator<(const Arc2<Real>& lhs, const Arc2<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator<=(const Arc2<Real>& lhs, const Arc2<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator>(const Arc2<Real>& lhs, const Arc2<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator>=(const Arc2<Real>& lhs, const Arc2<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool Approximate(const Arc2<Real>& lhs, const Arc2<Real>& rhs, Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1);

    // 调试输出
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    std::ostream& operator<<(std::ostream& out, const Arc2<Real>& arc2);
}

#endif  // MATHEMATICS_OBJECTS_2D_ARC2_H
