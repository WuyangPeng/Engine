///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/02/22 14:18)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_CIRCLE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_CIRCLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Circle3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistancePoint3Circle3 : public DistanceBase<Real, Vector3<Real>>
    {
    public:
        using ClassType = DistancePoint3Circle3<Real>;
        using Vector3 = Vector3<Real>;
        using ParentType = DistanceBase<Real, Vector3>;
        using Circle3 = Circle3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistancePoint3Circle3(const Vector3& point, const Circle3& circle) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Vector3 GetPoint() const noexcept;
        NODISCARD Circle3 GetCircle() const noexcept;

        /// 静态距离查询。 计算从点P到圆的距离。 当P在法线C + t * N上，其中C是圆心并且N是包含该圆的平面的法线时，则所有圆点都与P等距。
        /// 在这种情况下，返回点为C + r * U，其中U是垂直于N的向量。
        NODISCARD DistanceResult GetSquared() const override;

        // 动态距离查询的函数计算。
        NODISCARD DistanceResult GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const override;

    private:
        Vector3 point;
        Circle3 circle;
    };

    using DistancePoint3Circle3F = DistancePoint3Circle3<float>;
    using DistancePoint3Circle3D = DistancePoint3Circle3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_CIRCLE3_H
