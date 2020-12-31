///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/22 17:50)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_BOX2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_BOX2_ACHIEVE_H

#include "StaticFindIntersectorLine2Box2.h"
#include "Detail/Line2Box2Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorSegment2Box2<Real>::StaticFindIntersectorSegment2Box2(const Segment2& segment, const Box2& box, bool solid, const Real dotThreshold)
    : ParentType{ dotThreshold },
      m_Segment{ segment },
      m_Box{ box },
      m_Solid{ solid },
      m_Quantity{},
      m_Point0{},
      m_Point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorSegment2Box2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && 0 <= m_Quantity)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Segment2<Real> Mathematics::StaticFindIntersectorSegment2Box2<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Segment;
}

template <typename Real>
const Mathematics::Box2<Real> Mathematics::StaticFindIntersectorSegment2Box2<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Box;
}

template <typename Real>
void Mathematics::StaticFindIntersectorSegment2Box2<Real>::Find()
{
    const auto t0 = -m_Segment.GetExtent();
    const auto t1 = m_Segment.GetExtent();

    const Line2Box2<Real> line2Box2{ t0, t1, m_Segment.GetCenterPoint(), m_Segment.GetDirection(), m_Box, m_Solid };
    m_Quantity = line2Box2.GetRootCount();
    if (0 < m_Quantity)
    {
        m_Point0 = line2Box2.GetParameter(0);
    }

    if (1 < m_Quantity)
    {
        m_Point1 = line2Box2.GetParameter(1);
    }

    this->SetIntersectionType(line2Box2.GetIntersects());
}

template <typename Real>
int Mathematics::StaticFindIntersectorSegment2Box2<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::StaticFindIntersectorSegment2Box2<Real>::GetPoint(int index) const
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

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_BOX2_ACHIEVE_H