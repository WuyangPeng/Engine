///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 17:44)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_BOX2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_BOX2_DETAIL_H

#include "StaticFindIntersectorRay2Box2.h"
#include "Detail/Line2Box2Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorRay2Box2<Real>::StaticFindIntersectorRay2Box2(const Ray2& ray, const Box2& box, const Real dotThreshold)
    : ParentType{ dotThreshold }, ray{ ray }, box{ box }, quantity{}, point0{}, point1{}
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
Mathematics::Ray2<Real> Mathematics::StaticFindIntersectorRay2Box2<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ray;
}

template <typename Real>
Mathematics::Box2<Real> Mathematics::StaticFindIntersectorRay2Box2<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return box;
}

template <typename Real>
void Mathematics::StaticFindIntersectorRay2Box2<Real>::Find()
{
    constexpr auto t0 = MathType::GetValue(0);
    constexpr auto t1 = MathType::maxReal;

    const Line2Box2<Real> line2Box2{ t0, t1, ray.GetOrigin(), ray.GetDirection(), box, true };
    quantity = line2Box2.GetRootCount();
    if (0 < quantity)
    {
        point0 = line2Box2.GetParameter(0);
    }

    if (1 < quantity)
    {
        point1 = line2Box2.GetParameter(1);
    }

    this->SetIntersectionType(line2Box2.GetIntersects());
}

template <typename Real>
int Mathematics::StaticFindIntersectorRay2Box2<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::StaticFindIntersectorRay2Box2<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index == 0)
    {
        return point0;
    }
    else if (index == 1)
    {
        return point1;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("索引越界"s));
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_BOX2_DETAIL_H