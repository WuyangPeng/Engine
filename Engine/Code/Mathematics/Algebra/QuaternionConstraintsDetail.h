// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/05 18:16)

#ifndef MATHEMATICS_ALGEBRA_QUATERNION_CONSTRAINTS_DETAIL_H
#define MATHEMATICS_ALGEBRA_QUATERNION_CONSTRAINTS_DETAIL_H

#include "QuaternionConstraints.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_QUATERNION_CONSTRAINTS_DETAIL)

#include "Mathematics/Base/Math.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::QuaternionConstraints<Real>
	::QuaternionConstraints( Real minAngle, Real maxAngle )
	:m_MinAngle{ minAngle }, m_MaxAngle{ maxAngle }, m_CosMinAngle{ Math::Cos(m_MinAngle) }, m_SinMinAngle{ Math::Sin(m_MinAngle) },
	 m_CosMaxAngle{ Math::Cos(m_MaxAngle) }, m_SinMaxAngle{ Math::Sin(m_MaxAngle) }, m_DiffCosMaxMin{ m_CosMaxAngle - m_CosMinAngle }, m_DiffSinMaxMin{ m_SinMaxAngle - m_SinMinAngle },
	 m_AvrAngle{ static_cast<Real>(0.5) * (m_MinAngle + m_MaxAngle) }, m_CosAvrAngle{ Math::Cos(m_AvrAngle) }, m_SinAvrAngle{ Math::Sin(m_AvrAngle) }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::QuaternionConstraints<Real>
	::IsValid() const noexcept
{
	if(-Math::sm_HalfPI <= m_MinAngle && m_MinAngle <= Math::sm_HalfPI && m_MinAngle <= m_MaxAngle && m_MaxAngle <= Math::sm_HalfPI)
	    return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::QuaternionConstraints<Real>
	::IsValid( Real x, Real y ) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_1(Math::Approximate(Math::Sqrt(x * x + y * y),static_cast<Real>(1)),"(x,y)�����ǵ�λ���ȣ�");

	// ����(x,y)�Ƿ�����Լ��������
	auto xm = x - m_CosMinAngle;
	auto ym = y - m_SinMinAngle;
	if (ym * m_DiffCosMaxMin <= xm * m_DiffSinMaxMin )
	{
		return true;
	}

	// ����(-x,-y)�Ƿ�����Լ��������
	auto xp = x + m_CosMinAngle;
	auto yp = y + m_SinMinAngle;
	if (xp * m_DiffSinMaxMin <= yp * m_DiffCosMaxMin)
	{
		return true;
	}

	return false;
}


template <typename Real>
Real Mathematics::QuaternionConstraints<Real>
	::GetCosMinAngle() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_CosMinAngle;
}

template <typename Real>
Real Mathematics::QuaternionConstraints<Real>
	::GetSinMinAngle() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_SinMinAngle;
}

template <typename Real>
Real Mathematics::QuaternionConstraints<Real>
	::GetCosMaxAngle() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_CosMaxAngle;
}

template <typename Real>
Real Mathematics::QuaternionConstraints<Real>
	::GetSinMaxAngle() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_SinMaxAngle;
}

template <typename Real>
Real Mathematics::QuaternionConstraints<Real>
	::GetCosAvrAngle() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_CosAvrAngle;
}

template <typename Real>
Real Mathematics::QuaternionConstraints<Real>
	::GetSinAvrAngle() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_SinAvrAngle;
}

template <typename Real>
Real Mathematics::QuaternionConstraints<Real>
	::GetMinAngle() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_MinAngle;
}

template <typename Real>
Real Mathematics::QuaternionConstraints<Real>
	::GetMaxAngle() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_MaxAngle;
}

#endif // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_QUATERNION_CONSTRAINTS_DETAIL)

#endif // MATHEMATICS_ALGEBRA_QUATERNION_CONSTRAINTS_DETAIL_H

