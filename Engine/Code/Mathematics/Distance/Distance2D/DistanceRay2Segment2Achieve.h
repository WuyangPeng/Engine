///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 17:51)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RAY2_SEGMENT2_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_RAY2_SEGMENT2_ACHIEVE_H

#include "DistanceRay2Segment2.h"
#include "Detail/DistanceLine2Line2ToolDetail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Objects2D/Ray2Detail.h"
#include "Mathematics/Objects2D/Segment2Detail.h"

template <typename Real>
Mathematics::DistanceRay2Segment2<Real>::DistanceRay2Segment2(const Ray2& ray, const Segment2& segment) noexcept
    : ParentType{}, ray{ ray }, segment{ segment }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DistanceRay2Segment2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Segment2<Real> Mathematics::DistanceRay2Segment2<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segment;
}

template <typename Real>
Mathematics::Ray2<Real> Mathematics::DistanceRay2Segment2<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ray;
}

template <typename Real>
typename Mathematics::DistanceRay2Segment2<Real>::DistanceResult Mathematics::DistanceRay2Segment2<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const DistanceLine2Line2Tool tool{ ray.GetOrigin(), ray.GetDirection(), segment.GetCenterPoint(), segment.GetDirection() };

    const auto det = tool.GetDet();
    const auto rhsExtent = segment.GetExtent();

    if (this->GetZeroThreshold() <= det)
    {
        // 射线和线段不平行
        const auto lhsT = tool.GetLhsT();
        const auto rhsT = tool.GetRhsT();
        const auto rhsExtentMultiplyDet = rhsExtent * det;

        if (Math::GetValue(0) <= lhsT)
        {
            if (-rhsExtentMultiplyDet <= rhsT)
            {
                if (rhsT <= rhsExtentMultiplyDet)
                {
                    // 区域 0

                    // 最小点为射线和线段内部点。
                    return DistanceResult{ Math::GetValue(0),
                                           Math::GetValue(0),
                                           ray.GetOrigin() + lhsT / det * ray.GetDirection(),
                                           segment.GetCenterPoint() + rhsT / det * segment.GetDirection() };
                }
                else
                {
                    // 区域 1
                    return GetSquaredWithClosestPointsIsSegmentEndPoint(tool, rhsExtent);
                }
            }
            else
            {
                // 区域 5
                return GetSquaredWithClosestPointsIsSegmentEndPoint(tool, -rhsExtent);
            }
        }
        else
        {
            if (rhsT <= -rhsExtentMultiplyDet)
            {
                // 区域 4
                return GetSquaredWithClosestPointsIsSegmentBeginPoint(tool, rhsExtent);
            }
            else if (rhsT <= rhsExtentMultiplyDet)
            {
                // 区域 3
                return GetSquaredWithClosestPointsIsRayOrigin(tool, rhsExtent);
            }
            else
            {
                // 区域 2
                return GetSquaredWithClosestPointsIsSegmentBeginPoint(tool, -rhsExtent);
            }
        }
    }
    else
    {
        // 射线和线段平行
        if (Math::GetValue(0) < tool.GetDirectionDot())
        {
            // 相反的方向向量。
            return GetSquaredWithClosestPointsIsSegmentEndPoint(tool, -rhsExtent);
        }
        else
        {
            // 相同的方向向量
            return GetSquaredWithClosestPointsIsSegmentEndPoint(tool, rhsExtent);
        }
    }
}

template <typename Real>
typename Mathematics::DistanceRay2Segment2<Real>::DistanceResult Mathematics::DistanceRay2Segment2<Real>::GetSquaredWithClosestPointsIsSegmentEndPoint(const DistanceLine2Line2Tool& tool, Real rhsExtent) const
{
    const auto t = tool.GetLhsT(-rhsExtent);
    const auto rhsSquare = rhsExtent * (rhsExtent + Math::GetValue(2) * tool.GetOriginDifferenceDotRhsDirection()) +
                           tool.GetOriginDifferenceSquaredLength();

    if (Math::GetValue(0) < t)
    {
        return DistanceResult{ Math::GetNumericalRoundOffNonnegative(-t * t + rhsSquare),
                               Math::GetValue(0),
                               ray.GetOrigin() + t * ray.GetDirection(),
                               segment.GetCenterPoint() + rhsExtent * segment.GetDirection() };
    }
    else
    {
        return DistanceResult{ Math::GetNumericalRoundOffNonnegative(rhsSquare),
                               Math::GetValue(0),
                               ray.GetOrigin(),
                               segment.GetCenterPoint() + rhsExtent * segment.GetDirection() };
    }
}

template <typename Real>
typename Mathematics::DistanceRay2Segment2<Real>::DistanceResult Mathematics::DistanceRay2Segment2<Real>::GetSquaredWithClosestPointsIsSegmentBeginPoint(const DistanceLine2Line2Tool& tool, Real rhsExtent) const
{
    auto t = tool.GetLhsT(rhsExtent);
    if (Math::GetValue(0) < t)
    {
        const auto rhsSquare = -rhsExtent * (-rhsExtent + Math::GetValue(2) * tool.GetOriginDifferenceDotRhsDirection()) +
                               tool.GetOriginDifferenceSquaredLength();

        return DistanceResult{ Math::GetNumericalRoundOffNonnegative(-t * t + rhsSquare),
                               Math::GetValue(0),
                               ray.GetOrigin() + t * ray.GetDirection(),
                               segment.GetCenterPoint() - rhsExtent * segment.GetDirection() };
    }
    else
    {
        return GetSquaredWithClosestPointsIsRayOrigin(tool, Math::FAbs(rhsExtent));
    }
}

template <typename Real>
typename Mathematics::DistanceRay2Segment2<Real>::DistanceResult Mathematics::DistanceRay2Segment2<Real>::GetSquaredWithClosestPointsIsRayOrigin(const DistanceLine2Line2Tool& tool, Real rhsExtent) const
{
    auto dotRhsDirection = -tool.GetOriginDifferenceDotRhsDirection();
    if (dotRhsDirection < -rhsExtent)
    {
        dotRhsDirection = -rhsExtent;
    }
    else if (rhsExtent < dotRhsDirection)
    {
        dotRhsDirection = rhsExtent;
    }

    return DistanceResult{ Math::GetNumericalRoundOffNonnegative(dotRhsDirection * (dotRhsDirection + Math::GetValue(2) * tool.GetOriginDifferenceDotRhsDirection()) +
                                                                 tool.GetOriginDifferenceSquaredLength()),
                           Math::GetValue(0),
                           ray.GetOrigin(),
                           segment.GetCenterPoint() + dotRhsDirection * segment.GetDirection() };
}

template <typename Real>
typename Mathematics::DistanceRay2Segment2<Real>::DistanceResult Mathematics::DistanceRay2Segment2<Real>::GetSquared(Real t, const Vector2& lhsVelocity, const Vector2& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movedRay = ray.GetMove(t, lhsVelocity);
    const auto movedSegment = segment.GetMove(t, rhsVelocity);

    ClassType distance{ movedRay, movedSegment };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RAY2_SEGMENT2_ACHIEVE_H
