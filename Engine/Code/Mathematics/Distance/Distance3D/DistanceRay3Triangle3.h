///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/02/22 15:19)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RAY3_TRIANGLE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_RAY3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Ray3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class DistanceRay3Triangle3 : public DistanceBase<Real, Vector3<Real>>
    {
    public:
        using ClassType = DistanceRay3Triangle3<Real>;
        using Vector3 = Vector3<Real>;
        using ParentType = DistanceBase<Real, Vector3>;
        using Ray3 = Ray3<Real>;
        using Triangle3 = Triangle3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceRay3Triangle3(const Ray3& ray, const Triangle3& triangle) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Ray3 GetRay() const noexcept;
        NODISCARD Triangle3 GetTriangle() const noexcept;

        NODISCARD DistanceResult GetSquared() const override;

        NODISCARD DistanceResult GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const override;

        // 有关最接近点的信息。
        NODISCARD Real GetTriangleBary(int index) const;

    private:
        Ray3 ray;
        Triangle3 triangle;

        // closest0 = ray.origin+param*ray.direction
        // closest1 = sum_{i=0}^2 bary[i]*tri.vertex[i]
        mutable Vector3 triangleBary;
    };

    using DistanceRay3Triangle3F = DistanceRay3Triangle3<float>;
    using DistanceRay3Triangle3D = DistanceRay3Triangle3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RAY3_TRIANGLE3_H
