///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/21 23:10)

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