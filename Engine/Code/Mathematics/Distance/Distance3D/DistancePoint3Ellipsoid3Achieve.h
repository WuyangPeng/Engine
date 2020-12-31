///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/09 19:08)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_ELLIPSOID3_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_ELLIPSOID3_ACHIEVE_H

#include "DistancePoint3Ellipsoid3.h"
#include "Detail/DistancePoint3Ellipsoid3ToolDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistancePoint3Ellipsoid3<Real>::DistancePoint3Ellipsoid3(const Vector3D& point, const Ellipsoid3& ellipsoid) noexcept
    : ParentType{}, m_Point{ point }, m_Ellipsoid{ ellipsoid }
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
const Mathematics::Vector3D<Real> Mathematics::DistancePoint3Ellipsoid3<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Point;
}

template <typename Real>
const Mathematics::Ellipsoid3<Real> Mathematics::DistancePoint3Ellipsoid3<Real>::GetEllipsoid() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Ellipsoid;
}

template <typename Real>
const typename Mathematics::DistancePoint3Ellipsoid3<Real>::DistanceResult Mathematics::DistancePoint3Ellipsoid3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto diff = m_Point - m_Ellipsoid.GetCenter();
    const Vector3D dot{ Vector3DTools::DotProduct(diff, m_Ellipsoid.GetAxis0()),
                        Vector3DTools::DotProduct(diff, m_Ellipsoid.GetAxis1()),
                        Vector3DTools::DotProduct(diff, m_Ellipsoid.GetAxis2()) };

    const DistancePoint3Ellipsoid3Tool<Real> point3Ellipsoid3SquaredDistance{ m_Ellipsoid.GetExtent0(), m_Ellipsoid.GetExtent1(), m_Ellipsoid.GetExtent2(), dot, this->GetZeroThreshold() };

    auto squaredDistance = point3Ellipsoid3SquaredDistance.GetSquaredDistance();
    const auto outputVector = point3Ellipsoid3SquaredDistance.GetOutputVector();

    const auto lhsClosestPoint = m_Point;
    auto rhsClosestPoint = m_Ellipsoid.GetCenter() + outputVector.GetX() * m_Ellipsoid.GetAxis0() + outputVector.GetY() * m_Ellipsoid.GetAxis1() + outputVector.GetZ() * m_Ellipsoid.GetAxis2();

    return DistanceResult{ squaredDistance, Math::GetValue(0), lhsClosestPoint, rhsClosestPoint };
}

template <typename Real>
typename const Mathematics::DistancePoint3Ellipsoid3<Real>::DistanceResult Mathematics::DistancePoint3Ellipsoid3<Real>::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movedPoint = m_Point.GetMove(t, lhsVelocity);
    auto movedEllipsoid = m_Ellipsoid.GetMove(t, rhsVelocity);

    ClassType distance{ movedPoint, movedEllipsoid };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_ELLIPSOID3_ACHIEVE_H
