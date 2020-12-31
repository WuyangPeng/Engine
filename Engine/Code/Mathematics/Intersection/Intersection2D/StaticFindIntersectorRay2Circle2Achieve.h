///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/22 15:58)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_CIRCLE2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_CIRCLE2_ACHIEVE_H

#include "StaticFindIntersectorRay2Circle2.h"
#include "Detail/Line2Circle2Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorRay2Circle2<Real>::StaticFindIntersectorRay2Circle2(const Ray2& ray, const Circle2& circle, const Real dotThreshold)
    : ParentType{ dotThreshold }, m_Ray{ ray }, m_Circle{ circle }, m_Quantity{}, m_Point0{}, m_Point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorRay2Circle2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Ray2<Real> Mathematics::StaticFindIntersectorRay2Circle2<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Ray;
}

template <typename Real>
const Mathematics::Circle2<Real> Mathematics::StaticFindIntersectorRay2Circle2<Real>::GetCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Circle;
}

template <typename Real>
void Mathematics::StaticFindIntersectorRay2Circle2<Real>::Find()
{
    Line2Circle2<Real> line2Circle2{ m_Ray.GetOrigin(), m_Ray.GetDirection(), m_Circle.GetCenter(), m_Circle.GetRadius() };

    if (line2Circle2.IsIntersects())
    {
        // 如果线与圆的交点不在射光线中，则减少根数。
        auto quantity = line2Circle2.GetRootCount();
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

        m_Quantity = 0;
        for (auto i = 0; i < line2Circle2.GetRootCount(); ++i)
        {
            auto point = m_Ray.GetOrigin() + line2Circle2.GetParameter(i) * m_Ray.GetDirection();

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

template <typename Real>
int Mathematics::StaticFindIntersectorRay2Circle2<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::StaticFindIntersectorRay2Circle2<Real>::GetPoint(int index) const
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

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_CIRCLE2_ACHIEVE_H