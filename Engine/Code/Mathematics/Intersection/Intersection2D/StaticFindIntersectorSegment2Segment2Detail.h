// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/24 15:55)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_SEGMENT2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_SEGMENT2_DETAIL_H 

#include "StaticFindIntersectorSegment2Segment2.h"

#include "StaticTestIntersectorLine2ClassifyDetail.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Intersection/StaticFindIntersector1.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"

template <typename Real>
Mathematics::StaticFindIntersectorSegment2Segment2<Real>
	::StaticFindIntersectorSegment2Segment2(const Segment2& lhsSegment, const Segment2& rhsSegment, const Real dotThreshold, const Real intervalThreshold)
	:ParentType{ dotThreshold }, m_LhsSegment{ lhsSegment }, m_RhsSegment{ rhsSegment }, m_Quantity{ 0 }, m_IntervalThreshold{ intervalThreshold }, m_Point{}
{
	Find();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::StaticFindIntersectorSegment2Segment2<Real>
	::Find()
{
	auto dotThreshold = this->GetEpsilon();
	StaticTestIntersectorLine2Classify<Real> classify{ m_LhsSegment.GetCenterPoint(), m_LhsSegment.GetDirection(), m_RhsSegment.GetCenterPoint(), m_RhsSegment.GetDirection(),  true, dotThreshold };

	auto intersectionType = classify.GetIntersectionType();

	if (intersectionType == IntersectionType::Point)
	{
		// 测试直线-直线的相交点是否在线段上。
		if (Math::FAbs(classify.GetFirstParameter()) <= m_LhsSegment.GetExtent() + m_IntervalThreshold &&
			Math::FAbs(classify.GetSecondParameter()) <= m_RhsSegment.GetExtent() + m_IntervalThreshold)
		{
			m_Quantity = 1;
			m_Point[0] = m_LhsSegment.GetCenterPoint() + classify.GetFirstParameter() * m_LhsSegment.GetDirection();
		}
		else
		{
			m_Quantity = 0;
			intersectionType = IntersectionType::Empty;
		}
	}
	else if (intersectionType == IntersectionType::Line)
	{
		// 计算线段m_RhsSegment终点相对于线段m_LhsSegment的位置。
		auto difference = m_RhsSegment.GetCenterPoint() - m_LhsSegment.GetCenterPoint();
		auto dotProduct = Vector2DTools::DotProduct(m_LhsSegment.GetDirection(), difference);
		auto tmin = dotProduct - m_RhsSegment.GetExtent();
		auto tmax = dotProduct + m_RhsSegment.GetExtent();

		StaticFindIntersector1<Real> calc{ -m_LhsSegment.GetExtent(), m_LhsSegment.GetExtent(), tmin, tmax, dotThreshold };

		m_Quantity = calc.GetNumIntersections();
		if (m_Quantity == 2)
		{
			intersectionType = IntersectionType::Segment;
			m_Point[0] = m_LhsSegment.GetCenterPoint() + calc.GetIntersection(0) * m_LhsSegment.GetDirection();
			m_Point[1] = m_LhsSegment.GetCenterPoint() + calc.GetIntersection(1) * m_LhsSegment.GetDirection();
		}
		else if (m_Quantity == 1)
		{
			intersectionType = IntersectionType::Point;
			m_Point[0] = m_LhsSegment.GetCenterPoint() + calc.GetIntersection(0) * m_LhsSegment.GetDirection();
		}
		else
		{
			intersectionType = IntersectionType::Empty;
		}
	}
	else
	{
		m_Quantity = 0;
		intersectionType = IntersectionType::Empty;
	}

	ParentType::SetIntersectionType(intersectionType);
}

template <typename Real>
Mathematics::StaticFindIntersectorSegment2Segment2<Real>
	::~StaticFindIntersectorSegment2Segment2()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorSegment2Segment2<Real>
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && 0 <= m_Quantity)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::StaticFindIntersectorSegment2Segment2<Real>::Segment2 Mathematics::StaticFindIntersectorSegment2Segment2<Real>
	::GetLhsSegment() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_LhsSegment;
}

template <typename Real>
typename const Mathematics::StaticFindIntersectorSegment2Segment2<Real>::Segment2 Mathematics::StaticFindIntersectorSegment2Segment2<Real>
	::GetRhsSegment() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_RhsSegment;
}

template <typename Real>
int Mathematics::StaticFindIntersectorSegment2Segment2<Real>
	::GetQuantity() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Quantity;
}

template <typename Real>
Real Mathematics::StaticFindIntersectorSegment2Segment2<Real>
	::GetIntervalThreshold() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_IntervalThreshold;
}

template <typename Real>
typename const Mathematics::StaticFindIntersectorSegment2Segment2<Real>::Vector2D Mathematics::StaticFindIntersectorSegment2Segment2<Real>
	::GetPoint(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < static_cast<int>(m_Point.size()), "索引错误\n");

	return m_Point[index];
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_SEGMENT2_DETAIL_H
