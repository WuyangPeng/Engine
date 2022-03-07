///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/10 10:16)

#ifndef MATHEMATICS_OBJECTS2D_CIRCLE2_H
#define MATHEMATICS_OBJECTS2D_CIRCLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2.h"

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
        using Vector2 = Vector2<Real>;

    public:
        Circle2(const Vector2& center, Real radius) noexcept;
        Circle2() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector2 GetCenter() const noexcept;
        NODISCARD Real GetRadius() const noexcept;

        void SetCircle(const Vector2& newCenter, Real newRadius) noexcept;

    private:
        Vector2 center;
        Real radius;
    };

    template <typename Real>
    NODISCARD bool Approximate(const Circle2<Real>& lhs, const Circle2<Real>& rhs, const Real epsilon) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

    // 调试输出
    template <typename Real>
    std::ostream& operator<<(std::ostream& out, const Circle2<Real>& circle2);

    using Circle2F = Circle2<float>;
    using Circle2D = Circle2<double>;
}

#endif  // MATHEMATICS_OBJECTS2D_CIRCLE2_H
