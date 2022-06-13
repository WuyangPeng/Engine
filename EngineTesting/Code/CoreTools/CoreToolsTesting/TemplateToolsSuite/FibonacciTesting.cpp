///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 19:02)

#include "FibonacciTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/TemplateTools/Fibonacci.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, FibonacciTesting)

void CoreTools::FibonacciTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RecursiveVsNonrecursiveTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TemplateVersionTest);
}

void CoreTools::FibonacciTesting::RecursiveVsNonrecursiveTest()
{
    for (auto i = 0; i < 10; ++i)
    {
        ASSERT_EQUAL(RecursiveFibonacci(i), NonRecursiveFibonacci(i));
    }
}

void CoreTools::FibonacciTesting::TemplateVersionTest()
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
