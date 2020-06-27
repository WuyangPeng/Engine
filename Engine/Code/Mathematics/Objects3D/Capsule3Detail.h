// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/19 17:29)

#ifndef MATHEMATICS_OBJECTS3D_CAPSULE3_DETAIL_H
#define MATHEMATICS_OBJECTS3D_CAPSULE3_DETAIL_H

#include "Capsule3.h"
#include "Mathematics/Base/MathDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Capsule3<Real>
	::Capsule3(const Segment3& segment, Real radius)
	:m_Segment{ segment }, m_Radius{ radius }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Capsule3<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::Capsule3<Real>::Segment3 Mathematics::Capsule3<Real>
	::GetSegment() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Segment;
}

template <typename Real>
Real Mathematics::Capsule3<Real>
	::GetRadius() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Radius;
}

#endif // MATHEMATICS_OBJECTS3D_CAPSULE3_DETAIL_H