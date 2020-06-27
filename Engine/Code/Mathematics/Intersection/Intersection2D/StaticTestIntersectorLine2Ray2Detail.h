// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/24 15:59)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_RAY2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_RAY2_DETAIL_H

#include "StaticTestIntersectorLine2Ray2.h"
#include "StaticTestIntersectorLine2ClassifyDetail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticTestIntersectorLine2Ray2<Real>
	::StaticTestIntersectorLine2Ray2(const Line2& line, const Ray2& ray, const Real dotThreshold)
	:ParentType{ dotThreshold }, m_Line{ line }, m_Ray{ ray }, m_Quantity{ 0 }
{
	Test();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::StaticTestIntersectorLine2Ray2<Real>
	::Test()
{
	StaticTestIntersectorLine2Classify<Real> classify{ m_Line.GetOrigin(), m_Line.GetDirection(),m_Ray.GetOrigin(), m_Ray.GetDirection(),true, this->GetEpsilon() };

	auto intersectionType = classify.GetIntersectionType();

	if (intersectionType == IntersectionType::Point)
	{
		// 测试线-线相交的点是否在射线上。
		if (Math::sm_Zero <= classify.GetSecondParameter())
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
		intersectionType = IntersectionType::Ray;
		m_Quantity = std::numeric_limits<int>::max();
	}
	else
	{
		m_Quantity = 0;
		intersectionType = IntersectionType::Empty;
	}

	this->SetIntersectionType(intersectionType);
}

template <typename Real>
Mathematics::StaticTestIntersectorLine2Ray2<Real>
	::~StaticTestIntersectorLine2Ray2()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticTestIntersectorLine2Ray2<Real>
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && 0 <= m_Quantity)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::StaticTestIntersectorLine2Ray2<Real>::Line2 Mathematics::StaticTestIntersectorLine2Ray2<Real>
	::GetLine() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Line;
}

template <typename Real>
typename const Mathematics::StaticTestIntersectorLine2Ray2<Real>::Ray2 Mathematics::StaticTestIntersectorLine2Ray2<Real>
	::GetRay() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Ray;
}

template <typename Real>
int Mathematics::StaticTestIntersectorLine2Ray2<Real>
	::GetQuantity() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Quantity;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_RAY2_DETAIL_H
