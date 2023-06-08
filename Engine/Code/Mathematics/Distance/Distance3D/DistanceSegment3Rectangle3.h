///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 17:58)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_SEGMENT3_RECTANGLE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_SEGMENT3_RECTANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Rectangle3.h"
#include "Mathematics/Objects3D/Segment3.h"

namespace Mathematics
{
    template <typename Real>
    class DistanceSegment3Rectangle3 : public DistanceBase<Real, Vector3<Real>>
    {
    public:
        using ClassType = DistanceSegment3Rectangle3<Real>;
        using Vector3 = Vector3<Real>;
        using ParentType = DistanceBase<Real, Vector3>;
        using Segment3 = Segment3<Real>;
        using Rectangle3 = Rectangle3<Real>;
        using Vector2 = Vector2<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceSegment3Rectangle3(const Segment3& segment, const Rectangle3& rectangle) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Segment3 GetSegment() const noexcept;
        NODISCARD Rectangle3 GetRectangle() const noexcept;

        NODISCARD DistanceResult GetSquared() const override;

        NODISCARD DistanceResult GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const override;

        NODISCARD Real GetRectangleCoordinate(int index) const;

    private:
        Segment3 segment;
        Rectangle3 rectangle;

        mutable Vector2 rectCoord;
    };

    using DistanceSegment3Rectangle3F = DistanceSegment3Rectangle3<float>;
    using DistanceSegment3Rectangle3D = DistanceSegment3Rectangle3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_SEGMENT3_RECTANGLE3_H
