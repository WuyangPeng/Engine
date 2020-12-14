///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/14 11:21)

#ifndef MATHEMATICS_DISTANCE_DIST_POINT3_CIRCLE3_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DIST_POINT3_CIRCLE3_ACHIEVE_H

#include "DistancePoint3Circle3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistancePoint3Circle3<Real>::DistancePoint3Circle3(const Vector3D& point, const Circle3& circle) noexcept
    : ParentType{}, m_Point{ point }, m_Circle{ circle }
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
const Mathematics::Vector3D<Real> Mathematics::DistancePoint3Circle3<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Point;
}

template <typename Real>
const Mathematics::Circle3<Real> Mathematics::DistancePoint3Circle3<Real>::GetCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Circle;
}

template <typename Real>
typename const Mathematics::DistancePoint3Circle3<Real>::DistanceResult Mathematics::DistancePoint3Circle3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    // P-C在平面上的投影为 Q-C = P-C - Dot(N,P - C) * N。
    auto pointMinusCenter = m_Point - m_Circle.GetCenter();
    auto discriminant = pointMinusCenter - Vector3DTools::DotProduct(m_Circle.GetNormal(), pointMinusCenter) * m_Circle.GetNormal();
    auto lengthDiscriminant = Vector3DTools::VectorMagnitude(discriminant);
    Vector3D closestPoint{};

    if (Math::GetValue(0) < lengthDiscriminant)
    {
        closestPoint = m_Circle.GetCenter() + m_Circle.GetRadius() * discriminant / lengthDiscriminant;
    }
    else
    {
        // 所有圆点都与P等距。返回其中一个。
        closestPoint = m_Circle.GetCenter() + m_Circle.GetRadius() * m_Circle.GetDirection0();
    }

    auto diff = m_Point - closestPoint;
    auto sqrDistance = Vector3DTools::DotProduct(diff, diff);

    return DistanceResult{ sqrDistance, Math::GetValue(0), m_Point, closestPoint };
}

template <typename Real>
typename const Mathematics::DistancePoint3Circle3<Real>::DistanceResult Mathematics::DistancePoint3Circle3<Real>::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movePoint = m_Point.GetMove(t, lhsVelocity);
    const auto movedCenter = m_Circle.GetMove(t, rhsVelocity);

    ClassType distance{ movePoint, movedCenter };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DIST_POINT3_CIRCLE3_ACHIEVE_H