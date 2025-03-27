///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 17:29)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_TRIANGLE2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_TRIANGLE2_DETAIL_H

#include "StaticFindIntersectorLine2Triangle2.h"
#include "Detail/Line2Triangle2Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Intersection/Intersector1.h"
#include "Mathematics/Intersection/StaticFindIntersector1Detail.h"

template <typename Real>
Mathematics::StaticFindIntersectorLine2Triangle2<Real>::StaticFindIntersectorLine2Triangle2(const Line2& line, const Triangle2& triangle, const Real dotThreshold)
    : ParentType{ dotThreshold }, line{ line }, triangle{ triangle }, quantity{}, point0{}, point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorLine2Triangle2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Line2<Real> Mathematics::StaticFindIntersectorLine2Triangle2<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return line;
}

template <typename Real>
Mathematics::Triangle2<Real> Mathematics::StaticFindIntersectorLine2Triangle2<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle;
}

template <typename Real>
void Mathematics::StaticFindIntersectorLine2Triangle2<Real>::Find()
{
    const Line2Triangle2<Real> line2Triangle2{ line.GetOrigin(), line.GetDirection(), triangle };

    if (line2Triangle2.GetPositive() == 3 || line2Triangle2.GetNegative() == 3)
    {
        // 不相交。
        quantity = 0;
        this->SetIntersectionType(IntersectionType::Empty);
    }
    else
    {
        auto param = line2Triangle2.GetInterval();

        StaticFindIntersector1<Real> intr{ param[0], param[1], -MathType::maxReal, +MathType::maxReal };

        quantity = intr.GetNumIntersections();
        if (quantity == 2)
        {
            // 线段相交

            this->SetIntersectionType(IntersectionType::Segment);
            point0 = line.GetOrigin() + intr.GetIntersection(0) * line.GetDirection();
            point1 = line.GetOrigin() + intr.GetIntersection(1) * line.GetDirection();
        }
        else if (quantity == 1)
        {
            // 点相交

            this->SetIntersectionType(IntersectionType::Point);
            point0 = line.GetOrigin() + intr.GetIntersection(0) * line.GetDirection();
        }
        else
        {
            // 不相交
            this->SetIntersectionType(IntersectionType::Empty);
        }
    }
}

template <typename Real>
int Mathematics::StaticFindIntersectorLine2Triangle2<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::StaticFindIntersectorLine2Triangle2<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < quantity)
    {
        if (index == 0)
        {
            return point0;
        }
        else if (index == 1)
        {
            return point1;
        }
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界"s));
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_TRIANGLE2_DETAIL_H