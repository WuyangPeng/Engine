///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.3 (2022/02/22 14:35)

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

    return DistanceResult{ Math::FAbs(signedDistance), Math::GetValue(0), point, point - signedDistance * plane.GetNormal() };
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