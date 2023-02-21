///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
///	¡™œµ◊˜’ﬂ£∫94458936@qq.com
///
///	±Í◊º£∫std:c++20
///	“˝«Ê≤‚ ‘∞Ê±æ£∫0.9.0.2 (2023/02/05 21:35)

#include "AssertNotThrowExceptionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::AssertNotThrowExceptionTesting::AssertNotThrowExceptionTesting(const OStreamShared& stream)
    : ParentType{ stream },
      parameter0{ 1 },
      parameter1{ 2 },
      parameter2{ 3 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, AssertNotThrowExceptionTesting)

void CoreTools::AssertNotThrowExceptionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::AssertNotThrowExceptionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AssertExceptionMacroTest);
}

void CoreTools::AssertNotThrowExceptionTesting::AssertExceptionMacroTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AssertNotThrowExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_1(AssertNotThrowExceptionTestWithParameter, parameter0);
    ASSERT_NOT_THROW_EXCEPTION_2(AssertNotThrowExceptionTestWith2Parameter, parameter0, parameter1);
    ASSERT_NOT_THROW_EXCEPTION_3(AssertNotThrowExceptionTestWith3Parameter, parameter0, parameter1, parameter2);

    ASSERT_NOT_THROW_EXCEPTION_USE_MESSAGE_0(AssertNotThrowExceptionTest, "≤‚ ‘AssertExceptionMacro");
    ASSERT_NOT_THROW_EXCEPTION_USE_MESSAGE_1(AssertNotThrowExceptionTestWithParameter, parameter0, "≤‚ ‘AssertExceptionMacro");
    ASSERT_NOT_THROW_EXCEPTION_USE_MESSAGE_2(AssertNotThrowExceptionTestWith2Parameter, parameter0, parameter1, "≤‚ ‘AssertExceptionMacro");
    ASSERT_NOT_THROW_EXCEPTION_USE_MESSAGE_3(AssertNotThrowExceptionTestWith3Parameter, parameter0, parameter1, parameter2, "≤‚ ‘AssertExceptionMacro");
}

void CoreTools::AssertNotThrowExceptionTesting::AssertNotThrowExceptionTest() noexcept
{
}

void CoreTools::AssertNotThrowExceptionTesting::AssertNotThrowExceptionTestWithParameter(int aParameter)
{
    ASSERT_EQUAL(aParameter, parameter0);
}

void CoreTools::AssertNotThrowExceptionTesting::AssertNotThrowExceptionTestWith2Parameter(int aParameter0, int aParameter1)
{
    ASSERT_EQUAL(aParameter0, parameter0);
    ASSERT_EQUAL(aParameter1, parameter1);
}

void CoreTools::AssertNotThrowExceptionTesting::AssertNotThrowExceptionTestWith3Parameter(int aParameter0, int aParameter1, int aParameter2)
{
    ASSERT_EQUAL(aParameter0, parameter0);
    ASSERT_EQUAL(aParameter1, parameter1);
    ASSERT_EQUAL(aParameter2, parameter2);
}
