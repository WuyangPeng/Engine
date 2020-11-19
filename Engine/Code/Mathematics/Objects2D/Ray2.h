///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/13 16:29)

#ifndef MATHEMATICS_OBJECTS2D_RAY2_H
#define MATHEMATICS_OBJECTS2D_RAY2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"
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
        using Vector2D = Vector2D<Real>;
        using Math = Math<Real>;

    public:
        // 射线表示为P+t*D，其中P是线原点，D是单位长度的方向向量，t >= 0。
        // 用户必须确保D是单位长度。

        Ray2(const Vector2D& origin, const Vector2D& direction, const Real epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector2D GetOrigin() const noexcept;
        [[nodiscard]] const Vector2D GetDirection() const noexcept;

        [[nodiscard]] const Ray2 GetMove(Real t, const Vector2D& velocity) const;

    private:
        Vector2D m_Origin;
        Vector2D m_Direction;
        Real m_Epsilon;
    };

    using FloatRay2 = Ray2<float>;
    using DoubleRay2 = Ray2<double>;

    template <typename Real>
    [[nodiscard]] bool Approximate(const Ray2<Real>& lhs, const Ray2<Real>& rhs, const Real epsilon);

    // 调试输出
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Ray2<Real>& ray);
}

#endif  // MATHEMATICS_OBJECTS2D_RAY2_H
