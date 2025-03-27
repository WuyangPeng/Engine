///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 16:35)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RAY3_SEGMENT3_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_RAY3_SEGMENT3_ACHIEVE_H

#include "DistanceRay3Segment3.h"
#include "Detail/DistanceLine3Line3ToolDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Objects3D/Ray3Detail.h"
#include "Mathematics/Objects3D/Segment3Detail.h"

template <typename Real>
Mathematics::DistanceRay3Segment3<Real>::DistanceRay3Segment3(const Ray3& ray, const Segment3& segment) noexcept
    : ParentType{}, ray{ ray }, segment{ segment }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DistanceRay3Segment3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Segment3<Real> Mathematics::DistanceRay3Segment3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segment;
}

template <typename Real>
Mathematics::Ray3<Real> Mathematics::DistanceRay3Segment3<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ray;
}

template <typename Real>
typename Mathematics::DistanceRay3Segment3<Real>::DistanceResult Mathematics::DistanceRay3Segment3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const DistanceLine3Line3Tool tool{ ray.GetOrigin(), ray.GetDirection(), segment.GetCenterPoint(), segment.GetDirection() };

    const auto det = tool.GetDet();
    const auto rhsExtent = segment.GetExtent();

    if (this->GetZeroThreshold() <= det)
    {
        // 射线和线段不平行
        auto lhsT = tool.GetLhsT();
        auto rhsT = tool.GetRhsT();
        auto rhsExtentMultiplyDet = rhsExtent * det;

        if (MathType::GetValue(0) <= lhsT)
        {
            if (-rhsExtentMultiplyDet <= rhsT)
            {
                if (rhsT <= rhsExtentMultiplyDet)
                {
                    // 区域 0

                    // 最小点为射线和线段内部点。
                    lhsT /= det;
                    rhsT /= det;

                    auto squaredDistance = lhsT * (lhsT + tool.GetDirectionDot() * rhsT + MathType::GetValue(2) * tool.GetOriginDifferenceDotLhsDirection()) +
                                           rhsT * (tool.GetDirectionDot() * lhsT + rhsT + MathType::GetValue(2) * tool.GetOriginDifferenceDotRhsDirection()) +
                                           tool.GetOriginDifferenceSquaredLength();

                    return DistanceResult{ MathType::GetNumericalRoundOffNonnegative(squaredDistance),
                                           MathType::GetValue(0),
                                           ray.GetOrigin() + lhsT * ray.GetDirection(),
                                           segment.GetCenterPoint() + rhsT * segment.GetDirection(),
                                           lhsT,
                                           rhsT };
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
typename Mathematics::DistanceRay3Segment3<Real>::DistanceResult Mathematics::DistanceRay3Segment3<Real>::GetSquaredWithClosestPointsIsSegmentEndPoint(const DistanceLine3Line3Tool& tool, Real rhsExtent) const
{
    const auto t = tool.GetLhsT(-rhsExtent);
    const auto rhsSquare = rhsExtent * (rhsExtent + MathType::GetValue(2) * tool.GetOriginDifferenceDotRhsDirection()) + tool.GetOriginDifferenceSquaredLength();

    if (MathType::GetValue(0) < t)
    {
        return DistanceResult{ MathType::GetNumericalRoundOffNonnegative(-t * t + rhsSquare),
                               MathType::GetValue(0),
                               ray.GetOrigin() + t * ray.GetDirection(),
                               segment.GetCenterPoint() + rhsExtent * segment.GetDirection(),
                               t,
                               rhsExtent };
    }
    else
    {
        return DistanceResult{ MathType::GetNumericalRoundOffNonnegative(rhsSquare),
                               MathType::GetValue(0),
                               ray.GetOrigin(),
                               segment.GetCenterPoint() + rhsExtent * segment.GetDirection(),
                               MathType::GetValue(0),
                               rhsExtent };
    }
}

template <typename Real>
typename Mathematics::DistanceRay3Segment3<Real>::DistanceResult Mathematics::DistanceRay3Segment3<Real>::GetSquaredWithClosestPointsIsSegmentBeginPoint(const DistanceLine3Line3Tool& tool, Real rhsExtent) const
{
    const auto t = tool.GetLhsT(rhsExtent);
    if (MathType::GetValue(0) < t)
    {
        const auto rhsSquare = -rhsExtent * (-rhsExtent + MathType::GetValue(2) * tool.GetOriginDifferenceDotRhsDirection()) + tool.GetOriginDifferenceSquaredLength();

        return DistanceResult{ MathType::GetNumericalRoundOffNonnegative(-t * t + rhsSquare),
                               MathType::GetValue(0),
                               ray.GetOrigin() + t * ray.GetDirection(),
                               segment.GetCenterPoint() - rhsExtent * segment.GetDirection(),
                               t,
                               -rhsExtent };
    }
    else
    {
        return GetSquaredWithClosestPointsIsRayOrigin(tool, MathType::FAbs(rhsExtent));
    }
}

template <typename Real>
typename Mathematics::DistanceRay3Segment3<Real>::DistanceResult Mathematics::DistanceRay3Segment3<Real>::GetSquaredWithClosestPointsIsRayOrigin(const DistanceLine3Line3Tool& tool, Real rhsExtent) const
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

    return DistanceResult{ MathType::GetNumericalRoundOffNonnegative(dotRhsDirection * (dotRhsDirection + MathType::GetValue(2) * tool.GetOriginDifferenceDotRhsDirection()) + tool.GetOriginDifferenceSquaredLength()),
                           MathType::GetValue(0),
                           ray.GetOrigin(),
                           segment.GetCenterPoint() + dotRhsDirection * segment.GetDirection(),
                           MathType::GetValue(0),
                           dotRhsDirection };
}

template <typename Real>
typename Mathematics::DistanceRay3Segment3<Real>::DistanceResult Mathematics::DistanceRay3Segment3<Real>::GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const
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

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RAY3_SEGMENT3_ACHIEVE_H
