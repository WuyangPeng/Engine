// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/04 11:40)

#ifndef MATHEMATICS_ALGEBRA_QUATERNION_FLAGS_H
#define MATHEMATICS_ALGEBRA_QUATERNION_FLAGS_H

#include "System/EnumOperator/EnumCastDetail.h"

namespace Mathematics
{	
	enum class QuaternionClosestAxis
	{
		X = 1,
		Y = 2,
		Z = 3
	};

	static_assert(System::EnumCastUnderlying(QuaternionClosestAxis::X) == 1 && 
				  System::EnumCastUnderlying(QuaternionClosestAxis::Y) == 2 &&
				  System::EnumCastUnderlying(QuaternionClosestAxis::Z) == 3,"QuaternionClosestAxis is error.");

	enum class QuaternionFactorFlags
	{
		XYZ,
		XZY,
		YZX,
		YXZ,
		ZXY,
		ZYX
	};
}

#endif // MATHEMATICS_ALGEBRA_QUATERNION_FLAGS_H
