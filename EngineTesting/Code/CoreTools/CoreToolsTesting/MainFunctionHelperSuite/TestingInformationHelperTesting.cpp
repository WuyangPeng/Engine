///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/13 11:20)

#include "TestingInformationHelperTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MainFunctionHelper/TestingInformationHelper.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::TestingInformationHelperTesting::TestingInformationHelperTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, TestingInformationHelperTesting)

void CoreTools::TestingInformationHelperTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}
void CoreTools::TestingInformationHelperTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InformationTest);
    ASSERT_THROW_EXCEPTION_0(SuiteExceptionTest);
    ASSERT_THROW_EXCEPTION_0(TestingExceptionTest);
}

void CoreTools::TestingInformationHelperTesting::InformationTest()
{
    const auto testingInformationHelper = TestingInformationHelper::Create();

    ASSERT_LESS(0, testingInformationHelper.GetLoopCount("mainFunctionHelperSuite", "TestingInformationHelperTesting"));
}

void CoreTools::TestingInformationHelperTesting::SuiteExceptionTest()
{
    const auto testingInformationHelper = TestingInformationHelper::Create();

    ASSERT_LESS(0, testingInformationHelper.GetLoopCount("errorSuite", "errorTesting"));
}

void CoreTools::TestingInformationHelperTesting::TestingExceptionTest()
{
    const auto testingInformationHelper = TestingInformationHelper::Create();

    ASSERT_LESS(0, testingInformationHelper.GetLoopCount("mainFunctionHelperSuite", "errorTesting"));
}
