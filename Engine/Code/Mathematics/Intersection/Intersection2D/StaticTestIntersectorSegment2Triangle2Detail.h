///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/02/25 11:46)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT2_TRIANGLE2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT2_TRIANGLE2_DETAIL_H

#include "StaticTestIntersectorLine2Triangle2.h"
#include "StaticTestIntersectorSegment2Triangle2.h"
#include "Detail/Line2Triangle2Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Intersection/StaticFindIntersector1.h"

template <typename Real>
Mathematics::StaticTestIntersectorSegment2Triangle2<Real>::StaticTestIntersectorSegment2Triangle2(const Segment2& segment, const Triangle2& triangle, const Real dotThreshold)
    : ParentType{ dotThreshold }, segment{ segment }, triangle{ triangle }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorSegment2Triangle2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Segment2<Real> Mathematics::StaticTestIntersectorSegment2Triangle2<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segment;
}

template <typename Real>
Mathematics::Triangle2<Real> Mathematics::StaticTestIntersectorSegment2Triangle2<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle;
}

template <typename Real>
void Mathematics::StaticTestIntersectorSegment2Triangle2<Real>::Test()
{
    const Line2Triangle2<Real> line2Triangle2{ segment.GetCenterPoint(), segment.GetDirection(), triangle };

    if (line2Triangle2.GetPositive() == 3 || line2Triangle2.GetNegative() == 3)
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
    else
    {
        const auto param = line2Triangle2.GetInterval();

        StaticFindIntersector1<Real> intr{ param[0], param[1], -segment.GetExtent(), +segment.GetExtent() };

        const auto quantity = intr.GetNumIntersections();
        if (quantity == 2)
        {
            this->SetIntersectionType(IntersectionType::Segment);
        }
        else if (quantity == 1)
        {
            this->SetIntersectionType(IntersectionType::Point);
        }
        else
        {
            this->SetIntersectionType(IntersectionType::Empty);
        }
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT2_TRIANGLE2_DETAIL_H