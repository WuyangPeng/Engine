///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/10 10:42)

#ifndef MATHEMATICS_OBJECTS2D_RAY2_H
#define MATHEMATICS_OBJECTS2D_RAY2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Ray2 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Ray2<Real>;
        using Vector2 = Vector2<Real>;
        using Math = Math<Real>;

    public:
        // 射线表示为P+t*D，其中P是线原点，D是单位长度的方向向量，t >= 0。
        // 用户必须确保D是单位长度。

        Ray2(const Vector2& origin, const Vector2& direction, const Real epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector2 GetOrigin() const noexcept;
        NODISCARD Vector2 GetDirection() const noexcept;

        NODISCARD Ray2 GetMove(Real t, const Vector2& velocity) const;

    private:
        Vector2 origin;
        Vector2 direction;
        Real epsilon;
    };

    using Ray2F = Ray2<float>;
    using Ray2D = Ray2<double>;

    template <typename Real>
    NODISCARD bool Approximate(const Ray2<Real>& lhs, const Ray2<Real>& rhs, const Real epsilon) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

    // 调试输出
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Ray2<Real>& ray);
}

#endif  // MATHEMATICS_OBJECTS2D_RAY2_H
