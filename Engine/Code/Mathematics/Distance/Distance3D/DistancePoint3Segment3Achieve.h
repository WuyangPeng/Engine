///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/10 11:23)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_SEGMENT3_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_SEGMENT3_ACHIEVE_H

#include "DistancePoint3Segment3.h"
#include "Mathematics/Algebra/Vector3DDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Objects3D/Segment3Detail.h"

template <typename Real>
Mathematics::DistancePoint3Segment3<Real>::DistancePoint3Segment3(const Vector3D& point, const Segment3& segment) noexcept
    : ParentType{}, m_Point{ point }, m_Segment{ segment }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistancePoint3Segment3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DistancePoint3Segment3<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Point;
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::DistancePoint3Segment3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Segment;
}

template <typename Real>
const typename Mathematics::DistancePoint3Segment3<Real>::DistanceResult Mathematics::DistancePoint3Segment3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto difference = m_Point - m_Segment.GetCenterPoint();
    auto param = Vector3DTools::DotProduct(m_Segment.GetDirection(), difference);

    Vector3D rhsClosestPoint{};
    if (-m_Segment.GetExtent() < param)
    {
        if (param < m_Segment.GetExtent())
        {
            rhsClosestPoint = m_Segment.GetCenterPoint() + param * m_Segment.GetDirection();
        }
        else
        {
            rhsClosestPoint = m_Segment.GetEndPoint();
            param = m_Segment.GetExtent();
        }
    }
    else
    {
        rhsClosestPoint = m_Segment.GetBeginPoint();
        param = -m_Segment.GetExtent();
    }

    difference = rhsClosestPoint - m_Point;

    return DistanceResult{ Vector3DTools::VectorMagnitudeSquared(difference), Math::GetValue(0),
                           m_Point, rhsClosestPoint, Math::GetValue(0), param };
}

template <typename Real>
const typename Mathematics::DistancePoint3Segment3<Real>::DistanceResult Mathematics::DistancePoint3Segment3<Real>::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movePoint = m_Point.GetMove(t, lhsVelocity);
    const auto movedSegment = m_Segment.GetMove(t, rhsVelocity);

    ClassType distance{ movePoint, movedSegment };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_SEGMENT3_ACHIEVE_H
