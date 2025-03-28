///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 15:17)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_RAY2_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_RAY2_ACHIEVE_H

#include "DistancePoint2Ray2.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Objects2D/Ray2Detail.h"

template <typename Real>
Mathematics::DistancePoint2Ray2<Real>::DistancePoint2Ray2(const Vector2Type& point, const Ray2Type& ray) noexcept
    : ParentType{}, point{ point }, ray{ ray }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DistancePoint2Ray2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Vector2<Real> Mathematics::DistancePoint2Ray2<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return point;
}

template <typename Real>
Mathematics::Ray2<Real> Mathematics::DistancePoint2Ray2<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ray;
}

template <typename Real>
typename Mathematics::DistancePoint2Ray2<Real>::DistanceResult Mathematics::DistancePoint2Ray2<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto difference = point - ray.GetOrigin();
    auto param = Vector2ToolsType::DotProduct(ray.GetDirection(), difference);

    if (param <= MathType::GetValue(0))
    {
        param = MathType::GetValue(0);
    }

    const auto rhsClosestPoint = ray.GetOrigin() + param * ray.GetDirection();
    difference = rhsClosestPoint - point;

    return DistanceResult{ Vector2ToolsType::GetLengthSquared(difference), MathType::GetValue(0), point, rhsClosestPoint };
}

template <typename Real>
typename Mathematics::DistancePoint2Ray2<Real>::DistanceResult Mathematics::DistancePoint2Ray2<Real>::GetSquared(Real t, const Vector2Type& lhsVelocity, const Vector2Type& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movePoint = point.GetMove(t, lhsVelocity);
    const auto movedRay = ray.GetMove(t, rhsVelocity);

    ClassType distance{ movePoint, movedRay };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT2_RAY2_ACHIEVE_H
