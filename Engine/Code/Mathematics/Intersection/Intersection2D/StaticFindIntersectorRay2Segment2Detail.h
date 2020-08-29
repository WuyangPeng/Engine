// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/24 15:53)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_SEGMENT2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_SEGMENT2_DETAIL_H 

#include "StaticFindIntersectorRay2Segment2.h"
#include "StaticTestIntersectorLine2ClassifyDetail.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h" 
#include "Mathematics/Intersection/StaticIntersectorDetail.h"
#include "Mathematics/Intersection/StaticFindIntersector1Detail.h"

template <typename Real>
Mathematics::StaticFindIntersectorRay2Segment2<Real>
	::StaticFindIntersectorRay2Segment2(const Ray2& ray, const Segment2& segment, const Real dotThreshold, const Real intervalThreshold)
	:ParentType{ dotThreshold }, m_Ray{ ray }, m_Segment{ segment }, m_Quantity{ 0 }, m_IntervalThreshold{ intervalThreshold }, m_Point{}
{
	Find();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::StaticFindIntersectorRay2Segment2<Real>
	::Find()
{
	auto dotThreshold = this->GetEpsilon();
	StaticTestIntersectorLine2Classify<Real> classify{ m_Ray.GetOrigin(), m_Ray.GetDirection(),m_Segment.GetCenterPoint(), m_Segment.GetDirection(),true, dotThreshold };

	auto intersectionType = classify.GetIntersectionType();

	if (intersectionType == IntersectionType::Point)
	{
		// 测试直线-直线的相交点是否在射线和线段上。
		if (0 <= classify.GetFirstParameter() && Math::FAbs(classify.GetSecondParameter()) <= m_Segment.GetExtent() + m_IntervalThreshold)
		{
			m_Quantity = 1;
			m_Point[0] = m_Ray.GetOrigin() + classify.GetFirstParameter() * m_Ray.GetDirection();
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
		StaticFindIntersector1<Real> calc{ Math::GetValue(0), Math::sm_MaxReal, tmin, tmax,dotThreshold };

		m_Quantity = calc.GetNumIntersections();

		if (m_Quantity == 2)
		{
			intersectionType = IntersectionType::Segment;
			m_Point[0] = m_Ray.GetOrigin() + calc.GetIntersection(0) * m_Ray.GetDirection();
			m_Point[1] = m_Ray.GetOrigin() + calc.GetIntersection(1) * m_Ray.GetDirection();
		}
		else if (m_Quantity == 1)
		{
			intersectionType = IntersectionType::Point;
			m_Point[0] = m_Ray.GetOrigin();
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

template <typename Real>
Mathematics::StaticFindIntersectorRay2Segment2<Real>
	::~StaticFindIntersectorRay2Segment2()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorRay2Segment2<Real>
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && 0 <= m_Quantity)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::StaticFindIntersectorRay2Segment2<Real>::Ray2 Mathematics::StaticFindIntersectorRay2Segment2<Real>
	::GetRay() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Ray;
}

template <typename Real>
typename const Mathematics::StaticFindIntersectorRay2Segment2<Real>::Segment2 Mathematics::StaticFindIntersectorRay2Segment2<Real>
	::GetSegment() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Segment;
}

template <typename Real>
int Mathematics::StaticFindIntersectorRay2Segment2<Real>
	::GetQuantity() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Quantity;
}

template <typename Real>
Real Mathematics::StaticFindIntersectorRay2Segment2<Real>
	::GetIntervalThreshold() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_IntervalThreshold;
}

template <typename Real>
const typename Mathematics::StaticFindIntersectorRay2Segment2<Real>::Vector2D Mathematics::StaticFindIntersectorRay2Segment2<Real>
	::GetPoint(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < static_cast<int>(m_Point.size()), "索引错误\n");

	return m_Point[index];
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_SEGMENT2_DETAIL_H
