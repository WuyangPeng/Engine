// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/04 11:49)

#ifndef MATHEMATICS_ALGEBRA_QUATERNION_SWING_TWIST_H
#define MATHEMATICS_ALGEBRA_QUATERNION_SWING_TWIST_H

#include "Mathematics/MathematicsFwd.h"

#include <type_traits>

namespace Mathematics
{
	template <typename Real>
	class QuaternionSwingTwist  
	{
	public:		
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = QuaternionSwingTwist<Real>;
		using Quaternion = Quaternion<Real>;

	public:
		QuaternionSwingTwist(const Quaternion& swing,const Quaternion& twist);
	
		CLASS_INVARIANT_DECLARE;

		const Quaternion GetTwist() const;
		const Quaternion GetSwing() const;

	private:
		Quaternion m_Swing;
		Quaternion m_Twist;
	};

	using QuaternionSwingTwistf = QuaternionSwingTwist<float>;
	using QuaternionSwingTwistd = QuaternionSwingTwist<double>;
}

#endif // MATHEMATICS_ALGEBRA_QUATERNION_SWING_TWIST_H
