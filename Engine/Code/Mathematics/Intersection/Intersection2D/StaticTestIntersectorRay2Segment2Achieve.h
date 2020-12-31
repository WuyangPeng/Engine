///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/23 16:58)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_SEGMENT2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_SEGMENT2_ACHIEVE_H

#include "StaticTestIntersectorLine2ClassifyDetail.h"
#include "StaticTestIntersectorRay2Segment2.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"

template <typename Real>
Mathematics::StaticTestIntersectorRay2Segment2<Real>::StaticTestIntersectorRay2Segment2(const Ray2& ray, const Segment2& segment, const Real dotThreshold, const Real intervalThreshold)
    : ParentType{ dotThreshold }, m_Ray{ ray }, m_Segment{ segment }, m_Quantity{ 0 }, m_IntervalThreshold{ intervalThreshold }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::StaticTestIntersectorRay2Segment2<Real>::Test()
{
    auto dotThreshold = this->GetEpsilon();
    StaticTestIntersectorLine2Classify<Real> classify{ m_Ray.GetOrigin(), m_Ray.GetDirection(), m_Segment.GetCenterPoint(), m_Segment.GetDirection(), true, dotThreshold };

    auto intersectionType = classify.GetIntersectionType();

    if (intersectionType == IntersectionType::Point)
    {
        // 测试直线-直线的相交点是否在射线和线段上。
        if (0 <= classify.GetParameter0() && Math::FAbs(classify.GetParameter1()) <= m_Segment.GetExtent() + m_IntervalThreshold)
        {
            m_Quantity = 1;
        }
        else
        {
            m_Quantity = 0;
            intersectionType = IntersectionType::Empty;
        }
    }
    else if (intersectionType == IntersectionType::Line)
    {
        // 计算线段segment中心相对于射线ray的位置。
        auto difference = m_Segment.GetCenterPoint() - m_Ray.GetOrigin();
        auto dotProduct = Vector2DTools::DotProduct(m_Ray.GetDirection(), difference);

        // 计算线段相对于射线方向的最右点的位置。
        auto tmax = dotProduct + m_Segment.GetExtent();

        if (dotThreshold < tmax)
        {
            m_Quantity = 2;
            intersectionType = IntersectionType::Segment;
        }
        else if (tmax < -dotThreshold)
        {
            m_Quantity = 0;
            intersectionType = IntersectionType::Empty;
        }
        else  // tmax == 0
        {
            m_Quantity = 1;
            intersectionType = IntersectionType::Point;
        }
    }
    else
    {
        m_Quantity = 0;
        intersectionType = IntersectionType::Empty;
    }

    this->SetIntersectionType(intersectionType);
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticTestIntersectorRay2Segment2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && 0 <= m_Quantity)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Ray2<Real> Mathematics::StaticTestIntersectorRay2Segment2<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Ray;
}

template <typename Real>
const Mathematics::Segment2<Real> Mathematics::StaticTestIntersectorRay2Segment2<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Segment;
}

template <typename Real>
int Mathematics::StaticTestIntersectorRay2Segment2<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Quantity;
}

template <typename Real>
Real Mathematics::StaticTestIntersectorRay2Segment2<Real>::GetIntervalThreshold() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_IntervalThreshold;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_SEGMENT2_ACHIEVE_H
