///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.2 (2022/09/07 19:35)

#include "RenderingDeviceTesting.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/Renderers/EnvironmentParameter.h"
#include "Rendering/Renderers/RendererParameter.h"
#include "Rendering/Renderers/RenderingEnvironment.h"

Rendering::RenderingDeviceTesting::RenderingDeviceTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, RenderingDeviceTesting)

void Rendering::RenderingDeviceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::RenderingDeviceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SwapBuffersTest);
}

void Rendering::RenderingDeviceTesting::SwapBuffersTest()
{
    RenderingDevice renderingDevice{ CoreTools::DisableNotThrow::Disable };
    renderingDevice.SwapBuffers();
}
