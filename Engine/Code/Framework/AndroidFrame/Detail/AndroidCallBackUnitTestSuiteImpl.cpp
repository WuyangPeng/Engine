///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/05 18:41)

#include "Framework/FrameworkExport.h"

#include "AndroidCallBackUnitTestSuiteImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/UnitTestSuite/Suite.h"
#include "CoreTools/UnitTestSuite/UnitTestComposite.h"

using std::make_shared;
using std::string;

Framework::AndroidCallBackUnitTestSuiteImpl::AndroidCallBackUnitTestSuiteImpl(const string& name, const OStreamShared& streamShared)
    : testingInformationHelper{ CoreTools::TestingInformationHelper::Create() }, suite{ make_shared<Suite>(name, streamShared, testingInformationHelper.IsPrintRun()) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Framework::AndroidCallBackUnitTestSuiteImpl::IsValid() const noexcept
{
    if (suite != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void Framework::AndroidCallBackUnitTestSuiteImpl::AddSuite(const Suite& aSuite)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    suite->AddSuite(aSuite);
}

void Framework::AndroidCallBackUnitTestSuiteImpl::RunUnitTest()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    suite->RunUnitTest();
}

void Framework::AndroidCallBackUnitTestSuiteImpl::PrintReport()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    suite->PrintReport();
}

void Framework::AndroidCallBackUnitTestSuiteImpl::ResetTestData()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    suite->ResetTestData();
}

int Framework::AndroidCallBackUnitTestSuiteImpl::GetPassedNumber() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return suite->GetPassedNumber();
}

void Framework::AndroidCallBackUnitTestSuiteImpl::AddTest(const string& suiteName, Suite& aSuite, const string& testName, const UnitTestSharedPtr& unitTest)
{
    try
    {
        const auto testLoopCount = testingInformationHelper.GetLoopCount(suiteName, testName);

        if (0 < testLoopCount)
        {
            unitTest->SetTestLoopCount(testLoopCount);
            unitTest->SetRandomSeed(testingInformationHelper.GetRandomSeed());
            aSuite.AddTest(unitTest);
        }
        else if (testLoopCount < 0)
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools, SYSTEM_TEXT("测试"), testName, SYSTEM_TEXT("未配置！在测试套件："), aSuite.GetName(), SYSTEM_TEXT("。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
        }
    }
    catch (const CoreTools::Error& error)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools, error, CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

bool Framework::AndroidCallBackUnitTestSuiteImpl::IsPrintRun() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return testingInformationHelper.IsPrintRun();
}
