///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 15:18)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RAY2_SEGMENT2_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_RAY2_SEGMENT2_ACHIEVE_H

#include "DistanceRay2Segment2.h"
#include "Detail/DistanceLine2Line2ToolDetail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Objects2D/Ray2Detail.h"
#include "Mathematics/Objects2D/Segment2Detail.h"

template <typename Real>
Mathematics::DistanceRay2Segment2<Real>::DistanceRay2Segment2(const Ray2Type& ray, const Segment2Type& segment) noexcept
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

    const DistanceLine2Line2ToolType tool{ ray.GetOrigin(), ray.GetDirection(), segment.GetCenterPoint(), segment.GetDirection() };

    const auto det = tool.GetDet();
    const auto rhsExtent = segment.GetExtent();

    if (this->GetZeroThreshold() <= det)
    {
        // 射线和线段不平行
        const auto lhsT = tool.GetLhsT();
        const auto rhsT = tool.GetRhsT();
        const auto rhsExtentMultiplyDet = rhsExtent * det;

        if (MathType::GetValue(0) <= lhsT)
        {
            if (-rhsExtentMultiplyDet <= rhsT)
            {
                if (rhsT <= rhsExtentMultiplyDet)
                {
                    // 区域 0

                    // 最小点为射线和线段内部点。
                    return DistanceResult{ MathType::GetValue(0),
                                           MathType::GetValue(0),
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
        if (MathType::GetValue(0) < tool.GetDirectionDot())
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
typename Mathematics::DistanceRay2Segment2<Real>::DistanceResult Mathematics::DistanceRay2Segment2<Real>::GetSquaredWithClosestPointsIsSegmentEndPoint(const DistanceLine2Line2ToolType& tool, Real rhsExtent) const
{
    const auto t = tool.GetLhsT(-rhsExtent);
    const auto rhsSquare = rhsExtent * (rhsExtent + MathType::GetValue(2) * tool.GetOriginDifferenceDotRhsDirection()) +
                           tool.GetOriginDifferenceSquaredLength();

    if (MathType::GetValue(0) < t)
    {
        return DistanceResult{ MathType::GetNumericalRoundOffNonnegative(-t * t + rhsSquare),
                               MathType::GetValue(0),
                               ray.GetOrigin() + t * ray.GetDirection(),
                               segment.GetCenterPoint() + rhsExtent * segment.GetDirection() };
    }
    else
    {
        return DistanceResult{ MathType::GetNumericalRoundOffNonnegative(rhsSquare),
                               MathType::GetValue(0),
                               ray.GetOrigin(),
                               segment.GetCenterPoint() + rhsExtent * segment.GetDirection() };
    }
}

template <typename Real>
typename Mathematics::DistanceRay2Segment2<Real>::DistanceResult Mathematics::DistanceRay2Segment2<Real>::GetSquaredWithClosestPointsIsSegmentBeginPoint(const DistanceLine2Line2ToolType& tool, Real rhsExtent) const
{
    auto t = tool.GetLhsT(rhsExtent);
    if (MathType::GetValue(0) < t)
    {
        const auto rhsSquare = -rhsExtent * (-rhsExtent + MathType::GetValue(2) * tool.GetOriginDifferenceDotRhsDirection()) +
                               tool.GetOriginDifferenceSquaredLength();

        return DistanceResult{ MathType::GetNumericalRoundOffNonnegative(-t * t + rhsSquare),
                               MathType::GetValue(0),
                               ray.GetOrigin() + t * ray.GetDirection(),
                               segment.GetCenterPoint() - rhsExtent * segment.GetDirection() };
    }
    else
    {
        return GetSquaredWithClosestPointsIsRayOrigin(tool, MathType::FAbs(rhsExtent));
    }
}

template <typename Real>
typename Mathematics::DistanceRay2Segment2<Real>::DistanceResult Mathematics::DistanceRay2Segment2<Real>::GetSquaredWithClosestPointsIsRayOrigin(const DistanceLine2Line2ToolType& tool, Real rhsExtent) const
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

    return DistanceResult{ MathType::GetNumericalRoundOffNonnegative(dotRhsDirection * (dotRhsDirection + MathType::GetValue(2) * tool.GetOriginDifferenceDotRhsDirection()) +
                                                                 tool.GetOriginDifferenceSquaredLength()),
                           MathType::GetValue(0),
                           ray.GetOrigin(),
                           segment.GetCenterPoint() + dotRhsDirection * segment.GetDirection() };
}

template <typename Real>
typename Mathematics::DistanceRay2Segment2<Real>::DistanceResult Mathematics::DistanceRay2Segment2<Real>::GetSquared(Real t, const Vector2Type& lhsVelocity, const Vector2Type& rhsVelocity) const
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
