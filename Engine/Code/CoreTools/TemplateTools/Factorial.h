// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 10:34)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_FACTORIAL_H
#define CORE_TOOLS_TEMPLATE_TOOLS_FACTORIAL_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
	template<unsigned N>
	struct Factorial
	{
		enum
		{
			Value = N * Factorial<N - 1>::Value
		};
	};

	template<>
	struct Factorial<0>
	{
		enum
		{
			Value = 1
		};
	};

	template<>
	struct Factorial<1>
	{
		enum
		{
			Value = 1
		};
	};

	uint32_t CORE_TOOLS_DEFAULT_DECLARE RecursiveFactorial(uint32_t integer) noexcept;
	constexpr uint32_t NonRecursiveFactorial(uint32_t integer) noexcept
	{
		auto result = 1u;

		for (auto index = 1u; index <= integer; ++index)
		{
			result *= index;
		}

		return result;
	}
}

#define FACTORIAL( n ) CoreTools::Factorial< n >::Value

#endif // CORE_TOOLS_TEMPLATE_TOOLS_FACTORIAL_H
