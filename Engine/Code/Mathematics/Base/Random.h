// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/18 19:11)

#ifndef MATHEMATICS_BASE_RANDOM_H
#define MATHEMATICS_BASE_RANDOM_H

#include "Mathematics/MathematicsDll.h"

#include "Math.h"

#include <type_traits> 

namespace Mathematics
{
	template <typename Real>
	class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Random
	{
	public:
		static_assert(std::is_floating_point<Real>::value, "Real must be floating point.");

		using ClassType = Random<Real>;
		using Math = Math<Real>;

	public:
		// 产生范围在[0,1]的随机数。
		// 随机数生成器可以通过调用UnitRandom先设置一个正数的种子。
		static Real UnitRandom(uint32_t seed = 0);

		// 产生范围在[-1,1]的随机数。
		// 随机数生成器可以通过调用UnitRandom先设置一个正数的种子。
		static Real SymmetricRandom(uint32_t seed = 0);

		// 产生范围在[min,max]的随机数。
		// 随机数生成器可以通过调用UnitRandom先设置一个正数的种子。
		static Real IntervalRandom(Real min, Real max, uint32_t seed = 0);
	};

	using Randomf = Random<float>;
	using Randomd = Random<double>;
}

#endif // MATHEMATICS_BASE_RANDOM_H
