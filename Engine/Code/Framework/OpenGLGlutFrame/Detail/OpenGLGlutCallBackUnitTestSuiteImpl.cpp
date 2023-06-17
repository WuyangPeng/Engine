///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:17)

#include "Framework/FrameworkExport.h"

#include "OpenGLGlutCallBackUnitTestSuiteImpl.h"
#include "System/Windows/Flags/WindowsKeyCodesFlags.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/UnitTestSuite/Suite.h"
#include "CoreTools/UnitTestSuite/UnitTestComposite.h"

Framework::OpenGLGlutCallBackUnitTestSuiteImpl::OpenGLGlutCallBackUnitTestSuiteImpl(const std::string& name, const OStreamShared& streamShared)
    : testingInformationHelper{ CoreTools::TestingInformationHelper::Create() },
      openglSuite{ std::make_shared<Suite>(name, streamShared, testingInformationHelper.IsPrintRun()) },
      process{ { System::WindowsKeyCodes::F1, &ClassType::ResetTestDataOnMessage },
               { System::WindowsKeyCodes::F5, &ClassType::RunUnitTestOnMessage } }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Framework::OpenGLGlutCallBackUnitTestSuiteImpl::IsValid() const noexcept
{
    if (openglSuite != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void Framework::OpenGLGlutCallBackUnitTestSuiteImpl::AddSuite(const Suite& suite)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    openglSuite->AddSuite(suite);
}

void Framework::OpenGLGlutCallBackUnitTestSuiteImpl::RunUnitTest()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    openglSuite->RunUnitTest();
}

void Framework::OpenGLGlutCallBackUnitTestSuiteImpl::PrintReport()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    openglSuite->PrintReport();
}

void Framework::OpenGLGlutCallBackUnitTestSuiteImpl::ResetTestData()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    openglSuite->ResetTestData();
}

int Framework::OpenGLGlutCallBackUnitTestSuiteImpl::GetPassedNumber() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return openglSuite->GetPassedNumber();
}

void Framework::OpenGLGlutCallBackUnitTestSuiteImpl::AddTest(const std::string& suiteName, Suite& suite, const std::string& testName, const UnitTestSharedPtr& unitTest)
{
    try
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
            LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools,
                                          SYSTEM_TEXT("测试"),
                                          testName,
                                          SYSTEM_TEXT("未配置！在测试套件："),
                                          suite.GetName(),
                                          SYSTEM_TEXT("。"),
                                          CoreTools::LogAppenderIOManageSign::TriggerAssert);
        }
    }
    catch (const CoreTools::Error& error)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools, error, CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

void Framework::OpenGLGlutCallBackUnitTestSuiteImpl::KeyDownMessage(WindowsKeyCodes windowsKeyCodes)
{
    const auto iter = process.find(windowsKeyCodes);
    if (iter != process.cend())
    {
        (this->*(iter->second))();
    }
}

bool Framework::OpenGLGlutCallBackUnitTestSuiteImpl::IsPrintRun() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return testingInformationHelper.IsPrintRun();
}

// private
void Framework::OpenGLGlutCallBackUnitTestSuiteImpl::RunUnitTestOnMessage()
{
    RunUnitTest();
    PrintReport();
}

// private
void Framework::OpenGLGlutCallBackUnitTestSuiteImpl::ResetTestDataOnMessage()
{
    ResetTestData();
    openglSuite->GetStream() << "测试数据已清零。\n";
}