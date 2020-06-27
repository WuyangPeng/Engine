// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/18 19:06)

#ifndef MATHEMATICS_BASE_BIT_HACKS_H
#define MATHEMATICS_BASE_BIT_HACKS_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
	class MATHEMATICS_DEFAULT_DECLARE BitHacks
	{
	public:
		using ClassType = BitHacks;

	public:
		template <typename T>
		static bool IsPowerOfTwo(T value) noexcept;

		template <typename T>
		static T Log2OfPowerOfTwo(T powerOfTwo);

		// 从IEEE32位区间在[0,1]的浮点数F，
		// 快速转换为区间在[0,2^P-1]的一个32位整数I，
		// 输入“value”是F，输入“power”是P和函数的返回值是I。
		static int ScaledFloatToInt(float value, int power);
	};
}

#endif // MATHEMATICS_BASE_BIT_HACKS_H
