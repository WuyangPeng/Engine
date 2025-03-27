///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 16:33)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_PLANE3_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_PLANE3_ACHIEVE_H

#include "DistancePoint3Plane3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistancePoint3Plane3<Real>::DistancePoint3Plane3(const Vector3& point, const Plane3& plane) noexcept
    : ParentType{}, point{ point }, plane{ plane }
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
Mathematics::Vector3<Real> Mathematics::DistancePoint3Plane3<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return point;
}

template <typename Real>
Mathematics::Plane3<Real> Mathematics::DistancePoint3Plane3<Real>::GetPlane() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return plane;
}

template <typename Real>
typename Mathematics::DistancePoint3Plane3<Real>::DistanceResult Mathematics::DistancePoint3Plane3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto signedDistance = Vector3Tools::DotProduct(plane.GetNormal(), point) - plane.GetConstant();

    return DistanceResult{ MathType::FAbs(signedDistance), MathType::GetValue(0), point, point - signedDistance * plane.GetNormal() };
}

template <typename Real>
typename Mathematics::DistancePoint3Plane3<Real>::DistanceResult Mathematics::DistancePoint3Plane3<Real>::GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movePoint = point.GetMove(t, lhsVelocity);
    const auto movedPlane = plane.GetMove(t, rhsVelocity);

    ClassType distance{ movePoint, movedPlane };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_PLANE3_ACHIEVE_H