// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/04 09:54)

#ifndef MATHEMATICS_ALGEBRA_ALGEBRA_TRAITS_H
#define MATHEMATICS_ALGEBRA_ALGEBRA_TRAITS_H

namespace Mathematics
{	
	template<typename Traits>
	struct AlgebraTraits
	{
		enum
		{
			NullValue = 0,
			UnitValue = 1,
		};		
	};		
}

#endif // MATHEMATICS_ALGEBRA_ALGEBRA_TRAITS_H
