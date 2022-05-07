///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 14:01)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_WINDOW_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_IMPL_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_WINDOW_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_IMPL_H

#include "Framework/FrameworkDll.h"

#include "System/Windows/Fwd/WindowsFlagsFwd.h"
#include "CoreTools/MainFunctionHelper/TestingInformationHelper.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

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
        OpenGLGlutCallBackUnitTestSuiteImpl(const std::string& name, const OStreamShared& streamShared);

        CLASS_INVARIANT_DECLARE;

        void AddSuite(const Suite& suite);
        void RunUnitTest();
        void PrintReport();
        void ResetTestData();

        void KeyDownMessage(WindowsKeyCodes windowsKeyCodes);

        void AddTest(const std::string& suiteName, Suite& suite, const std::string& testName, const UnitTestSharedPtr& unitTest);

        NODISCARD bool IsPrintRun() const noexcept;
        NODISCARD int GetPassedNumber() const noexcept;

    private:
        using SuiteSharedPtr = std::shared_ptr<Suite>;
        using HandlerFunction = void (ClassType::*)();
        using Process = std::map<System::WindowsKeyCodes, HandlerFunction>;

    private:
        void RunUnitTestOnMessage();
        void ResetTestDataOnMessage();

    private:
        TestingInformationHelper testingInformationHelper;
        SuiteSharedPtr openglSuite;
        Process process;
    };
}

#endif  // FRAMEWORK_OPENGL_GLUT_FRAME_WINDOW_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_IMPL_H
