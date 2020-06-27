// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/18 19:08)

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
		// ���ö���ʽ�ƽ����Ǻ����ͷ����Ǻ����Ŀ��ټ��㡣�ٶ����������������

		// ��������ڷ�Χ[0,pi/2]

		// 1.0e-3����
		static Real FastSinRoughCalculation(Real angle);
		// 1.0e-6���ȣ�float����1.0e-8���ȣ�double��
		static Real FastSinPreciseCalculation(Real angle);
		// 1.0e-7���ȣ�float����1.0e-10���ȣ�double��
		static Real FastSinMorePreciseCalculation(Real angle);

		// ��������ڷ�Χ[0,pi/2]

		// 1.0e-2����
		static Real FastCosRoughCalculation(Real angle);
		// 1.0e-7���ȣ�float����1.0e-8���ȣ�double��
		static Real FastCosPreciseCalculation(Real angle);
		// 1.0e-7���ȣ�float����1.0e-10���ȣ�double��
		static Real FastCosMorePreciseCalculation(Real angle);

		// ��������ڷ�Χ[0,pi/4]

		// 1.0e-3����
		static Real FastTanRoughCalculation(Real angle);
		// 1.0e-7����
		static Real FastTanPreciseCalculation(Real angle);
		// 1.0e-7���ȣ�float����1.0e-10���ȣ�double��
		static Real FastTanMorePreciseCalculation(Real angle);

		// ��������ڷ�Χ[0,1]

		// 1.0e-4����
		static Real FastInvSinRoughCalculation(Real value);
		// 1.0e-6���ȣ�float����1.0e-7���ȣ�double��
		static Real FastInvSinPreciseCalculation(Real value);

		// ��������ڷ�Χ [0,1]

		// 1.0e-4����
		static Real FastInvCosRoughCalculation(Real value);
		// 1.0e-6���ȣ�float����1.0e-7���ȣ�double��
		static Real FastInvCosPreciseCalculation(Real value);

		// ��������ڷ�Χ [-1,1]

		// 1.0e-4����
		static Real FastInvTanRoughCalculation(Real value);
		// 1.0e-7����
		static Real FastInvTanPreciseCalculation(Real value);
	};

	using FastTrigonometricf = FastTrigonometric<float>;
	using FastTrigonometricd = FastTrigonometric<double>;
}

#endif // MATHEMATICS_BASE_FAST_TRIGONOMETRIC_H
