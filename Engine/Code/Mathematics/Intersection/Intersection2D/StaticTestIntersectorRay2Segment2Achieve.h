///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 17:57)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_SEGMENT2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_SEGMENT2_ACHIEVE_H

#include "StaticTestIntersectorLine2ClassifyDetail.h"
#include "StaticTestIntersectorRay2Segment2.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"

template <typename Real>
Mathematics::StaticTestIntersectorRay2Segment2<Real>::StaticTestIntersectorRay2Segment2(const Ray2Type& ray, const Segment2Type& segment, const Real dotThreshold, const Real intervalThreshold)
    : ParentType{ dotThreshold }, ray{ ray }, segment{ segment }, quantity{ 0 }, intervalThreshold{ intervalThreshold }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::StaticTestIntersectorRay2Segment2<Real>::Test()
{
    auto dotThreshold = this->GetEpsilon();
    StaticTestIntersectorLine2Classify<Real> classify{ ray.GetOrigin(), ray.GetDirection(), segment.GetCenterPoint(), segment.GetDirection(), true, dotThreshold };

    auto intersectionType = classify.GetIntersectionType();

    if (intersectionType == IntersectionType::Point)
    {
        // 测试直线-直线的相交点是否在射线和线段上。
        if (0 <= classify.GetParameter0() && MathType::FAbs(classify.GetParameter1()) <= segment.GetExtent() + intervalThreshold)
        {
            quantity = 1;
        }
        else
        {
            quantity = 0;
            intersectionType = IntersectionType::Empty;
        }
    }
    else if (intersectionType == IntersectionType::Line)
    {
        // 计算线段segment中心相对于射线ray的位置。
        auto difference = segment.GetCenterPoint() - ray.GetOrigin();
        auto dotProduct = Vector2ToolsType::DotProduct(ray.GetDirection(), difference);

        // 计算线段相对于射线方向的最右点的位置。
        auto tmax = dotProduct + segment.GetExtent();

        if (dotThreshold < tmax)
        {
            quantity = 2;
            intersectionType = IntersectionType::Segment;
        }
        else if (tmax < -dotThreshold)
        {
            quantity = 0;
            intersectionType = IntersectionType::Empty;
        }
        else  // tmax == 0
        {
            quantity = 1;
            intersectionType = IntersectionType::Point;
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
bool Mathematics::StaticTestIntersectorRay2Segment2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && 0 <= quantity)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Ray2<Real> Mathematics::StaticTestIntersectorRay2Segment2<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ray;
}

template <typename Real>
Mathematics::Segment2<Real> Mathematics::StaticTestIntersectorRay2Segment2<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segment;
}

template <typename Real>
int Mathematics::StaticTestIntersectorRay2Segment2<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Real Mathematics::StaticTestIntersectorRay2Segment2<Real>::GetIntervalThreshold() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return intervalThreshold;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_SEGMENT2_ACHIEVE_H
