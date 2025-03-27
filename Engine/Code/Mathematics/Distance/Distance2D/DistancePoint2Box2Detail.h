///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 15:16)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_BOX2_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_BOX2_DETAIL_H

#include "DistancePoint2Box2.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Objects2D/Box2Detail.h"

template <typename Real>
Mathematics::DistancePoint2Box2<Real>::DistancePoint2Box2(const Vector2& point, const Box2& box) noexcept
    : ParentType{}, point{ point }, box{ box }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DistancePoint2Box2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Vector2<Real> Mathematics::DistancePoint2Box2<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return point;
}

template <typename Real>
Mathematics::Box2<Real> Mathematics::DistancePoint2Box2<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return box;
}

template <typename Real>
typename Mathematics::DistancePoint2Box2<Real>::DistanceResult Mathematics::DistancePoint2Box2<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    // 在包围盒的坐标系中工作。
    auto difference = point - box.GetCenter();

    // 计算平方距离和包围盒上的最近点。
    Vector2 closest{ Vector2Tools::DotProduct(difference, box.GetAxis0()),
                     Vector2Tools::DotProduct(difference, box.GetAxis1()) };
    auto squaredDistance = MathType::GetValue(0);
    auto delta = MathType::GetValue(0);

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

    return DistanceResult{ squaredDistance,
                           MathType::GetValue(0),
                           point,
                           box.GetCenter() + closest.GetX() * box.GetAxis0() + closest.GetY() * box.GetAxis1() };
}

template <typename Real>
typename Mathematics::DistancePoint2Box2<Real>::DistanceResult Mathematics::DistancePoint2Box2<Real>::GetSquared(Real t, const Vector2& lhsVelocity, const Vector2& rhsVelocity) const
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

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT2_BOX2_DETAIL_H
