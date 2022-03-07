///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/02/24 18:42)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_TRIANGLE2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_TRIANGLE2_DETAIL_H

#include "StaticFindIntersectorSegment2Triangle2.h"
#include "Detail/Line2Triangle2Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Intersection/StaticFindIntersector1Detail.h"

template <typename Real>
Mathematics::StaticFindIntersectorSegment2Triangle2<Real>::StaticFindIntersectorSegment2Triangle2(const Segment2& segment, const Triangle2& triangle, const Real dotThreshold)
    : ParentType{ dotThreshold },
      segment{ segment },
      triangle{ triangle },
      quantity{},
      point0{},
      point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorSegment2Triangle2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && 0 <= quantity)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Segment2<Real> Mathematics::StaticFindIntersectorSegment2Triangle2<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segment;
}

template <typename Real>
Mathematics::Triangle2<Real> Mathematics::StaticFindIntersectorSegment2Triangle2<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle;
}

template <typename Real>
void Mathematics::StaticFindIntersectorSegment2Triangle2<Real>::Find()
{
    const Line2Triangle2<Real> line2Triangle2{ segment.GetCenterPoint(), segment.GetDirection(), triangle };

    if (line2Triangle2.GetPositive() == 3 || line2Triangle2.GetNegative() == 3)
    {
        // 不相交。
        quantity = 0;
        this->SetIntersectionType(IntersectionType::Empty);
    }
    else
    {
        auto param = line2Triangle2.GetInterval();

        StaticFindIntersector1<Real> intr{ param[0], param[1], -segment.GetExtent(), +segment.GetExtent() };

        quantity = intr.GetNumIntersections();
        if (quantity == 2)
        {
            // 线段相交
            this->SetIntersectionType(IntersectionType::Segment);
            point0 = segment.GetCenterPoint() + intr.GetIntersection(0) * segment.GetDirection();
            point1 = segment.GetCenterPoint() + intr.GetIntersection(1) * segment.GetDirection();
        }
        else if (quantity == 1)
        {
            // 点相交

            this->SetIntersectionType(IntersectionType::Point);
            point0 = segment.GetCenterPoint() + intr.GetIntersection(0) * segment.GetDirection();
        }
        else
        {
            // 不相交
            this->SetIntersectionType(IntersectionType::Empty);
        }
    }
}

template <typename Real>
int Mathematics::StaticFindIntersectorSegment2Triangle2<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::StaticFindIntersectorSegment2Triangle2<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index == 0)
    {
        return point0;
    }
    else if (index == 1)
    {
        return point1;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("索引越界"s));
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_TRIANGLE2_DETAIL_H