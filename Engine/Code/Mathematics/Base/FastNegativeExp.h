// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/03 19:20)

#ifndef MATHEMATICS_BASE_FAST_NEGATIVE_EXP_H
#define MATHEMATICS_BASE_FAST_NEGATIVE_EXP_H

#include "Mathematics/MathematicsDll.h"

#include <boost/type_traits/is_floating_point.hpp>
#include <boost/static_assert.hpp>

namespace Mathematics
{	
	template <typename Real>
	class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE FastNegativeExp
	{
	public:
		BOOST_STATIC_ASSERT((boost::is_floating_point<Real>::value));

		using ClassType = FastNegativeExp<Real>;
	
	public:   
		// ���ٱƽ�exp(-x)������x�����ڷ�Χ[0,�����)	
		
		// 1.0e-3���ȣ�float����1.0e-4���ȣ�double��
		static Real FastNegativeExpMoreRoughCalculation  (Real value);
		// 1.0e-4����
		static Real FastNegativeExpRoughCalculation (Real value);
		// 1.0e-5����
		static Real FastNegativeExpPreciseCalculation (Real value);
		// 1.0e-6����
		static Real FastNegativeExpMorePreciseCalculation (Real value);	
	};

	using FastNegativeExpf = FastNegativeExp<float>;
	using FastNegativeExpd = FastNegativeExp<double>;
}

#endif // MATHEMATICS_BASE_FAST_NEGATIVE_EXP_H
