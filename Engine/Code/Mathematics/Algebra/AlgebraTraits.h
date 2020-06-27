// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 10:04)

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
