///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/22 10:17)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_SEGMENT2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_SEGMENT2_ACHIEVE_H

#include "StaticFindIntersectorLine2Segment2.h"
#include "StaticTestIntersectorLine2ClassifyDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"

template <typename Real>
Mathematics::StaticFindIntersectorLine2Segment2<Real>::StaticFindIntersectorLine2Segment2(const Line2& line, const Segment2& segment, const Real dotThreshold, const Real intervalThreshold)
    : ParentType{ dotThreshold }, m_Line{ line }, m_Segment{ segment }, m_Quantity{ 0 }, m_IntervalThreshold{ intervalThreshold }, m_Point{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::StaticFindIntersectorLine2Segment2<Real>::Find()
{
    StaticTestIntersectorLine2Classify<Real> classify{ m_Line.GetOrigin(), m_Line.GetDirection(), m_Segment.GetCenterPoint(), m_Segment.GetDirection(), true, this->GetEpsilon() };

    auto intersectionType = classify.GetIntersectionType();

    if (intersectionType == IntersectionType::Point)
    {
        // 测试线-线相交的点是否在线段上。
        if (Math::FAbs(classify.GetParameter1()) <= m_Segment.GetExtent() + m_IntervalThreshold)
        {
            m_Quantity = 1;
            m_Point = m_Line.GetOrigin() + classify.GetParameter0() * m_Line.GetDirection();
        }
        else
        {
            m_Quantity = 0;
            intersectionType = IntersectionType::Empty;
        }
    }
    else if (intersectionType == IntersectionType::Line)
    {
        intersectionType = IntersectionType::Segment;
        m_Quantity = std::numeric_limits<int>::max();
    }
    else
    {
        m_Quantity = 0;
        intersectionType = IntersectionType::Empty;
    }

    this->SetIntersectionType(intersectionType);
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorLine2Segment2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && 0 <= m_Quantity)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Line2<Real> Mathematics::StaticFindIntersectorLine2Segment2<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Line;
}

template <typename Real>
const Mathematics::Segment2<Real> Mathematics::StaticFindIntersectorLine2Segment2<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Segment;
}

template <typename Real>
int Mathematics::StaticFindIntersectorLine2Segment2<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Quantity;
}

template <typename Real>
Real Mathematics::StaticFindIntersectorLine2Segment2<Real>::GetIntervalThreshold() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_IntervalThreshold;
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::StaticFindIntersectorLine2Segment2<Real>::GetPoint() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (m_Quantity == 1)
    {
        return m_Point;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("不存在唯一的交点。\n"s));
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_SEGMENT2_ACHIEVE_H
