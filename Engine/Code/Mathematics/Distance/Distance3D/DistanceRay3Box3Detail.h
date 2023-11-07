///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 16:34)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RAY3_BOX3_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_RAY3_BOX3_DETAIL_H

#include "DistanceLine3Box3.h"
#include "DistancePoint3Box3.h"
#include "DistanceRay3Box3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistanceRay3Box3<Real>::DistanceRay3Box3(const Ray3& ray, const Box3& box) noexcept
    : ParentType{}, ray{ ray }, box{ box }
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
Mathematics::Ray3<Real> Mathematics::DistanceRay3Box3<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ray;
}

template <typename Real>
Mathematics::Box3<Real> Mathematics::DistanceRay3Box3<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return box;
}

template <typename Real>
typename Mathematics::DistanceRay3Box3<Real>::DistanceResult Mathematics::DistanceRay3Box3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Vector3 closestPoint0{};
    Vector3 closestPoint1{};

    const Line3<Real> line{ ray.GetOrigin(), ray.GetDirection() };
    const DistanceLine3Box3<Real> distanceLine3Box3{ line, box };
    auto sqrDistance = distanceLine3Box3.GetSquared();
    auto lineParameter = sqrDistance.GetLhsParameter();

    if (Math::GetValue(0) <= lineParameter)
    {
        closestPoint0 = sqrDistance.GetLhsClosestPoint();
        closestPoint1 = sqrDistance.GetRhsClosestPoint();
    }
    else
    {
        const DistancePoint3Box3<Real> distancePoint3Box3{ ray.GetOrigin(), box };
        sqrDistance = distancePoint3Box3.GetSquared();
        closestPoint0 = sqrDistance.GetLhsClosestPoint();
        closestPoint1 = sqrDistance.GetRhsClosestPoint();
    }

    return DistanceResult{ sqrDistance.GetDistance(), Math::GetValue(0), closestPoint0, closestPoint1 };
}

template <typename Real>
typename Mathematics::DistanceRay3Box3<Real>::DistanceResult Mathematics::DistanceRay3Box3<Real>::GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto moveRay = ray.GetMove(t, lhsVelocity);
    const auto movedBox = box.GetMove(t, rhsVelocity);

    ClassType distance{ moveRay, movedBox };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RAY3_BOX3_DETAIL_H