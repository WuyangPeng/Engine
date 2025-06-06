/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 11:17)

#ifndef MATHEMATICS_OBJECTS_2D_CIRCLE2_H
#define MATHEMATICS_OBJECTS_2D_CIRCLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector/Vector2.h"
#include "Mathematics/Algebra/Vector2.h"

#include <iosfwd>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Circle2 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Circle2<Real>;

        using MathType = Math<Real>;
        using Vector2Type = Vector2<Real>;
        using AlgebraVector2 = Algebra::Vector2<Real>;

    public:
        Circle2(const Vector2Type& center, Real radius) noexcept;
        Circle2() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector2Type GetCenter() const noexcept;
        NODISCARD Real GetRadius() const noexcept;

        void SetCircle(const Vector2Type& aCenter, Real aRadius) noexcept;
        void SetCenter(const Vector2Type& aCenter) noexcept;
        void SetCenter(const AlgebraVector2& aCenter);
        void SetCenterX(Real x) noexcept;
        void SetCenterY(Real y) noexcept;
        void SetRadius(Real aRadius) noexcept;

    private:
        Vector2Type center;
        Real radius;
    };

    template <typename Real>
    NODISCARD bool Approximate(const Circle2<Real>& lhs, const Circle2<Real>& rhs, Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1);

    // 调试输出
    template <typename Real>
    std::ostream& operator<<(std::ostream& out, const Circle2<Real>& circle2);

    using Circle2F = Circle2<float>;
    using Circle2D = Circle2<double>;
}

#endif  // MATHEMATICS_OBJECTS_2D_CIRCLE2_H
