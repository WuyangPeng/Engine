///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 13:52)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_BOX3_DETAIL_H

#include "StaticFindIntersectorLine3Box3Detail.h"
#include "StaticFindIntersectorRay3Box3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorRay3Box3<Real>::StaticFindIntersectorRay3Box3(const Ray3Type& ray, const Box3Type& box, const Real epsilon)
    : ParentType{ epsilon }, ray{ ray }, box{ box }, quantity{}, point0{}, point1{}
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
Mathematics::Ray3<Real> Mathematics::StaticFindIntersectorRay3Box3<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ray;
}

template <typename Real>
Mathematics::Box3<Real> Mathematics::StaticFindIntersectorRay3Box3<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return box;
}

template <typename Real>
void Mathematics::StaticFindIntersectorRay3Box3<Real>::Find()
{
    constexpr auto t0 = MathType::GetValue(0);
    constexpr auto t1 = MathType::maxReal;

    const auto findShared = StaticFindIntersectorLine3Box3<Real>::DoClipping(t0, t1, ray.GetOrigin(), ray.GetDirection(), box, true);
    quantity = findShared.quantity;
    if (findShared.quantity == 1)
    {
        point0 = findShared.point0;
    }
    else if (findShared.quantity == 2)
    {
        point0 = findShared.point0;
        point1 = findShared.point1;
    }

    this->SetIntersectionType(findShared.intersectionType);
}

template <typename Real>
int Mathematics::StaticFindIntersectorRay3Box3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::StaticFindIntersectorRay3Box3<Real>::GetPoint(int index) const
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

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_BOX3_DETAIL_H