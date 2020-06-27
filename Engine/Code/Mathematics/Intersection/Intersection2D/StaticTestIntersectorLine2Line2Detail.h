// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/24 15:58)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_LINE2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_LINE2_DETAIL_H

#include "StaticTestIntersectorLine2Line2.h"
#include "StaticTestIntersectorLine2ClassifyDetail.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"

template <typename Real>
Mathematics::StaticTestIntersectorLine2Line2<Real>
	::StaticTestIntersectorLine2Line2(const Line2& lhsLine, const Line2& rhsLine, const Real dotThreshold)
	:ParentType{ dotThreshold }, m_LhsLine{ lhsLine }, m_RhsLine{ rhsLine }, m_Quantity{ 0 }
{
	Test();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::StaticTestIntersectorLine2Line2<Real>
	::Test()
{
	StaticTestIntersectorLine2Classify<Real> classify{ m_LhsLine.GetOrigin(), m_LhsLine.GetDirection(),m_RhsLine.GetOrigin(), m_RhsLine.GetDirection(),false, this->GetEpsilon() };

	auto intersectionType = classify.GetIntersectionType();
	this->SetIntersectionType(intersectionType);

	switch (intersectionType)
	{
	case IntersectionType::Empty:
		m_Quantity = 0;
		break;
	case IntersectionType::Point:
		m_Quantity = 1;
		break;
	case IntersectionType::Line:
		m_Quantity = std::numeric_limits<int>::max();
		break;
	default:
		MATHEMATICS_ASSERTION_3(false, "相交类型计算错误！\n");
		break;
	}
}

template <typename Real>
Mathematics::StaticTestIntersectorLine2Line2<Real>
	::~StaticTestIntersectorLine2Line2()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticTestIntersectorLine2Line2<Real>
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && 0 <= m_Quantity)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::StaticTestIntersectorLine2Line2<Real>::Line2 Mathematics::StaticTestIntersectorLine2Line2<Real>
	::GetLhsLine() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_LhsLine;
}

template <typename Real>
typename const Mathematics::StaticTestIntersectorLine2Line2<Real>::Line2 Mathematics::StaticTestIntersectorLine2Line2<Real>
	::GetRhsLine() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_RhsLine;
}

template <typename Real>
int Mathematics::StaticTestIntersectorLine2Line2<Real>
	::GetQuantity() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Quantity;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_LINE2_DETAIL_H
