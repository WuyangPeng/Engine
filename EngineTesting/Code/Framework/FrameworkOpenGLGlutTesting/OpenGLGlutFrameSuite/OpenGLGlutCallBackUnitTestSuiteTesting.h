// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/11 11:09)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_TESTING_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
    class OpenGLGlutCallBackUnitTestSuiteTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(OpenGLGlutCallBackUnitTestSuiteTesting);

    private:
        void MainTest() noexcept;

        void DoRunUnitTest() final;
    };
}

#endif  // FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_TESTING_H