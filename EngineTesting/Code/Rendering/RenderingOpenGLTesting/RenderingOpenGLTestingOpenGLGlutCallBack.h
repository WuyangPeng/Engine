///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/17 22:48)

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
        NODISCARD virtual std::string GetSuiteName() const;

        void AddSuite() override;
        void AddRenderersSuite();
        void AddOpenGLRendererSuite();
    };

    using OpenGLGlutProcessSystemOpenGLTesting = Framework::OpenGLGlutProcess<RenderingOpenGLTestingOpenGLGlutCallBack>;
}

#endif  // RENDERING_OPENGL_TESTING_RENDERING_OPENGL_TESTING_OPENGL_GLUT_CALL_BACK_H
