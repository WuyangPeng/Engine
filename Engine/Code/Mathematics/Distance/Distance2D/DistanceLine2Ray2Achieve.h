///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 15:16)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE2_RAY2_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE2_RAY2_ACHIEVE_H

#include "DistanceLine2Ray2.h"
#include "Detail/DistanceLine2Line2ToolDetail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Objects2D/Line2Detail.h"
#include "Mathematics/Objects2D/Ray2Detail.h"

template <typename Real>
Mathematics::DistanceLine2Ray2<Real>::DistanceLine2Ray2(const Line2Type& line, const Ray2Type& ray) noexcept
    : ParentType{}, line{ line }, ray{ ray }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>

bool Mathematics::DistanceLine2Ray2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Line2<Real> Mathematics::DistanceLine2Ray2<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return line;
}

template <typename Real>
Mathematics::Ray2<Real> Mathematics::DistanceLine2Ray2<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ray;
}

template <typename Real>
typename Mathematics::DistanceLine2Ray2<Real>::DistanceResult Mathematics::DistanceLine2Ray2<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const DistanceLine2Line2ToolType tool{ line.GetOrigin(), line.GetDirection(), ray.GetOrigin(), ray.GetDirection() };

    const auto det = tool.GetDet();

    if (this->GetZeroThreshold() <= det)
    {
        const auto rhsT = tool.GetRhsT();

        if (MathType::GetValue(0) <= rhsT)
        {
            // 两个内部点最接近，一个在直线上，一个在射线上。
            const auto lhsT = tool.GetLhsT();

            return DistanceResult{ MathType::GetValue(0), MathType::GetValue(0), line.GetOrigin() + lhsT / det * line.GetDirection(), ray.GetOrigin() + rhsT / det * ray.GetDirection() };
        }
        else
        {
            // 射线的原点同直线的某一点最接近。
            return GetSquaredWithClosestPoints(tool);
        }
    }
    else
    {
        // 线是平行的，最接近的一对点在射线原点。
        return GetSquaredWithClosestPoints(tool);
    }
}

template <typename Real>
typename Mathematics::DistanceLine2Ray2<Real>::DistanceResult Mathematics::DistanceLine2Ray2<Real>::GetSquaredWithClosestPoints(const DistanceLine2Line2ToolType& tool) const
{
    const auto squaredDistance = tool.GetSquaredDistanceWithLhs();

    return DistanceResult{ squaredDistance, MathType::GetValue(0), line.GetOrigin() - tool.GetOriginDifferenceDotLhsDirection() * line.GetDirection(), ray.GetOrigin() };
}

template <typename Real>
typename Mathematics::DistanceLine2Ray2<Real>::DistanceResult Mathematics::DistanceLine2Ray2<Real>::GetSquared(Real t, const Vector2Type& lhsVelocity, const Vector2Type& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movedLine = line.GetMove(t, lhsVelocity);
    const auto movedRay = ray.GetMove(t, rhsVelocity);

    ClassType distance{ movedLine, movedRay };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE2_RAY2_ACHIEVE_H
