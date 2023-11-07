///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 17:28)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_CIRCLE2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_CIRCLE2_ACHIEVE_H

#include "StaticFindIntersectorLine2Circle2.h"
#include "Detail/Line2Circle2Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorLine2Circle2<Real>::StaticFindIntersectorLine2Circle2(const Line2& line, const Circle2& circle, const Real epsilon)
    : ParentType{ epsilon }, line{ line }, circle{ circle }, quantity{}, point0{}, point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorLine2Circle2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Line2<Real> Mathematics::StaticFindIntersectorLine2Circle2<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return line;
}

template <typename Real>
Mathematics::Circle2<Real> Mathematics::StaticFindIntersectorLine2Circle2<Real>::GetCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return circle;
}

template <typename Real>
int Mathematics::StaticFindIntersectorLine2Circle2<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::StaticFindIntersectorLine2Circle2<Real>::GetPoint(int index) const
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

template <typename Real>
void Mathematics::StaticFindIntersectorLine2Circle2<Real>::Find()
{
    const Line2Circle2<Real> line2Circle2{ line.GetOrigin(), line.GetDirection(), circle.GetCenter(), circle.GetRadius() };

    quantity = 0;
    if (line2Circle2.IsIntersects())
    {
        for (auto i = 0; i < line2Circle2.GetRootCount(); ++i)
        {
            auto point = line.GetOrigin() + line2Circle2.GetParameter(i) * line.GetDirection();

            if (quantity == 0)
            {
                point0 = point;
            }
            else if (quantity == 1)
            {
                point1 = point;
            }

            ++quantity;
        }
    }

    this->SetIntersectionType(0 < quantity ? IntersectionType::Point : IntersectionType::Empty);
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_CIRCLE2_ACHIEVE_H