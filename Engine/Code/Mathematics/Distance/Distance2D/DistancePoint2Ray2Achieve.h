///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/08 16:55)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_RAY2_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_RAY2_ACHIEVE_H

#include "DistancePoint2Ray2.h"
#include "Mathematics/Algebra/Vector2DDetail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Objects2D/Ray2Detail.h"

template <typename Real>
Mathematics::DistancePoint2Ray2<Real>::DistancePoint2Ray2(const Vector2D& point, const Ray2& ray) noexcept
    : ParentType{}, m_Point{ point }, m_Ray{ ray }
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
const Mathematics::Vector2D<Real> Mathematics::DistancePoint2Ray2<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Point;
}

template <typename Real>
const Mathematics::Ray2<Real> Mathematics::DistancePoint2Ray2<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Ray;
}

template <typename Real>
const typename Mathematics::DistancePoint2Ray2<Real>::DistanceResult Mathematics::DistancePoint2Ray2<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto difference = m_Point - m_Ray.GetOrigin();
    auto param = Vector2DTools::DotProduct(m_Ray.GetDirection(), difference);

    if (param <= Math::GetValue(0))
    {
        param = Math::GetValue(0);
    }

    auto rhsClosestPoint = m_Ray.GetOrigin() + param * m_Ray.GetDirection();
    difference = rhsClosestPoint - m_Point;

    return DistanceResult{ Vector2DTools::VectorMagnitudeSquared(difference), Math::GetValue(0), m_Point, rhsClosestPoint };
}

template <typename Real>
const typename Mathematics::DistancePoint2Ray2<Real>::DistanceResult Mathematics::DistancePoint2Ray2<Real>::GetSquared(Real t, const Vector2D& lhsVelocity, const Vector2D& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movePoint = m_Point.GetMove(t, lhsVelocity);
    const auto movedRay = m_Ray.GetMove(t, rhsVelocity);

    ClassType distance{ movePoint, movedRay };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT2_RAY2_ACHIEVE_H
