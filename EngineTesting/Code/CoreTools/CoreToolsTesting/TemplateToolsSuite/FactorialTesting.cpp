/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 12:35)

#include "FactorialTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TemplateTools/Factorial.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::FactorialTesting::FactorialTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, FactorialTesting)

void CoreTools::FactorialTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::FactorialTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RecursiveVsNonRecursiveTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TemplateVersionTest);
}

void CoreTools::FactorialTesting::RecursiveVsNonRecursiveTest()
{
    for (auto index = 0; index < 10; ++index)
    {
        ASSERT_EQUAL(RecursiveFactorial(index), NonRecursiveFactorial(index));
    }
}

void CoreTools::FactorialTesting::TemplateVersionTest()
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
