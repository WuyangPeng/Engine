///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/13 13:38)

#ifndef MATHEMATICS_OBJECTS2D_CIRCLE2_H
#define MATHEMATICS_OBJECTS2D_CIRCLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"

#include <iosfwd>
#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Circle2 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Circle2<Real>;
        using Math = Math<Real>;
        using Vector2D = Vector2D<Real>;

    public:
        Circle2(const Vector2D& center, Real radius) noexcept;
        Circle2() noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector2D GetCenter() const noexcept;  
        [[nodiscard]] Real GetRadius() const noexcept;

        void SetCircle(const Vector2D& center, Real radius) noexcept;

    private:
        Vector2D m_Center;
        Real m_Radius;
    };

    template <typename Real>
    [[nodiscard]] bool Approximate(const Circle2<Real>& lhs, const Circle2<Real>& rhs, const Real epsilon);

    // 调试输出
    template <typename Real>
    std::ostream& operator<<(std::ostream& out, const Circle2<Real>& circle2);

    using FloatCircle2 = Circle2<float>;
    using DoubleCircle2 = Circle2<double>;
}

#endif  // MATHEMATICS_OBJECTS2D_CIRCLE2_H
