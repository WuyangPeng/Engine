///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/14 11:16)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_CIRCLE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_CIRCLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Circle3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistancePoint3Circle3 : public DistanceBase<Real, Vector3D<Real>>
    {
    public:
        using ClassType = DistancePoint3Circle3<Real>;
        using Vector3D = Vector3D<Real>;
        using ParentType = DistanceBase<Real, Vector3D>;
        using Circle3 = Circle3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistancePoint3Circle3(const Vector3D& point, const Circle3& circle) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Vector3D GetPoint() const noexcept;
        [[nodiscard]] const Circle3 GetCircle() const noexcept;

        /// 静态距离查询。 计算从点P到圆的距离。 当P在法线C + t * N上，其中C是圆心并且N是包含该圆的平面的法线时，则所有圆点都与P等距。
        /// 在这种情况下，返回点为C + r * U，其中U是垂直于N的向量。
        [[nodiscard]] const DistanceResult GetSquared() const override;

        // 动态距离查询的函数计算。
        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

    private:
        Vector3D m_Point;
        Circle3 m_Circle;
    };

    using FloatDistancePoint3Circle3 = DistancePoint3Circle3<float>;
    using DoubleDistancePoint3Circle3 = DistancePoint3Circle3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_CIRCLE3_H
