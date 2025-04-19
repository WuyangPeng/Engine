///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 17:57)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_RAY2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_RAY2_ACHIEVE_H

#include "StaticTestIntersectorLine2ClassifyDetail.h"
#include "StaticTestIntersectorRay2Ray2.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"

template <typename Real>
Mathematics::StaticTestIntersectorRay2Ray2<Real>::StaticTestIntersectorRay2Ray2(const Ray2Type& lhsRay, const Ray2Type& rhsRay, const Real dotThreshold)
    : ParentType{ dotThreshold }, lhsRay{ lhsRay }, rhsRay{ rhsRay }, quantity{ 0 }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::StaticTestIntersectorRay2Ray2<Real>::Test()
{
    auto dotThreshold = this->GetEpsilon();
    StaticTestIntersectorLine2Classify<Real> classify{ lhsRay.GetOrigin(), lhsRay.GetDirection(), rhsRay.GetOrigin(), rhsRay.GetDirection(), true, dotThreshold };

    auto intersectionType = classify.GetIntersectionType();

    if (intersectionType == IntersectionType::Point)
    {
        // 测试直线交点是否在射线上。
        if (MathType::GetValue(0) <= classify.GetParameter0() && MathType::GetValue(0) <= classify.GetParameter1())
        {
            quantity = 1;
            intersectionType = IntersectionType::Point;
        }
        else
        {
            quantity = 0;
            intersectionType = IntersectionType::Empty;
        }
    }
    else if (intersectionType == IntersectionType::Line)
    {
        if (MathType::GetValue(0) < Vector2ToolsType::DotProduct(lhsRay.GetDirection(), rhsRay.GetDirection()))
        {
            // 射线是共线的并且在相同的方向，所以它们必须是重叠的。
            quantity = std::numeric_limits<int>::max();
            intersectionType = IntersectionType::Ray;
        }
        else
        {
            // 射线是共线的，且方向相反。 测试它们是否重叠。
            // lhsRay具有间隔[0，+无穷大），
            // rhsRay具有相对于ray0方向的间隔（-infinity，dotProduct] 。
            auto dotProduct = Vector2ToolsType::DotProduct(lhsRay.GetDirection(), rhsRay.GetOrigin() - lhsRay.GetOrigin());
            if (dotThreshold < dotProduct)
            {
                quantity = 2;
                intersectionType = IntersectionType::Segment;
            }
            else if (dotProduct < -dotThreshold)
            {
                quantity = 0;
                intersectionType = IntersectionType::Empty;
            }
            else  // dotProduct == 0
            {
                quantity = 1;
                intersectionType = IntersectionType::Point;
            }
        }
    }
    else
    {
        quantity = 0;
        intersectionType = IntersectionType::Empty;
    }

    ParentType::SetIntersectionType(intersectionType);
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorRay2Ray2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && 0 <= quantity)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Ray2<Real> Mathematics::StaticTestIntersectorRay2Ray2<Real>::GetLhsRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return lhsRay;
}

template <typename Real>
Mathematics::Ray2<Real> Mathematics::StaticTestIntersectorRay2Ray2<Real>::GetRhsRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rhsRay;
}

template <typename Real>
int Mathematics::StaticTestIntersectorRay2Ray2<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_RAY2_ACHIEVE_H
