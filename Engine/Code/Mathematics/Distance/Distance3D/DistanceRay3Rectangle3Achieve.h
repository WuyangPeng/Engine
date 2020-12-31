///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/15 11:09)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RAY3_RECTANGLE3_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_RAY3_RECTANGLE3_ACHIEVE_H

#include "DistanceLine3Rectangle3.h"
#include "DistancePoint3Rectangle3.h"
#include "DistanceRay3Rectangle3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistanceRay3Rectangle3<Real>::DistanceRay3Rectangle3(const Ray3& ray, const Rectangle3& rectangle) noexcept
    : ParentType{}, m_Ray{ ray }, m_Rectangle{ rectangle }, m_RectCoord{}
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
const Mathematics::Ray3<Real> Mathematics::DistanceRay3Rectangle3<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Ray;
}

template <typename Real>
const Mathematics::Rectangle3<Real> Mathematics::DistanceRay3Rectangle3<Real>::GetRectangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Rectangle;
}

template <typename Real>
typename const Mathematics::DistanceRay3Rectangle3<Real>::DistanceResult Mathematics::DistanceRay3Rectangle3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Vector3D closestPoint0{};
    Vector3D closestPoint1{};

    const Line3<Real> line{ m_Ray.GetOrigin(), m_Ray.GetDirection() };
    DistanceLine3Rectangle3<Real> distanceLine3Rectangle3{ line, m_Rectangle };
    auto sqrDist = distanceLine3Rectangle3.GetSquared();
    auto rayParameter = sqrDist.GetLhsParameter();

    if (Math::GetValue(0) <= rayParameter)
    {
        closestPoint0 = sqrDist.GetLhsClosestPoint();
        closestPoint1 = sqrDist.GetRhsClosestPoint();
        m_RectCoord[0] = distanceLine3Rectangle3.GetRectangleCoordinate(0);
        m_RectCoord[1] = distanceLine3Rectangle3.GetRectangleCoordinate(1);
    }
    else
    {
        closestPoint0 = m_Ray.GetOrigin();
        DistancePoint3Rectangle3<Real> distancePoint3Rectangle3{ closestPoint0, m_Rectangle };
        sqrDist = distancePoint3Rectangle3.GetSquared();
        closestPoint1 = sqrDist.GetRhsClosestPoint();
        rayParameter = Math::GetValue(0);
        m_RectCoord[0] = distancePoint3Rectangle3.GetRectangleCoordinate(0);
        m_RectCoord[1] = distancePoint3Rectangle3.GetRectangleCoordinate(1);
    }

    return DistanceResult{ sqrDist.GetDistance(), Math::GetValue(0), closestPoint0, closestPoint1, rayParameter, Math::GetValue(0) };
}

template <typename Real>
typename const Mathematics::DistanceRay3Rectangle3<Real>::DistanceResult Mathematics::DistanceRay3Rectangle3<Real>::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movedRay = m_Ray.GetMove(t, lhsVelocity);
    const auto movedRectangle = m_Rectangle.GetMove(t, rhsVelocity);

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

    return m_RectCoord[index];
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RAY3_RECTANGLE3_ACHIEVE_H