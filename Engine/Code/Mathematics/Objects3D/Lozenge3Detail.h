// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/08 10:03)

#ifndef MATHEMATICS_OBJECTS3D_LOZENGE3_DETAIL_H
#define MATHEMATICS_OBJECTS3D_LOZENGE3_DETAIL_H

#include "Lozenge3.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Lozenge3<Real>
	::Lozenge3( const Rectangle3& rectangle, Real radius )
	:m_Rectangle{ rectangle }, m_Radius{ radius }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Lozenge3<Real>
	::IsValid() const noexcept
{
	if (Real{} < m_Radius)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT


template <typename Real>
typename const Mathematics::Lozenge3<Real>::Rectangle3 Mathematics::Lozenge3<Real>
	::GetRectangle() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Rectangle;
}


template <typename Real>
Real Mathematics::Lozenge3<Real>
	::GetRadius() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Radius;
}


#endif // MATHEMATICS_OBJECTS3D_LOZENGE3_DETAIL_H

