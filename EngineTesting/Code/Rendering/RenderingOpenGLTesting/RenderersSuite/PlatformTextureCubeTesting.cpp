///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/18 16:15)

#include "PlatformTextureCubeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/Renderers/PlatformTextureCube.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/Textures/LoadTexture.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, PlatformTextureCubeTesting)

void Rendering::PlatformTextureCubeTesting::MainTest()
{
    RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(TextureCubeTest);

    RendererManager::Destroy();
}

void Rendering::PlatformTextureCubeTesting::TextureCubeTest() noexcept
{
}
