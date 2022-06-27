///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/18 16:14)

#include "PlatformTexture1DTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/Renderers/PlatformTexture1D.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/LoadTexture.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, PlatformTexture1DTesting)

void Rendering::PlatformTexture1DTesting::MainTest()
{
    RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(Texture1DTest);

    RendererManager::Destroy();
}

void Rendering::PlatformTexture1DTesting::Texture1DTest() noexcept
{
}
