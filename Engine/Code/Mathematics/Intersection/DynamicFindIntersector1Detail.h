// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/24 15:16)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR1_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR1_DETAIL_H

#include "DynamicFindIntersector1.h"
#include "Intersector1Detail.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

template <typename Real>
Mathematics::DynamicFindIntersector1<Real>
	::DynamicFindIntersector1(Real u0, Real u1, Real v0, Real v1, Real tMax, Real speedU, Real speedV, const Real epsilon)
	:ParentType{ u0, u1, v0, v1,epsilon }, m_FirstTime{}, m_LastTime{}, m_Intersections{}
{
	Find(tMax, speedU, speedV);

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::DynamicFindIntersector1<Real>
	::Find(Real tMax, Real speedU, Real speedV)
{
	auto u0 = this->GetU(0);
	auto u1 = this->GetU(1);
	auto v0 = this->GetV(0);
	auto v1 = this->GetV(1);
	auto epsilon = this->GetEpsilon();

	if (u1 + epsilon < v0)
	{
		// [u0,u1]最初在[v0,v1]的左边。
		auto differenceSpeed = speedU - speedV;
		if (Math::GetValue(0) < differenceSpeed)
		{
			// 区间必须朝向彼此移动。
			auto differencePosition = v0 - u1;
			if (differencePosition <= tMax * differenceSpeed)
			{
				// 区间在指定时间内相交。
				m_FirstTime = differencePosition / differenceSpeed;
				m_LastTime = (v1 - u0) / differenceSpeed;

				m_Intersections.push_back(u1 + m_FirstTime * speedU);
			}
		}
	}
	else if (v1 + epsilon < u0)
	{
		// [u0,u1]最初在[v0,v1]的右边。
		auto differenceSpeed = speedV - speedU;
		if (Math::GetValue(0) < differenceSpeed)
		{
			// 区间必须朝向彼此移动。
			auto differencePosition = u0 - v1;
			if (differencePosition <= tMax * differenceSpeed)
			{
				// 区间在指定时间内相交。
				m_FirstTime = differencePosition / differenceSpeed;
				m_LastTime = (u1 - v0) / differenceSpeed;

				m_Intersections.push_back(v1 + m_FirstTime * speedV);
			}
		}
	}
	else
	{
		// 区间本来就相交。
		m_FirstTime = Math::GetValue(0);
		if (speedU + epsilon < speedV)
		{
			m_LastTime = (u1 - v0) / (speedV - speedU);
		}
		else if (speedV + epsilon < speedU)
		{
			m_LastTime = (v1 - u0) / (speedU - speedV);
		}
		else
		{
			m_LastTime = Math::sm_MaxReal;
		}

		if (v0 + epsilon < u1)
		{
			if (u0 + epsilon < v1)
			{
				auto lhsIntersection = (u0 < v0 ? v0 : u0);
				auto rhsIntersection = (v1 < u1 ? v1 : u1);

				if (Math::Approximate(lhsIntersection, rhsIntersection, epsilon))
				{
					m_Intersections.push_back((lhsIntersection + rhsIntersection) / static_cast<Real>(2));
				}
				else
				{
					m_Intersections.push_back(lhsIntersection);
					m_Intersections.push_back(rhsIntersection);
				}
			}
			else  // u0 == v1 
			{
				m_Intersections.push_back((u0 + v1) / static_cast<Real>(2));
			}
		}
		else  // u1 == v0 
		{
			m_Intersections.push_back((u1 + v0) / static_cast<Real>(2));
		}
	}
}

template <typename Real>
Mathematics::DynamicFindIntersector1<Real>
	::~DynamicFindIntersector1()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DynamicFindIntersector1<Real>
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && Math::GetValue(0) <= m_FirstTime && m_FirstTime <= m_LastTime)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT	

template <typename Real>
bool Mathematics::DynamicFindIntersector1<Real>
	::IsIntersection() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return !m_Intersections.empty();
}

template <typename Real>
int Mathematics::DynamicFindIntersector1<Real>
	::GetNumIntersections() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return boost::numeric_cast<int>(m_Intersections.size());
}

template <typename Real>
Real Mathematics::DynamicFindIntersector1<Real>
	::GetIntersection(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < GetNumIntersections(), "索引越界！\n");

	return m_Intersections[index];
}

template <typename Real>
Real Mathematics::DynamicFindIntersector1<Real>
	::GetFirstTime() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	if (IsIntersection())
	{
		return m_FirstTime;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("区间不相交\n"));
	}
}

template <typename Real>
Real Mathematics::DynamicFindIntersector1<Real>
	::GetLastTime() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	if (IsIntersection())
	{
		return m_LastTime;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("区间不相交\n"));
	}
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR1_DETAIL_H
