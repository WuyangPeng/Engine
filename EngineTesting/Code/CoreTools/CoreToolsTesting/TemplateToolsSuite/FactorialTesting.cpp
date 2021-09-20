// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 16:04)

#include "FactorialTesting.h"
#include "CoreTools/TemplateTools/Factorial.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, FactorialTesting)

void CoreTools::FactorialTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(RecursiveVsNonrecursiveTest);
	ASSERT_NOT_THROW_EXCEPTION_0(TemplateVersionTest);
}

void CoreTools::FactorialTesting
	::RecursiveVsNonrecursiveTest()
{
	for (auto index = 0; index < 10; ++index)
	{
		ASSERT_EQUAL(RecursiveFactorial(index), NonRecursiveFactorial(index));
	}
}

void CoreTools::FactorialTesting
	::TemplateVersionTest()
{
	ASSERT_TRUE(FACTORIAL(0) == NonRecursiveFactorial(0));
	ASSERT_TRUE(FACTORIAL(1) == NonRecursiveFactorial(1));
	ASSERT_TRUE(FACTORIAL(2) == NonRecursiveFactorial(2));
	ASSERT_TRUE(FACTORIAL(3) == NonRecursiveFactorial(3));
	ASSERT_TRUE(FACTORIAL(4) == NonRecursiveFactorial(4));
	ASSERT_TRUE(FACTORIAL(5) == NonRecursiveFactorial(5));
	ASSERT_TRUE(FACTORIAL(6) == NonRecursiveFactorial(6));
	ASSERT_TRUE(FACTORIAL(7) == NonRecursiveFactorial(7));
	ASSERT_TRUE(FACTORIAL(8) == NonRecursiveFactorial(8));
	ASSERT_TRUE(FACTORIAL(9) == NonRecursiveFactorial(9));
}



