// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/09 10:31)

#include "RendererParameterTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/DataTypes/ColourDetail.h"
#include "Rendering/Renderers/RendererParameter.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, RendererParameterTesting)
#include SYSTEM_WARNING_DISABLE(26496)
void Rendering::RendererParameterTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
}

void Rendering::RendererParameterTesting::AccessTest()
{
    RendererParameter firstRendererParameter("Configuration/Renderer.json");

    ASSERT_ENUM_EQUAL(firstRendererParameter.GetRendererType(), RendererTypes::Glut);

    ASSERT_ENUM_EQUAL(firstRendererParameter.GetColorFormat(), TextureFormat::A8R8G8B8);
    ASSERT_ENUM_EQUAL(firstRendererParameter.GetDepthStencilFormat(), TextureFormat::D24S8);
    ASSERT_EQUAL(firstRendererParameter.GetNumMultisamples(), 1);

    ASSERT_TRUE(Approximate(firstRendererParameter.GetClearColor(), Colour<float>(0.0f, 0.0f, 0.0f, 1.0f), 1e-8f));

    ASSERT_EQUAL(firstRendererParameter.GetXPosition(), 0);
    ASSERT_EQUAL(firstRendererParameter.GetYPosition(), 0);
    ASSERT_EQUAL(firstRendererParameter.GetWidth(), 1024);
    ASSERT_EQUAL(firstRendererParameter.GetHeight(), 768);
    ASSERT_TRUE(firstRendererParameter.IsAllowResize());

    firstRendererParameter.Resize(100, 10);

    ASSERT_EQUAL(firstRendererParameter.GetWidth(), 100);
    ASSERT_EQUAL(firstRendererParameter.GetHeight(), 10);

    RendererBasis rendererBasis = firstRendererParameter.GetRendererBasis();

    ASSERT_ENUM_EQUAL(rendererBasis.GetColorFormat(), TextureFormat::A8R8G8B8);
    ASSERT_ENUM_EQUAL(rendererBasis.GetDepthStencilFormat(), TextureFormat::D24S8);
    ASSERT_EQUAL(rendererBasis.GetNumMultisamples(), 1);

    ASSERT_EQUAL(rendererBasis.GetWidth(), 100);
    ASSERT_EQUAL(rendererBasis.GetHeight(), 10);
}

void Rendering::RendererParameterTesting::ConstructionTest()
{
    RendererParameter firstRendererParameter("Configuration/Renderer.json");
    firstRendererParameter.LoadConfiguration("Configuration/RendererCopy.json");

    ASSERT_ENUM_EQUAL(firstRendererParameter.GetRendererType(), RendererTypes::OpenGL);

    ASSERT_ENUM_EQUAL(firstRendererParameter.GetColorFormat(), TextureFormat::R8G8B8);
    ASSERT_ENUM_EQUAL(firstRendererParameter.GetDepthStencilFormat(), TextureFormat::D24S8);
    ASSERT_EQUAL(firstRendererParameter.GetNumMultisamples(), 2);

    ASSERT_TRUE(Approximate(firstRendererParameter.GetClearColor(), Colour<float>(1.0f, 1.0f, 1.0f, 0.0f), 1e-8f));

    ASSERT_EQUAL(firstRendererParameter.GetWindowTitle(), "RenderingTesting");
    ASSERT_EQUAL(firstRendererParameter.GetXPosition(), 10);
    ASSERT_EQUAL(firstRendererParameter.GetYPosition(), 10);
    ASSERT_EQUAL(firstRendererParameter.GetWidth(), 102);
    ASSERT_EQUAL(firstRendererParameter.GetHeight(), 76);
    ASSERT_FALSE(firstRendererParameter.IsAllowResize());

    RendererBasis rendererBasis = firstRendererParameter.GetRendererBasis();

    ASSERT_ENUM_EQUAL(rendererBasis.GetColorFormat(), TextureFormat::R8G8B8);
    ASSERT_ENUM_EQUAL(rendererBasis.GetDepthStencilFormat(), TextureFormat::D24S8);
    ASSERT_EQUAL(rendererBasis.GetNumMultisamples(), 2);

    ASSERT_EQUAL(rendererBasis.GetWidth(), 102);
    ASSERT_EQUAL(rendererBasis.GetHeight(), 76);
}
