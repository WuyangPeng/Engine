///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 15:17)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_SEGMENT2_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_SEGMENT2_ACHIEVE_H

#include "DistancePoint2Segment2.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Objects2D/Segment2Detail.h"

template <typename Real>
Mathematics::DistancePoint2Segment2<Real>::DistancePoint2Segment2(const Vector2Type& point, const Segment2Type& segment) noexcept
    : ParentType{}, point{ point }, segment{ segment }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DistancePoint2Segment2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Vector2<Real> Mathematics::DistancePoint2Segment2<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return point;
}

template <typename Real>
Mathematics::Segment2<Real> Mathematics::DistancePoint2Segment2<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segment;
}

template <typename Real>
typename Mathematics::DistancePoint2Segment2<Real>::DistanceResult Mathematics::DistancePoint2Segment2<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto difference = point - segment.GetCenterPoint();
    auto param = Vector2ToolsType::DotProduct(segment.GetDirection(), difference);

    Vector2Type rhsClosestPoint{};
    if (-segment.GetExtent() < param)
    {
        if (param < segment.GetExtent())
        {
            rhsClosestPoint = segment.GetCenterPoint() + param * segment.GetDirection();
        }
        else
        {
            rhsClosestPoint = segment.GetEndPoint();
        }
    }
    else
    {
        rhsClosestPoint = segment.GetBeginPoint();
    }

    difference = rhsClosestPoint - point;

    return DistanceResult{ Vector2ToolsType::GetLengthSquared(difference), MathType::GetValue(0), point, rhsClosestPoint };
}

template <typename Real>
typename Mathematics::DistancePoint2Segment2<Real>::DistanceResult Mathematics::DistancePoint2Segment2<Real>::GetSquared(Real t, const Vector2Type& lhsVelocity, const Vector2Type& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movePoint = point.GetMove(t, lhsVelocity);
    const auto movedSegment = segment.GetMove(t, rhsVelocity);

    ClassType distance{ movePoint, movedSegment };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT2_SEGMENT2_ACHIEVE_H
