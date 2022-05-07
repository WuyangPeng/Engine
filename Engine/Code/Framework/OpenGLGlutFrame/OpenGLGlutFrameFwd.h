///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/05/07 14:36)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_FWD_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_FWD_H

namespace Framework
{
    enum class FrameParameter;

    class OpenGLGlutProcessManager;

    template <typename OpenGLGlutCallBack>
    class OpenGLGlutProcess;

    class OpenGLGlutCallBackInterface;

    template <typename MiddleLayer>
    class OpenGLGlutCallBack;

    class OpenGLGlutCallBackUnitTestSuite;

    template <typename OpenGLGlutProcess>
    class OpenGLGlutFrameBuild;
}

#endif  // FRAMEWORK_OPENGL_GLUT_FRAME_FWD_H