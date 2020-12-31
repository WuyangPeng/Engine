///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/22 16:05)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_SEGMENT2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_SEGMENT2_ACHIEVE_H

#include "StaticFindIntersectorRay2Segment2.h"
#include "StaticTestIntersectorLine2ClassifyDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Intersection/StaticFindIntersector1Detail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"

template <typename Real>
Mathematics::StaticFindIntersectorRay2Segment2<Real>::StaticFindIntersectorRay2Segment2(const Ray2& ray, const Segment2& segment, const Real dotThreshold, const Real intervalThreshold)
    : ParentType{ dotThreshold }, m_Ray{ ray }, m_Segment{ segment }, m_Quantity{ 0 }, m_IntervalThreshold{ intervalThreshold }, m_Point0{}, m_Point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::StaticFindIntersectorRay2Segment2<Real>::Find()
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
            m_Point0 = m_Ray.GetOrigin() + classify.GetParameter0() * m_Ray.GetDirection();
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

        // 计算线段相对于射线方向的终点的位置。
        auto tmin = dotProduct - m_Segment.GetExtent();
        auto tmax = dotProduct + m_Segment.GetExtent();

        // 计算区间 [0,+infinity) 和 [tmin,tmax]相交点。
        StaticFindIntersector1<Real> calc{ Math::GetValue(0), Math::sm_MaxReal, tmin, tmax, dotThreshold };

        m_Quantity = calc.GetNumIntersections();

        if (m_Quantity == 2)
        {
            intersectionType = IntersectionType::Segment;
            m_Point0 = m_Ray.GetOrigin() + calc.GetIntersection(0) * m_Ray.GetDirection();
            m_Point1 = m_Ray.GetOrigin() + calc.GetIntersection(1) * m_Ray.GetDirection();
        }
        else if (m_Quantity == 1)
        {
            intersectionType = IntersectionType::Point;
            m_Point0 = m_Ray.GetOrigin();
        }
        else
        {
            m_Quantity = 0;
            intersectionType = IntersectionType::Empty;
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
bool Mathematics::StaticFindIntersectorRay2Segment2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && 0 <= m_Quantity)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Ray2<Real> Mathematics::StaticFindIntersectorRay2Segment2<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Ray;
}

template <typename Real>
const Mathematics::Segment2<Real> Mathematics::StaticFindIntersectorRay2Segment2<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Segment;
}

template <typename Real>
int Mathematics::StaticFindIntersectorRay2Segment2<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Quantity;
}

template <typename Real>
Real Mathematics::StaticFindIntersectorRay2Segment2<Real>::GetIntervalThreshold() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_IntervalThreshold;
}

template <typename Real>
const typename Mathematics::StaticFindIntersectorRay2Segment2<Real>::Vector2D Mathematics::StaticFindIntersectorRay2Segment2<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index == 0)
    {
        return m_Point0;
    }
    else if (index == 1)
    {
        return m_Point1;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("索引越界"s));
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_SEGMENT2_ACHIEVE_H
