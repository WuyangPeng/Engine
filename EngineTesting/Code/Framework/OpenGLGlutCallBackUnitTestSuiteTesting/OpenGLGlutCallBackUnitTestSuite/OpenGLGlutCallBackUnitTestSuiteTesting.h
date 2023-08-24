///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/10 11:29)

#ifndef OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_TESTING_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_TESTING_H
#define OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_TESTING_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Framework/OpenGLGlutCallBackUnitTestSuiteTesting/OpenGLGlutCallBack.h"

namespace OpenGLGlutCallBackUnitTestSuiteTesting
{
    class OpenGLGlutCallBackUnitTestSuiteTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLGlutCallBackUnitTestSuiteTesting;
        using ParentType = UnitTest;

        using OpenGLGlutCallBackWeakPtr = std::weak_ptr<OpenGLGlutCallBack>;

    public:
        explicit OpenGLGlutCallBackUnitTestSuiteTesting(const OStreamShared& stream, const OpenGLGlutCallBackWeakPtr& message);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void KeyDownMessageTest();
        void CreateMessageTest();
        void DisplayTest();

        void DoRunUnitTest() final;

    private:
        OpenGLGlutCallBackWeakPtr message;
    };
}

#endif  // OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_TESTING_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_TESTING_H
