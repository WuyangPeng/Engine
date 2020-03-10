// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 10:35)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_FIBONACCI_H
#define CORE_TOOLS_TEMPLATE_TOOLS_FIBONACCI_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
	template<unsigned N>
	struct Fibonacci
	{
		enum
		{
			Value = Fibonacci<N - 1>::Value + Fibonacci<N - 2>::Value
		};
	};

	template<>
	struct Fibonacci<0>
	{
		enum
		{
			Value = 0
		};
	};

	template<>
	struct Fibonacci<1>
	{
		enum
		{
			Value = 1
		};
	};

	uint32_t CORE_TOOLS_DEFAULT_DECLARE RecursiveFibonacci(uint32_t integer) noexcept;
	uint32_t CORE_TOOLS_DEFAULT_DECLARE NonRecursiveFibonacci(uint32_t integer) noexcept;
}

#define FIBONACCI( n ) CoreTools::Fibonacci< n >::Value

#endif // CORE_TOOLS_TEMPLATE_TOOLS_FIBONACCI_H
