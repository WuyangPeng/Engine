///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 16:34)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_SEGMENT3_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_SEGMENT3_ACHIEVE_H

#include "DistancePoint3Segment3.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Objects3D/Segment3Detail.h"

template <typename Real>
Mathematics::DistancePoint3Segment3<Real>::DistancePoint3Segment3(const Vector3& point, const Segment3& segment) noexcept
    : ParentType{}, point{ point }, segment{ segment }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DistancePoint3Segment3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Vector3<Real> Mathematics::DistancePoint3Segment3<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return point;
}

template <typename Real>
Mathematics::Segment3<Real> Mathematics::DistancePoint3Segment3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segment;
}

template <typename Real>
typename Mathematics::DistancePoint3Segment3<Real>::DistanceResult Mathematics::DistancePoint3Segment3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto difference = point - segment.GetCenterPoint();
    auto param = Vector3Tools::DotProduct(segment.GetDirection(), difference);

    Vector3 rhsClosestPoint{};
    if (-segment.GetExtent() < param)
    {
        if (param < segment.GetExtent())
        {
            rhsClosestPoint = segment.GetCenterPoint() + param * segment.GetDirection();
        }
        else
        {
            rhsClosestPoint = segment.GetEndPoint();
            param = segment.GetExtent();
        }
    }
    else
    {
        rhsClosestPoint = segment.GetBeginPoint();
        param = -segment.GetExtent();
    }

    difference = rhsClosestPoint - point;

    return DistanceResult{ Vector3Tools::GetLengthSquared(difference),
                           MathType::GetValue(0),
                           point,
                           rhsClosestPoint,
                           MathType::GetValue(0),
                           param };
}

template <typename Real>
typename Mathematics::DistancePoint3Segment3<Real>::DistanceResult Mathematics::DistancePoint3Segment3<Real>::GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const
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

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_SEGMENT3_ACHIEVE_H
