// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/24 15:36)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_CIRCLE2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_CIRCLE2_DETAIL_H

#include "StaticFindIntersectorArc2Circle2.h"
#include "StaticFindIntersectorCircle2Circle2Detail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Objects2D/Arc2Detail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

template <typename Real>
Mathematics::StaticFindIntersectorArc2Circle2<Real>
	::StaticFindIntersectorArc2Circle2(const Arc2& arc, const Circle2& circle, const Real epsilon)
	:ParentType{ epsilon }, m_Arc{ arc }, m_Circle{ circle }, m_Point{}
{
	Find();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::StaticFindIntersectorArc2Circle2<Real>
	::Find()
{
	Circle2 circleOfArc{ m_Arc.GetCenter(), m_Arc.GetRadius() };
	StaticFindIntersectorCircle2Circle2<Real> intersector{ circleOfArc, m_Circle };

	if (!intersector.IsIntersection())
	{
		// 圆和圆弧不相交。
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	if (intersector.GetIntersectionType() == IntersectionType::Other)
	{
		// 圆弧在圆上。
		this->SetIntersectionType(IntersectionType::Other);
		return;
	}

	// 测试圆与圆的交点是否在圆弧上。
	for (auto i = 0; i < intersector.GetQuantity(); ++i)
	{
		if (m_Arc.Contains(intersector.GetPoint(i)))
		{
			m_Point.push_back(intersector.GetPoint(i));
		}
	}

	this->SetIntersectionType(0 < m_Point.size() ? IntersectionType::Point : IntersectionType::Empty);
}

template <typename Real>
Mathematics::StaticFindIntersectorArc2Circle2<Real>
	::~StaticFindIntersectorArc2Circle2()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorArc2Circle2<Real>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename const  Mathematics::StaticFindIntersectorArc2Circle2<Real>::Arc2 Mathematics::StaticFindIntersectorArc2Circle2<Real>
	::GetArc() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Arc;
}

template <typename Real>
typename const Mathematics::StaticFindIntersectorArc2Circle2<Real>::Circle2 Mathematics::StaticFindIntersectorArc2Circle2<Real>
	::GetCircle() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Circle;
}

template <typename Real>
int Mathematics::StaticFindIntersectorArc2Circle2<Real>
	::GetQuantity() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return boost::numeric_cast<int>(m_Point.size());
}

template <typename Real>
typename const Mathematics::StaticFindIntersectorArc2Circle2<Real>::Vector2D Mathematics::StaticFindIntersectorArc2Circle2<Real>
	::GetPoint(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < GetQuantity(), "索引错误！\n");

	return m_Point[index];
}

template <typename Real>
typename const Mathematics::StaticFindIntersectorArc2Circle2<Real>::Arc2 Mathematics::StaticFindIntersectorArc2Circle2<Real>
	::GetIntersectionArc() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	if (this->GetIntersectionType() == IntersectionType::Other)
	{
		return m_Arc;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("要查询的圆弧和圆并不是重叠的。\n"));
	}
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_CIRCLE2_DETAIL_H
