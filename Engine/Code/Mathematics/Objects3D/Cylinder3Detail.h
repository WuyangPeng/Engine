// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/19 17:38)

#ifndef MATHEMATICS_OBJECTS3D_CYLINDER3_DETAIL_H
#define MATHEMATICS_OBJECTS3D_CYLINDER3_DETAIL_H

#include "Cylinder3.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Cylinder3<Real>
	::Cylinder3(const Line3& axis, Real radius, Real height)
	:m_Axis{ axis }, m_Radius{ radius }, m_Height{ height }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Cylinder3<Real>
	::IsValid() const noexcept
{
	if (Math::GetValue(0) <= m_Radius && Math::GetValue(0) <= m_Height)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::Cylinder3<Real>::Line3 Mathematics::Cylinder3<Real>
	::GetAxis() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Axis;
}

template <typename Real>
Real Mathematics::Cylinder3<Real>
	::GetRadius() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Radius;
}

template <typename Real>
Real Mathematics::Cylinder3<Real>
	::GetHeight() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Height;
}

#endif // MATHEMATICS_OBJECTS3D_CYLINDER3_DETAIL_H