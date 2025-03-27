///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 17:13)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_SEGMENT3_TRIANGLE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_SEGMENT3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Segment3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class DistanceSegment3Triangle3 : public DistanceBase<Real, Vector3<Real>>
    {
    public:
        using ClassType = DistanceSegment3Triangle3<Real>;
        using Vector3 = Vector3<Real>;
        using ParentType = DistanceBase<Real, Vector3>;

        using Segment3 = Segment3<Real>;
        using Triangle3 = Triangle3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;
        using DistanceResult = typename ParentType::DistanceResultType;

    public:
        DistanceSegment3Triangle3(const Segment3& segment, const Triangle3& triangle) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Segment3 GetSegment() const noexcept;
        NODISCARD Triangle3 GetTriangle() const noexcept;

        NODISCARD DistanceResult GetSquared() const override;

        NODISCARD DistanceResult GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const override;

        NODISCARD Real GetTriangleBary(int index) const;

    private:
        Segment3 segment;
        Triangle3 triangle;

        mutable Vector3 triangleBary;
    };

    using DistanceSegment3Triangle3F = DistanceSegment3Triangle3<float>;
    using DistanceSegment3Triangle3D = DistanceSegment3Triangle3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_SEGMENT3_TRIANGLE3_H
