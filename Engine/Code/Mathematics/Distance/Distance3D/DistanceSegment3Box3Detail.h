///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/02/22 15:36)

#ifndef MATHEMATICS_DISTANCE_DIST_SEGMENT3_BOX3_DETAIL_H
#define MATHEMATICS_DISTANCE_DIST_SEGMENT3_BOX3_DETAIL_H

#include "DistanceLine3Box3.h"
#include "DistancePoint3Box3.h"
#include "DistanceSegment3Box3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistanceSegment3Box3<Real>::DistanceSegment3Box3(const Segment3& segment, const Box3& box) noexcept
    : ParentType{}, segment{ segment }, box{ box }
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
Mathematics::Segment3<Real> Mathematics::DistanceSegment3Box3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segment;
}

template <typename Real>
Mathematics::Box3<Real> Mathematics::DistanceSegment3Box3<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return box;
}

template <typename Real>
typename Mathematics::DistanceSegment3Box3<Real>::DistanceResult Mathematics::DistanceSegment3Box3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Vector3 closestPoint0{};
    Vector3 closestPoint1{};

    const Line3<Real> line{ segment.GetCenterPoint(), segment.GetDirection() };
    DistanceLine3Box3<Real> distanceLine3Box3{ line, box };
    auto sqrDistance = distanceLine3Box3.GetSquared();
    auto lineParameter = sqrDistance.GetLhsParameter();

    if (-segment.GetExtent() <= lineParameter)
    {
        if (lineParameter <= segment.GetExtent())
        {
            closestPoint0 = sqrDistance.GetLhsClosestPoint();
            closestPoint1 = sqrDistance.GetRhsClosestPoint();
        }
        else
        {
            DistancePoint3Box3<Real> distancePoint3Box3{ segment.GetEndPoint(), box };
            sqrDistance = distancePoint3Box3.GetSquared();
            closestPoint0 = sqrDistance.GetLhsClosestPoint();
            closestPoint1 = sqrDistance.GetRhsClosestPoint();
        }
    }
    else
    {
        DistancePoint3Box3<Real> distancePoint3Box3{ segment.GetBeginPoint(), box };
        sqrDistance = distancePoint3Box3.GetSquared();
        closestPoint0 = sqrDistance.GetLhsClosestPoint();
        closestPoint1 = sqrDistance.GetRhsClosestPoint();
    }

    return DistanceResult{ sqrDistance.GetDistance(), Math::GetValue(0), closestPoint0, closestPoint1, lineParameter, Math::GetValue(0) };
}

template <typename Real>
typename Mathematics::DistanceSegment3Box3<Real>::DistanceResult Mathematics::DistanceSegment3Box3<Real>::GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movedSegment = segment.GetMove(t, lhsVelocity);
    const auto movedBox = box.GetMove(t, rhsVelocity);

    ClassType distance{ movedSegment, movedBox };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DIST_SEGMENT3_BOX3_DETAIL_H