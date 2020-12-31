// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.2.5 (2020/03/24 15:51)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_ARC2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_ARC2_ACHIEVE_H

#include "StaticFindIntersectorRay2Arc2.h"
#include "Detail/Line2Circle2Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorRay2Arc2<Real>::StaticFindIntersectorRay2Arc2(const Ray2& ray, const Arc2& arc, const Real dotThreshold)
    : ParentType{ dotThreshold }, m_Ray{ ray }, m_Arc{ arc }, m_Quantity{ 0 }, m_Point0{}, m_Point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorRay2Arc2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Ray2<Real> Mathematics::StaticFindIntersectorRay2Arc2<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Ray;
}

template <typename Real>
const Mathematics::Arc2<Real> Mathematics::StaticFindIntersectorRay2Arc2<Real>::GetArc() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Arc;
}

template <typename Real>
void Mathematics::StaticFindIntersectorRay2Arc2<Real>::Find()
{
    Line2Circle2<Real> line2Circle2{ m_Ray.GetOrigin(), m_Ray.GetDirection(), m_Arc.GetCenter(), m_Arc.GetRadius() };

    auto quantity = line2Circle2.GetRootCount();
    if (line2Circle2.IsIntersects())
    {
        /// 如果线与圆的交点不在射线中，则减少根数。
        if (quantity == 1)
        {
            if (line2Circle2.GetParameter(0) < Math::GetValue(0))
            {
                quantity = 0;
            }
        }
        else
        {
            if (line2Circle2.GetParameter(1) < Math::GetValue(0))
            {
                quantity = 0;
            }
            else if (line2Circle2.GetParameter(0) < Math::GetValue(0))
            {
                quantity = 1;
                line2Circle2.ClearParameter0();
            }
        }

        for (auto i = 0; i < quantity; ++i)
        {
            auto point = m_Ray.GetOrigin() + m_Ray.GetDirection() * line2Circle2.GetParameter(i);
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
int Mathematics::StaticFindIntersectorRay2Arc2<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::StaticFindIntersectorRay2Arc2<Real>::GetPoint(int index) const
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

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_ARC2_ACHIEVE_H