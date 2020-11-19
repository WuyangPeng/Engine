///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/13 11:15)

#ifndef MATHEMATICS_OBJECTS2D_ARC2_H
#define MATHEMATICS_OBJECTS2D_ARC2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/Vector2DTools.h"
#include "Mathematics/Base/MathDetail.h"

#include <iosfwd>
#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Arc2 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Arc2<Real>;
        using Math = Math<Real>;
        using Vector2D = Vector2D<Real>;
        using Vector2DTools = Vector2DTools<Real>;

    public:
        // 圆弧是定义在圆上的两点end0和end1，
        // 以便end1通过end0逆时针方向遍历获得。
        // 应用程序负责确保end0和end1在圆环上，和他们正确的排序。

        Arc2(const Vector2D& center, Real radius, const Vector2D& end0, const Vector2D& end1, const Real epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        // 检验point是否在弧上。应用程序必须确保point在圆上，也就是说，|P-C| = Real。
        // 该测试适用于在B-C 和 A-C的任何角度，而不仅仅是0 到 pi弧度之间。
        [[nodiscard]] bool Contains(const Vector2D& point) const;

        [[nodiscard]] const Vector2D GetCenter() const noexcept;
        [[nodiscard]] Real GetRadius() const noexcept;
        [[nodiscard]] const Vector2D GetEnd0() const noexcept;
        [[nodiscard]] const Vector2D GetEnd1() const noexcept;

    private:
        Vector2D m_Center;
        Real m_Radius;
        Vector2D m_End0;
        Vector2D m_End1;
        Real m_Epsilon;
    };

    using FloatArc2 = Arc2<float>;
    using DoubleArc2 = Arc2<double>;

    template <typename Real>
    [[nodiscard]] bool Approximate(const Arc2<Real>& lhs, const Arc2<Real>& rhs, const Real epsilon);

    // 调试输出
    template <typename Real>
    std::ostream& operator<<(std::ostream& out, const Arc2<Real>& arc2);
}

#endif  // MATHEMATICS_OBJECTS2D_ARC2_H
