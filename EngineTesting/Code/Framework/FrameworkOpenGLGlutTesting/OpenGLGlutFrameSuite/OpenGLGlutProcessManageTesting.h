///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/24 15:47)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_PROCESS_MANAGE_TESTING_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_PROCESS_MANAGE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
    class OpenGLGlutProcessManagerTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(OpenGLGlutProcessManagerTesting);

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

        void DoRunUnitTest() final;
    };
}

#endif  // FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_PROCESS_MANAGE_TESTING_H