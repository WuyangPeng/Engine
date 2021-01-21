///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/20 19:09)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_CYLINDER3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_CYLINDER3_ACHIEVE_H

#include "StaticFindIntersectorLine3Cylinder3Detail.h"
#include "StaticFindIntersectorRay3Cylinder3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorRay3Cylinder3<Real>::StaticFindIntersectorRay3Cylinder3(const Ray3& ray, const Cylinder3& cylinder, const Real epsilon)
    : ParentType{ epsilon }, m_Ray{ ray }, m_Cylinder{ cylinder }, m_Quantity{}, m_Point0{}, m_Point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorRay3Cylinder3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Ray3<Real> Mathematics::StaticFindIntersectorRay3Cylinder3<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Ray;
}

template <typename Real>
const Mathematics::Cylinder3<Real> Mathematics::StaticFindIntersectorRay3Cylinder3<Real>::GetCylinder() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Cylinder;
}

template <typename Real>
void Mathematics::StaticFindIntersectorRay3Cylinder3<Real>::Find()
{
    const auto findShared = StaticFindIntersectorLine3Cylinder3<Real>::Find(m_Ray.GetOrigin(), m_Ray.GetDirection(), m_Cylinder);

    if (0 < findShared.m_Quantity && Math::GetValue(0) <= findShared.m_Parameter0)
    {
        m_Point0 = m_Ray.GetOrigin() + findShared.m_Parameter0 * m_Ray.GetDirection();
        ++m_Quantity;
    }

    if (1 < findShared.m_Quantity && Math::GetValue(0) <= findShared.m_Parameter1)
    {
        if (m_Quantity == 0)
        {
            m_Point0 = m_Ray.GetOrigin() + findShared.m_Parameter1 * m_Ray.GetDirection();
        }
        else
        {
            m_Point1 = m_Ray.GetOrigin() + findShared.m_Parameter1 * m_Ray.GetDirection();
        }

        ++m_Quantity;
    }

    if (m_Quantity == 2)
    {
        this->SetIntersectionType(IntersectionType::Segment);
    }
    else if (m_Quantity == 1)
    {
        this->SetIntersectionType(IntersectionType::Point);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

template <typename Real>
int Mathematics::StaticFindIntersectorRay3Cylinder3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorRay3Cylinder3<Real>::GetPoint(int index) const
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

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_CYLINDER3_ACHIEVE_H