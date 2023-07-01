///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 14:48)

#ifndef RENDERING_RENDERING_OPENGL_RENDERER_SUITE_OPENGL_TEXTURE_DATA_MANAGE_TESTING_H
#define RENDERING_RENDERING_OPENGL_RENDERER_SUITE_OPENGL_TEXTURE_DATA_MANAGE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class OpenGLTextureDataManageTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLTextureDataManageTesting;
        using ParentType = UnitTest;

    public:
        explicit OpenGLTextureDataManageTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest() noexcept;
        void Texture1DTest();
        void Texture2DTest();
        void Texture3DTest();
        void TextureCubeTest();

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_RENDERING_OPENGL_RENDERER_SUITE_OPENGL_TEXTURE_DATA_MANAGE_TESTING_H