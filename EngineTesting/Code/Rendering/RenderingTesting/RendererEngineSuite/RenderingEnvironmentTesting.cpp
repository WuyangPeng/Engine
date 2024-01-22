///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/25 16:42)

#include "RenderingEnvironmentTesting.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/RendererEngine/EnvironmentParameter.h"
#include "Rendering/RendererEngine/RendererParameter.h"
#include "Rendering/RendererEngine/RenderingEnvironment.h"
#include "Rendering/Resources/Flags/DataFormatType.h"

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
    ASSERT_NOT_THROW_EXCEPTION_0(ParameterTest);
}

void Rendering::RenderingEnvironmentTesting::HWndExceptionTest()
{
    const auto hWnd = System::GetActiveWindow();

    const auto environmentParameter = EnvironmentParameter::Create(hWnd);
    const RendererParameter rendererParameter("Configuration/RendererCopy.json");

    RenderingEnvironment renderingEnvironment{ environmentParameter, rendererParameter };
}

void Rendering::RenderingEnvironmentTesting::GetNullRenderingDeviceTest()
{
    const auto environmentParameter = EnvironmentParameter::Create();
    const RendererParameter rendererParameter("Configuration/RendererNull.json");

    RenderingEnvironment renderingEnvironment{ environmentParameter, rendererParameter };

    auto renderingDevice = renderingEnvironment.GetRenderingDevice();

    renderingDevice.DisplayColorBuffer(0);

    renderingEnvironment.Release();
}

void Rendering::RenderingEnvironmentTesting::ParameterTest()
{
    const auto environmentParameter = EnvironmentParameter::Create();
    const RendererParameter rendererParameter("Configuration/RendererNull.json");

    const RenderingEnvironment renderingEnvironment{ environmentParameter, rendererParameter };

    ASSERT_EQUAL(renderingEnvironment.GetHeight(), 768);
    ASSERT_EQUAL(renderingEnvironment.GetWidth(), 1024);
    ASSERT_ENUM_EQUAL(renderingEnvironment.GetColorFormat(), DataFormatType::R32G32B32A32Float);
    ASSERT_ENUM_EQUAL(renderingEnvironment.GetDepthStencilFormat(), DataFormatType::D24UNormS8UInt);
    ASSERT_EQUAL(renderingEnvironment.GetNumMultiSamples(), 1);
}
