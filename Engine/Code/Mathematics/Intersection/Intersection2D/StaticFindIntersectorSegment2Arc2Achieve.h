///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/22 17:43)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_ARC2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_ARC2_ACHIEVE_H

#include "StaticFindIntersectorSegment2Arc2.h"
#include "Detail/Line2Circle2Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorSegment2Arc2<Real>::StaticFindIntersectorSegment2Arc2(const Segment2& segment, const Arc2& arc, const Real dotThreshold)
    : ParentType{ dotThreshold },
      m_Segment{ segment },
      m_Arc{ arc },
      m_Quantity{},
      m_Point0{},
      m_Point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorSegment2Arc2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && 0 <= m_Quantity)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Segment2<Real> Mathematics::StaticFindIntersectorSegment2Arc2<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Segment;
}

template <typename Real>
const Mathematics::Arc2<Real> Mathematics::StaticFindIntersectorSegment2Arc2<Real>::GetArc() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Arc;
}

template <typename Real>
void Mathematics::StaticFindIntersectorSegment2Arc2<Real>::Find()
{
    Line2Circle2<Real> line2Circle2{ m_Segment.GetCenterPoint(), m_Segment.GetDirection(), m_Arc.GetCenter(), m_Arc.GetRadius() };

    if (line2Circle2.IsIntersects())
    {
        auto quantity = line2Circle2.GetRootCount();

        // 如果线-圆交点不在线段上，则减少根数。
        if (quantity == 1)
        {
            if (m_Segment.GetExtent() < Math::FAbs(line2Circle2.GetParameter(0)))
            {
                quantity = 0;
            }
        }
        else
        {
            if (line2Circle2.GetParameter(1) < -m_Segment.GetExtent() || m_Segment.GetExtent() < line2Circle2.GetParameter(0))
            {
                quantity = 0;
            }
            else
            {
                if (line2Circle2.GetParameter(1) <= m_Segment.GetExtent())
                {
                    if (line2Circle2.GetParameter(0) < -m_Segment.GetExtent())
                    {
                        quantity = 1;
                        line2Circle2.ClearParameter0();
                    }
                }
                else
                {
                    quantity = (-m_Segment.GetExtent() <= line2Circle2.GetParameter(0) ? 1 : 0);
                }
            }
        }

        m_Quantity = 0;
        for (auto i = 0; i < quantity; ++i)
        {
            auto point = m_Segment.GetCenterPoint() + m_Segment.GetDirection() * line2Circle2.GetParameter(i);

            if (m_Arc.Contains(point))
            {
                if (m_Quantity == 0)
                {
                    m_Point0 = point;
                }
                else if (m_Quantity == 1)
                {
                    m_Point1 = point;
                }

                ++m_Quantity;
            }
        }
    }

    this->SetIntersectionType(0 < m_Quantity ? IntersectionType::Point : IntersectionType::Empty);
}

template <typename Real>
int Mathematics::StaticFindIntersectorSegment2Arc2<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::StaticFindIntersectorSegment2Arc2<Real>::GetPoint(int index) const
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

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_ARC2_ACHIEVE_H