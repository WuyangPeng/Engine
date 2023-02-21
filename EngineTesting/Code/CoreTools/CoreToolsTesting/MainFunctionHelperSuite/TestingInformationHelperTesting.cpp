///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 18:56)

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
    auto testingInformationHelper = TestingInformationHelper::Create();

    ASSERT_LESS(0, testingInformationHelper.GetLoopCount("mainFunctionHelperSuite", "TestingInformationHelperTesting"));
}

void CoreTools::TestingInformationHelperTesting::SuiteExceptionTest()
{
    auto testingInformationHelper = TestingInformationHelper::Create();

    ASSERT_LESS(0, testingInformationHelper.GetLoopCount("errorSuite", "errorTesting"));
}

void CoreTools::TestingInformationHelperTesting::TestingExceptionTest()
{
    auto testingInformationHelper = TestingInformationHelper::Create();

    ASSERT_LESS(0, testingInformationHelper.GetLoopCount("mainFunctionHelperSuite", "errorTesting"));
}
