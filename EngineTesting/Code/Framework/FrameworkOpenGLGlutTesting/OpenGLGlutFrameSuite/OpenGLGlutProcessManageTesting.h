///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/11 16:54)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_PROCESS_MANAGE_TESTING_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_PROCESS_MANAGE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class OpenGLGlutProcessManagerTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLGlutProcessManagerTesting;
        using ParentType = UnitTest;

    public:
        explicit OpenGLGlutProcessManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void OpenGLGlutCallBackPtrTest();
        void MainFunctionHelperPtrTest();
        void SetWindowIDSucceedTest();
        void SetMillisecondSucceedTest();

        void RenderSceneCallbackSucceedTest();
        void ChangeSizeCallbackSucceedTest();
        void TimerFunctionCallbackSucceedTest();
        void SpecialKeysDownCallbackSucceedTest();
        void KeyboardDownCallbackSucceedTest();
        void SpecialKeysUpCallbackSucceedTest();
        void KeyboardUpCallbackSucceedTest();
        void MouseFunctionCallbackSucceedTest();
        void MotionFunctionCallbackSucceedTest();
        void IdleFunctionCallbackSucceedTest();
        void ProcessMenuCallbackSucceedTest();
        void TerminateCallbackSucceedTest();
        void PreCreateSucceedTest();
        void InitializeSucceedTest();
        void PreIdleSucceedTest();
        void TerminateSucceedTest();

        void DoRunUnitTest() override;
    };
}

#endif  // FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_PROCESS_MANAGE_TESTING_H