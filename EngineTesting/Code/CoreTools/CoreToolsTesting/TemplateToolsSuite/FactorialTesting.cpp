/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.10 (2024/05/29 20:22)

#include "FactorialTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
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
    ASSERT_EQUAL(FACTORIAL(0), boost::numeric_cast<int>(NonRecursiveFactorial(0)));
    ASSERT_EQUAL(FACTORIAL(1), boost::numeric_cast<int>(NonRecursiveFactorial(1)));
    ASSERT_EQUAL(FACTORIAL(2), boost::numeric_cast<int>(NonRecursiveFactorial(2)));
    ASSERT_EQUAL(FACTORIAL(3), boost::numeric_cast<int>(NonRecursiveFactorial(3)));
    ASSERT_EQUAL(FACTORIAL(4), boost::numeric_cast<int>(NonRecursiveFactorial(4)));
    ASSERT_EQUAL(FACTORIAL(5), boost::numeric_cast<int>(NonRecursiveFactorial(5)));
    ASSERT_EQUAL(FACTORIAL(6), boost::numeric_cast<int>(NonRecursiveFactorial(6)));
    ASSERT_EQUAL(FACTORIAL(7), boost::numeric_cast<int>(NonRecursiveFactorial(7)));
    ASSERT_EQUAL(FACTORIAL(8), boost::numeric_cast<int>(NonRecursiveFactorial(8)));
    ASSERT_EQUAL(FACTORIAL(9), boost::numeric_cast<int>(NonRecursiveFactorial(9)));
}
