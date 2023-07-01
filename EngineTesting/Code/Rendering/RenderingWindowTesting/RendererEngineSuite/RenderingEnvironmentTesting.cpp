///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/25 16:53)

#include "RenderingEnvironmentTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/RendererEngine/EnvironmentParameter.h"
#include "Rendering/RendererEngine/RendererParameter.h"
#include "Rendering/RendererEngine/RenderingEnvironment.h"

RenderingWindowTesting::RenderingEnvironmentTesting::RenderingEnvironmentTesting(const OStreamShared& stream, HWnd hWnd)
    : ParentType{ stream }, hWnd{ hWnd }
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
    const auto environmentParameter = Rendering::EnvironmentParameter::Create(hWnd);
    const Rendering::RendererParameter rendererParameter("Configuration/RendererEnvironment.json");

    Rendering::RenderingEnvironment renderingEnvironment{ environmentParameter, rendererParameter };
    renderingEnvironment.Release();
}

void RenderingWindowTesting::RenderingEnvironmentTesting::GetRenderingDeviceTest()
{
    const auto environmentParameter = Rendering::EnvironmentParameter::Create(hWnd);
    const Rendering::RendererParameter rendererParameter("Configuration/RendererEnvironment.json");

    const Rendering::RenderingEnvironment renderingEnvironment{ environmentParameter, rendererParameter };
    auto renderingDevice = renderingEnvironment.GetRenderingDevice();
    renderingDevice.SwapBuffers(0);
}
