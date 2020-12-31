///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/15 13:12)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RAY3_TRIANGLE3_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_RAY3_TRIANGLE3_ACHIEVE_H

#include "DistanceLine3Triangle3.h"
#include "DistancePoint3Triangle3.h"
#include "DistanceRay3Triangle3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistanceRay3Triangle3<Real>::DistanceRay3Triangle3(const Ray3& ray, const Triangle3& triangle) noexcept
    : ParentType{}, m_Ray{ ray }, m_Triangle{ triangle }, m_TriangleBary{}
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
const Mathematics::Ray3<Real> Mathematics::DistanceRay3Triangle3<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Ray;
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::DistanceRay3Triangle3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Triangle;
}

template <typename Real>
typename const Mathematics::DistanceRay3Triangle3<Real>::DistanceResult Mathematics::DistanceRay3Triangle3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Vector3D closestPoint0{};
    Vector3D closestPoint1{};

    const Line3<Real> line{ m_Ray.GetOrigin(), m_Ray.GetDirection() };
    DistanceLine3Triangle3<Real> distanceLine3Triangle3{ line, m_Triangle };
    auto sqrDist = distanceLine3Triangle3.GetSquared();
    auto rayParameter = sqrDist.GetLhsParameter();

    if (Math::GetValue(0) <= rayParameter)
    {
        closestPoint0 = sqrDist.GetLhsClosestPoint();
        closestPoint1 = sqrDist.GetRhsClosestPoint();
        m_TriangleBary[0] = distanceLine3Triangle3.GetTriangleBary(0);
        m_TriangleBary[1] = distanceLine3Triangle3.GetTriangleBary(1);
        m_TriangleBary[2] = distanceLine3Triangle3.GetTriangleBary(2);
    }
    else
    {
        closestPoint0 = m_Ray.GetOrigin();
        DistancePoint3Triangle3<Real> distancePoint3Triangle3{ closestPoint0, m_Triangle };
        sqrDist = distancePoint3Triangle3.GetSquared();
        closestPoint1 = sqrDist.GetRhsClosestPoint();
        rayParameter = Math::GetValue(0);
        m_TriangleBary[0] = distancePoint3Triangle3.GetTriangleBary(0);
        m_TriangleBary[1] = distancePoint3Triangle3.GetTriangleBary(1);
        m_TriangleBary[2] = distancePoint3Triangle3.GetTriangleBary(2);
    }

    return DistanceResult{ sqrDist.GetDistance(), Math::GetValue(0), closestPoint0, closestPoint1, rayParameter, Math::GetValue(0) };
}

template <typename Real>
typename const Mathematics::DistanceRay3Triangle3<Real>::DistanceResult Mathematics::DistanceRay3Triangle3<Real>::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movedRay = m_Ray.GetMove(t, lhsVelocity);
    const auto movedTriangle = m_Triangle.GetMove(t, rhsVelocity);

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

    return m_TriangleBary[index];
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RAY3_TRIANGLE3_ACHIEVE_H