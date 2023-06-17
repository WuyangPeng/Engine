///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 19:51)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_TESTING_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class OpenGLGlutCallBackUnitTestSuiteTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLGlutCallBackUnitTestSuiteTesting;
        using ParentType = UnitTest;

    public:
        explicit OpenGLGlutCallBackUnitTestSuiteTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

    private:
        void MainTest() noexcept;
    };
}

#endif  // FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_TESTING_H