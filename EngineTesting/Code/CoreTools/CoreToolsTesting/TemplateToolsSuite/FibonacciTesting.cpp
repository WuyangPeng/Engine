// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 16:04)

#include "FibonacciTesting.h"
#include "CoreTools/TemplateTools/Fibonacci.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, FibonacciTesting)

void CoreTools::FibonacciTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(RecursiveVsNonrecursiveTest);
	ASSERT_NOT_THROW_EXCEPTION_0(TemplateVersionTest);
}

void CoreTools::FibonacciTesting
	::RecursiveVsNonrecursiveTest()
{
	for (auto i = 0; i < 10; ++i)
	{
		ASSERT_EQUAL(RecursiveFibonacci(i), NonRecursiveFibonacci(i));
	}
}

void CoreTools::FibonacciTesting
	::TemplateVersionTest()
{
	ASSERT_TRUE(FIBONACCI(0) == NonRecursiveFibonacci(0));
	ASSERT_TRUE(FIBONACCI(1) == NonRecursiveFibonacci(1));
	ASSERT_TRUE(FIBONACCI(2) == NonRecursiveFibonacci(2));
	ASSERT_TRUE(FIBONACCI(3) == NonRecursiveFibonacci(3));
	ASSERT_TRUE(FIBONACCI(4) == NonRecursiveFibonacci(4));
	ASSERT_TRUE(FIBONACCI(5) == NonRecursiveFibonacci(5));
	ASSERT_TRUE(FIBONACCI(6) == NonRecursiveFibonacci(6));
	ASSERT_TRUE(FIBONACCI(7) == NonRecursiveFibonacci(7));
	ASSERT_TRUE(FIBONACCI(8) == NonRecursiveFibonacci(8));
	ASSERT_TRUE(FIBONACCI(9) == NonRecursiveFibonacci(9));
}



