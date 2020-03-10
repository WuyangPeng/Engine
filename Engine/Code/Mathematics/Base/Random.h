// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/03 19:32)

#ifndef MATHEMATICS_BASE_RANDOM_H
#define MATHEMATICS_BASE_RANDOM_H

#include "Mathematics/MathematicsDll.h"

#include <boost/type_traits/is_floating_point.hpp>
#include <boost/static_assert.hpp>

namespace Mathematics
{	
	template <typename Real>
	class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Random
	{
	public:
		BOOST_STATIC_ASSERT((boost::is_floating_point<Real>::value));

		using ClassType = Random<Real>;
	
	public:   
		// ������Χ��[0,1]���������
		// ���������������ͨ������UnitRandom������һ�����������ӡ�
		static Real UnitRandom (uint32_t seed = 0);
    
		// ������Χ��[-1,1]���������
		// ���������������ͨ������UnitRandom������һ�����������ӡ�
		static Real SymmetricRandom (uint32_t seed = 0);
		
		// ������Χ��[min,max]���������
		// ���������������ͨ������UnitRandom������һ�����������ӡ�
		static Real IntervalRandom (Real min, Real max, uint32_t seed = 0);
	};

	using Randomf = Random<float>;
	using Randomd = Random<double>;
}

#endif // MATHEMATICS_BASE_RANDOM_H
