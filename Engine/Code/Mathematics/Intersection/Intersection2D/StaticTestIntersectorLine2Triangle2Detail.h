///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 17:57)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_TRIANGLE2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_TRIANGLE2_DETAIL_H

#include "StaticTestIntersectorLine2Triangle2.h"
#include "Detail/Line2Triangle2Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Intersection/StaticFindIntersector1.h"

template <typename Real>
Mathematics::StaticTestIntersectorLine2Triangle2<Real>::StaticTestIntersectorLine2Triangle2(const Line2& line, const Triangle2& triangle, const Real dotThreshold)
    : ParentType{ dotThreshold }, line{ line }, triangle{ triangle }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorLine2Triangle2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Line2<Real> Mathematics::StaticTestIntersectorLine2Triangle2<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return line;
}

template <typename Real>
Mathematics::Triangle2<Real> Mathematics::StaticTestIntersectorLine2Triangle2<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle;
}

template <typename Real>
void Mathematics::StaticTestIntersectorLine2Triangle2<Real>::Test()
{
    const Line2Triangle2<Real> line2Triangle2{ line.GetOrigin(), line.GetDirection(), triangle };

    if (line2Triangle2.GetPositive() == 3 || line2Triangle2.GetNegative() == 3)
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
    else
    {
        const auto param = line2Triangle2.GetInterval();

        StaticFindIntersector1<Real> intr{ param[0], param[1], -MathType::maxReal, +MathType::maxReal };

        const auto quantity = intr.GetNumIntersections();
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
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_TRIANGLE2_DETAIL_H