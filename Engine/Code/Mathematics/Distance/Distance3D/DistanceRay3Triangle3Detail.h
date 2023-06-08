///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 18:07)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RAY3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_RAY3_TRIANGLE3_DETAIL_H

#include "DistanceLine3Triangle3.h"
#include "DistancePoint3Triangle3.h"
#include "DistanceRay3Triangle3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistanceRay3Triangle3<Real>::DistanceRay3Triangle3(const Ray3& ray, const Triangle3& triangle) noexcept
    : ParentType{}, ray{ ray }, triangle{ triangle }, triangleBary{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DistanceRay3Triangle3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Ray3<Real> Mathematics::DistanceRay3Triangle3<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ray;
}

template <typename Real>
Mathematics::Triangle3<Real> Mathematics::DistanceRay3Triangle3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle;
}

template <typename Real>
typename Mathematics::DistanceRay3Triangle3<Real>::DistanceResult Mathematics::DistanceRay3Triangle3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Vector3 closestPoint0{};
    Vector3 closestPoint1{};

    const Line3<Real> line{ ray.GetOrigin(), ray.GetDirection() };
    DistanceLine3Triangle3<Real> distanceLine3Triangle3{ line, triangle };
    auto sqrDist = distanceLine3Triangle3.GetSquared();
    auto rayParameter = sqrDist.GetLhsParameter();

    if (Math::GetValue(0) <= rayParameter)
    {
        closestPoint0 = sqrDist.GetLhsClosestPoint();
        closestPoint1 = sqrDist.GetRhsClosestPoint();
        triangleBary[0] = distanceLine3Triangle3.GetTriangleBary(0);
        triangleBary[1] = distanceLine3Triangle3.GetTriangleBary(1);
        triangleBary[2] = distanceLine3Triangle3.GetTriangleBary(2);
    }
    else
    {
        closestPoint0 = ray.GetOrigin();
        DistancePoint3Triangle3<Real> distancePoint3Triangle3{ closestPoint0, triangle };
        sqrDist = distancePoint3Triangle3.GetSquared();
        closestPoint1 = sqrDist.GetRhsClosestPoint();
        rayParameter = Math::GetValue(0);
        triangleBary[0] = distancePoint3Triangle3.GetTriangleBary(0);
        triangleBary[1] = distancePoint3Triangle3.GetTriangleBary(1);
        triangleBary[2] = distancePoint3Triangle3.GetTriangleBary(2);
    }

    return DistanceResult{ sqrDist.GetDistance(), Math::GetValue(0), closestPoint0, closestPoint1, rayParameter, Math::GetValue(0) };
}

template <typename Real>
typename Mathematics::DistanceRay3Triangle3<Real>::DistanceResult Mathematics::DistanceRay3Triangle3<Real>::GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movedRay = ray.GetMove(t, lhsVelocity);
    const auto movedTriangle = triangle.GetMove(t, rhsVelocity);

    ClassType distance{ movedRay, movedTriangle };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

template <typename Real>
Real Mathematics::DistanceRay3Triangle3<Real>::GetTriangleBary(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangleBary[index];
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RAY3_TRIANGLE3_DETAIL_H