///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/11 16:56)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_PROCESS_OPENGL_GLUT_CALL_BACK_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_PROCESS_OPENGL_GLUT_CALL_BACK_H

#include "Framework/OpenGLGlutFrame/OpenGLGlutCallBackInterface.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutProcess.h"

namespace Framework
{
    class OpenGLGlutProcessOpenGLGlutCallBack final : public OpenGLGlutCallBackInterface
    {
    public:
        using ClassType = OpenGLGlutProcessOpenGLGlutCallBack;
        using ParentType = OpenGLGlutCallBackInterface;

    public:
        OpenGLGlutProcessOpenGLGlutCallBack() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };

    template <>
    OpenGLGlutProcess<OpenGLGlutProcessOpenGLGlutCallBack>::OpenGLGlutProcess(int64_t delta);
}

#endif  // FRAMEWORK_OPENGL_GLUT_FRAME_SUITE_OPENGL_GLUT_PROCESS_OPENGL_GLUT_CALL_BACK_H