///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 14:04)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_BIND_TEXTURES_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_BIND_TEXTURES_TESTING_H

#include "OpenGLTexturesTestingBase.h"

namespace System
{
    class OpenGLBindTexturesTesting final : public OpenGLTexturesTestingBase
    {
    public:
        using ClassType = OpenGLBindTexturesTesting;
        using ParentType = OpenGLTexturesTestingBase;

    public:
        explicit OpenGLBindTexturesTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void OpenGLBindTexturesTest();

        void DoOpenGLBindTexturesTest(TextureTarget textureTarget, OpenGLUInt texture) noexcept;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_BIND_TEXTURES_TESTING_H