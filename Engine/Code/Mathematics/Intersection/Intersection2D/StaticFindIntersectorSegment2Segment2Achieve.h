///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 17:51)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_SEGMENT2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_SEGMENT2_ACHIEVE_H

#include "StaticFindIntersectorSegment2Segment2.h"
#include "StaticTestIntersectorLine2ClassifyDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Intersection/StaticFindIntersector1.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"

template <typename Real>
Mathematics::StaticFindIntersectorSegment2Segment2<Real>::StaticFindIntersectorSegment2Segment2(const Segment2& lhsSegment, const Segment2& rhsSegment, const Real dotThreshold, const Real intervalThreshold)
    : ParentType{ dotThreshold }, lhsSegment{ lhsSegment }, rhsSegment{ rhsSegment }, quantity{ 0 }, intervalThreshold{ intervalThreshold }, point0{}, point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::StaticFindIntersectorSegment2Segment2<Real>::Find()
{
    auto dotThreshold = this->GetEpsilon();
    StaticTestIntersectorLine2Classify<Real> classify{ lhsSegment.GetCenterPoint(), lhsSegment.GetDirection(), rhsSegment.GetCenterPoint(), rhsSegment.GetDirection(), true, dotThreshold };

    auto intersectionType = classify.GetIntersectionType();

    if (intersectionType == IntersectionType::Point)
    {
        // 测试直线-直线的相交点是否在线段上。
        if (Math::FAbs(classify.GetParameter0()) <= lhsSegment.GetExtent() + intervalThreshold &&
            Math::FAbs(classify.GetParameter1()) <= rhsSegment.GetExtent() + intervalThreshold)
        {
            quantity = 1;
            point0 = lhsSegment.GetCenterPoint() + classify.GetParameter0() * lhsSegment.GetDirection();
        }
        else
        {
            quantity = 0;
            intersectionType = IntersectionType::Empty;
        }
    }
    else if (intersectionType == IntersectionType::Line)
    {
        // 计算线段m_RhsSegment终点相对于线段m_LhsSegment的位置。
        auto difference = rhsSegment.GetCenterPoint() - lhsSegment.GetCenterPoint();
        auto dotProduct = Vector2Tools::DotProduct(lhsSegment.GetDirection(), difference);
        auto tmin = dotProduct - rhsSegment.GetExtent();
        auto tmax = dotProduct + rhsSegment.GetExtent();

        StaticFindIntersector1<Real> calc{ -lhsSegment.GetExtent(), lhsSegment.GetExtent(), tmin, tmax, dotThreshold };

        quantity = calc.GetNumIntersections();
        if (quantity == 2)
        {
            intersectionType = IntersectionType::Segment;
            point0 = lhsSegment.GetCenterPoint() + calc.GetIntersection(0) * lhsSegment.GetDirection();
            point1 = lhsSegment.GetCenterPoint() + calc.GetIntersection(1) * lhsSegment.GetDirection();
        }
        else if (quantity == 1)
        {
            intersectionType = IntersectionType::Point;
            point0 = lhsSegment.GetCenterPoint() + calc.GetIntersection(0) * lhsSegment.GetDirection();
        }
        else
        {
            intersectionType = IntersectionType::Empty;
        }
    }
    else
    {
        quantity = 0;
        intersectionType = IntersectionType::Empty;
    }

    this->SetIntersectionType(intersectionType);
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorSegment2Segment2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && 0 <= quantity)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename Mathematics::StaticFindIntersectorSegment2Segment2<Real>::Segment2 Mathematics::StaticFindIntersectorSegment2Segment2<Real>::GetLhsSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return lhsSegment;
}

template <typename Real>
typename Mathematics::StaticFindIntersectorSegment2Segment2<Real>::Segment2 Mathematics::StaticFindIntersectorSegment2Segment2<Real>::GetRhsSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rhsSegment;
}

template <typename Real>
int Mathematics::StaticFindIntersectorSegment2Segment2<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Real Mathematics::StaticFindIntersectorSegment2Segment2<Real>::GetIntervalThreshold() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return intervalThreshold;
}

template <typename Real>
typename Mathematics::StaticFindIntersectorSegment2Segment2<Real>::Vector2 Mathematics::StaticFindIntersectorSegment2Segment2<Real>::GetPoint(int index) const
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

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_SEGMENT2_ACHIEVE_H
