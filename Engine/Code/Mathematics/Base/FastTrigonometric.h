// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/03 19:21)

#ifndef MATHEMATICS_BASE_FAST_TRIGONOMETRIC_H
#define MATHEMATICS_BASE_FAST_TRIGONOMETRIC_H

#include "Mathematics/MathematicsDll.h"

#include <boost/type_traits/is_floating_point.hpp>
#include <boost/static_assert.hpp>

namespace Mathematics
{	
	template <typename Real>
	class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE FastTrigonometric
	{
	public:
		BOOST_STATIC_ASSERT((boost::is_floating_point<Real>::value));

		using ClassType = FastTrigonometric<Real>;
	
	public:   
		// ���ö���ʽ�ƽ����Ǻ����ͷ����Ǻ����Ŀ��ټ��㡣�ٶ����������������
		
		// ��������ڷ�Χ[0,pi/2]

		// 1.0e-3����
		static Real FastSinRoughCalculation (Real angle); 
		// 1.0e-6���ȣ�float����1.0e-8���ȣ�double��
		static Real FastSinPreciseCalculation (Real angle); 
		// 1.0e-7���ȣ�float����1.0e-10���ȣ�double��
		static Real FastSinMorePreciseCalculation (Real angle);
		
		// ��������ڷ�Χ[0,pi/2]

		// 1.0e-2����
		static Real FastCosRoughCalculation (Real angle);
		// 1.0e-7���ȣ�float����1.0e-8���ȣ�double��
		static Real FastCosPreciseCalculation (Real angle);
		// 1.0e-7���ȣ�float����1.0e-10���ȣ�double��
		static Real FastCosMorePreciseCalculation (Real angle);
		
		// ��������ڷ�Χ[0,pi/4]

		// 1.0e-3����
		static Real FastTanRoughCalculation (Real angle);
		// 1.0e-7����
        static Real FastTanPreciseCalculation (Real angle);
		// 1.0e-7���ȣ�float����1.0e-10���ȣ�double��
		static Real FastTanMorePreciseCalculation (Real angle);
		
		// ��������ڷ�Χ[0,1]

		// 1.0e-4����
		static Real FastInvSinRoughCalculation (Real value);
		// 1.0e-6���ȣ�float����1.0e-7���ȣ�double��
		static Real FastInvSinPreciseCalculation (Real value);
		
		// ��������ڷ�Χ [0,1]

		// 1.0e-4����
		static Real FastInvCosRoughCalculation (Real value);
		// 1.0e-6���ȣ�float����1.0e-7���ȣ�double��
		static Real FastInvCosPreciseCalculation (Real value);
		
		// ��������ڷ�Χ [-1,1]

		// 1.0e-4����
		static Real FastInvTanRoughCalculation (Real value);
		// 1.0e-7����
		static Real FastInvTanPreciseCalculation (Real value);		
	};

	using FastTrigonometricf = FastTrigonometric<float>;
	using FastTrigonometricd = FastTrigonometric<double>;
}

#endif // MATHEMATICS_BASE_FAST_TRIGONOMETRIC_H
