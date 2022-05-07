// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/17 09:36)

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
        virtual std::string GetSuiteName() const;

        void AddSuite() override;
    };

    using OpenGLGlutProcessOpenGLGlutCallBackUnitTestSuiteTesting = Framework::OpenGLGlutProcess<OpenGLGlutCallBackUnitTestSuiteTestingOpenGLGlutCallBack>;
}

#endif  // OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_TESTING_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_TESTING_OPENGL_GLUT_CALL_BACK_H
