///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/13 14:08)

#include "Framework/FrameworkExport.h"

#include "WindowMessageUnitTestSuiteImpl.h"
#include "System/Windows/Flags/WindowsKeyCodesFlags.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/UnitTestSuite/Suite.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

using namespace std::literals;

Framework::WindowMessageUnitTestSuiteImpl::WindowMessageUnitTestSuiteImpl(const std::string& name, const OStreamShared& streamShared)
    : alloc{ ConsoleAlloc::Create() },
      testingInformationHelper{ CoreTools::TestingInformationHelper::Create() },
      windowSuite{ make_unique<Suite>(name, streamShared, testingInformationHelper.IsPrintRun()) },
      process{ { System::WindowsKeyCodes::F1, &ClassType::ResetTestDataOnMessage },
               { System::WindowsKeyCodes::F5, &ClassType::RunUnitTestOnMessage } }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Framework::WindowMessageUnitTestSuiteImpl::IsValid() const noexcept
{
    if (windowSuite != nullptr)
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

    const auto iter = process.find(windowsKeyCodes);
    if (iter != process.cend())
    {
        (this->*(iter->second))();
    }
}

void Framework::WindowMessageUnitTestSuiteImpl::AddTest(const std::string& suiteName, Suite& suite, const std::string& testName, const UnitTestSharedPtr& unitTest)
{
    const auto testLoopCount = testingInformationHelper.GetLoopCount(suiteName, testName);

    if (0 < testLoopCount)
    {
        unitTest->SetTestLoopCount(testLoopCount);
        unitTest->SetRandomSeed(testingInformationHelper.GetRandomSeed());
        suite.AddTest(unitTest);
    }
    else if (testLoopCount < 0)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn,
                                      CoreTools,
                                      SYSTEM_TEXT("����"s),
                                      testName,
                                      SYSTEM_TEXT("δ���ã��ڲ����׼���"s),
                                      suite.GetName(),
                                      SYSTEM_TEXT("��"s),
                                      CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

// private
void Framework::WindowMessageUnitTestSuiteImpl::ResetTestDataOnMessage()
{
    ResetTestData();
    windowSuite->GetStream() << "�������������㡣\n";
}
