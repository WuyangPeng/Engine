///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 17:29)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_LINE2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_LINE2_ACHIEVE_H

#include "StaticFindIntersectorLine2Line2.h"
#include "StaticTestIntersectorLine2ClassifyDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"

template <typename Real>
Mathematics::StaticFindIntersectorLine2Line2<Real>::StaticFindIntersectorLine2Line2(const Line2Type& lhsLine, const Line2Type& rhsLine, const Real dotThreshold)
    : ParentType{ dotThreshold }, lhsLine{ lhsLine }, rhsLine{ rhsLine }, quantity{ 0 }, point{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::StaticFindIntersectorLine2Line2<Real>::Find()
{
    StaticTestIntersectorLine2Classify<Real> classify{ lhsLine.GetOrigin(), lhsLine.GetDirection(), rhsLine.GetOrigin(), rhsLine.GetDirection(), true, this->GetEpsilon() };

    const auto intersectionType = classify.GetIntersectionType();
    this->SetIntersectionType(intersectionType);

    switch (intersectionType)
    {
        case IntersectionType::Empty:
        {
            quantity = 0;
            break;
        }
        case IntersectionType::Point:
        {
            quantity = 1;
            point = lhsLine.GetOrigin() + classify.GetParameter0() * lhsLine.GetDirection();
            break;
        }
        case IntersectionType::Line:
        {
            quantity = std::numeric_limits<int>::max();
            break;
        }
        default:
        {
            MATHEMATICS_ASSERTION_3(false, "相交类型计算错误！\n");
            break;
        }
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorLine2Line2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && 0 <= quantity)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Line2<Real> Mathematics::StaticFindIntersectorLine2Line2<Real>::GetLhsLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return lhsLine;
}

template <typename Real>
Mathematics::Line2<Real> Mathematics::StaticFindIntersectorLine2Line2<Real>::GetRhsLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rhsLine;
}

template <typename Real>
int Mathematics::StaticFindIntersectorLine2Line2<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::StaticFindIntersectorLine2Line2<Real>::GetPoint() const
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

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_LINE2_ACHIEVE_H
