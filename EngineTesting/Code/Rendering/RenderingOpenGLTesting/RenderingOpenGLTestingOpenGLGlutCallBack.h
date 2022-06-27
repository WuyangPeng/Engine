///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/17 22:48)

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
