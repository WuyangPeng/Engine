///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/25 16:20)

#ifndef RENDERING_OPENGL_TESTING_RENDERING_OPENGL_TESTING_OPENGL_GLUT_CALL_BACK_H
#define RENDERING_OPENGL_TESTING_RENDERING_OPENGL_TESTING_OPENGL_GLUT_CALL_BACK_H

#include "Framework/OpenGLGlutFrame/OpenGLGlutCallBackUnitTestSuite.h"

namespace Rendering
{
    class RenderingOpenGLTestingOpenGLGlutCallBack final : public Framework::OpenGLGlutCallBackUnitTestSuite
    {
    public:
        using ClassType = RenderingOpenGLTestingOpenGLGlutCallBack;
        using ParentType = OpenGLGlutCallBackUnitTestSuite;

    public:
        explicit RenderingOpenGLTestingOpenGLGlutCallBack(int64_t delta);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void AddSuite() override;
        void AddRendererEngineSuite();
        void AddOpenGLRendererSuite();
    };

    using OpenGLGlutProcessSystemOpenGLTesting = Framework::OpenGLGlutProcess<RenderingOpenGLTestingOpenGLGlutCallBack>;
}

#endif  // RENDERING_OPENGL_TESTING_RENDERING_OPENGL_TESTING_OPENGL_GLUT_CALL_BACK_H
