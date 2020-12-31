///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/15 17:12)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_RECTANGLE3_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_RECTANGLE3_ACHIEVE_H

#include "DistancePoint3Rectangle3.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DistancePoint3Rectangle3<Real>::DistancePoint3Rectangle3(const Vector3D& point, const Rectangle3& rectangle) noexcept
    : ParentType{}, m_Point{ point }, m_Rectangle{ rectangle }, m_RectCoord{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistancePoint3Rectangle3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DistancePoint3Rectangle3<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Point;
}

template <typename Real>
const Mathematics::Rectangle3<Real> Mathematics::DistancePoint3Rectangle3<Real>::GetRectangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Rectangle;
}

template <typename Real>
typename const Mathematics::DistancePoint3Rectangle3<Real>::DistanceResult Mathematics::DistancePoint3Rectangle3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto diff = m_Rectangle.GetCenter() - m_Point;
    auto dot0 = Vector3DTools::DotProduct(diff, m_Rectangle.GetAxis(0));
    auto dot1 = Vector3DTools::DotProduct(diff, m_Rectangle.GetAxis(1));
    auto s0 = -dot0;
    auto s1 = -dot1;
    auto sqrDistance = Vector3DTools::VectorMagnitudeSquared(diff);

    if (s0 < -m_Rectangle.GetExtent(0))
    {
        s0 = -m_Rectangle.GetExtent(0);
    }
    else if (m_Rectangle.GetExtent(0)  < s0)
    {
        s0 = m_Rectangle.GetExtent(0);
    }
    sqrDistance += s0 * (s0 + (Math::GetValue(2)) * dot0);

    if (s1 < -m_Rectangle.GetExtent(1))
    {
        s1 = -m_Rectangle.GetExtent(1);
    }
    else if (m_Rectangle.GetExtent(1)  < s1)
    {
        s1 = m_Rectangle.GetExtent(1);
    }
    sqrDistance += s1 * (s1 + (Math::GetValue(2)) * dot1);

    // 解决数字舍入误差。 
    if (sqrDistance < Math::GetValue(0))
    {
        sqrDistance = Math::GetValue(0);
    }

    auto closestPoint = m_Rectangle.GetCenter() + s0 * m_Rectangle.GetAxis(0) + s1 * m_Rectangle.GetAxis(1);
    m_RectCoord[0] = s0;
    m_RectCoord[1] = s1;

    return DistanceResult{ sqrDistance, Math::GetValue(0), m_Point, closestPoint };
}

template <typename Real>
typename const Mathematics::DistancePoint3Rectangle3<Real>::DistanceResult Mathematics::DistancePoint3Rectangle3<Real>::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movePoint = m_Point.GetMove(t, lhsVelocity);
    const auto movedRectangle = m_Rectangle.GetMove(t, rhsVelocity);

    ClassType distance{ movePoint, movedRectangle };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

template <typename Real>
Real Mathematics::DistancePoint3Rectangle3<Real>::GetRectangleCoordinate(int index) const
{
    return m_RectCoord[index];
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_RECTANGLE3_ACHIEVE_H
