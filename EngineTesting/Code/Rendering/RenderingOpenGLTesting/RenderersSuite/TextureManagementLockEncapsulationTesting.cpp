///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/18 16:16)

#include "TextureManagementLockEncapsulationTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/Renderers/PlatformIndexBuffer.h"
#include "Rendering/Renderers/PlatformTexture1D.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Renderers/TextureManagementDetail.h"
#include "Rendering/Resources/Buffers/IndexBuffer.h"
#include "Rendering/Resources/Textures/LoadTexture.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, TextureManagementLockEncapsulationTesting)

void Rendering::TextureManagementLockEncapsulationTesting::MainTest()
{
    RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(Texture1DTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Texture2DTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Texture3DTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TextureCubeTest);

    RendererManager::Destroy();
}

void Rendering::TextureManagementLockEncapsulationTesting::Texture1DTest() noexcept
{
}

void Rendering::TextureManagementLockEncapsulationTesting::Texture2DTest() noexcept
{
}

void Rendering::TextureManagementLockEncapsulationTesting::Texture3DTest() noexcept
{
}

void Rendering::TextureManagementLockEncapsulationTesting::TextureCubeTest() noexcept
{
}