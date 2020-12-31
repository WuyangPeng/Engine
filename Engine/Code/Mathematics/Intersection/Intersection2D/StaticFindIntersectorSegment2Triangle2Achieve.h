///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/22 17:56)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_TRIANGLE2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_TRIANGLE2_ACHIEVE_H

#include "StaticFindIntersectorSegment2Triangle2.h"
#include "Detail/Line2Triangle2Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Intersection/StaticFindIntersector1Detail.h"

template <typename Real>
Mathematics::StaticFindIntersectorSegment2Triangle2<Real>::StaticFindIntersectorSegment2Triangle2(const Segment2& segment, const Triangle2& triangle, const Real dotThreshold)
    : ParentType{ dotThreshold },
      m_Segment{ segment },
      m_Triangle{ triangle },
      m_Quantity{},
      m_Point0{},
      m_Point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorSegment2Triangle2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && 0 <= m_Quantity)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Segment2<Real> Mathematics::StaticFindIntersectorSegment2Triangle2<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Segment;
}

template <typename Real>
const Mathematics::Triangle2<Real> Mathematics::StaticFindIntersectorSegment2Triangle2<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Triangle;
}

template <typename Real>
void Mathematics::StaticFindIntersectorSegment2Triangle2<Real>::Find()
{
    Line2Triangle2<Real> line2Triangle2{ m_Segment.GetCenterPoint(), m_Segment.GetDirection(), m_Triangle };

    if (line2Triangle2.GetPositive() == 3 || line2Triangle2.GetNegative() == 3)
    {
        // 不相交。
        m_Quantity = 0;
        this->SetIntersectionType(IntersectionType::Empty);
    }
    else
    {
        auto param = line2Triangle2.GetInterval();

        StaticFindIntersector1<Real> intr{ param[0], param[1], -m_Segment.GetExtent(), +m_Segment.GetExtent() };

        m_Quantity = intr.GetNumIntersections();
        if (m_Quantity == 2)
        {
            // 线段相交
            this->SetIntersectionType(IntersectionType::Segment);
            m_Point0 = m_Segment.GetCenterPoint() + intr.GetIntersection(0) * m_Segment.GetDirection();
            m_Point1 = m_Segment.GetCenterPoint() + intr.GetIntersection(1) * m_Segment.GetDirection();
        }
        else if (m_Quantity == 1)
        {
            // 点相交

            this->SetIntersectionType(IntersectionType::Point);
            m_Point0 = m_Segment.GetCenterPoint() + intr.GetIntersection(0) * m_Segment.GetDirection();
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

    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::StaticFindIntersectorSegment2Triangle2<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index == 0)
    {
        return m_Point0;
    }
    else if (index == 1)
    {
        return m_Point1;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("索引越界"s));
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_TRIANGLE2_ACHIEVE_H