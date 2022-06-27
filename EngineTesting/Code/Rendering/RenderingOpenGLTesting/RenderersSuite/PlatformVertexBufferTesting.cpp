///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/18 16:15)

#include "PlatformVertexBufferTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/Renderers/PlatformVertexBuffer.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/VertexBuffer.h"
#include "Rendering/SceneGraph/LoadVisual.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, PlatformVertexBufferTesting)

void Rendering::PlatformVertexBufferTesting::MainTest()
{
    RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(VertexBufferTest);

    RendererManager::Destroy();
}

void Rendering::PlatformVertexBufferTesting::VertexBufferTest() noexcept
{
}
