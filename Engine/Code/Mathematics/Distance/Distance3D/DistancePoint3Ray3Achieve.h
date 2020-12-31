///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/10 11:05)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_RAY3_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_RAY3_ACHIEVE_H

#include "DistancePoint3Ray3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Objects3D/Ray3Detail.h"

template <typename Real>
Mathematics::DistancePoint3Ray3<Real>::DistancePoint3Ray3(const Vector3D& point, const Ray3& ray) noexcept
    : ParentType{}, m_Point{ point }, m_Ray{ ray }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistancePoint3Ray3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DistancePoint3Ray3<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Point;
}

template <typename Real>
const Mathematics::Ray3<Real> Mathematics::DistancePoint3Ray3<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Ray;
}

template <typename Real>
const typename Mathematics::DistancePoint3Ray3<Real>::DistanceResult Mathematics::DistancePoint3Ray3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto difference = m_Point - m_Ray.GetOrigin();
    auto param = Vector3DTools::DotProduct(m_Ray.GetDirection(), difference);

    if (param <= Math::GetValue(0))
    {
        param = Math::GetValue(0);
    }

    auto rhsClosestPoint = m_Ray.GetOrigin() + param * m_Ray.GetDirection();
    difference = rhsClosestPoint - m_Point;

    return DistanceResult{ Vector3DTools::VectorMagnitudeSquared(difference), Math::GetValue(0),
                           m_Point, rhsClosestPoint, Math::GetValue(0), param };
}

template <typename Real>
const typename Mathematics::DistancePoint3Ray3<Real>::DistanceResult Mathematics::DistancePoint3Ray3<Real>::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
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

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_RAY3_ACHIEVE_H
