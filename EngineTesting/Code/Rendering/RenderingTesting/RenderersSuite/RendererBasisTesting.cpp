///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.2 (2022/09/05 14:28)

#include "RendererBasisTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/Renderers/RendererBasis.h"
#include "Rendering/Resources/Flags/DataFormatType.h"

Rendering::RendererBasisTesting::RendererBasisTesting(const OStreamShared& stream)
    : ParentType{ stream },
      windowWidth{ 0 },
      windowHeight{ 0 },
      colorFormat{ DataFormatType::R32G32B32A32Float },
      depthStencilFormat{ DataFormatType::D24UNormS8UInt },
      multisamplesNumber{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, RendererBasisTesting)

void Rendering::RendererBasisTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::RendererBasisTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ExceptionTest);
}

void Rendering::RendererBasisTesting::AccessTest()
{
    windowWidth = 0;
    windowHeight = 0;
    colorFormat = DataFormatType::R32G32B32A32Float;
    depthStencilFormat = DataFormatType::D24UNormS8UInt;
    multisamplesNumber = 0;

    RendererBasis rendererBasis{};
    ASSERT_NOT_THROW_EXCEPTION_1(ExecuteTest, rendererBasis);

    ASSERT_NOT_THROW_EXCEPTION_1(SetSizeTest, rendererBasis);
    ASSERT_NOT_THROW_EXCEPTION_1(SetMultisamplesNumberTest, rendererBasis);
    ASSERT_NOT_THROW_EXCEPTION_1(SetDataFormat, rendererBasis);
}

void Rendering::RendererBasisTesting::SetSizeTest(RendererBasis& rendererBasis)
{
    windowWidth = 50;
    windowHeight = 70;
    rendererBasis.SetSize(windowWidth, windowHeight);

    ASSERT_NOT_THROW_EXCEPTION_1(ExecuteTest, rendererBasis);
}

void Rendering::RendererBasisTesting::SetMultisamplesNumberTest(RendererBasis& rendererBasis)
{
    multisamplesNumber = 7;
    rendererBasis.SetMultisamplesNumber(multisamplesNumber);

    ASSERT_NOT_THROW_EXCEPTION_1(ExecuteTest, rendererBasis);
}

void Rendering::RendererBasisTesting::SetDataFormat(RendererBasis& rendererBasis)
{
    colorFormat = DataFormatType::R32G32B32Float;
    depthStencilFormat = DataFormatType::D32Float;
    rendererBasis.SetDataFormat(colorFormat, depthStencilFormat);

    ASSERT_NOT_THROW_EXCEPTION_1(ExecuteTest, rendererBasis);
}

void Rendering::RendererBasisTesting::ExecuteTest(const RendererBasis& rendererBasis)
{
    ASSERT_EQUAL(rendererBasis.GetWidth(), windowWidth);
    ASSERT_EQUAL(rendererBasis.GetHeight(), windowHeight);
    ASSERT_EQUAL(rendererBasis.GetNumMultisamples(), multisamplesNumber);
    ASSERT_EQUAL(rendererBasis.GetColorFormat(), colorFormat);
    ASSERT_EQUAL(rendererBasis.GetDepthStencilFormat(), depthStencilFormat);
}

void Rendering::RendererBasisTesting::ConstructionTest()
{
    windowWidth = 1024;
    windowHeight = 768;
    colorFormat = DataFormatType::R32G32B32Float;
    depthStencilFormat = DataFormatType::D32FloatS8X24UInt;
    multisamplesNumber = 1;

    RendererBasis rendererBasis{ windowWidth, windowHeight, colorFormat, depthStencilFormat, multisamplesNumber };
    ASSERT_NOT_THROW_EXCEPTION_1(ExecuteTest, rendererBasis);

    ASSERT_NOT_THROW_EXCEPTION_1(SetSizeTest, rendererBasis);
    ASSERT_NOT_THROW_EXCEPTION_1(SetMultisamplesNumberTest, rendererBasis);
    ASSERT_NOT_THROW_EXCEPTION_1(SetDataFormat, rendererBasis);
}

void Rendering::RendererBasisTesting::ExceptionTest()
{
    ASSERT_THROW_EXCEPTION_0(WidthConstructionExceptionTest);
    ASSERT_THROW_EXCEPTION_0(HeightConstructionExceptionTest);
    ASSERT_THROW_EXCEPTION_0(MultisamplesNumberConstructionExceptionTest);

    ASSERT_THROW_EXCEPTION_0(SetWidthConstructionExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetHeightConstructionExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetMultisamplesNumberConstructionExceptionTest);
}

void Rendering::RendererBasisTesting::WidthConstructionExceptionTest()
{
    const RendererBasis rendererBasis{ -1, windowHeight, colorFormat, depthStencilFormat, multisamplesNumber };
}

void Rendering::RendererBasisTesting::HeightConstructionExceptionTest()
{
    const RendererBasis rendererBasis{ windowWidth, -1, colorFormat, depthStencilFormat, multisamplesNumber };
}

void Rendering::RendererBasisTesting::MultisamplesNumberConstructionExceptionTest()
{
    const RendererBasis rendererBasis{ windowWidth, windowHeight, colorFormat, depthStencilFormat, -1 };
}

void Rendering::RendererBasisTesting::SetWidthConstructionExceptionTest()
{
    RendererBasis rendererBasis{ windowWidth, windowHeight, colorFormat, depthStencilFormat, multisamplesNumber };

    rendererBasis.SetSize(-1, windowHeight);
}

void Rendering::RendererBasisTesting::SetHeightConstructionExceptionTest()
{
    RendererBasis rendererBasis{ windowWidth, windowHeight, colorFormat, depthStencilFormat, multisamplesNumber };

    rendererBasis.SetSize(windowWidth, -1);
}

void Rendering::RendererBasisTesting::SetMultisamplesNumberConstructionExceptionTest()
{
    RendererBasis rendererBasis{ windowWidth, windowHeight, colorFormat, depthStencilFormat, multisamplesNumber };

    rendererBasis.SetMultisamplesNumber(-1);
}
