///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 15:17)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_LINE2_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_LINE2_ACHIEVE_H

#include "DistancePoint2Line2.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Objects2D/Line2Detail.h"

template <typename Real>
Mathematics::DistancePoint2Line2<Real>::DistancePoint2Line2(const Vector2Type& point, const Line2Type& line) noexcept
    : ParentType{}, point{ point }, line{ line }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DistancePoint2Line2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Vector2<Real> Mathematics::DistancePoint2Line2<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return point;
}

template <typename Real>
Mathematics::Line2<Real> Mathematics::DistancePoint2Line2<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return line;
}

template <typename Real>
typename Mathematics::DistancePoint2Line2<Real>::DistanceResult Mathematics::DistancePoint2Line2<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto difference = point - line.GetOrigin();
    const auto param = Vector2ToolsType::DotProduct(line.GetDirection(), difference);
    const auto rhsClosestPoint = line.GetOrigin() + param * line.GetDirection();
    difference = rhsClosestPoint - point;

    return DistanceResult{ Vector2ToolsType::GetLengthSquared(difference), MathType::GetValue(0), point, rhsClosestPoint };
}

template <typename Real>
typename Mathematics::DistancePoint2Line2<Real>::DistanceResult Mathematics::DistancePoint2Line2<Real>::GetSquared(Real t, const Vector2Type& lhsVelocity, const Vector2Type& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movePoint = point.GetMove(t, lhsVelocity);
    const auto movedLine = line.GetMove(t, rhsVelocity);

    ClassType distance{ movePoint, movedLine };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT2_LINE2_ACHIEVE_H
