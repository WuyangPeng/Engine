///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 14:51)

#include "RenderingDeviceTesting.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/RendererEngine/EnvironmentParameter.h"
#include "Rendering/RendererEngine/RendererParameter.h"
#include "Rendering/RendererEngine/RenderingEnvironment.h"

RenderingWindowTesting::RenderingDeviceTesting::RenderingDeviceTesting(const OStreamShared& stream, HWnd hwnd)
    : ParentType{ stream }, hwnd{ hwnd }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(RenderingWindowTesting, RenderingDeviceTesting)

void RenderingWindowTesting::RenderingDeviceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void RenderingWindowTesting::RenderingDeviceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SwapBuffersTest);
}

void RenderingWindowTesting::RenderingDeviceTesting::SwapBuffersTest()
{
    auto environmentParameter = Rendering::EnvironmentParameter::Create(hwnd);
    Rendering::RendererParameter rendererParameter("Configuration/RendererEnvironment.json");

    Rendering::RenderingEnvironment renderingEnvironment{ environmentParameter, rendererParameter };

    auto renderingDevice = renderingEnvironment.GetRenderingDevice();
    renderingDevice.DisplayColorBuffer(0);
}
