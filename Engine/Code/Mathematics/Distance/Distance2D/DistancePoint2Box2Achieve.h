///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/08 14:26)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_BOX2_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_BOX2_ACHIEVE_H

#include "DistancePoint2Box2.h"
#include "Mathematics/Algebra/Vector2DDetail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Objects2D/Box2Detail.h"

template <typename Real>
Mathematics::DistancePoint2Box2<Real>::DistancePoint2Box2(const Vector2D& point, const Box2& box) noexcept
    : ParentType{}, m_Point{ point }, m_Box{ box }
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
const Mathematics::Vector2D<Real> Mathematics::DistancePoint2Box2<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Point;
}

template <typename Real>
const Mathematics::Box2<Real> Mathematics::DistancePoint2Box2<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Box;
}

template <typename Real>
const typename Mathematics::DistancePoint2Box2<Real>::DistanceResult Mathematics::DistancePoint2Box2<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    // 在包围盒的坐标系中工作。
    auto difference = m_Point - m_Box.GetCenter();

    // 计算平方距离和包围盒上的最近点。
    Vector2D closest{ Vector2DTools::DotProduct(difference, m_Box.GetAxis0()),
                      Vector2DTools::DotProduct(difference, m_Box.GetAxis1()) };
    auto squaredDistance = Math::GetValue(0);
    auto delta = Math::GetValue(0);

    if (closest.GetX() < -m_Box.GetExtent0())
    {
        delta = closest.GetX() + m_Box.GetExtent0();
        squaredDistance += delta * delta;
        closest.SetX(-m_Box.GetExtent0());
    }
    else if (m_Box.GetExtent0() < closest.GetX())
    {
        delta = closest.GetX() - m_Box.GetExtent0();
        squaredDistance += delta * delta;
        closest.SetX(m_Box.GetExtent0());
    }

    if (closest.GetY() < -m_Box.GetExtent1())
    {
        delta = closest.GetY() + m_Box.GetExtent1();
        squaredDistance += delta * delta;
        closest.SetY(-m_Box.GetExtent1());
    }
    else if (m_Box.GetExtent1() < closest.GetY())
    {
        delta = closest.GetY() - m_Box.GetExtent1();
        squaredDistance += delta * delta;
        closest.SetY(m_Box.GetExtent1());
    }

    return DistanceResult{ squaredDistance, Math::GetValue(0), m_Point,
                           m_Box.GetCenter() + closest.GetX() * m_Box.GetAxis0() + closest.GetY() * m_Box.GetAxis1() };
}

template <typename Real>
const typename Mathematics::DistancePoint2Box2<Real>::DistanceResult Mathematics::DistancePoint2Box2<Real>::GetSquared(Real t, const Vector2D& lhsVelocity, const Vector2D& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movePoint = m_Point.GetMove(t, lhsVelocity);
    auto movedBox = m_Box.GetMove(t, rhsVelocity);

    ClassType distance{ movePoint, movedBox };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT2_BOX2_ACHIEVE_H
