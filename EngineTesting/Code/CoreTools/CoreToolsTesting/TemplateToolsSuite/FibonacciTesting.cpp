/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.10 (2024/05/29 20:22)

#include "FibonacciTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TemplateTools/Fibonacci.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::FibonacciTesting::FibonacciTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, FibonacciTesting)

void CoreTools::FibonacciTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::FibonacciTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RecursiveVsNonRecursiveTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TemplateVersionTest);
}

void CoreTools::FibonacciTesting::RecursiveVsNonRecursiveTest()
{
    for (auto i = 0; i < 10; ++i)
    {
        ASSERT_EQUAL(RecursiveFibonacci(i), NonRecursiveFibonacci(i));
    }
}

void CoreTools::FibonacciTesting::TemplateVersionTest()
{
    ASSERT_EQUAL(FIBONACCI(0), boost::numeric_cast<int>(NonRecursiveFibonacci(0)));
    ASSERT_EQUAL(FIBONACCI(1), boost::numeric_cast<int>(NonRecursiveFibonacci(1)));
    ASSERT_EQUAL(FIBONACCI(2), boost::numeric_cast<int>(NonRecursiveFibonacci(2)));
    ASSERT_EQUAL(FIBONACCI(3), boost::numeric_cast<int>(NonRecursiveFibonacci(3)));
    ASSERT_EQUAL(FIBONACCI(4), boost::numeric_cast<int>(NonRecursiveFibonacci(4)));
    ASSERT_EQUAL(FIBONACCI(5), boost::numeric_cast<int>(NonRecursiveFibonacci(5)));
    ASSERT_EQUAL(FIBONACCI(6), boost::numeric_cast<int>(NonRecursiveFibonacci(6)));
    ASSERT_EQUAL(FIBONACCI(7), boost::numeric_cast<int>(NonRecursiveFibonacci(7)));
    ASSERT_EQUAL(FIBONACCI(8), boost::numeric_cast<int>(NonRecursiveFibonacci(8)));
    ASSERT_EQUAL(FIBONACCI(9), boost::numeric_cast<int>(NonRecursiveFibonacci(9)));
}
