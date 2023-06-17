///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 19:23)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_CALL_BACK_TESTING_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_CALL_BACK_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class OpenGLGlutCallBackTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLGlutCallBackTesting;
        using ParentType = UnitTest;

    public:
        explicit OpenGLGlutCallBackTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void InterfaceTest();

        void DoRunUnitTest() final;

        static void TimerFunction(int value) noexcept;
    };
}

#endif  // FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_CALL_BACK_TESTING_H