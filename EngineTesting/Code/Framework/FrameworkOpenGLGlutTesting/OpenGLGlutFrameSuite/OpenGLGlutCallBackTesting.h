// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.0.4 (2019/09/11 11:09)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_CALL_BACK_TESTING_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_CALL_BACK_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
    class OpenGLGlutCallBackTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(OpenGLGlutCallBackTesting);

    private:
        void MainTest();
        void InterfaceTest();

        void DoRunUnitTest() final;

        static void TimerFunction(int value) noexcept;
    };
}

#endif  // FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_CALL_BACK_TESTING_H