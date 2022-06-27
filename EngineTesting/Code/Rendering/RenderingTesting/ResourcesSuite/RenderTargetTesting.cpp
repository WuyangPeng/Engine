///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/15 15:56)

#include "RenderTargetTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/RenderTarget.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, RenderTargetTesting)

void Rendering::RenderTargetTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

    RendererManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::RenderTargetTesting::BaseTest()
{
    RenderTarget firstRenderTarget(5, TextureFormat::A8B8G8R8, 20, 22, false, true);

    ASSERT_EQUAL(firstRenderTarget.GetNumTargets(), 5);
    ASSERT_ENUM_EQUAL(firstRenderTarget.GetFormat(), TextureFormat::A8B8G8R8);
    ASSERT_EQUAL(firstRenderTarget.GetWidth(), 20);
    ASSERT_EQUAL(firstRenderTarget.GetHeight(), 22);

    ASSERT_FALSE(firstRenderTarget.HasMipmaps());
    ASSERT_TRUE(firstRenderTarget.HasDepthStencil());
}

void Rendering::RenderTargetTesting::StreamTest() noexcept
{
}
