/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 16:40)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_FRAME_BUFFER_TEXTURES_2D_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_FRAME_BUFFER_TEXTURES_2D_TESTING_H

#include "OpenGLTexturesTestingBase.h"

namespace System
{
    class OpenGLFrameBufferTextures2DTesting final : public OpenGLTexturesTestingBase
    {
    public:
        using ClassType = OpenGLFrameBufferTextures2DTesting;
        using ParentType = OpenGLTexturesTestingBase;

    public:
        explicit OpenGLFrameBufferTextures2DTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void FrameBufferTextures2DTest(FrameBufferType frameBufferType);
        void DeleteFrameBufferTest(OpenGLUnsignedInt buffer) const noexcept;
        void DoFrameBufferTextures2DTest(FrameBufferType frameBufferType, OpenGLInt frameBuffers);
        void FrameBufferTexturesTest(FrameBufferType frameBufferType, OpenGLInt texture) const noexcept;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_FRAME_BUFFER_TEXTURES_2D_TESTING_H