// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/13 09:58)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_RAY2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_RAY2_DETAIL_H

#include "StaticFindIntersectorRay2Ray2.h"
#include "StaticTestIntersectorLine2ClassifyDetail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <boost/numeric/conversion/cast.hpp>

template <typename Real>
Mathematics::StaticFindIntersectorRay2Ray2<Real>
	::StaticFindIntersectorRay2Ray2(const Ray2& lhsRay, const Ray2& rhsRay, const Real dotThreshold)
	:ParentType{ dotThreshold }, m_LhsRay{ lhsRay }, m_RhsRay{ rhsRay }, m_Quantity{ 0 }, m_Point{}
{
	Find();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::StaticFindIntersectorRay2Ray2<Real>
	::Find()
{
	Real dotThreshold = this->GetEpsilon();
	StaticTestIntersectorLine2Classify<Real> classify{ m_LhsRay.GetOrigin(), m_LhsRay.GetDirection(),m_RhsRay.GetOrigin(), m_RhsRay.GetDirection(),true, dotThreshold };

	auto intersectionType = classify.GetIntersectionType();

	if (intersectionType == IntersectionType::Point)
	{
		// 测试直线交点是否在射线上。
		if (Real{} <= classify.GetFirstParameter() && Real{} <= classify.GetSecondParameter())
		{
			m_Quantity = 1;
			intersectionType = IntersectionType::Point;
			m_Point[0] = m_LhsRay.GetOrigin() + classify.GetFirstParameter() * m_LhsRay.GetDirection();
		}
		else
		{
			m_Quantity = 0;
			intersectionType = IntersectionType::Empty;
		}
	}
	else if (intersectionType == IntersectionType::Line)
	{
		auto dotProduct = Vector2DTools::DotProduct(m_LhsRay.GetDirection(), m_RhsRay.GetOrigin() - m_LhsRay.GetOrigin());

		if (Real{} < Vector2DTools::DotProduct(m_LhsRay.GetDirection(),m_RhsRay.GetDirection()))
		{			
			// 射线是共线的并且在相同的方向，所以它们必须是重叠的。
			m_Quantity = std::numeric_limits<int>::max();
			intersectionType = IntersectionType::Ray;
			m_Point[0] = (Real{} < dotProduct ? m_RhsRay.GetOrigin() : m_LhsRay.GetOrigin());
		}
		else
		{	
			// 射线是共线的，且方向相反。 测试它们是否重叠。
			// m_LhsRay具有间隔[0，+无穷大），
			// m_RhsRay具有相对于ray0方向的间隔（-infinity，dotProduct] 。
			if (dotThreshold < dotProduct)
			{
				m_Quantity = 2;
				intersectionType = IntersectionType::Segment;
				m_Point[0] = m_LhsRay.GetOrigin();
				m_Point[1] = m_RhsRay.GetOrigin();
			}
			else if (dotProduct < -dotThreshold)
			{
				m_Quantity = 0;
				intersectionType = IntersectionType::Empty;
			}
			else  // dotProduct == 0
			{
				m_Quantity = 1;
				intersectionType = IntersectionType::Point;
				m_Point[0] = m_LhsRay.GetOrigin();
			}
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
Mathematics::StaticFindIntersectorRay2Ray2<Real>
	::~StaticFindIntersectorRay2Ray2()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorRay2Ray2<Real>
	::IsValid() const noexcept
{	
	if (ParentType::IsValid() && 0 <= m_Quantity)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::StaticFindIntersectorRay2Ray2<Real>::Ray2 Mathematics::StaticFindIntersectorRay2Ray2<Real>
	::GetLhsRay() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_LhsRay;
}

template <typename Real>
typename const Mathematics::StaticFindIntersectorRay2Ray2<Real>::Ray2 Mathematics::StaticFindIntersectorRay2Ray2<Real>
	::GetRhsRay() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_RhsRay;
}

template <typename Real>
int Mathematics::StaticFindIntersectorRay2Ray2<Real>
	::GetQuantity() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Quantity;
}

template <typename Real>
typename const Mathematics::StaticFindIntersectorRay2Ray2<Real>::Vector2D Mathematics::StaticFindIntersectorRay2Ray2<Real>
	::GetPoint(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_Point.size()), "索引错误\n");

	return m_Point[index];
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_RAY2_DETAIL_H
 