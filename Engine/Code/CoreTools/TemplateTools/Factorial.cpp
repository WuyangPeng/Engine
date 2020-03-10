// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.2.2 (2020/01/22 10:45)

#include "CoreTools/CoreToolsExport.h"

#include "Factorial.h"

uint32_t CoreTools
	::RecursiveFactorial(uint32_t integer) noexcept
{
	return ((integer <= 1) ? 1 : (integer * RecursiveFactorial(integer - 1)));
}

uint32_t CoreTools
	::NonRecursiveFactorial(uint32_t integer) noexcept
{
	auto result = 1u;

	for (auto index = 1u; index <= integer; ++index)
	{
		result *= index;
	}

	return result;
}
