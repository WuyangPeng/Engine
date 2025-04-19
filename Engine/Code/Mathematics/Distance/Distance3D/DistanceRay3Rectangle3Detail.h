///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 16:35)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RAY3_RECTANGLE3_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_RAY3_RECTANGLE3_DETAIL_H

#include "DistanceLine3Rectangle3.h"
#include "DistancePoint3Rectangle3.h"
#include "DistanceRay3Rectangle3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistanceRay3Rectangle3<Real>::DistanceRay3Rectangle3(const Ray3Type& ray, const Rectangle3Type& rectangle) noexcept
    : ParentType{}, ray{ ray }, rectangle{ rectangle }, rectCoord{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DistanceRay3Rectangle3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Ray3<Real> Mathematics::DistanceRay3Rectangle3<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ray;
}

template <typename Real>
Mathematics::Rectangle3<Real> Mathematics::DistanceRay3Rectangle3<Real>::GetRectangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rectangle;
}

template <typename Real>
typename Mathematics::DistanceRay3Rectangle3<Real>::DistanceResult Mathematics::DistanceRay3Rectangle3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Vector3Type closestPoint0{};
    Vector3Type closestPoint1{};

    const Line3<Real> line{ ray.GetOrigin(), ray.GetDirection() };
    DistanceLine3Rectangle3<Real> distanceLine3Rectangle3{ line, rectangle };
    auto sqrDist = distanceLine3Rectangle3.GetSquared();
    auto rayParameter = sqrDist.GetLhsParameter();

    if (MathType::GetValue(0) <= rayParameter)
    {
        closestPoint0 = sqrDist.GetLhsClosestPoint();
        closestPoint1 = sqrDist.GetRhsClosestPoint();
        rectCoord[0] = distanceLine3Rectangle3.GetRectangleCoordinate(0);
        rectCoord[1] = distanceLine3Rectangle3.GetRectangleCoordinate(1);
    }
    else
    {
        closestPoint0 = ray.GetOrigin();
        DistancePoint3Rectangle3<Real> distancePoint3Rectangle3{ closestPoint0, rectangle };
        sqrDist = distancePoint3Rectangle3.GetSquared();
        closestPoint1 = sqrDist.GetRhsClosestPoint();
        rayParameter = MathType::GetValue(0);
        rectCoord[0] = distancePoint3Rectangle3.GetRectangleCoordinate(0);
        rectCoord[1] = distancePoint3Rectangle3.GetRectangleCoordinate(1);
    }

    return DistanceResult{ sqrDist.GetDistance(), MathType::GetValue(0), closestPoint0, closestPoint1, rayParameter, MathType::GetValue(0) };
}

template <typename Real>
typename Mathematics::DistanceRay3Rectangle3<Real>::DistanceResult Mathematics::DistanceRay3Rectangle3<Real>::GetSquared(Real t, const Vector3Type& lhsVelocity, const Vector3Type& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movedRay = ray.GetMove(t, lhsVelocity);
    const auto movedRectangle = rectangle.GetMove(t, rhsVelocity);

    ClassType distance{ movedRay, movedRectangle };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

template <typename Real>
Real Mathematics::DistanceRay3Rectangle3<Real>::GetRectangleCoordinate(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rectCoord[index];
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RAY3_RECTANGLE3_DETAIL_H