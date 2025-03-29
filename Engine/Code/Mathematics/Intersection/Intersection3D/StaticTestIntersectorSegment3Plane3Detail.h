///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:29)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_PLANE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_PLANE3_DETAIL_H

#include "StaticTestIntersectorLine3Plane3.h"
#include "StaticTestIntersectorSegment3Plane3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticTestIntersectorSegment3Plane3<Real>::StaticTestIntersectorSegment3Plane3(const Segment3Type& segment, const Plane3Type& plane, const Real epsilon) noexcept
    : ParentType{ epsilon }, segment{ segment }, plane{ plane }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorSegment3Plane3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Segment3<Real> Mathematics::StaticTestIntersectorSegment3Plane3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return segment;
}

template <typename Real>
Mathematics::Plane3<Real> Mathematics::StaticTestIntersectorSegment3Plane3<Real>::GetPlane() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return plane;
}

template <typename Real>
void Mathematics::StaticTestIntersectorSegment3Plane3<Real>::Test() noexcept
{
    const auto p0 = segment.GetBeginPoint();
    auto sdistance0 = plane.DistanceTo(p0);
    if (MathType::FAbs(sdistance0) <= MathType::GetZeroTolerance())
    {
        sdistance0 = MathType::GetValue(0);
    }

    const auto p1 = segment.GetEndPoint();
    auto sdistance1 = plane.DistanceTo(p1);
    if (MathType::FAbs(sdistance1) <= MathType::GetZeroTolerance())
    {
        sdistance1 = MathType::GetValue(0);
    }

    auto prod = sdistance0 * sdistance1;
    if (prod < MathType::GetValue(0))
    {
        this->SetIntersectionType(IntersectionType::Point);
        return;
    }

    if (MathType::GetValue(0) < prod)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    if (this->GetEpsilon() <= MathType::FAbs(sdistance0) || this->GetEpsilon() <= MathType::FAbs(sdistance1))
    {
        this->SetIntersectionType(IntersectionType::Point);
        return;
    }

    this->SetIntersectionType(IntersectionType::Segment);
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_PLANE3_DETAIL_H