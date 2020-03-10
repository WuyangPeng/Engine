// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/12 19:33)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_ARC2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_ARC2_DETAIL_H

#include "StaticFindIntersectorArc2Arc2.h"
#include "StaticFindIntersectorCircle2Circle2Detail.h"
#include "Mathematics/Objects2D/Arc2Detail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <boost/numeric/conversion/cast.hpp>

template <typename Real>
Mathematics::StaticFindIntersectorArc2Arc2<Real>
	::StaticFindIntersectorArc2Arc2(const Arc2& lhsArc, const Arc2& rhsArc, const Real epsilon)
	:ParentType{ epsilon }, m_LhsArc{ lhsArc }, m_RhsArc{ rhsArc }, m_Point{}, m_IntersectionArc{ lhsArc }
{
	Find();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::StaticFindIntersectorArc2Arc2<Real>
	::Find()
{
	Circle2 lhsCircle{ m_LhsArc.GetCenter(), m_LhsArc.GetRadius() };
	Circle2 rhsCircle{ m_RhsArc.GetCenter(), m_RhsArc.GetRadius() };
	StaticFindIntersectorCircle2Circle2<Real> intersector{ lhsCircle, rhsCircle };
    if (!intersector.IsIntersection())
    {
        // 圆弧不相交。
		this->SetIntersectionType(IntersectionType::Empty);
		return;
    }

	if (intersector.GetIntersectionType() == IntersectionType::Other)
    {
		// 圆弧是同个圆。 确定圆弧是否重叠。
		// 令m_LhsArc为<A0，A1>，m_RhsArc为<B0，B1>，
		// 点围绕圆弧逆时针排列。
		if (m_RhsArc.Contains(m_LhsArc.GetFirstEnd()))
        {
			if (m_RhsArc.Contains(m_LhsArc.GetSecondEnd()))
            {
                // m_LhsArc的m_RhsArc里, <B0,A0,A1,B1>.
				this->SetIntersectionType(IntersectionType::Other);
				m_IntersectionArc = m_LhsArc;
            }
            else
            {
				if(!Vector2DTools::Approximate (m_LhsArc.GetFirstEnd() , m_RhsArc.GetSecondEnd(), this->GetEpsilon()))
                {
                    // m_LhsArc和m_RhsArc重叠, <B0,A0,B1,A1>.
					this->SetIntersectionType(IntersectionType::Other);
					m_IntersectionArc = Arc2{ m_LhsArc.GetCenter(),m_LhsArc.GetRadius(),
											  m_LhsArc.GetFirstEnd(),m_RhsArc.GetSecondEnd(), this->GetEpsilon() };
                }
                else
                {
                    // m_LhsArc和m_RhsArc共享端点 <B0,A0,B1,A1>, A0 = B1.
					this->SetIntersectionType(IntersectionType::Point);
					m_Point.push_back((m_LhsArc.GetFirstEnd() + m_RhsArc.GetSecondEnd()) / static_cast<Real>(2));
                }
            }
            return;
        }

		if (m_RhsArc.Contains(m_LhsArc.GetSecondEnd()))
        {
			if (!Vector2DTools::Approximate(m_LhsArc.GetSecondEnd(), m_RhsArc.GetFirstEnd(), this->GetEpsilon()))
            {
                // m_LhsArc和m_RhsArc重叠, <A0,B0,A1,B1>.
				this->SetIntersectionType(IntersectionType::Other);
				m_IntersectionArc = Arc2{ m_LhsArc.GetCenter(), m_LhsArc.GetRadius(), m_RhsArc.GetFirstEnd(), m_LhsArc.GetSecondEnd(), this->GetEpsilon() };
            }
            else
            {
                // m_LhsArc和m_RhsArc共享端点， <A0,B0,A1,B1>, B0 = A1.
				this->SetIntersectionType(IntersectionType::Point);
				m_Point.push_back((m_RhsArc.GetFirstEnd() + m_LhsArc.GetSecondEnd()) / static_cast<Real>(2));
            }

            return;
        }

		if (m_LhsArc.Contains(m_RhsArc.GetFirstEnd()))
        {
            // m_RhsArc在m_LhsArc里, <A0,B0,B1,A1>.
			this->SetIntersectionType(IntersectionType::Other);
			m_IntersectionArc = m_RhsArc;
            return;
        }
        else
        {
            // 圆弧不重叠 <A0,A1,B0,B1>.
			this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    // 测试圆弧上是否有交点。
    for (auto i = 0; i < intersector.GetQuantity(); ++i)
    {
		if (m_LhsArc.Contains(intersector.GetPoint(i))	&& m_RhsArc.Contains(intersector.GetPoint(i)))
        {
            m_Point.push_back(intersector.GetPoint(i));
        }
    }

	this->SetIntersectionType(0 < m_Point.size() ? IntersectionType::Point : IntersectionType::Empty);
}


template <typename Real>
Mathematics::StaticFindIntersectorArc2Arc2<Real>	
	::~StaticFindIntersectorArc2Arc2()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorArc2Arc2<Real>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT	

template <typename Real>
typename const Mathematics::StaticFindIntersectorArc2Arc2<Real>::Arc2 Mathematics::StaticFindIntersectorArc2Arc2<Real>
	::GetLhsArc() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_LhsArc;
}

template <typename Real>
typename const Mathematics::StaticFindIntersectorArc2Arc2<Real>::Arc2 Mathematics::StaticFindIntersectorArc2Arc2<Real>
	::GetRhsArc() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_RhsArc;
}

template <typename Real>
int Mathematics::StaticFindIntersectorArc2Arc2<Real>
	::GetQuantity() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return boost::numeric_cast<int>(m_Point.size());
}

template <typename Real>
typename const Mathematics::StaticFindIntersectorArc2Arc2<Real>::Vector2D Mathematics::StaticFindIntersectorArc2Arc2<Real>
	::GetPoint(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < GetQuantity(), "索引越界\n");

	return m_Point[index];
}

template <typename Real>
typename const Mathematics::StaticFindIntersectorArc2Arc2<Real>::Arc2 Mathematics::StaticFindIntersectorArc2Arc2<Real>
	::GetIntersectionArc() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	if (this->GetIntersectionType() == IntersectionType::Other)
	{
		return m_IntersectionArc;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("要查询的圆弧并不是重叠的。\n"));
	}
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_ARC2_DETAIL_H
