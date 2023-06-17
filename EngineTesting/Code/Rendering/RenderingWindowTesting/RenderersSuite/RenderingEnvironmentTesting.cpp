///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 14:51)

#include "RenderingEnvironmentTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/Renderers/EnvironmentParameter.h"
#include "Rendering/Renderers/RendererParameter.h"
#include "Rendering/Renderers/RenderingEnvironment.h"

RenderingWindowTesting::RenderingEnvironmentTesting::RenderingEnvironmentTesting(const OStreamShared& stream, HWnd hwnd)
    : ParentType{ stream }, hwnd{ hwnd }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(RenderingWindowTesting, RenderingEnvironmentTesting)

void RenderingWindowTesting::RenderingEnvironmentTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void RenderingWindowTesting::RenderingEnvironmentTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RenderingEnvironmentTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetRenderingDeviceTest);
}

void RenderingWindowTesting::RenderingEnvironmentTesting::RenderingEnvironmentTest()
{
    auto environmentParameter = Rendering::EnvironmentParameter::Create(hwnd);
    Rendering::RendererParameter rendererParameter("Configuration/RendererEnvironment.json");

    Rendering::RenderingEnvironment renderingEnvironment{ environmentParameter, rendererParameter };
    renderingEnvironment.Release();
}

void RenderingWindowTesting::RenderingEnvironmentTesting::GetRenderingDeviceTest()
{
    auto environmentParameter = Rendering::EnvironmentParameter::Create(hwnd);
    Rendering::RendererParameter rendererParameter("Configuration/RendererEnvironment.json");

    Rendering::RenderingEnvironment renderingEnvironment{ environmentParameter, rendererParameter };
    auto renderingDevice = renderingEnvironment.GetRenderingDevice();
    renderingDevice.SwapBuffers();
}
