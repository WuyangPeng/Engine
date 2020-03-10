// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/03 19:20)

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
		// 快速逼近exp(-x)。输入x必须在范围[0,无穷大)	
		
		// 1.0e-3精度（float）、1.0e-4精度（double）
		static Real FastNegativeExpMoreRoughCalculation  (Real value);
		// 1.0e-4精度
		static Real FastNegativeExpRoughCalculation (Real value);
		// 1.0e-5精度
		static Real FastNegativeExpPreciseCalculation (Real value);
		// 1.0e-6精度
		static Real FastNegativeExpMorePreciseCalculation (Real value);	
	};

	using FastNegativeExpf = FastNegativeExp<float>;
	using FastNegativeExpd = FastNegativeExp<double>;
}

#endif // MATHEMATICS_BASE_FAST_NEGATIVE_EXP_H
