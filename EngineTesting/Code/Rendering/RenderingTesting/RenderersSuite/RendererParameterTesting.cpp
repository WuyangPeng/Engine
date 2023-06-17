///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 15:43)

#include "RendererParameterTesting.h"
#include "System/Windows/Flags/WindowsPictorialFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/DataTypes/ColourDetail.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "Rendering/Renderers/RendererParameter.h"
#include "Rendering/Resources/Flags/DataFormatType.h"

using namespace std::literals;

Rendering::RendererParameterTesting::RendererParameterTesting(const OStreamShared& stream)
    : ParentType{ stream },
      rendererType{ RendererTypes::OpenGL },
      windowWidth{ 800 },
      windowHeight{ 600 },
      colorFormat{ DataFormatType::R32G32B32Float },
      depthStencilFormat{ DataFormatType::D32FloatS8X24UInt },
      multisamplesNumber{ 2 },
      colour{ 1.0f, 0.7f, 0.5f, 0.0f },
      windowTitle{ "RenderingTesting"s },
      windowX{ 10 },
      windowY{ 15 },
      isAllowResize{ false },
      className{ SYSTEM_TEXT("RenderingTestingClassName"s) },
      menuName{ SYSTEM_TEXT("RenderingTestingMenuName"s) },
      icon{ 1001 },
      isIconDefault{ false },
      cursor{ 1002 },
      isCursorDefault{ false },
      background{ WindowsBrushTypes::GrayBrush }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, RendererParameterTesting)

void Rendering::RendererParameterTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::RendererParameterTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
}

void Rendering::RendererParameterTesting::AccessTest()
{
    RendererParameter rendererParameter("Configuration/RendererCopy.json");

    ASSERT_NOT_THROW_EXCEPTION_1(ExecuteTest, rendererParameter);

    ASSERT_NOT_THROW_EXCEPTION_1(ResizeTest, rendererParameter);
}

void Rendering::RendererParameterTesting::ExecuteTest(const RendererParameter& rendererParameter)
{
    ASSERT_ENUM_EQUAL(rendererParameter.GetRendererType(), rendererType);

    ASSERT_ENUM_EQUAL(rendererParameter.GetColorFormat(), colorFormat);
    ASSERT_ENUM_EQUAL(rendererParameter.GetDepthStencilFormat(), depthStencilFormat);
    ASSERT_EQUAL(rendererParameter.GetNumMultisamples(), multisamplesNumber);

    ASSERT_TRUE(Approximate(rendererParameter.GetClearColor(), colour, 1e-8f));

    ASSERT_EQUAL(rendererParameter.GetWindowTitle(), windowTitle);

    ASSERT_EQUAL(rendererParameter.GetXPosition(), windowX);
    ASSERT_EQUAL(rendererParameter.GetYPosition(), windowY);
    ASSERT_EQUAL(rendererParameter.GetWidth(), windowWidth);
    ASSERT_EQUAL(rendererParameter.GetHeight(), windowHeight);
    ASSERT_EQUAL(rendererParameter.IsAllowResize(), isAllowResize);

    ASSERT_EQUAL(rendererParameter.GetWindowClassName(), className);
    ASSERT_EQUAL(rendererParameter.GetWindowMenuName(), menuName);

    ASSERT_EQUAL(rendererParameter.GetIcon(), icon);
    ASSERT_EQUAL(rendererParameter.IsIconDefault(), isIconDefault);
    ASSERT_EQUAL(rendererParameter.GetCursor(), cursor);
    ASSERT_EQUAL(rendererParameter.IsCursorDefault(), isCursorDefault);
    ASSERT_EQUAL(rendererParameter.GetBackground(), background);

    const auto rendererBasis = rendererParameter.GetRendererBasis();

    ASSERT_ENUM_EQUAL(rendererBasis.GetColorFormat(), rendererParameter.GetColorFormat());
    ASSERT_ENUM_EQUAL(rendererBasis.GetDepthStencilFormat(), rendererParameter.GetDepthStencilFormat());
    ASSERT_EQUAL(rendererBasis.GetNumMultisamples(), rendererParameter.GetNumMultisamples());
    ASSERT_EQUAL(rendererBasis.GetWidth(), rendererParameter.GetWidth());
    ASSERT_EQUAL(rendererBasis.GetHeight(), rendererParameter.GetHeight());
}

void Rendering::RendererParameterTesting::ResizeTest(RendererParameter& rendererParameter)
{
    windowWidth = 100;
    windowHeight = 10;
    rendererParameter.Resize(windowWidth, windowHeight);

    ASSERT_NOT_THROW_EXCEPTION_1(ExecuteTest, rendererParameter);
}
