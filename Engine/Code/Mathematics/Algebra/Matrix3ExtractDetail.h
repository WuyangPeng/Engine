// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/19 13:25)

#ifndef MATHEMATICS_ALGEBRA_MATRIX3_EXTRACT_DETAIL_H
#define MATHEMATICS_ALGEBRA_MATRIX3_EXTRACT_DETAIL_H

#include "Matrix3Extract.h"
#include "Vector3D.h"
#include "AlgebraTraits.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Matrix3Extract<Real>
	::Matrix3Extract(Real angle, const Vector3D& axis) noexcept
	: m_Angle{ angle }, m_Axis{ axis }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Matrix3Extract<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif	// OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::Matrix3Extract<Real>
	::GetAngle() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Angle;
}

template <typename Real>
typename const Mathematics::Matrix3Extract<Real>::Vector3D Mathematics::Matrix3Extract<Real>
	::GetAxis() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Axis;
}

#endif // MATHEMATICS_ALGEBRA_MATRIX3_EXTRACT_DETAIL_H
