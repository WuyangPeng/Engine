///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 17:10)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_PLANE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_PLANE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Plane3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistancePoint3Plane3 : public DistanceBase<Real, Vector3<Real>>
    {
    public:
        using ClassType = DistancePoint3Plane3<Real>;
        using Vector3 = Vector3<Real>;
        using ParentType = DistanceBase<Real, Vector3>;

        using Plane3 = Plane3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistancePoint3Plane3(const Vector3& point, const Plane3& plane) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Vector3 GetPoint() const noexcept;
        NODISCARD Plane3 GetPlane() const noexcept;

        NODISCARD DistanceResult GetSquared() const override;

        NODISCARD DistanceResult GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const override;

    private:
        Vector3 point;
        Plane3 plane;
    };

    using DistancePoint3Plane3F = DistancePoint3Plane3<float>;
    using DistancePoint3Plane3D = DistancePoint3Plane3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_PLANE3_H
