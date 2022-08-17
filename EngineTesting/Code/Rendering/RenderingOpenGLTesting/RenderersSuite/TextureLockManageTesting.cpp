///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/18 16:15)

#include "TextureLockManageTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/Renderers/PlatformTexture1D.h"
#include "Rendering/Renderers/PlatformTexture2D.h"
#include "Rendering/Renderers/PlatformTexture3D.h"
#include "Rendering/Renderers/PlatformTextureCube.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Renderers/TextureLockManagerDetail.h"
#include "Rendering/Resources/Textures/LoadTexture.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, TextureLockManageTesting)

void Rendering::TextureLockManageTesting::MainTest()
{
    RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(Texture1DTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Texture2DTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Texture3DTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TextureCubeTest);

    RendererManager::Destroy();
}

void Rendering::TextureLockManageTesting::Texture1DTest() noexcept
{
}

void Rendering::TextureLockManageTesting::Texture2DTest() noexcept
{
}

void Rendering::TextureLockManageTesting::Texture3DTest() noexcept
{
}

void Rendering::TextureLockManageTesting::TextureCubeTest() noexcept
{
}
