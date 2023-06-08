///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 19:26)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_CIRCLE2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_CIRCLE2_ACHIEVE_H

#include "StaticFindIntersectorRay2Circle2.h"
#include "Detail/Line2Circle2Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorRay2Circle2<Real>::StaticFindIntersectorRay2Circle2(const Ray2& ray, const Circle2& circle, const Real dotThreshold)
    : ParentType{ dotThreshold }, ray{ ray }, circle{ circle }, quantity{}, point0{}, point1{}
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
Mathematics::Ray2<Real> Mathematics::StaticFindIntersectorRay2Circle2<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ray;
}

template <typename Real>
Mathematics::Circle2<Real> Mathematics::StaticFindIntersectorRay2Circle2<Real>::GetCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return circle;
}

template <typename Real>
void Mathematics::StaticFindIntersectorRay2Circle2<Real>::Find()
{
    Line2Circle2<Real> line2Circle2{ ray.GetOrigin(), ray.GetDirection(), circle.GetCenter(), circle.GetRadius() };

    if (line2Circle2.IsIntersects())
    {
        // 如果线与圆的交点不在射光线中，则减少根数。
        auto rootCount = line2Circle2.GetRootCount();
        if (rootCount == 1)
        {
            if (line2Circle2.GetParameter(0) < Math::GetValue(0))
            {
                rootCount = 0;
            }
        }
        else
        {
            if (line2Circle2.GetParameter(1) < Math::GetValue(0))
            {
                rootCount = 0;
            }
            else if (line2Circle2.GetParameter(0) < Math::GetValue(0))
            {
                rootCount = 1;
                line2Circle2.ClearParameter0();
            }
        }

        quantity = 0;
        for (auto i = 0; i < line2Circle2.GetRootCount(); ++i)
        {
            auto point = ray.GetOrigin() + line2Circle2.GetParameter(i) * ray.GetDirection();

            if (rootCount == 0)
            {
                point0 = point;
            }
            else if (rootCount == 1)
            {
                point1 = point;
            }

            ++quantity;
        }
    }

    this->SetIntersectionType(0 < quantity ? IntersectionType::Point : IntersectionType::Empty);
}

template <typename Real>
int Mathematics::StaticFindIntersectorRay2Circle2<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::StaticFindIntersectorRay2Circle2<Real>::GetPoint(int index) const
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

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_CIRCLE2_ACHIEVE_H