///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 16:32)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_CIRCLE3_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_CIRCLE3_ACHIEVE_H

#include "DistancePoint3Circle3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistancePoint3Circle3<Real>::DistancePoint3Circle3(const Vector3Type& point, const Circle3Type& circle) noexcept
    : ParentType{}, point{ point }, circle{ circle }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DistancePoint3Circle3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Vector3<Real> Mathematics::DistancePoint3Circle3<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return point;
}

template <typename Real>
Mathematics::Circle3<Real> Mathematics::DistancePoint3Circle3<Real>::GetCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return circle;
}

template <typename Real>
typename Mathematics::DistancePoint3Circle3<Real>::DistanceResult Mathematics::DistancePoint3Circle3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    // P-C在平面上的投影为 Q-C = P-C - Dot(N,P - C) * N。
    const auto pointMinusCenter = point - circle.GetCenter();
    const auto discriminant = pointMinusCenter - Vector3ToolsType::DotProduct(circle.GetNormal(), pointMinusCenter) * circle.GetNormal();
    const auto lengthDiscriminant = Vector3ToolsType::GetLength(discriminant);
    Vector3Type closestPoint{};

    if (MathType::GetValue(0) < lengthDiscriminant)
    {
        closestPoint = circle.GetCenter() + circle.GetRadius() * discriminant / lengthDiscriminant;
    }
    else
    {
        // 所有圆点都与P等距。返回其中一个。
        closestPoint = circle.GetCenter() + circle.GetRadius() * circle.GetDirection0();
    }

    const auto diff = point - closestPoint;
    const auto sqrDistance = Vector3ToolsType::DotProduct(diff, diff);

    return DistanceResult{ sqrDistance, MathType::GetValue(0), point, closestPoint };
}

template <typename Real>
typename Mathematics::DistancePoint3Circle3<Real>::DistanceResult Mathematics::DistancePoint3Circle3<Real>::GetSquared(Real t, const Vector3Type& lhsVelocity, const Vector3Type& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movePoint = point.GetMove(t, lhsVelocity);
    const auto movedCenter = circle.GetMove(t, rhsVelocity);

    ClassType distance{ movePoint, movedCenter };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_CIRCLE3_ACHIEVE_H