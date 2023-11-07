///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 16:32)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_ELLIPSOID3_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_ELLIPSOID3_DETAIL_H

#include "DistancePoint3Ellipsoid3.h"
#include "Detail/DistancePoint3Ellipsoid3ToolDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistancePoint3Ellipsoid3<Real>::DistancePoint3Ellipsoid3(const Vector3& point, const Ellipsoid3& ellipsoid) noexcept
    : ParentType{}, point{ point }, ellipsoid{ ellipsoid }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DistancePoint3Ellipsoid3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Vector3<Real> Mathematics::DistancePoint3Ellipsoid3<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return point;
}

template <typename Real>
Mathematics::Ellipsoid3<Real> Mathematics::DistancePoint3Ellipsoid3<Real>::GetEllipsoid() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ellipsoid;
}

template <typename Real>
typename Mathematics::DistancePoint3Ellipsoid3<Real>::DistanceResult Mathematics::DistancePoint3Ellipsoid3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto diff = point - ellipsoid.GetCenter();
    const Vector3 dot{ Vector3Tools::DotProduct(diff, ellipsoid.GetAxis0()),
                       Vector3Tools::DotProduct(diff, ellipsoid.GetAxis1()),
                       Vector3Tools::DotProduct(diff, ellipsoid.GetAxis2()) };

    const DistancePoint3Ellipsoid3Tool<Real> point3Ellipsoid3SquaredDistance{ ellipsoid.GetExtent0(), ellipsoid.GetExtent1(), ellipsoid.GetExtent2(), dot, this->GetZeroThreshold() };

    const auto squaredDistance = point3Ellipsoid3SquaredDistance.GetSquaredDistance();
    const auto outputVector = point3Ellipsoid3SquaredDistance.GetOutputVector();

    const auto lhsClosestPoint = point;
    const auto rhsClosestPoint = ellipsoid.GetCenter() + outputVector.GetX() * ellipsoid.GetAxis0() + outputVector.GetY() * ellipsoid.GetAxis1() + outputVector.GetZ() * ellipsoid.GetAxis2();

    return DistanceResult{ squaredDistance, Math::GetValue(0), lhsClosestPoint, rhsClosestPoint };
}

template <typename Real>
typename Mathematics::DistancePoint3Ellipsoid3<Real>::DistanceResult Mathematics::DistancePoint3Ellipsoid3<Real>::GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movedPoint = point.GetMove(t, lhsVelocity);
    const auto movedEllipsoid = ellipsoid.GetMove(t, rhsVelocity);

    ClassType distance{ movedPoint, movedEllipsoid };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_ELLIPSOID3_DETAIL_H
