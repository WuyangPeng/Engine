///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/21 23:10)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_FRAMEBUFFER_TEXTURES_2D_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_FRAMEBUFFER_TEXTURES_2D_TESTING_H

#include "OpenGLTexturesTestingBase.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"

namespace System
{
    class OpenGLFramebufferTextures2DTesting final : public OpenGLTexturesTestingBase
    {
    public:
        using ClassType = OpenGLFramebufferTextures2DTesting;
        using ParentType = OpenGLTexturesTestingBase;

    public:
        explicit OpenGLFramebufferTextures2DTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void OpenGLFramebufferTextures2DTest(FrameBufferType frameBufferType);
        void SetGLDeleteFramebufferTest(OpenGLUInt buffer) noexcept;
        void DoOpenGLFramebufferTextures2DTest(FrameBufferType frameBufferType, OpenGLInt framebuffers);
        void FramebufferTexturesTest(FrameBufferType frameBufferType, OpenGLInt texture) noexcept;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_FRAMEBUFFER_TEXTURES_2D_TESTING_H