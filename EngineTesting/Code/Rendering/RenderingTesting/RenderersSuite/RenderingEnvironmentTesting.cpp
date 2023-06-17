///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:43)

#include "RenderingEnvironmentTesting.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/Renderers/EnvironmentParameter.h"
#include "Rendering/Renderers/RendererParameter.h"
#include "Rendering/Renderers/RenderingEnvironment.h"

Rendering::RenderingEnvironmentTesting::RenderingEnvironmentTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, RenderingEnvironmentTesting)

void Rendering::RenderingEnvironmentTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::RenderingEnvironmentTesting::MainTest()
{
    ASSERT_THROW_EXCEPTION_0(HWndExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetNullRenderingDeviceTest);
}

void Rendering::RenderingEnvironmentTesting::HWndExceptionTest()
{
    auto hWnd = System::GetActiveWindow();

    auto environmentParameter = EnvironmentParameter::Create(hWnd);
    RendererParameter rendererParameter("Configuration/RendererCopy.json");

    RenderingEnvironment renderingEnvironment{ environmentParameter, rendererParameter };
}

void Rendering::RenderingEnvironmentTesting::GetNullRenderingDeviceTest()
{
    auto hWnd = System::GetActiveWindow();

    auto environmentParameter = EnvironmentParameter::Create(hWnd);
    RendererParameter rendererParameter("Configuration/RendererNull.json");

    RenderingEnvironment renderingEnvironment{ environmentParameter, rendererParameter };

    auto renderingDevice = renderingEnvironment.GetRenderingDevice();

    renderingDevice.SwapBuffers();
}
