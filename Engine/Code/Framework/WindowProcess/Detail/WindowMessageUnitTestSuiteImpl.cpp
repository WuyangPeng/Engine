///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/04 14:59)

#include "Framework/FrameworkExport.h"

#include "WindowMessageUnitTestSuiteImpl.h"
#include "System/Windows/Flags/WindowsKeyCodesFlags.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/UnitTestSuite/Suite.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

Framework::WindowMessageUnitTestSuiteImpl::WindowMessageUnitTestSuiteImpl(const std::string& name)
    : stream{ std::make_unique<WindowMessageUnitTestSuiteStream>(true) },
      alloc{ ConsoleAlloc::Create() },
      testingInformationHelper{ TestingInformationHelper::Create() },
      windowSuite{ make_unique<Suite>(name, stream->GetStreamShared(), testingInformationHelper.IsPrintRun()) },
      process{ { System::WindowsKeyCodes::F1, &ClassType::ResetTestDataOnMessage },
               { System::WindowsKeyCodes::F5, &ClassType::RunUnitTestOnMessage } }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Framework::WindowMessageUnitTestSuiteImpl::IsValid() const noexcept
{
    if (stream != nullptr && windowSuite != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

bool Framework::WindowMessageUnitTestSuiteImpl::IsPrintRun() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return testingInformationHelper.IsPrintRun();
}

int Framework::WindowMessageUnitTestSuiteImpl::GetPassedNumber() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return windowSuite->GetPassedNumber();
}

void Framework::WindowMessageUnitTestSuiteImpl::RunUnitTest()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    windowSuite->RunUnitTest();
}

void Framework::WindowMessageUnitTestSuiteImpl::PrintReport()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    windowSuite->PrintReport();
}

void Framework::WindowMessageUnitTestSuiteImpl::ResetTestData()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    windowSuite->ResetTestData();
}

void Framework::WindowMessageUnitTestSuiteImpl::RunUnitTestOnMessage()
{
    RunUnitTest();
    PrintReport();
}

void Framework::WindowMessageUnitTestSuiteImpl::AddSuite(const Suite& suite)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    windowSuite->AddSuite(suite);
}

void Framework::WindowMessageUnitTestSuiteImpl::KeyDownMessage(System::WindowsKeyCodes windowsKeyCodes)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (const auto iter = process.find(windowsKeyCodes);
        iter != process.cend())
    {
        (this->*(iter->second))();
    }
}

void Framework::WindowMessageUnitTestSuiteImpl::AddTest(const std::string& suiteName, Suite& suite, const std::string& testName, const UnitTestSharedPtr& unitTest)
{
    if (const auto testLoopCount = testingInformationHelper.GetLoopCount(suiteName, testName);
        0 < testLoopCount)
    {
        unitTest->SetTestLoopCount(testLoopCount);
        unitTest->SetRandomSeed(testingInformationHelper.GetRandomSeed());

        suite.AddTest(unitTest);
    }
    else if (testLoopCount < 0)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn,
                                      CoreTools,
                                      SYSTEM_TEXT("����"),
                                      testName,
                                      SYSTEM_TEXT("δ���ã��ڲ����׼���"),
                                      suite.GetName(),
                                      SYSTEM_TEXT("��"),
                                      CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

Framework::WindowMessageUnitTestSuiteImpl::OStreamShared Framework::WindowMessageUnitTestSuiteImpl::GetStreamShared() noexcept
{
    return stream->GetStreamShared();
}

void Framework::WindowMessageUnitTestSuiteImpl::ResetTestDataOnMessage()
{
    ResetTestData();

    windowSuite->GetStream() << "�������������㡣\n";
}
