///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 13:52)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_CYLINDER3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_CYLINDER3_ACHIEVE_H

#include "StaticFindIntersectorLine3Cylinder3Detail.h"
#include "StaticFindIntersectorRay3Cylinder3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorRay3Cylinder3<Real>::StaticFindIntersectorRay3Cylinder3(const Ray3Type& ray, const Cylinder3Type& cylinder, const Real epsilon)
    : ParentType{ epsilon }, ray{ ray }, cylinder{ cylinder }, quantity{}, point0{}, point1{}
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
Mathematics::Ray3<Real> Mathematics::StaticFindIntersectorRay3Cylinder3<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ray;
}

template <typename Real>
Mathematics::Cylinder3<Real> Mathematics::StaticFindIntersectorRay3Cylinder3<Real>::GetCylinder() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return cylinder;
}

template <typename Real>
void Mathematics::StaticFindIntersectorRay3Cylinder3<Real>::Find()
{
    const auto findShared = StaticFindIntersectorLine3Cylinder3<Real>::Find(ray.GetOrigin(), ray.GetDirection(), cylinder);

    if (0 < findShared.quantity && MathType::GetValue(0) <= findShared.parameter0)
    {
        point0 = ray.GetOrigin() + findShared.parameter0 * ray.GetDirection();
        ++quantity;
    }

    if (1 < findShared.quantity && MathType::GetValue(0) <= findShared.parameter1)
    {
        if (quantity == 0)
        {
            point0 = ray.GetOrigin() + findShared.parameter1 * ray.GetDirection();
        }
        else
        {
            point1 = ray.GetOrigin() + findShared.parameter1 * ray.GetDirection();
        }

        ++quantity;
    }

    if (quantity == 2)
    {
        this->SetIntersectionType(IntersectionType::Segment);
    }
    else if (quantity == 1)
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

    return quantity;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::StaticFindIntersectorRay3Cylinder3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < quantity)
    {
        if (index == 0)
            return point0;
        else
            return point1;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"s));
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_CYLINDER3_ACHIEVE_H