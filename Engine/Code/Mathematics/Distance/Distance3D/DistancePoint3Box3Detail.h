///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 16:32)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_BOX3_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_BOX3_DETAIL_H

#include "DistancePoint3Box3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Objects3D/Box3Detail.h"

template <typename Real>
Mathematics::DistancePoint3Box3<Real>::DistancePoint3Box3(const Vector3& point, const Box3& box) noexcept
    : ParentType{}, point{ point }, box{ box }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DistancePoint3Box3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Vector3<Real> Mathematics::DistancePoint3Box3<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return point;
}

template <typename Real>
Mathematics::Box3<Real> Mathematics::DistancePoint3Box3<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return box;
}

template <typename Real>
typename Mathematics::DistancePoint3Box3<Real>::DistanceResult Mathematics::DistancePoint3Box3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    // 在包围盒的坐标系中工作。
    auto difference = point - box.GetCenter();

    // 计算平方距离和包围盒上的最近点。
    Vector3 closest{ Vector3Tools::DotProduct(difference, box.GetAxis0()),
                     Vector3Tools::DotProduct(difference, box.GetAxis1()),
                     Vector3Tools::DotProduct(difference, box.GetAxis2()) };
    auto squaredDistance = Math::GetValue(0);
    auto delta = Math::GetValue(0);

    if (closest.GetX() < -box.GetExtent0())
    {
        delta = closest.GetX() + box.GetExtent0();
        squaredDistance += delta * delta;
        closest.SetX(-box.GetExtent0());
    }
    else if (box.GetExtent0() < closest.GetX())
    {
        delta = closest.GetX() - box.GetExtent0();
        squaredDistance += delta * delta;
        closest.SetX(box.GetExtent0());
    }

    if (closest.GetY() < -box.GetExtent1())
    {
        delta = closest.GetY() + box.GetExtent1();
        squaredDistance += delta * delta;
        closest.SetY(-box.GetExtent1());
    }
    else if (box.GetExtent1() < closest.GetY())
    {
        delta = closest.GetY() - box.GetExtent1();
        squaredDistance += delta * delta;
        closest.SetY(box.GetExtent1());
    }

    if (closest.GetZ() < -box.GetExtent2())
    {
        delta = closest.GetZ() + box.GetExtent2();
        squaredDistance += delta * delta;
        closest.SetZ(-box.GetExtent2());
    }
    else if (box.GetExtent2() < closest.GetZ())
    {
        delta = closest.GetZ() - box.GetExtent2();
        squaredDistance += delta * delta;
        closest.SetZ(box.GetExtent2());
    }

    return DistanceResult{ squaredDistance,
                           Math::GetValue(0),
                           point,
                           box.GetCenter() + closest.GetX() * box.GetAxis0() + closest.GetY() * box.GetAxis1() + closest.GetZ() * box.GetAxis2() };
}

template <typename Real>
typename Mathematics::DistancePoint3Box3<Real>::DistanceResult Mathematics::DistancePoint3Box3<Real>::GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movePoint = point.GetMove(t, lhsVelocity);
    const auto movedBox = box.GetMove(t, rhsVelocity);

    ClassType distance{ movePoint, movedBox };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_BOX3_DETAIL_H
