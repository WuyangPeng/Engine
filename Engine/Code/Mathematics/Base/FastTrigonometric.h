// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/18 19:08)

#ifndef MATHEMATICS_BASE_FAST_TRIGONOMETRIC_H
#define MATHEMATICS_BASE_FAST_TRIGONOMETRIC_H

#include "Mathematics/MathematicsDll.h"

#include "Math.h"

#include <type_traits> 

namespace Mathematics
{
	template <typename Real>
	class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE FastTrigonometric
	{
	public:
		static_assert(std::is_floating_point<Real>::value, "Real must be floating point.");

		using ClassType = FastTrigonometric<Real>;
		using Math = Math<Real>;

	public:
		// 采用多项式逼近三角函数和反三角函数的快速计算。速度起伏依靠处理器。

		// 输入必须在范围[0,pi/2]

		// 1.0e-3精度
		static Real FastSinRoughCalculation(Real angle);
		// 1.0e-6精度（float）、1.0e-8精度（double）
		static Real FastSinPreciseCalculation(Real angle);
		// 1.0e-7精度（float）、1.0e-10精度（double）
		static Real FastSinMorePreciseCalculation(Real angle);

		// 输入必须在范围[0,pi/2]

		// 1.0e-2精度
		static Real FastCosRoughCalculation(Real angle);
		// 1.0e-7精度（float）、1.0e-8精度（double）
		static Real FastCosPreciseCalculation(Real angle);
		// 1.0e-7精度（float）、1.0e-10精度（double）
		static Real FastCosMorePreciseCalculation(Real angle);

		// 输入必须在范围[0,pi/4]

		// 1.0e-3精度
		static Real FastTanRoughCalculation(Real angle);
		// 1.0e-7精度
		static Real FastTanPreciseCalculation(Real angle);
		// 1.0e-7精度（float）、1.0e-10精度（double）
		static Real FastTanMorePreciseCalculation(Real angle);

		// 输入必须在范围[0,1]

		// 1.0e-4精度
		static Real FastInvSinRoughCalculation(Real value);
		// 1.0e-6精度（float）、1.0e-7精度（double）
		static Real FastInvSinPreciseCalculation(Real value);

		// 输入必须在范围 [0,1]

		// 1.0e-4精度
		static Real FastInvCosRoughCalculation(Real value);
		// 1.0e-6精度（float）、1.0e-7精度（double）
		static Real FastInvCosPreciseCalculation(Real value);

		// 输入必须在范围 [-1,1]

		// 1.0e-4精度
		static Real FastInvTanRoughCalculation(Real value);
		// 1.0e-7精度
		static Real FastInvTanPreciseCalculation(Real value);
	};

	using FastTrigonometricf = FastTrigonometric<float>;
	using FastTrigonometricd = FastTrigonometric<double>;
}

#endif // MATHEMATICS_BASE_FAST_TRIGONOMETRIC_H
