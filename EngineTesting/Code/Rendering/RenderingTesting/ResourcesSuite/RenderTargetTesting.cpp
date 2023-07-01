///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:37)

#include "RenderTargetTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/Resources/Flags/DataFormatType.h"
#include "Rendering/Resources/Textures/DrawTarget.h"

Rendering::RenderTargetTesting::RenderTargetTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, RenderTargetTesting)

void Rendering::RenderTargetTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::RenderTargetTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

  

    CoreTools::InitTerm::ExecuteTerminator();
}

void Rendering::RenderTargetTesting::BaseTest()
{
    DrawTarget firstRenderTarget(5, DataFormatType::A8P8, 20, 22, false, DataFormatType::D24UNormS8UInt);

    ASSERT_EQUAL(firstRenderTarget.GetNumTargets(), 5);
    ASSERT_ENUM_EQUAL(firstRenderTarget.GetRenderTargetFormat(), DataFormatType::A8P8);
    ASSERT_EQUAL(firstRenderTarget.GetWidth(), 20);
    ASSERT_EQUAL(firstRenderTarget.GetHeight(), 22);

    ASSERT_FALSE(firstRenderTarget.HasRenderTargetMipMaps());
    ASSERT_TRUE(firstRenderTarget.HasDepthStencil());
}

void Rendering::RenderTargetTesting::StreamTest() noexcept
{
}
