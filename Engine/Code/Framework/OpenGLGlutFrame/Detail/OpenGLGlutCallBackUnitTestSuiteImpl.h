/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:54)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_WINDOW_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_IMPL_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_WINDOW_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_IMPL_H

#include "Framework/FrameworkDll.h"

#include "System/Windows/Fwd/WindowsFlagsFwd.h"
#include "CoreTools/MainFunctionHelper/TestingInformationHelper.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"
#include "Framework/WindowProcess/Detail/WindowMessageUnitTestSuiteStream.h"

#include <map>
#include <string>

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE OpenGLGlutCallBackUnitTestSuiteImpl
    {
    public:
        using ClassType = OpenGLGlutCallBackUnitTestSuiteImpl;

        using WindowsKeyCodes = System::WindowsKeyCodes;
        using Suite = CoreTools::Suite;
        using OStreamShared = CoreTools::OStreamShared;
        using TestingInformationHelper = CoreTools::TestingInformationHelper;
        using UnitTestSharedPtr = std::shared_ptr<CoreTools::UnitTestComposite>;

    public:
        explicit OpenGLGlutCallBackUnitTestSuiteImpl(const std::string& name);

        CLASS_INVARIANT_DECLARE;

        void AddSuite(const Suite& suite);
        void RunUnitTest();
        void PrintReport();
        void ResetTestData();

        void KeyDownMessage(WindowsKeyCodes windowsKeyCodes);

        void AddTest(const std::string& suiteName, Suite& suite, const std::string& testName, const UnitTestSharedPtr& unitTest);

        NODISCARD bool IsPrintRun() const noexcept;
        NODISCARD int GetPassedNumber() const noexcept;
        NODISCARD OStreamShared GetStreamShared() noexcept;

    private:
        using SuiteUniquePtr = std::unique_ptr<Suite>;
        using HandlerFunction = void (ClassType::*)();
        using Process = std::map<WindowsKeyCodes, HandlerFunction>;
        using StreamTypeUniquePtr = std::unique_ptr<WindowMessageUnitTestSuiteStream>;

    private:
        void RunUnitTestOnMessage();
        void ResetTestDataOnMessage();
        void DoAddTest(const std::string& suiteName, Suite& suite, const std::string& testName, const UnitTestSharedPtr& unitTest);

    private:
        StreamTypeUniquePtr stream;
        TestingInformationHelper testingInformationHelper;
        SuiteUniquePtr openglSuite;
        Process process;
    };
}

#endif  // FRAMEWORK_OPENGL_GLUT_FRAME_WINDOW_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_IMPL_H
