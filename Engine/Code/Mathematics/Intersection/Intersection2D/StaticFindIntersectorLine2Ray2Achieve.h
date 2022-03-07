///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/02/24 15:47)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_RAY2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_RAY2_ACHIEVE_H

#include "StaticFindIntersectorLine2Ray2.h"
#include "StaticTestIntersectorLine2ClassifyDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"

template <typename Real>
Mathematics::StaticFindIntersectorLine2Ray2<Real>::StaticFindIntersectorLine2Ray2(const Line2& line, const Ray2& ray, const Real dotThreshold)
    : ParentType{ dotThreshold }, line{ line }, ray{ ray }, quantity{ 0 }, point{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::StaticFindIntersectorLine2Ray2<Real>::Find()
{
    StaticTestIntersectorLine2Classify<Real> classify{ line.GetOrigin(), line.GetDirection(), ray.GetOrigin(), ray.GetDirection(), true, this->GetEpsilon() };

    auto intersectionType = classify.GetIntersectionType();

    if (intersectionType == IntersectionType::Point)
    {
        // 测试线-线相交的点是否在射线上。
        if (Math::GetValue(0) <= classify.GetParameter1())
        {
            quantity = 1;
            point = line.GetOrigin() + classify.GetParameter0() * line.GetDirection();
        }
        else
        {
            quantity = 0;
            intersectionType = IntersectionType::Empty;
        }
    }
    else if (intersectionType == IntersectionType::Line)
    {
        intersectionType = IntersectionType::Ray;
        quantity = std::numeric_limits<int>::max();
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
bool Mathematics::StaticFindIntersectorLine2Ray2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && 0 <= quantity)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Line2<Real> Mathematics::StaticFindIntersectorLine2Ray2<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return line;
}

template <typename Real>
Mathematics::Ray2<Real> Mathematics::StaticFindIntersectorLine2Ray2<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ray;
}

template <typename Real>
int Mathematics::StaticFindIntersectorLine2Ray2<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::StaticFindIntersectorLine2Ray2<Real>::GetPoint() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (quantity == 1)
    {
        return point;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("不存在唯一的交点。\n"s));
    }
}
#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_RAY2_ACHIEVE_H
