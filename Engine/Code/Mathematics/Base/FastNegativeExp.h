// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/18 19:07)

#ifndef MATHEMATICS_BASE_FAST_NEGATIVE_EXP_H
#define MATHEMATICS_BASE_FAST_NEGATIVE_EXP_H

#include "Mathematics/MathematicsDll.h"

#include "Math.h"

#include <type_traits> 

namespace Mathematics
{
	template <typename Real>
	class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE FastNegativeExp
	{
	public:
		static_assert(std::is_floating_point<Real>::value, "Real must be floating point.");

		using ClassType = FastNegativeExp<Real>;
		using Math = Math<Real>;

	public:
		// ���ٱƽ�exp(-x)������x�����ڷ�Χ[0,�����)	

		// 1.0e-3���ȣ�float����1.0e-4���ȣ�double��
		static Real FastNegativeExpMoreRoughCalculation(Real value);
		// 1.0e-4����
		static Real FastNegativeExpRoughCalculation(Real value);
		// 1.0e-5����
		static Real FastNegativeExpPreciseCalculation(Real value);
		// 1.0e-6����
		static Real FastNegativeExpMorePreciseCalculation(Real value);
	};

	using FastNegativeExpf = FastNegativeExp<float>;
	using FastNegativeExpd = FastNegativeExp<double>;
}

#endif // MATHEMATICS_BASE_FAST_NEGATIVE_EXP_H
