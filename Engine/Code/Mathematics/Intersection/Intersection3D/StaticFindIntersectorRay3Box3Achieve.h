///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/20 18:41)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_BOX3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_BOX3_ACHIEVE_H

#include "StaticFindIntersectorLine3Box3Detail.h"
#include "StaticFindIntersectorRay3Box3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorRay3Box3<Real>::StaticFindIntersectorRay3Box3(const Ray3& ray, const Box3& box, const Real epsilon)
    : ParentType{ epsilon }, m_Ray{ ray }, m_Box{ box }, m_Quantity{}, m_Point0{}, m_Point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorRay3Box3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Ray3<Real> Mathematics::StaticFindIntersectorRay3Box3<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Ray;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::StaticFindIntersectorRay3Box3<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Box;
}

template <typename Real>
void Mathematics::StaticFindIntersectorRay3Box3<Real>::Find()
{
    constexpr auto t0 = Math::GetValue(0);
    constexpr auto t1 = Math::sm_MaxReal;

    const auto findShared = StaticFindIntersectorLine3Box3<Real>::DoClipping(t0, t1, m_Ray.GetOrigin(), m_Ray.GetDirection(), m_Box, true);
    m_Quantity = findShared.m_Quantity;
    if (findShared.m_Quantity == 1)
    {
        m_Point0 = findShared.m_Point0;
    }
    else if (findShared.m_Quantity == 2)
    {
        m_Point0 = findShared.m_Point0;
        m_Point1 = findShared.m_Point1;
    }

    this->SetIntersectionType(findShared.m_IntersectionType);
}

template <typename Real>
int Mathematics::StaticFindIntersectorRay3Box3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorRay3Box3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < m_Quantity)
    {
        if (index == 0)
            return m_Point0;
        else
            return m_Point1;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"s));
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_BOX3_ACHIEVE_H