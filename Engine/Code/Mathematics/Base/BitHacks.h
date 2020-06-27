// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/18 19:06)

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

		// ��IEEE32λ������[0,1]�ĸ�����F��
		// ����ת��Ϊ������[0,2^P-1]��һ��32λ����I��
		// ���롰value����F�����롰power����P�ͺ����ķ���ֵ��I��
		static int ScaledFloatToInt(float value, int power);
	};
}

#endif // MATHEMATICS_BASE_BIT_HACKS_H
