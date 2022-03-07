///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/02/22 15:46)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_TRIANGLE3_TRIANGLE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_TRIANGLE3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class DistanceTriangle3Triangle3 : public DistanceBase<Real, Vector3<Real>>
    {
    public:
        using ClassType = DistanceTriangle3Triangle3<Real>;
        using Vector3 = Vector3<Real>;
        using ParentType = DistanceBase<Real, Vector3>;
        using Triangle3 = Triangle3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceTriangle3Triangle3(const Triangle3& lhsTriangle, const Triangle3& rhsTriangle) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Triangle3 GetLhsTriangle() const noexcept;
        NODISCARD Triangle3 GetRhsTriangle() const noexcept;

        NODISCARD DistanceResult GetSquared() const override;

        NODISCARD DistanceResult GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const override;

        NODISCARD Real GetTriangleBary0(int index) const;
        NODISCARD Real GetTriangleBary1(int index) const;

    private:
        Triangle3 lhsTriangle;
        Triangle3 rhsTriangle;

        mutable Vector3 triangleBary0;  // closest0 = sum_{i=0}^2 bary0[i]*vertex0[i]
        mutable Vector3 triangleBary1;  // closest1 = sum_{i=0}^2 bary1[i]*vertex1[i]
    };

    using DistanceTriangle3Triangle3F = DistanceTriangle3Triangle3<float>;
    using DistanceTriangle3Triangle3D = DistanceTriangle3Triangle3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_TRIANGLE3_TRIANGLE3_H
