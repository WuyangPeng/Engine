///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 16:33)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_LINE3_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_LINE3_ACHIEVE_H

#include "DistancePoint3Line3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Objects3D/Line3Detail.h"

template <typename Real>
Mathematics::DistancePoint3Line3<Real>::DistancePoint3Line3(const Vector3& point, const Line3& line) noexcept
    : ParentType{}, point{ point }, line{ line }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DistancePoint3Line3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Vector3<Real> Mathematics::DistancePoint3Line3<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return point;
}

template <typename Real>
Mathematics::Line3<Real> Mathematics::DistancePoint3Line3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return line;
}

template <typename Real>
typename Mathematics::DistancePoint3Line3<Real>::DistanceResult Mathematics::DistancePoint3Line3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto difference = point - line.GetOrigin();
    const auto param = Vector3Tools::DotProduct(line.GetDirection(), difference);
    const auto rhsClosestPoint = line.GetOrigin() + param * line.GetDirection();
    difference = rhsClosestPoint - point;

    return DistanceResult{ Vector3Tools::GetLengthSquared(difference), Math::GetValue(0), point, rhsClosestPoint, Math::GetValue(0), param };
}

template <typename Real>
typename Mathematics::DistancePoint3Line3<Real>::DistanceResult Mathematics::DistancePoint3Line3<Real>::GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movePoint = point.GetMove(t, lhsVelocity);
    const auto movedLine = line.GetMove(t, rhsVelocity);

    ClassType distance{ movePoint, movedLine };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_LINE3_ACHIEVE_H
