///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/27 16:34)

#ifndef OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_TESTING_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_TESTING_OPENGL_GLUT_CALL_BACK_H
#define OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_TESTING_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_TESTING_OPENGL_GLUT_CALL_BACK_H

#include "Framework/OpenGLGlutFrame/OpenGLGlutCallBackUnitTestSuite.h"

namespace OpenGLGlutCallBackUnitTestSuiteTesting
{
    class OpenGLGlutCallBackUnitTestSuiteTestingOpenGLGlutCallBack : public Framework::OpenGLGlutCallBackUnitTestSuite
    {
    public:
        using ClassType = OpenGLGlutCallBackUnitTestSuiteTestingOpenGLGlutCallBack;
        using ParentType = OpenGLGlutCallBackUnitTestSuite;

    public:
        OpenGLGlutCallBackUnitTestSuiteTestingOpenGLGlutCallBack(int64_t delta);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        NODISCARD virtual std::string GetSuiteName() const;

        void AddSuite() override;
    };

    using OpenGLGlutProcessOpenGLGlutCallBackUnitTestSuiteTesting = Framework::OpenGLGlutProcess<OpenGLGlutCallBackUnitTestSuiteTestingOpenGLGlutCallBack>;
}

#endif  // OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_TESTING_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_TESTING_OPENGL_GLUT_CALL_BACK_H
