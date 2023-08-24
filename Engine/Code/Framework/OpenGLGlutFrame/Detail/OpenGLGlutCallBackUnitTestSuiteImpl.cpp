///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/05 13:48)

#include "Framework/FrameworkExport.h"

#include "OpenGLGlutCallBackUnitTestSuiteImpl.h"
#include "System/Windows/Flags/WindowsKeyCodesFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/UnitTestSuite/Suite.h"
#include "CoreTools/UnitTestSuite/UnitTestComposite.h"

Framework::OpenGLGlutCallBackUnitTestSuiteImpl::OpenGLGlutCallBackUnitTestSuiteImpl(const std::string& name)
    : stream{ std::make_unique<WindowMessageUnitTestSuiteStream>(true) },
      testingInformationHelper{ TestingInformationHelper::Create() },
      openglSuite{ std::make_unique<Suite>(name, stream->GetStreamShared(), testingInformationHelper.IsPrintRun()) },
      process{ { System::WindowsKeyCodes::F1, &ClassType::ResetTestDataOnMessage },
               { System::WindowsKeyCodes::F5, &ClassType::RunUnitTestOnMessage } }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Framework::OpenGLGlutCallBackUnitTestSuiteImpl::IsValid() const noexcept
{
    if (stream != nullptr && openglSuite != nullptr)
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

Framework::OpenGLGlutCallBackUnitTestSuiteImpl::OStreamShared Framework::OpenGLGlutCallBackUnitTestSuiteImpl::GetStreamShared() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return stream->GetStreamShared();
}

void Framework::OpenGLGlutCallBackUnitTestSuiteImpl::AddTest(const std::string& suiteName, Suite& suite, const std::string& testName, const UnitTestSharedPtr& unitTest)
{
    EXCEPTION_TRY
    {
        DoAddTest(suiteName, suite, testName, unitTest);
    }
    EXCEPTION_ENGINE_EXCEPTION_CATCH(CoreTools)
}

void Framework::OpenGLGlutCallBackUnitTestSuiteImpl::DoAddTest(const std::string& suiteName, Suite& suite, const std::string& testName, const UnitTestSharedPtr& unitTest)
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
        LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools,
                                      SYSTEM_TEXT("测试"),
                                      testName,
                                      SYSTEM_TEXT("未配置！在测试套件："),
                                      suite.GetName(),
                                      SYSTEM_TEXT("。"),
                                      CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

void Framework::OpenGLGlutCallBackUnitTestSuiteImpl::KeyDownMessage(WindowsKeyCodes windowsKeyCodes)
{
    if (const auto iter = process.find(windowsKeyCodes);
        iter != process.cend())
    {
        (this->*(iter->second))();
    }
}

bool Framework::OpenGLGlutCallBackUnitTestSuiteImpl::IsPrintRun() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return testingInformationHelper.IsPrintRun();
}

void Framework::OpenGLGlutCallBackUnitTestSuiteImpl::RunUnitTestOnMessage()
{
    RunUnitTest();
    PrintReport();
}

void Framework::OpenGLGlutCallBackUnitTestSuiteImpl::ResetTestDataOnMessage()
{
    ResetTestData();
    openglSuite->GetStream() << "测试数据已清零。\n";
}
