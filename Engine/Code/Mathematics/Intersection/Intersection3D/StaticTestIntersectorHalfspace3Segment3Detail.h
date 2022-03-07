///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/03/03 21:32)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_HALFSPACE3_SEGMENT3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_HALFSPACE3_SEGMENT3_DETAIL_H

#include "IntersectorUtility3.h"
#include "StaticTestIntersectorHalfspace3Segment3.h"
#include "TestIntersectorAxisDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticTestIntersectorHalfspace3Segment3<Real>::StaticTestIntersectorHalfspace3Segment3(const Plane3& halfspace, const Segment3& segment, const Real epsilon) noexcept
    : ParentType{ epsilon }, halfspace{ halfspace }, segment{ segment }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorHalfspace3Segment3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Plane3<Real> Mathematics::StaticTestIntersectorHalfspace3Segment3<Real>::GetHalfspace() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return halfspace;
}

template <typename Real>
Mathematics::Segment3<Real> Mathematics::StaticTestIntersectorHalfspace3Segment3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return segment;
}

template <typename Real>
void Mathematics::StaticTestIntersectorHalfspace3Segment3<Real>::Test() noexcept
{
    std::array<Vector3, 2> segmentType{ segment.GetBeginPoint(), segment.GetEndPoint() };

    const auto projection = TestIntersectorAxis<Real>::GetProjection(halfspace.GetNormal(), segmentType);
    if (projection.first <= halfspace.GetConstant())
    {
        this->SetIntersectionType(IntersectionType::Point);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_HALFSPACE3_SEGMENT3_DETAIL_H