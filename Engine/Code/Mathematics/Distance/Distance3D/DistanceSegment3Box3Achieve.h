///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/15 15:16)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_SEGMENT3_BOX3_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_SEGMENT3_BOX3_ACHIEVE_H

#include "DistanceLine3Box3.h"
#include "DistancePoint3Box3.h"
#include "DistanceSegment3Box3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistanceSegment3Box3<Real>::DistanceSegment3Box3(const Segment3& segment, const Box3& box) noexcept
    : ParentType{}, m_Segment{ segment }, m_Box{ box }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistanceSegment3Box3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::DistanceSegment3Box3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Segment;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::DistanceSegment3Box3<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Box;
}

template <typename Real>
typename const Mathematics::DistanceSegment3Box3<Real>::DistanceResult Mathematics::DistanceSegment3Box3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Vector3D closestPoint0{};
    Vector3D closestPoint1{};

    const Line3<Real> line{ m_Segment.GetCenterPoint(), m_Segment.GetDirection() };
    DistanceLine3Box3<Real> distanceLine3Box3{ line, m_Box };
    auto sqrDistance = distanceLine3Box3.GetSquared();
    auto lineParameter = sqrDistance.GetLhsParameter();

    if (-m_Segment.GetExtent() <= lineParameter)
    {
        if (lineParameter <= m_Segment.GetExtent())
        {
            closestPoint0 = sqrDistance.GetLhsClosestPoint();
            closestPoint1 = sqrDistance.GetRhsClosestPoint();
        }
        else
        {
            DistancePoint3Box3<Real> distancePoint3Box3{ m_Segment.GetEndPoint(), m_Box };
            sqrDistance = distancePoint3Box3.GetSquared();
            closestPoint0 = sqrDistance.GetLhsClosestPoint();
            closestPoint1 = sqrDistance.GetRhsClosestPoint();
        }
    }
    else
    {
        DistancePoint3Box3<Real> distancePoint3Box3{ m_Segment.GetBeginPoint(), m_Box };
        sqrDistance = distancePoint3Box3.GetSquared();
        closestPoint0 = sqrDistance.GetLhsClosestPoint();
        closestPoint1 = sqrDistance.GetRhsClosestPoint();
    }

    return DistanceResult{ sqrDistance.GetDistance(), Math::GetValue(0), closestPoint0, closestPoint1, lineParameter, Math::GetValue(0) };
}

template <typename Real>
typename const Mathematics::DistanceSegment3Box3<Real>::DistanceResult Mathematics::DistanceSegment3Box3<Real>::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movedSegment = m_Segment.GetMove(t, lhsVelocity);
    const auto movedBox = m_Box.GetMove(t, rhsVelocity);

    ClassType distance{ movedSegment, movedBox };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_SEGMENT3_BOX3_ACHIEVE_H