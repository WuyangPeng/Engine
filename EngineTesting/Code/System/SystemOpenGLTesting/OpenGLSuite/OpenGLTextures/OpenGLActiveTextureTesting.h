/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/25 22:29)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_ACTIVE_TEXTURE_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_ACTIVE_TEXTURE_TESTING_H

#include "OpenGLTexturesTestingBase.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/Flags/OpenGLTextureFlags.h"

namespace System
{
    class OpenGLActiveTextureTesting final : public OpenGLTexturesTestingBase
    {
    public:
        using ClassType = OpenGLActiveTextureTesting;
        using ParentType = OpenGLTexturesTestingBase;

    public:
        explicit OpenGLActiveTextureTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ActiveTextureTest();
        void DoActiveTextureTest(OpenGLUnsignedInt texture);

    private:
        static constexpr auto width = 256;
        static constexpr auto height = 128;
        static constexpr auto openGLData = OpenGLData::Byte;
        static constexpr auto textureInternalFormat = TextureInternalFormat::RGBA8;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_ACTIVE_TEXTURE_TESTING_H