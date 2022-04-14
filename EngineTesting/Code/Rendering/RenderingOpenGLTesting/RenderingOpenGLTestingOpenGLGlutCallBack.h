// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/09 12:51)

#ifndef RENDERING_OPENGL_TESTING_RENDERING_OPENGL_TESTING_OPENGL_GLUT_CALL_BACK_H
#define RENDERING_OPENGL_TESTING_RENDERING_OPENGL_TESTING_OPENGL_GLUT_CALL_BACK_H

#include "Framework/OpenGLGlutFrame/OpenGLGlutCallBackUnitTestSuite.h"

namespace Rendering
{
    class RenderingOpenGLTestingOpenGLGlutCallBack : public Framework::OpenGLGlutCallBackUnitTestSuite
    {
    public:
        using ClassType = RenderingOpenGLTestingOpenGLGlutCallBack;
        using ParentType = OpenGLGlutCallBackUnitTestSuite;

    public:
        explicit RenderingOpenGLTestingOpenGLGlutCallBack(int64_t delta);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        virtual std::string GetSuiteName() const;

        void AddSuite() override;
        void AddRenderersSuite();
        void AddOpenGLRendererSuite();
    };

    using OpenGLGlutProcessSystemOpenGLTesting = Framework::OpenGLGlutProcess<RenderingOpenGLTestingOpenGLGlutCallBack>;
}

#endif  // RENDERING_OPENGL_TESTING_RENDERING_OPENGL_TESTING_OPENGL_GLUT_CALL_BACK_H
