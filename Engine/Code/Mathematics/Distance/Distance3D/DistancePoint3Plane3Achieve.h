///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/14 15:11)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_PLANE3_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_PLANE3_ACHIEVE_H

#include "DistancePoint3Plane3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real> 
Mathematics::DistancePoint3Plane3<Real>::DistancePoint3Plane3(const Vector3D& point, const Plane3& plane) noexcept
    : ParentType{}, m_Point{ point }, m_Plane{ plane }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistancePoint3Plane3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DistancePoint3Plane3<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Point;
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::DistancePoint3Plane3<Real>::GetPlane() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Plane;
}

template <typename Real>
typename const Mathematics::DistancePoint3Plane3<Real>::DistanceResult Mathematics::DistancePoint3Plane3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto signedDistance = Vector3DTools::DotProduct(m_Plane.GetNormal(), m_Point) - m_Plane.GetConstant();

    return DistanceResult{ Math::FAbs(signedDistance), Math::GetValue(0), m_Point, m_Point - signedDistance * m_Plane.GetNormal() };
}

template <typename Real>
typename const Mathematics::DistancePoint3Plane3<Real>::DistanceResult Mathematics::DistancePoint3Plane3<Real>::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movePoint = m_Point.GetMove(t, lhsVelocity);
    const auto movedPlane = m_Plane.GetMove(t, rhsVelocity);

    ClassType distance{ movePoint, movedPlane };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_PLANE3_ACHIEVE_H