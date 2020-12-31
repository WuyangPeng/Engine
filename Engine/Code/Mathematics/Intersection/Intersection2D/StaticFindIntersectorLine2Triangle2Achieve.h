// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.2.5 (2020/03/24 15:50)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_TRIANGLE2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_TRIANGLE2_ACHIEVE_H

#include "StaticFindIntersectorLine2Triangle2.h"
#include "Detail/Line2Triangle2Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Intersection/Intersector1.h"
#include "Mathematics/Intersection/StaticFindIntersector1Detail.h"

template <typename Real>
Mathematics::StaticFindIntersectorLine2Triangle2<Real>::StaticFindIntersectorLine2Triangle2(const Line2& line, const Triangle2& triangle, const Real dotThreshold)
    : ParentType{ dotThreshold }, m_Line{ line }, m_Triangle{ triangle }, m_Quantity{}, m_Point0{}, m_Point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorLine2Triangle2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Line2<Real> Mathematics::StaticFindIntersectorLine2Triangle2<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Line;
}

template <typename Real>
const Mathematics::Triangle2<Real> Mathematics::StaticFindIntersectorLine2Triangle2<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Triangle;
}

template <typename Real>
void Mathematics::StaticFindIntersectorLine2Triangle2<Real>::Find()
{
    Line2Triangle2<Real> line2Triangle2{ m_Line.GetOrigin(), m_Line.GetDirection(), m_Triangle };

    if (line2Triangle2.GetPositive() == 3 || line2Triangle2.GetNegative() == 3)
    {
        // 不相交。
        m_Quantity = 0;
        this->SetIntersectionType(IntersectionType::Empty);
    }
    else
    {
        auto param = line2Triangle2.GetInterval();

        StaticFindIntersector1<Real> intr{ param[0], param[1], -Math::sm_MaxReal, +Math::sm_MaxReal };

        m_Quantity = intr.GetNumIntersections();
        if (m_Quantity == 2)
        {
            // 线段相交

            this->SetIntersectionType(IntersectionType::Segment);
            m_Point0 = m_Line.GetOrigin() + intr.GetIntersection(0) * m_Line.GetDirection();
            m_Point1 = m_Line.GetOrigin() + intr.GetIntersection(1) * m_Line.GetDirection();
        }
        else if (m_Quantity == 1)
        {
            // 点相交

            this->SetIntersectionType(IntersectionType::Point);
            m_Point0 = m_Line.GetOrigin() + intr.GetIntersection(0) * m_Line.GetDirection();
        }
        else
        {
            // 不相交
            this->SetIntersectionType(IntersectionType::Empty);
        }
    }
}

template <typename Real>
int Mathematics::StaticFindIntersectorLine2Triangle2<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::StaticFindIntersectorLine2Triangle2<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < m_Quantity)
    {
        if (index == 0)
        {
            return m_Point0;
        }
        else if (index == 1)
        {
            return m_Point1;
        }
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界"s));
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_TRIANGLE2_ACHIEVE_H