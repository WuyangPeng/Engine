///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/22 15:13)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_BOX2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_BOX2_ACHIEVE_H

#include "StaticFindIntersectorRay2Box2.h"
#include "Detail/Line2Box2Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorRay2Box2<Real>::StaticFindIntersectorRay2Box2(const Ray2& ray, const Box2& box, const Real dotThreshold)
    : ParentType{ dotThreshold }, m_Ray{ ray }, m_Box{ box }, m_Quantity{}, m_Point0{}, m_Point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorRay2Box2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Ray2<Real> Mathematics::StaticFindIntersectorRay2Box2<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Ray;
}

template <typename Real>
const Mathematics::Box2<Real> Mathematics::StaticFindIntersectorRay2Box2<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Box;
}

template <typename Real>
void Mathematics::StaticFindIntersectorRay2Box2<Real>::Find()
{
    constexpr auto t0 = Math::GetValue(0);
    constexpr auto t1 = Math::sm_MaxReal;

    const Line2Box2<Real> line2Box2{ t0, t1, m_Ray.GetOrigin(), m_Ray.GetDirection(), m_Box, true };
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
int Mathematics::StaticFindIntersectorRay2Box2<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::StaticFindIntersectorRay2Box2<Real>::GetPoint(int index) const
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

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_BOX2_ACHIEVE_H