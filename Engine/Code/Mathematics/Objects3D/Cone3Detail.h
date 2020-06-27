// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 17:32)

#ifndef MATHEMATICS_OBJECTS3D_CONE3_DETAIL_H
#define MATHEMATICS_OBJECTS3D_CONE3_DETAIL_H

#include "Cone3.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Algebra/Vector3DTools.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Cone3<Real>
	::Cone3(const Vector3D& vertex, const Vector3D& axis, const Real angle, const Real height, const Real epsilon)
	:m_Vertex{ vertex }, m_Axis{ axis }, m_CosAngle{ Math::Cos(angle) },
	 m_SinAngle{ Math::Sin(angle) }, m_Height{ height }, m_Epsilon{ epsilon }
{
	MATHEMATICS_ASSERTION_1(Math::sm_Zero <= angle && angle <= Math::sm_HalfPI, "角度必须在第一象限！");

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Cone3<Real>
	::Cone3(const Real cosAngle, const Real sinAngle, const Real height, const Vector3D& vertex, const Vector3D& axis, const Real epsilon)
	:m_Vertex{ vertex }, m_Axis{ axis }, m_CosAngle{ cosAngle }, m_SinAngle{ sinAngle }, m_Height{ height }, m_Epsilon{ epsilon }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Cone3<Real>
	::IsValid() const noexcept
{
	if (Math::Approximate(m_CosAngle * m_CosAngle + m_SinAngle * m_SinAngle, static_cast<Real>(1), m_Epsilon) &&
		m_Epsilon < m_Height &&
		m_Axis.IsNormalize(m_Epsilon))
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::Cone3<Real>::Vector3D Mathematics::Cone3<Real>
	::GetVertex() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Vertex;
}

template <typename Real>
typename const Mathematics::Cone3<Real>::Vector3D Mathematics::Cone3<Real>
	::GetAxis() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Axis;
}

template <typename Real>
Real Mathematics::Cone3<Real>
	::GetCosAngle() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_CosAngle;
}

template <typename Real>
Real Mathematics::Cone3<Real>
	::GetSinAngle() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_SinAngle;
}

template <typename Real>
Real Mathematics::Cone3<Real>
	::GetHeight() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Height;
}

#endif // MATHEMATICS_OBJECTS3D_CONE3_DETAIL_H

