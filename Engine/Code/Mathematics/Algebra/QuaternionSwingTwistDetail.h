// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/05 19:16)

#ifndef MATHEMATICS_ALGEBRA_QUATERNION_SWING_TWIST_DETAIL_H
#define MATHEMATICS_ALGEBRA_QUATERNION_SWING_TWIST_DETAIL_H

#include "QuaternionSwingTwist.h"
#include "Quaternion.h"
#include "AlgebraTraits.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/Math.h"

template <typename Real>
Mathematics:: QuaternionSwingTwist <Real>	
	:: QuaternionSwingTwist(const Quaternion& swing,const Quaternion& twist)
	: m_Swing{ swing }, m_Twist{ twist }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics:: QuaternionSwingTwist<Real>
	::IsValid() const noexcept
{
     return true;
}
#endif	// OPEN_CLASS_INVARIANT
 
template <typename Real>
typename const Mathematics:: QuaternionSwingTwist<Real>::Quaternion Mathematics::QuaternionSwingTwist<Real>
	::GetTwist() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Twist;
}

template <typename Real>
typename const Mathematics:: QuaternionSwingTwist<Real>::Quaternion Mathematics::QuaternionSwingTwist <Real>
	::GetSwing() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Swing;
} 

#endif // MATHEMATICS_ALGEBRA_QUATERNION_SWING_TWIST_DETAIL_H
