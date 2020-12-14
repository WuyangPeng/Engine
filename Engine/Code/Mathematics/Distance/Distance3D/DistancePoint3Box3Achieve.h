///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/09 19:04)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_BOX3_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_BOX3_ACHIEVE_H

#include "DistancePoint3Box3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Objects3D/Box3Detail.h"

template <typename Real>
Mathematics::DistancePoint3Box3<Real>::DistancePoint3Box3(const Vector3D& point, const Box3& box) noexcept
    : ParentType{}, m_Point{ point }, m_Box{ box }
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
const Mathematics::Vector3D<Real> Mathematics::DistancePoint3Box3<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Point;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::DistancePoint3Box3<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Box;
}

template <typename Real>
const typename Mathematics::DistancePoint3Box3<Real>::DistanceResult Mathematics::DistancePoint3Box3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    // 在包围盒的坐标系中工作。
    auto difference = m_Point - m_Box.GetCenter();

    // 计算平方距离和包围盒上的最近点。
    Vector3D closest{ Vector3DTools::DotProduct(difference, m_Box.GetAxis0()),
                      Vector3DTools::DotProduct(difference, m_Box.GetAxis1()),
                      Vector3DTools::DotProduct(difference, m_Box.GetAxis2()) };
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

    if (closest.GetZ() < -m_Box.GetExtent2())
    {
        delta = closest.GetZ() + m_Box.GetExtent2();
        squaredDistance += delta * delta;
        closest.SetZ(-m_Box.GetExtent2());
    }
    else if (m_Box.GetExtent2() < closest.GetZ())
    {
        delta = closest.GetZ() - m_Box.GetExtent2();
        squaredDistance += delta * delta;
        closest.SetZ(m_Box.GetExtent2());
    }

    return DistanceResult{ squaredDistance,
                           Math::GetValue(0),
                           m_Point,
                           m_Box.GetCenter() + closest.GetX() * m_Box.GetAxis0() + closest.GetY() * m_Box.GetAxis1() + closest.GetZ() * m_Box.GetAxis2() };
}

template <typename Real>
const typename Mathematics::DistancePoint3Box3<Real>::DistanceResult Mathematics::DistancePoint3Box3<Real>::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movePoint = m_Point.GetMove(t, lhsVelocity);
    const auto movedBox = m_Box.GetMove(t, rhsVelocity);

    ClassType distance{ movePoint, movedBox };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_BOX3_ACHIEVE_H
