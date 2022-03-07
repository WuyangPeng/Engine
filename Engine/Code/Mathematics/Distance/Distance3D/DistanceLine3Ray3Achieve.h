///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/02/21 15:43)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE3_RAY3_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE3_RAY3_ACHIEVE_H

#include "DistanceLine3Ray3.h"
#include "Detail/DistanceLine3Line3ToolDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Objects3D/Line3Detail.h"
#include "Mathematics/Objects3D/Ray3Detail.h"

template <typename Real>
Mathematics::DistanceLine3Ray3<Real>::DistanceLine3Ray3(const Line3& line, const Ray3& ray) noexcept
    : ParentType{}, line{ line }, ray{ ray }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DistanceLine3Ray3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Line3<Real> Mathematics::DistanceLine3Ray3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return line;
}

template <typename Real>
Mathematics::Ray3<Real> Mathematics::DistanceLine3Ray3<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ray;
}

template <typename Real>
typename Mathematics::DistanceLine3Ray3<Real>::DistanceResult Mathematics::DistanceLine3Ray3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const DistanceLine3Line3Tool tool{ line.GetOrigin(), line.GetDirection(), ray.GetOrigin(), ray.GetDirection() };

    const auto det = tool.GetDet();

    if (this->GetZeroThreshold() <= det)
    {
        auto rhsT = tool.GetRhsT();

        if (Math::GetValue(0) <= rhsT)
        {
            // 两个内部点最接近，一个在直线上，一个在射线上。
            auto lhsT = tool.GetLhsT() / det;
            rhsT /= det;
            auto squaredDistance = lhsT * (lhsT + tool.GetDirectionDot() * rhsT + Math::GetValue(2) * tool.GetOriginDifferenceDotLhsDirection()) +
                                   rhsT * (tool.GetDirectionDot() * lhsT + rhsT + Math::GetValue(2) * tool.GetOriginDifferenceDotRhsDirection()) +
                                   tool.GetOriginDifferenceSquaredLength();

            return DistanceResult{ Math::GetNumericalRoundOffNonnegative(squaredDistance),
                                   Math::GetValue(0),
                                   line.GetOrigin() + lhsT * line.GetDirection(),
                                   ray.GetOrigin() + rhsT * ray.GetDirection(),
                                   lhsT,
                                   rhsT };
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
typename Mathematics::DistanceLine3Ray3<Real>::DistanceResult Mathematics::DistanceLine3Ray3<Real>::GetSquaredWithClosestPoints(const DistanceLine3Line3Tool& tool) const
{
    auto squaredDistance = tool.GetSquaredDistanceWithLhs();

    return DistanceResult{ squaredDistance,
                           Math::GetValue(0),
                           line.GetOrigin() - tool.GetOriginDifferenceDotLhsDirection() * line.GetDirection(),
                           ray.GetOrigin(),
                           -tool.GetOriginDifferenceDotLhsDirection(),
                           Math::GetValue(0) };
}

template <typename Real>
typename Mathematics::DistanceLine3Ray3<Real>::DistanceResult Mathematics::DistanceLine3Ray3<Real>::GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const
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

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE3_RAY3_ACHIEVE_H
