///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 16:37)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_SEGMENT3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_SEGMENT3_TRIANGLE3_DETAIL_H

#include "DistanceLine3Triangle3.h"
#include "DistancePoint3Triangle3.h"
#include "DistanceSegment3Triangle3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistanceSegment3Triangle3<Real>::DistanceSegment3Triangle3(const Segment3& segment, const Triangle3& triangle) noexcept
    : ParentType{}, segment{ segment }, triangle{ triangle }, triangleBary{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DistanceSegment3Triangle3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Segment3<Real> Mathematics::DistanceSegment3Triangle3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segment;
}

template <typename Real>
Mathematics::Triangle3<Real> Mathematics::DistanceSegment3Triangle3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle;
}

template <typename Real>
typename Mathematics::DistanceSegment3Triangle3<Real>::DistanceResult Mathematics::DistanceSegment3Triangle3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Vector3 closestPoint0{};
    Vector3 closestPoint1{};

    const Line3<Real> line{ segment.GetCenterPoint(), segment.GetDirection() };
    DistanceLine3Triangle3<Real> distanceLine3Triangle3{ line, triangle };
    auto sqrDist = distanceLine3Triangle3.GetSquared();
    auto segmentParameter = sqrDist.GetLhsParameter();

    if (-segment.GetExtent() <= segmentParameter)
    {
        if (segmentParameter <= segment.GetExtent())
        {
            closestPoint0 = sqrDist.GetLhsClosestPoint();
            closestPoint1 = sqrDist.GetRhsClosestPoint();
            triangleBary[0] = distanceLine3Triangle3.GetTriangleBary(0);
            triangleBary[1] = distanceLine3Triangle3.GetTriangleBary(1);
            triangleBary[2] = distanceLine3Triangle3.GetTriangleBary(2);
        }
        else
        {
            closestPoint0 = segment.GetEndPoint();
            DistancePoint3Triangle3<Real> distancePoint3Triangle3{ closestPoint0, triangle };
            sqrDist = distancePoint3Triangle3.GetSquared();
            closestPoint1 = sqrDist.GetRhsClosestPoint();
            segmentParameter = segment.GetExtent();
            triangleBary[0] = distancePoint3Triangle3.GetTriangleBary(0);
            triangleBary[1] = distancePoint3Triangle3.GetTriangleBary(1);
            triangleBary[2] = distancePoint3Triangle3.GetTriangleBary(2);
        }
    }
    else
    {
        closestPoint0 = segment.GetBeginPoint();
        DistancePoint3Triangle3<Real> distancePoint3Triangle3{ closestPoint0, triangle };
        sqrDist = distancePoint3Triangle3.GetSquared();
        closestPoint1 = sqrDist.GetRhsClosestPoint();
        segmentParameter = -segment.GetExtent();
        triangleBary[0] = distancePoint3Triangle3.GetTriangleBary(0);
        triangleBary[1] = distancePoint3Triangle3.GetTriangleBary(1);
        triangleBary[2] = distancePoint3Triangle3.GetTriangleBary(2);
    }

    return DistanceResult{ sqrDist.GetDistance(), MathType::GetValue(0), closestPoint0, closestPoint1, segmentParameter, MathType::GetValue(0) };
}

template <typename Real>
typename Mathematics::DistanceSegment3Triangle3<Real>::DistanceResult Mathematics::DistanceSegment3Triangle3<Real>::GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movedSegment = segment.GetMove(t, lhsVelocity);
    const auto movedTriangle = triangle.GetMove(t, rhsVelocity);

    ClassType distance{ movedSegment, movedTriangle };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

template <typename Real>
Real Mathematics::DistanceSegment3Triangle3<Real>::GetTriangleBary(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangleBary[index];
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_SEGMENT3_TRIANGLE3_DETAIL_H