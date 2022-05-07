///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 16:42)

#include "Framework/FrameworkExport.h"

#include "WindowMessageUnitTestSuiteImpl.h"
#include "System/Windows/Flags/WindowsKeyCodesFlags.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/UnitTestSuite/Suite.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

using std::make_unique;
using std::string;
using namespace std::literals;

Framework::WindowMessageUnitTestSuiteImpl::WindowMessageUnitTestSuiteImpl(const string& name, const OStreamShared& streamShared)
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

void Framework::WindowMessageUnitTestSuiteImpl::AddTest(const string& suiteName, Suite& suite, const string& testName, const UnitTestSharedPtr& unitTest)
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
        LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
            << SYSTEM_TEXT("测试"s)
            << testName
            << SYSTEM_TEXT("未配置！在测试套件："s)
            << suite.GetName()
            << SYSTEM_TEXT("。"s)
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}

// private
void Framework::WindowMessageUnitTestSuiteImpl::ResetTestDataOnMessage()
{
    ResetTestData();
    windowSuite->GetStream() << "测试数据已清零。\n";
}
