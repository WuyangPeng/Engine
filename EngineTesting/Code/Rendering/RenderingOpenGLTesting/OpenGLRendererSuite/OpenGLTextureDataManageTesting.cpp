///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 14:48)

#include "OpenGLTextureDataManageTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/OpenGLRenderer/OpenGLTextureDataDetail.h"
#include "Rendering/OpenGLRenderer/OpenGLTextureDataManageDetail.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/Textures/LoadTexture.h"

Rendering::OpenGLTextureDataManageTesting::OpenGLTextureDataManageTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLTextureDataManageTesting)

void Rendering::OpenGLTextureDataManageTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::OpenGLTextureDataManageTesting::MainTest()
{
    RendererManager::Create();

    RendererManager::Destroy();
}

void Rendering::OpenGLTextureDataManageTesting::Texture1DTest()
{
    Texture1DSharedPtr firstTexture1D = LoadTexture::Load1DFromFile(SYSTEM_TEXT("Resource/OpenGLRendererSuite/Texture1D.trt"));

    OpenGLTextureData<Texture1D> data(firstTexture1D.get());

    ASSERT_TRUE(0 < data.GetTexture());

    data.Enable(0);
    {
        OpenGLTextureDataManager<OpenGLTextureData<Texture1D>> manage(data);
        ASSERT_UNEQUAL_NULL_PTR(manage.Lock(0, BufferLocking::WriteOnly));
    }

    data.Disable(0);
}

void Rendering::OpenGLTextureDataManageTesting::Texture2DTest()
{
    Texture2DSharedPtr firstTexture2D = LoadTexture::Load2DFromFile(SYSTEM_TEXT("Resource/OpenGLRendererSuite/Texture2D.trt"));

    OpenGLTextureData<Texture2D> data(firstTexture2D.get());

    ASSERT_TRUE(0 < data.GetTexture());

    data.Enable(0);
    {
        OpenGLTextureDataManager<OpenGLTextureData<Texture2D>> manage(data);
        ASSERT_UNEQUAL_NULL_PTR(manage.Lock(0, BufferLocking::WriteOnly));
    }

    data.Disable(0);
}

void Rendering::OpenGLTextureDataManageTesting::Texture3DTest()
{
    auto firstTexture3D = LoadTexture::Load3DFromFile(SYSTEM_TEXT("Resource/OpenGLRendererSuite/Texture3D.trt"));

    OpenGLTextureData<Texture3D> data(firstTexture3D.get());

    ASSERT_TRUE(0 < data.GetTexture());

    data.Enable(0);
    {
        OpenGLTextureDataManager<OpenGLTextureData<Texture3D>> manage(data);
        ASSERT_UNEQUAL_NULL_PTR(manage.Lock(0, BufferLocking::WriteOnly));
    }

    data.Disable(0);
}

void Rendering::OpenGLTextureDataManageTesting::TextureCubeTest()
{
    auto firstTextureCube = LoadTexture::LoadCubeFromFile(SYSTEM_TEXT("Resource/OpenGLRendererSuite/TextureCube.trt"));

    OpenGLTextureData<TextureCube> data(firstTextureCube.get());

    ASSERT_TRUE(0 < data.GetTexture());

    data.Enable(0);
    {
        OpenGLTextureDataManager<OpenGLTextureData<TextureCube>> manage(data);
        ASSERT_UNEQUAL_NULL_PTR(manage.Lock(3, 0, BufferLocking::WriteOnly));
    }

    data.Disable(0);
}