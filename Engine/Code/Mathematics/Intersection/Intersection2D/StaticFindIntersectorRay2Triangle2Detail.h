///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/02/24 17:11)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_TRIANGLE2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_TRIANGLE2_DETAIL_H

#include "StaticFindIntersectorLine2Triangle2.h"
#include "StaticFindIntersectorRay2Triangle2.h"
#include "Detail/Line2Triangle2Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Intersection/StaticFindIntersector1.h"

template <typename Real>
Mathematics::StaticFindIntersectorRay2Triangle2<Real>::StaticFindIntersectorRay2Triangle2(const Ray2& ray, const Triangle2& triangle, const Real dotThreshold)
    : ParentType{ dotThreshold }, ray{ ray }, triangle{ triangle }, quantity{}, point0{}, point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorRay2Triangle2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && 0 <= quantity)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Ray2<Real> Mathematics::StaticFindIntersectorRay2Triangle2<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ray;
}

template <typename Real>
Mathematics::Triangle2<Real> Mathematics::StaticFindIntersectorRay2Triangle2<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle;
}

template <typename Real>
void Mathematics::StaticFindIntersectorRay2Triangle2<Real>::Find()
{
    const Line2Triangle2<Real> line2Triangle2{ ray.GetOrigin(), ray.GetDirection(), triangle };

    if (line2Triangle2.GetPositive() == 3 || line2Triangle2.GetNegative() == 3)
    {
        // 不相交。
        quantity = 0;
        this->SetIntersectionType(IntersectionType::Empty);
    }
    else
    {
        auto param = line2Triangle2.GetInterval();

        StaticFindIntersector1<Real> intr{ param[0], param[1], Math::GetValue(0), Math::maxReal };

        quantity = intr.GetNumIntersections();
        if (quantity == 2)
        {
            // 线段相交

            this->SetIntersectionType(IntersectionType::Segment);
            point0 = ray.GetOrigin() + intr.GetIntersection(0) * ray.GetDirection();
            point1 = ray.GetOrigin() + intr.GetIntersection(1) * ray.GetDirection();
        }
        else if (quantity == 1)
        {
            // 点相交

            this->SetIntersectionType(IntersectionType::Point);
            point0 = ray.GetOrigin() + intr.GetIntersection(0) * ray.GetDirection();
        }
        else
        {
            // 不相交
            this->SetIntersectionType(IntersectionType::Empty);
        }
    }
}

template <typename Real>
int Mathematics::StaticFindIntersectorRay2Triangle2<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::StaticFindIntersectorRay2Triangle2<Real>::GetPoint(int index) const
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

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_TRIANGLE2_DETAIL_H