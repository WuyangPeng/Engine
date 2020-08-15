// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.2.2 (2020/01/22 10:45)

#include "CoreTools/CoreToolsExport.h"

#include "Fibonacci.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

uint32_t CoreTools
	::RecursiveFibonacci(uint32_t integer) noexcept
{
	if (integer <= 1)
		return integer;

	return RecursiveFibonacci(integer - 1) + RecursiveFibonacci(integer - 2);
}

uint32_t CoreTools
	::NonRecursiveFibonacci(uint32_t integer)  
{
	auto previous = -1;
	auto result = 1;
	for (auto i = 0u; i <= integer; ++i)
	{
		const auto sum = result + previous;
		previous = result;
		result = sum;
	}

	return boost::numeric_cast<uint32_t>(result);
}
