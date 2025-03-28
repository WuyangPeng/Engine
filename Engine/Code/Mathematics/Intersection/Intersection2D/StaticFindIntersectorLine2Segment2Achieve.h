///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 17:29)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_SEGMENT2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_SEGMENT2_ACHIEVE_H

#include "StaticFindIntersectorLine2Segment2.h"
#include "StaticTestIntersectorLine2ClassifyDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"

template <typename Real>
Mathematics::StaticFindIntersectorLine2Segment2<Real>::StaticFindIntersectorLine2Segment2(const Line2Type& line, const Segment2Type& segment, const Real dotThreshold, const Real intervalThreshold)
    : ParentType{ dotThreshold }, line{ line }, segment{ segment }, quantity{ 0 }, intervalThreshold{ intervalThreshold }, point{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::StaticFindIntersectorLine2Segment2<Real>::Find()
{
    StaticTestIntersectorLine2Classify<Real> classify{ line.GetOrigin(), line.GetDirection(), segment.GetCenterPoint(), segment.GetDirection(), true, this->GetEpsilon() };

    auto intersectionType = classify.GetIntersectionType();

    if (intersectionType == IntersectionType::Point)
    {
        // 测试线-线相交的点是否在线段上。
        if (MathType::FAbs(classify.GetParameter1()) <= segment.GetExtent() + intervalThreshold)
        {
            quantity = 1;
            point = line.GetOrigin() + classify.GetParameter0() * line.GetDirection();
        }
        else
        {
            quantity = 0;
            intersectionType = IntersectionType::Empty;
        }
    }
    else if (intersectionType == IntersectionType::Line)
    {
        intersectionType = IntersectionType::Segment;
        quantity = std::numeric_limits<int>::max();
    }
    else
    {
        quantity = 0;
        intersectionType = IntersectionType::Empty;
    }

    this->SetIntersectionType(intersectionType);
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorLine2Segment2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && 0 <= quantity)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Line2<Real> Mathematics::StaticFindIntersectorLine2Segment2<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return line;
}

template <typename Real>
Mathematics::Segment2<Real> Mathematics::StaticFindIntersectorLine2Segment2<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segment;
}

template <typename Real>
int Mathematics::StaticFindIntersectorLine2Segment2<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Real Mathematics::StaticFindIntersectorLine2Segment2<Real>::GetIntervalThreshold() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return intervalThreshold;
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::StaticFindIntersectorLine2Segment2<Real>::GetPoint() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (quantity == 1)
    {
        return point;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("不存在唯一的交点。\n"s));
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_SEGMENT2_ACHIEVE_H
