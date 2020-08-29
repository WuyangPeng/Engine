// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/19 17:48)

#ifndef MATHEMATICS_OBJECTS3D_TORUS3_PARAMETERS_DETAIL_H
#define MATHEMATICS_OBJECTS3D_TORUS3_PARAMETERS_DETAIL_H

#include "Torus3Parameters.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_TORUS3_PARAMETERS_DETAIL)

#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Torus3Parameters <Real>
	::Torus3Parameters(Real s, Real t) noexcept
	: m_S{ s }, m_T{ t }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Torus3Parameters<Real>
	::IsValid() const noexcept
{
	if (Math::GetValue(0) <= m_S && m_S <= static_cast<Real>(1) &&
		Math::GetValue(0) <= m_T && m_T <= static_cast<Real>(1))
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::Torus3Parameters<Real>
	::GetS() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_S;
}

template <typename Real>
Real Mathematics::Torus3Parameters<Real>
	::GetT() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_T;
}

#endif // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_TORUS3_PARAMETERS_DETAIL)


#endif // MATHEMATICS_OBJECTS3D_TORUS3_PARAMETERS_DETAIL_H