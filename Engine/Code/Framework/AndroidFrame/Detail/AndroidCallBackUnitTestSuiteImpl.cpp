///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/10 09:38)

#include "Framework/FrameworkExport.h"

#include "AndroidCallBackUnitTestSuiteImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/UnitTestSuite/Suite.h"
#include "CoreTools/UnitTestSuite/UnitTestComposite.h"
#include "Framework/WindowProcess/Detail/WindowMessageUnitTestSuiteStream.h"

Framework::AndroidCallBackUnitTestSuiteImpl::AndroidCallBackUnitTestSuiteImpl(const std::string& name)
    : stream{ std::make_shared<WindowMessageUnitTestSuiteStream>(true) },
      testingInformationHelper{ CoreTools::TestingInformationHelper::Create() },
      suite{ std::make_shared<Suite>(name, stream->GetStreamShared(), testingInformationHelper.IsPrintRun()) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Framework::AndroidCallBackUnitTestSuiteImpl::IsValid() const noexcept
{
    if (stream != nullptr && suite != nullptr)
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

void Framework::AndroidCallBackUnitTestSuiteImpl::AddTest(const std::string& suiteName, Suite& aSuite, const std::string& testName, const UnitTestSharedPtr& unitTest)
{
    EXCEPTION_TRY
    {
        DoAddTest(suiteName, aSuite, testName, unitTest);
    }
    EXCEPTION_ENGINE_EXCEPTION_CATCH(Framework)
}

void Framework::AndroidCallBackUnitTestSuiteImpl::DoAddTest(const std::string& suiteName, Suite& aSuite, const std::string& testName, const UnitTestSharedPtr& unitTest)
{
    if (const auto testLoopCount = testingInformationHelper.GetLoopCount(suiteName, testName);
        0 < testLoopCount)
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

bool Framework::AndroidCallBackUnitTestSuiteImpl::IsPrintRun() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return testingInformationHelper.IsPrintRun();
}

CoreTools::OStreamShared Framework::AndroidCallBackUnitTestSuiteImpl::GetStreamShared() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return stream->GetStreamShared();
}
