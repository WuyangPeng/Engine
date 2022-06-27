///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/18 16:15)

#include "RenderTargetManagementTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/Renderers/RenderTargetManagement.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/RenderTarget.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, RenderTargetManagementTesting)

void Rendering::RenderTargetManagementTesting::MainTest()
{
    RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(RenderTargetTest);

    RendererManager::Destroy();
}

void Rendering::RenderTargetManagementTesting::RenderTargetTest() noexcept
{
}
