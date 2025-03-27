///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 17:51)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_CIRCLE2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_CIRCLE2_ACHIEVE_H

#include "StaticFindIntersectorSegment2Circle2.h"
#include "Detail/Line2Circle2Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorSegment2Circle2<Real>::StaticFindIntersectorSegment2Circle2(const Segment2& segment, const Circle2& circle, const Real dotThreshold)
    : ParentType{ dotThreshold },
      segment{ segment },
      circle{ circle },
      quantity{},
      point0{},
      point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorSegment2Circle2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && 0 <= quantity)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Segment2<Real> Mathematics::StaticFindIntersectorSegment2Circle2<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segment;
}

template <typename Real>
Mathematics::Circle2<Real> Mathematics::StaticFindIntersectorSegment2Circle2<Real>::GetCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return circle;
}

template <typename Real>
void Mathematics::StaticFindIntersectorSegment2Circle2<Real>::Find()
{
    Line2Circle2<Real> line2Circle2{ segment.GetCenterPoint(), segment.GetDirection(), circle.GetCenter(), circle.GetRadius() };

    if (line2Circle2.IsIntersects())
    {
        auto rootCount = line2Circle2.GetRootCount();

        // 如果线-圆交点不在线段上，则减少根数。
        if (rootCount == 1)
        {
            if (segment.GetExtent() < MathType::FAbs(line2Circle2.GetParameter(0)))
            {
                rootCount = 0;
            }
        }
        else
        {
            if (line2Circle2.GetParameter(1) < -segment.GetExtent() || segment.GetExtent() < line2Circle2.GetParameter(0))
            {
                rootCount = 0;
            }
            else
            {
                if (line2Circle2.GetParameter(1) <= segment.GetExtent())
                {
                    if (line2Circle2.GetParameter(0) < -segment.GetExtent())
                    {
                        rootCount = 1;
                        line2Circle2.ClearParameter0();
                    }
                }
                else
                {
                    rootCount = (-segment.GetExtent() <= line2Circle2.GetParameter(0) ? 1 : 0);
                }
            }
        }

        quantity = 0;
        for (auto i = 0; i < rootCount; ++i)
        {
            auto point = segment.GetCenterPoint() + segment.GetDirection() * line2Circle2.GetParameter(i);

            if (rootCount == 0)
            {
                point0 = point;
            }
            else if (rootCount == 1)
            {
                point1 = point;
            }

            ++quantity;
        }
    }

    this->SetIntersectionType(0 < quantity ? IntersectionType::Point : IntersectionType::Empty);
}

template <typename Real>
int Mathematics::StaticFindIntersectorSegment2Circle2<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::StaticFindIntersectorSegment2Circle2<Real>::GetPoint(int index) const
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

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_CIRCLE2_ACHIEVE_H