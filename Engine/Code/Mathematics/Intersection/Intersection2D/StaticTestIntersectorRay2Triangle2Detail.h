///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 17:57)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_TRIANGLE2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_TRIANGLE2_DETAIL_H

#include "StaticTestIntersectorLine2Triangle2.h"
#include "StaticTestIntersectorRay2Triangle2.h"
#include "Detail/Line2Triangle2Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Intersection/StaticFindIntersector1.h"

template <typename Real>
Mathematics::StaticTestIntersectorRay2Triangle2<Real>::StaticTestIntersectorRay2Triangle2(const Ray2& ray, const Triangle2& triangle, const Real dotThreshold)
    : ParentType{ dotThreshold }, ray{ ray }, triangle{ triangle }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorRay2Triangle2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Ray2<Real> Mathematics::StaticTestIntersectorRay2Triangle2<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ray;
}

template <typename Real>
Mathematics::Triangle2<Real> Mathematics::StaticTestIntersectorRay2Triangle2<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle;
}

template <typename Real>
void Mathematics::StaticTestIntersectorRay2Triangle2<Real>::Test()
{
    const Line2Triangle2<Real> line2Triangle2{ ray.GetOrigin(), ray.GetDirection(), triangle };

    if (line2Triangle2.GetPositive() == 3 || line2Triangle2.GetNegative() == 3)
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
    else
    {
        auto param = line2Triangle2.GetInterval();

        StaticFindIntersector1<Real> intr{ param[0], param[1], Math::GetValue(0), Math::maxReal };

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

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_TRIANGLE2_DETAIL_H