// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/19 17:46)

#ifndef MATHEMATICS_OBJECTS3D_SPHERE3_DETAIL_H
#define MATHEMATICS_OBJECTS3D_SPHERE3_DETAIL_H

#include "Sphere3.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Sphere3<Real>
	::Sphere3(const Vector3D& center, Real radius)
	:m_Center{ center }, m_Radius{ radius }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Sphere3<Real>
	::Sphere3()
	:m_Center{}, m_Radius{}
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Sphere3<Real>
	::IsValid() const noexcept
{
	if (Math::sm_Zero <= m_Radius)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::Sphere3<Real>::Vector3D Mathematics::Sphere3<Real>
	::GetCenter() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Center;
}

template <typename Real>
Real Mathematics::Sphere3<Real>
	::GetRadius() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Radius;
}

template <typename Real>
void Mathematics::Sphere3<Real>
	::SetSphere(const Vector3D& center, Real radius)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	m_Center = center;
	m_Radius = radius;
}

#endif // MATHEMATICS_OBJECTS3D_SPHERE3_DETAIL_H