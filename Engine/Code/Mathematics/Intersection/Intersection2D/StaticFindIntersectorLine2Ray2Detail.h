// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/13 09:52)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_RAY2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_RAY2_DETAIL_H

#include "StaticFindIntersectorLine2Ray2.h"
#include "StaticTestIntersectorLine2ClassifyDetail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorLine2Ray2<Real>
	::StaticFindIntersectorLine2Ray2(const Line2& line, const Ray2& ray,const Real dotThreshold)
	:ParentType{ dotThreshold }, m_Line{ line }, m_Ray{ ray }, m_Quantity{ 0 }, m_Point{}
{
	Find();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::StaticFindIntersectorLine2Ray2<Real>
	::Find()
{
	StaticTestIntersectorLine2Classify<Real> classify{ m_Line.GetOrigin(), m_Line.GetDirection(),m_Ray.GetOrigin(), m_Ray.GetDirection(),true, this->GetEpsilon() };

	auto intersectionType = classify.GetIntersectionType();

	if (intersectionType == IntersectionType::Point)
	{
		// 测试线-线相交的点是否在射线上。
		if (Real{} <= classify.GetSecondParameter())
		{
			m_Quantity = 1;
			m_Point = m_Line.GetOrigin() + classify.GetFirstParameter() * m_Line.GetDirection();
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

	ParentType::SetIntersectionType(intersectionType);	 
}

template <typename Real>
Mathematics::StaticFindIntersectorLine2Ray2<Real>
	::~StaticFindIntersectorLine2Ray2()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorLine2Ray2<Real>
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && 0 <= m_Quantity)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::StaticFindIntersectorLine2Ray2<Real>::Line2 Mathematics::StaticFindIntersectorLine2Ray2<Real>
	::GetLine() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Line;
}

template <typename Real>
typename const Mathematics::StaticFindIntersectorLine2Ray2<Real>::Ray2 Mathematics::StaticFindIntersectorLine2Ray2<Real>
	::GetRay() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Ray;
}

template <typename Real>
int Mathematics::StaticFindIntersectorLine2Ray2<Real>
	::GetQuantity() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Quantity;
}

template <typename Real>
typename const Mathematics::StaticFindIntersectorLine2Ray2<Real>::Vector2D Mathematics::StaticFindIntersectorLine2Ray2<Real>
	::GetPoint() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	if (m_Quantity == 1)
	{
		return m_Point;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("不存在唯一的交点。\n"));
	}
}
#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_RAY2_DETAIL_H
