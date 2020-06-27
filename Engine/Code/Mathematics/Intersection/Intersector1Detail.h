// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/24 15:17)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTOR1_DETAIL_H
#define MATHEMATICS_INTERSECTION_INTERSECTOR1_DETAIL_H

#include "Intersector1.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Intersector1<Real>
	::Intersector1(Real u0, Real u1, Real v0, Real v1, const Real epsilon)
	:m_U{}, m_V{}, m_Epsilon{ epsilon }
{
	m_U[0] = u0;
	m_U[1] = u1;
	m_V[0] = v0;
	m_V[1] = v1;

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Intersector1<Real>
	::~Intersector1()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Intersector1<Real>
	::IsValid() const noexcept
{
	if (m_U[0] <= m_U[1] && m_V[0] <= m_V[1] && Math::sm_Zero <= m_Epsilon)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::Intersector1<Real>
	::GetU(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	if (0 <= index && index < sm_Size)
	{
		return m_U[index];
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"));
	}
}

template <typename Real>
Real Mathematics::Intersector1<Real>
	::GetV(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	if (0 <= index && index < sm_Size)
	{
		return m_V[index];
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"));
	}
}

template <typename Real>
Real Mathematics::Intersector1<Real>
	::GetEpsilon() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Epsilon;
}

#endif // MATHEMATICS_INTERSECTION_INTERSECTOR1_DETAIL_H