///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 17:47)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_SEGMENT2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_SEGMENT2_ACHIEVE_H

#include "StaticFindIntersectorRay2Segment2.h"
#include "StaticTestIntersectorLine2ClassifyDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Intersection/StaticFindIntersector1Detail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"

template <typename Real>
Mathematics::StaticFindIntersectorRay2Segment2<Real>::StaticFindIntersectorRay2Segment2(const Ray2& ray, const Segment2& segment, const Real dotThreshold, const Real intervalThreshold)
    : ParentType{ dotThreshold }, ray{ ray }, segment{ segment }, quantity{ 0 }, intervalThreshold{ intervalThreshold }, point0{}, point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::StaticFindIntersectorRay2Segment2<Real>::Find()
{
    auto dotThreshold = this->GetEpsilon();
    StaticTestIntersectorLine2Classify<Real> classify{ ray.GetOrigin(), ray.GetDirection(), segment.GetCenterPoint(), segment.GetDirection(), true, dotThreshold };

    auto intersectionType = classify.GetIntersectionType();

    if (intersectionType == IntersectionType::Point)
    {
        // 测试直线-直线的相交点是否在射线和线段上。
        if (0 <= classify.GetParameter0() && Math::FAbs(classify.GetParameter1()) <= segment.GetExtent() + intervalThreshold)
        {
            quantity = 1;
            point0 = ray.GetOrigin() + classify.GetParameter0() * ray.GetDirection();
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
        auto dotProduct = Vector2Tools::DotProduct(ray.GetDirection(), difference);

        // 计算线段相对于射线方向的终点的位置。
        auto tmin = dotProduct - segment.GetExtent();
        auto tmax = dotProduct + segment.GetExtent();

        // 计算区间 [0,+infinity) 和 [tmin,tmax]相交点。
        StaticFindIntersector1<Real> calc{ Math::GetValue(0), Math::maxReal, tmin, tmax, dotThreshold };

        quantity = calc.GetNumIntersections();

        if (quantity == 2)
        {
            intersectionType = IntersectionType::Segment;
            point0 = ray.GetOrigin() + calc.GetIntersection(0) * ray.GetDirection();
            point1 = ray.GetOrigin() + calc.GetIntersection(1) * ray.GetDirection();
        }
        else if (quantity == 1)
        {
            intersectionType = IntersectionType::Point;
            point0 = ray.GetOrigin();
        }
        else
        {
            quantity = 0;
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
bool Mathematics::StaticFindIntersectorRay2Segment2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && 0 <= quantity)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Ray2<Real> Mathematics::StaticFindIntersectorRay2Segment2<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ray;
}

template <typename Real>
Mathematics::Segment2<Real> Mathematics::StaticFindIntersectorRay2Segment2<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segment;
}

template <typename Real>
int Mathematics::StaticFindIntersectorRay2Segment2<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Real Mathematics::StaticFindIntersectorRay2Segment2<Real>::GetIntervalThreshold() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return intervalThreshold;
}

template <typename Real>
typename Mathematics::StaticFindIntersectorRay2Segment2<Real>::Vector2 Mathematics::StaticFindIntersectorRay2Segment2<Real>::GetPoint(int index) const
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

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_SEGMENT2_ACHIEVE_H
