///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/15 10:13)

#ifndef MATHEMATICS_DISTANCE_DIST_RAY3_BOX3_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DIST_RAY3_BOX3_ACHIEVE_H

#include "DistanceLine3Box3.h"
#include "DistancePoint3Box3.h"
#include "DistanceRay3Box3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistanceRay3Box3<Real>::DistanceRay3Box3(const Ray3& ray, const Box3& box) noexcept
    : ParentType{}, m_Ray{ ray }, m_Box{ box }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistanceRay3Box3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Ray3<Real> Mathematics::DistanceRay3Box3<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Ray;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::DistanceRay3Box3<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Box;
}

template <typename Real>
typename const Mathematics::DistanceRay3Box3<Real>::DistanceResult Mathematics::DistanceRay3Box3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Vector3D closestPoint0;
    Vector3D closestPoint1;

    const Line3<Real> line{ m_Ray.GetOrigin(), m_Ray.GetDirection() };
    DistanceLine3Box3<Real> distanceLine3Box3{ line, m_Box };
    auto sqrDistance = distanceLine3Box3.GetSquared();
    auto lineParameter = sqrDistance.GetLhsParameter();

    if (Math::GetValue(0) <= lineParameter)
    {
        closestPoint0 = sqrDistance.GetLhsClosestPoint();
        closestPoint1 = sqrDistance.GetRhsClosestPoint();
    }
    else
    {
        DistancePoint3Box3<Real> distancePoint3Box3{ m_Ray.GetOrigin(), m_Box };
        sqrDistance = distancePoint3Box3.GetSquared();
        closestPoint0 = sqrDistance.GetLhsClosestPoint();
        closestPoint1 = sqrDistance.GetRhsClosestPoint();
    }

    return DistanceResult{ sqrDistance.GetDistance(), Math::GetValue(0), closestPoint0, closestPoint1 };
}

template <typename Real>
typename const Mathematics::DistanceRay3Box3<Real>::DistanceResult Mathematics::DistanceRay3Box3<Real>::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto moveRay = m_Ray.GetMove(t, lhsVelocity);
    const auto movedBox = m_Box.GetMove(t, rhsVelocity);

    ClassType distance{ moveRay, movedBox };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DIST_RAY3_BOX3_ACHIEVE_H