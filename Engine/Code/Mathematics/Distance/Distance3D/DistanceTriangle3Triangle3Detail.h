///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 16:37)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_TRIANGLE3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_TRIANGLE3_TRIANGLE3_DETAIL_H

#include "DistanceSegment3Triangle3.h"
#include "DistanceTriangle3Triangle3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistanceTriangle3Triangle3<Real>::DistanceTriangle3Triangle3(const Triangle3Type& lhsTriangle, const Triangle3Type& rhsTriangle) noexcept
    : ParentType{}, lhsTriangle{ lhsTriangle }, rhsTriangle{ rhsTriangle }, triangleBary0{}, triangleBary1{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DistanceTriangle3Triangle3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Triangle3<Real> Mathematics::DistanceTriangle3Triangle3<Real>::GetLhsTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return lhsTriangle;
}

template <typename Real>
Mathematics::Triangle3<Real> Mathematics::DistanceTriangle3Triangle3<Real>::GetRhsTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rhsTriangle;
}

template <typename Real>
typename Mathematics::DistanceTriangle3Triangle3<Real>::DistanceResult Mathematics::DistanceTriangle3Triangle3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Vector3Type closestPoint0;
    Vector3Type closestPoint1;

    auto sqrDist = MathType::maxReal;

    // 比较三角形0的边缘与三角形1的内部。
    auto ratio = MathType::GetValue(0);

    for (auto i0 = 2, i1 = 0; i1 < 3; i0 = i1++)
    {
        auto center = (MathType::GetRational(1, 2)) * (lhsTriangle.GetVertex(i0) + lhsTriangle.GetVertex(i1));
        auto direction = lhsTriangle.GetVertex(i1) - lhsTriangle.GetVertex(i0);
        auto extent = (MathType::GetRational(1, 2)) * Vector3ToolsType::GetLength(direction);

        const Segment3<Real> edge{ extent, center, direction };

        DistanceSegment3Triangle3<Real> distanceSegment3Triangle3{ edge, rhsTriangle };

        if (auto squared = distanceSegment3Triangle3.GetSquared();
            squared.GetDistance() < sqrDist)
        {
            closestPoint0 = squared.GetLhsClosestPoint();
            closestPoint1 = squared.GetRhsClosestPoint();
            sqrDist = squared.GetDistance();

            ratio = squared.GetLhsParameter() / edge.GetExtent();
            triangleBary0[i0] = (MathType::GetRational(1, 2)) * (MathType::GetValue(1) - ratio);
            triangleBary0[i1] = MathType::GetValue(1) - triangleBary0[i0];
            triangleBary0[3 - i0 - i1] = MathType::GetValue(0);
            triangleBary1[0] = distanceSegment3Triangle3.GetTriangleBary(0);
            triangleBary1[1] = distanceSegment3Triangle3.GetTriangleBary(1);
            triangleBary1[2] = distanceSegment3Triangle3.GetTriangleBary(2);

            if (sqrDist <= MathType::GetZeroTolerance())
            {
                DistanceResult{ MathType::GetValue(0), MathType::GetValue(0), closestPoint0, closestPoint1 };
            }
        }
    }

    // 将三角形1的边缘与三角形0的内部进行比较。
    for (auto i0 = 2, i1 = 0; i1 < 3; i0 = i1++)
    {
        auto center = (MathType::GetRational(1, 2)) * (rhsTriangle.GetVertex(i0) + rhsTriangle.GetVertex(i1));
        auto direction = rhsTriangle.GetVertex(i1) - rhsTriangle.GetVertex(i0);
        auto extent = (MathType::GetRational(1, 2)) * Vector3ToolsType::GetLength(direction);

        const Segment3<Real> edge{ extent, center, direction };

        DistanceSegment3Triangle3<Real> distanceSegment3Triangle3{ edge, lhsTriangle };

        if (auto squared = distanceSegment3Triangle3.GetSquared();
            squared.GetDistance() < sqrDist)
        {
            closestPoint0 = squared.GetLhsClosestPoint();
            closestPoint1 = squared.GetRhsClosestPoint();
            sqrDist = squared.GetDistance();

            ratio = squared.GetLhsParameter() / edge.GetExtent();
            triangleBary1[i0] = (MathType::GetRational(1, 2)) * (MathType::GetValue(1) - ratio);
            triangleBary1[i1] = MathType::GetValue(1) - triangleBary1[i0];
            triangleBary1[3 - i0 - i1] = MathType::GetValue(0);
            triangleBary0[0] = distanceSegment3Triangle3.GetTriangleBary(0);
            triangleBary0[1] = distanceSegment3Triangle3.GetTriangleBary(1);
            triangleBary0[2] = distanceSegment3Triangle3.GetTriangleBary(2);

            if (sqrDist <= MathType::GetZeroTolerance())
            {
                return DistanceResult{ MathType::GetValue(0), MathType::GetValue(0), closestPoint0, closestPoint1 };
            }
        }
    }

    return DistanceResult{ sqrDist, MathType::GetValue(0), closestPoint0, closestPoint1 };
}

template <typename Real>
typename Mathematics::DistanceTriangle3Triangle3<Real>::DistanceResult Mathematics::DistanceTriangle3Triangle3<Real>::GetSquared(Real t, const Vector3Type& lhsVelocity, const Vector3Type& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movedLhsTriangle = lhsTriangle.GetMove(t, lhsVelocity);
    const auto movedRhsTriangle = rhsTriangle.GetMove(t, rhsVelocity);

    ClassType distance{ movedLhsTriangle, movedRhsTriangle };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

template <typename Real>
Real Mathematics::DistanceTriangle3Triangle3<Real>::GetTriangleBary0(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangleBary0[index];
}

template <typename Real>
Real Mathematics::DistanceTriangle3Triangle3<Real>::GetTriangleBary1(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangleBary1[index];
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_TRIANGLE3_TRIANGLE3_DETAIL_H
