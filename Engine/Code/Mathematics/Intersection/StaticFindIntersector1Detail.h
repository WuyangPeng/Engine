// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/24 15:18)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR1_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR1_DETAIL_H

#include "StaticFindIntersector1.h"
#include "Intersector1Detail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

template <typename Real>
Mathematics::StaticFindIntersector1<Real>
	::StaticFindIntersector1(Real u0, Real u1, Real v0, Real v1, const Real epsilon)
	:ParentType{ u0, u1, v0, v1,epsilon }, m_Intersections{}
{
	Find();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::StaticFindIntersector1<Real>
	::Find()
{
	auto u0 = this->GetU(0);
	auto u1 = this->GetU(1);
	auto v0 = this->GetV(0);
	auto v1 = this->GetV(1);
	auto epsilon = this->GetEpsilon();

	if (u0 - epsilon <= v1 && v0 - epsilon <= u1)
	{
		if (v0 + epsilon < u1)
		{
			if (u0 + epsilon <= v1)
			{
				auto lhsIntersection = (u0 < v0 ? v0 : u0);
				auto rhsIntersection = (v1 < u1 ? v1 : u1);

				if (Math::Approximate(lhsIntersection, rhsIntersection, epsilon))
				{
					m_Intersections.push_back((lhsIntersection + rhsIntersection) / Math::GetValue(2));
				}
				else
				{
					m_Intersections.push_back(lhsIntersection);
					m_Intersections.push_back(rhsIntersection);
				}
			}
			else  // u0 == v1
			{
				m_Intersections.push_back((u0 + v1) / Math::GetValue(2));
			}
		}
		else  // v0 == u1
		{
			m_Intersections.push_back((v0 + u1) / Math::GetValue(2));
		}
	}
}

template <typename Real>
Mathematics::StaticFindIntersector1<Real>
	::~StaticFindIntersector1()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersector1<Real>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT	

template <typename Real>
bool Mathematics::StaticFindIntersector1<Real>
	::IsIntersection() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return !m_Intersections.empty();
}

template <typename Real>
int Mathematics::StaticFindIntersector1<Real>
	::GetNumIntersections() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return boost::numeric_cast<int>(m_Intersections.size());
}

template <typename Real>
Real Mathematics::StaticFindIntersector1<Real>
	::GetIntersection(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < GetNumIntersections(), "索引越界！\n");

	return m_Intersections[index];
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR1_DETAIL_H

