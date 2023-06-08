///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 18:06)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_RECTANGLE3_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_RECTANGLE3_DETAIL_H

#include "DistancePoint3Rectangle3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistancePoint3Rectangle3<Real>::DistancePoint3Rectangle3(const Vector3& point, const Rectangle3& rectangle) noexcept
    : ParentType{}, point{ point }, rectangle{ rectangle }, rectCoord{}
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
Mathematics::Vector3<Real> Mathematics::DistancePoint3Rectangle3<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return point;
}

template <typename Real>
Mathematics::Rectangle3<Real> Mathematics::DistancePoint3Rectangle3<Real>::GetRectangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rectangle;
}

template <typename Real>
typename Mathematics::DistancePoint3Rectangle3<Real>::DistanceResult Mathematics::DistancePoint3Rectangle3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto diff = rectangle.GetCenter() - point;
    auto dot0 = Vector3Tools::DotProduct(diff, rectangle.GetAxis(0));
    auto dot1 = Vector3Tools::DotProduct(diff, rectangle.GetAxis(1));
    auto s0 = -dot0;
    auto s1 = -dot1;
    auto sqrDistance = Vector3Tools::GetLengthSquared(diff);

    if (s0 < -rectangle.GetExtent(0))
    {
        s0 = -rectangle.GetExtent(0);
    }
    else if (rectangle.GetExtent(0) < s0)
    {
        s0 = rectangle.GetExtent(0);
    }
    sqrDistance += s0 * (s0 + (Math::GetValue(2)) * dot0);

    if (s1 < -rectangle.GetExtent(1))
    {
        s1 = -rectangle.GetExtent(1);
    }
    else if (rectangle.GetExtent(1) < s1)
    {
        s1 = rectangle.GetExtent(1);
    }
    sqrDistance += s1 * (s1 + (Math::GetValue(2)) * dot1);

    // 解决数字舍入误差。
    if (sqrDistance < Math::GetValue(0))
    {
        sqrDistance = Math::GetValue(0);
    }

    auto closestPoint = rectangle.GetCenter() + s0 * rectangle.GetAxis(0) + s1 * rectangle.GetAxis(1);
    rectCoord[0] = s0;
    rectCoord[1] = s1;

    return DistanceResult{ sqrDistance, Math::GetValue(0), point, closestPoint };
}

template <typename Real>
typename Mathematics::DistancePoint3Rectangle3<Real>::DistanceResult Mathematics::DistancePoint3Rectangle3<Real>::GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movePoint = point.GetMove(t, lhsVelocity);
    const auto movedRectangle = rectangle.GetMove(t, rhsVelocity);

    ClassType distance{ movePoint, movedRectangle };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

template <typename Real>
Real Mathematics::DistancePoint3Rectangle3<Real>::GetRectangleCoordinate(int index) const
{
    return rectCoord[index];
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_RECTANGLE3_DETAIL_H
