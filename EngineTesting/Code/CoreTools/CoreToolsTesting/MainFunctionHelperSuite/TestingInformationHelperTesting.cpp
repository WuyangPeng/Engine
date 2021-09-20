// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 17:06)

#include "TestingInformationHelperTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MainFunctionHelper/TestingInformationHelper.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, TestingInformationHelperTesting)

void CoreTools::TestingInformationHelperTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InformationTest);
    ASSERT_THROW_EXCEPTION_0(SuiteExceptionTest);
    ASSERT_THROW_EXCEPTION_0(TestingExceptionTest);
}

void CoreTools::TestingInformationHelperTesting ::InformationTest()
{
    TestingInformationHelper testingInformationHelper{ DisableNotThrow::Disable };

    ASSERT_LESS(0, testingInformationHelper.GetLoopCount("mainFunctionHelperSuite", "TestingInformationHelperTesting"));
}

void CoreTools::TestingInformationHelperTesting ::SuiteExceptionTest()
{
    TestingInformationHelper testingInformationHelper{ DisableNotThrow::Disable };

    ASSERT_LESS(0, testingInformationHelper.GetLoopCount("errorSuite", "errorTesting"));
}

void CoreTools::TestingInformationHelperTesting ::TestingExceptionTest()
{
    TestingInformationHelper testingInformationHelper{ DisableNotThrow::Disable };

    ASSERT_LESS(0, testingInformationHelper.GetLoopCount("mainFunctionHelperSuite", "errorTesting"));
}
