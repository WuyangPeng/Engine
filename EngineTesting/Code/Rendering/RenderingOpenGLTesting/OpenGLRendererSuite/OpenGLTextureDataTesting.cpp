///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 14:48)

#include "OpenGLTextureDataTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/OpenGLRenderer/OpenGLTextureDataDetail.h"
#include "Rendering/Resources/Textures/LoadTexture.h"

Rendering::OpenGLTextureDataTesting::OpenGLTextureDataTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLTextureDataTesting)

void Rendering::OpenGLTextureDataTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::OpenGLTextureDataTesting::MainTest() noexcept
{

}

void Rendering::OpenGLTextureDataTesting::Texture1DTest()
{
    auto firstTexture1D = LoadTexture::Load1DFromFile(SYSTEM_TEXT("Resource/OpenGLRendererSuite/Texture1D.trt"));

    OpenGLTextureData<Texture1D> data(firstTexture1D.get());

    ASSERT_TRUE(0 < data.GetTexture());

    data.Enable(0);
    ASSERT_UNEQUAL_NULL_PTR(data.Lock(0, BufferLocking::WriteOnly));
    data.Unlock(0);
    data.Disable(0);
}

void Rendering::OpenGLTextureDataTesting::Texture2DTest()
{
    auto firstTexture2D = LoadTexture::Load2DFromFile(SYSTEM_TEXT("Resource/OpenGLRendererSuite/Texture2D.trt"));

    OpenGLTextureData<Texture2D> data(firstTexture2D.get());

    ASSERT_TRUE(0 < data.GetTexture());

    data.Enable(0);
    ASSERT_UNEQUAL_NULL_PTR(data.Lock(0, BufferLocking::WriteOnly));
    data.Unlock(0);
    data.Disable(0);
}

void Rendering::OpenGLTextureDataTesting::Texture3DTest()
{
    auto firstTexture3D = LoadTexture::Load3DFromFile(SYSTEM_TEXT("Resource/OpenGLRendererSuite/Texture3D.trt"));

    OpenGLTextureData<Texture3D> data(firstTexture3D.get());

    ASSERT_TRUE(0 < data.GetTexture());

    data.Enable(0);
    ASSERT_UNEQUAL_NULL_PTR(data.Lock(0, BufferLocking::WriteOnly));
    data.Unlock(0);
    data.Disable(0);
}

void Rendering::OpenGLTextureDataTesting::TextureCubeTest()
{
    auto firstTextureCube = LoadTexture::LoadCubeFromFile(SYSTEM_TEXT("Resource/OpenGLRendererSuite/TextureCube.trt"));

    OpenGLTextureData<TextureCube> data(firstTextureCube.get());

    ASSERT_TRUE(0 < data.GetTexture());

    data.Enable(0);
    ASSERT_UNEQUAL_NULL_PTR(data.Lock(2, 0, BufferLocking::WriteOnly));
    data.Unlock(2, 0);
    data.Disable(0);
}