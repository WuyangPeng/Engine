///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 18:07)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_SEGMENT3_RECTANGLE3_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_SEGMENT3_RECTANGLE3_DETAIL_H

#include "DistanceLine3Rectangle3.h"
#include "DistancePoint3Rectangle3.h"
#include "DistanceSegment3Rectangle3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistanceSegment3Rectangle3<Real>::DistanceSegment3Rectangle3(const Segment3& segment, const Rectangle3& rectangle) noexcept
    : ParentType{}, segment{ segment }, rectangle{ rectangle }, rectCoord{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DistanceSegment3Rectangle3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Segment3<Real> Mathematics::DistanceSegment3Rectangle3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segment;
}

template <typename Real>
Mathematics::Rectangle3<Real> Mathematics::DistanceSegment3Rectangle3<Real>::GetRectangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rectangle;
}

template <typename Real>
typename Mathematics::DistanceSegment3Rectangle3<Real>::DistanceResult Mathematics::DistanceSegment3Rectangle3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Vector3 closestPoint0{};
    Vector3 closestPoint1{};

    const Line3<Real> line{ segment.GetCenterPoint(), segment.GetDirection() };
    DistanceLine3Rectangle3<Real> distanceLine3Rectangle3{ line, rectangle };
    auto sqrDist = distanceLine3Rectangle3.GetSquared();
    auto segmentParameter = sqrDist.GetLhsParameter();

    if (-segment.GetExtent() <= segmentParameter)
    {
        if (segmentParameter <= segment.GetExtent())
        {
            closestPoint0 = sqrDist.GetLhsClosestPoint();
            closestPoint1 = sqrDist.GetRhsClosestPoint();
            rectCoord[0] = distanceLine3Rectangle3.GetRectangleCoordinate(0);
            rectCoord[1] = distanceLine3Rectangle3.GetRectangleCoordinate(1);
        }
        else
        {
            closestPoint0 = segment.GetEndPoint();
            DistancePoint3Rectangle3<Real> distancePoint3Rectangle3{ closestPoint0, rectangle };
            sqrDist = distancePoint3Rectangle3.GetSquared();
            closestPoint1 = sqrDist.GetRhsClosestPoint();
            segmentParameter = segment.GetExtent();
            rectCoord[0] = distancePoint3Rectangle3.GetRectangleCoordinate(0);
            rectCoord[1] = distancePoint3Rectangle3.GetRectangleCoordinate(1);
        }
    }
    else
    {
        closestPoint0 = segment.GetBeginPoint();
        DistancePoint3Rectangle3<Real> distancePoint3Rectangle3{ closestPoint0, rectangle };
        sqrDist = distancePoint3Rectangle3.GetSquared();
        closestPoint1 = sqrDist.GetRhsClosestPoint();
        segmentParameter = -segment.GetExtent();
        rectCoord[0] = distancePoint3Rectangle3.GetRectangleCoordinate(0);
        rectCoord[1] = distancePoint3Rectangle3.GetRectangleCoordinate(1);
    }

    return DistanceResult{ sqrDist.GetDistance(), Math::GetValue(0), closestPoint0, closestPoint1, segmentParameter, Math::GetValue(0) };
}

template <typename Real>
typename Mathematics::DistanceSegment3Rectangle3<Real>::DistanceResult Mathematics::DistanceSegment3Rectangle3<Real>::GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movedSegment = segment.GetMove(t, lhsVelocity);
    const auto movedRectangle = rectangle.GetMove(t, rhsVelocity);

    ClassType distance{ movedSegment, movedRectangle };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

template <typename Real>
Real Mathematics::DistanceSegment3Rectangle3<Real>::GetRectangleCoordinate(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rectCoord[index];
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_SEGMENT3_RECTANGLE3_DETAIL_H