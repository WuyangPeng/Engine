///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/21 18:34)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_CIRCLE2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_CIRCLE2_ACHIEVE_H

#include "StaticFindIntersectorLine2Circle2.h"
#include "Detail/Line2Circle2Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorLine2Circle2<Real>::StaticFindIntersectorLine2Circle2(const Line2& line, const Circle2& circle, const Real epsilon)
    : ParentType{ epsilon }, m_Line{ line }, m_Circle{ circle }, m_Quantity{}, m_Point0{}, m_Point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorLine2Circle2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Line2<Real> Mathematics::StaticFindIntersectorLine2Circle2<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Line;
}

template <typename Real>
const Mathematics::Circle2<Real> Mathematics::StaticFindIntersectorLine2Circle2<Real>::GetCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Circle;
}

template <typename Real>
int Mathematics::StaticFindIntersectorLine2Circle2<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::StaticFindIntersectorLine2Circle2<Real>::GetPoint(int index) const
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

template <typename Real>
void Mathematics::StaticFindIntersectorLine2Circle2<Real>::Find()
{
    const Line2Circle2<Real> line2Circle2{ m_Line.GetOrigin(), m_Line.GetDirection(), m_Circle.GetCenter(), m_Circle.GetRadius() };

    m_Quantity = 0;
    if (line2Circle2.IsIntersects())
    {
        for (auto i = 0; i < line2Circle2.GetRootCount(); ++i)
        {
            auto point = m_Line.GetOrigin() + line2Circle2.GetParameter(i) * m_Line.GetDirection();

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

    this->SetIntersectionType(0 < m_Quantity ? IntersectionType::Point : IntersectionType::Empty);
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_CIRCLE2_ACHIEVE_H