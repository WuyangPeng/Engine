// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/09 10:29)

#include "RendererBasisTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/Renderers/RendererBasis.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, RendererBasisTesting)

void Rendering::RendererBasisTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
}

void Rendering::RendererBasisTesting::AccessTest()
{
    RendererBasis rendererBasis;

    ASSERT_EQUAL(rendererBasis.GetWidth(), 0);
    ASSERT_EQUAL(rendererBasis.GetHeight(), 0);
    ASSERT_EQUAL(rendererBasis.GetNumMultisamples(), 0);
    ASSERT_ENUM_EQUAL(rendererBasis.GetColorFormat(), TextureFormat::DefaultColour);
    ASSERT_ENUM_EQUAL(rendererBasis.GetDepthStencilFormat(), TextureFormat::DefaultDepth);

    rendererBasis.SetSize(50, 70);

    ASSERT_EQUAL(rendererBasis.GetWidth(), 50);
    ASSERT_EQUAL(rendererBasis.GetHeight(), 70);
    ASSERT_EQUAL(rendererBasis.GetNumMultisamples(), 0);
    ASSERT_ENUM_EQUAL(rendererBasis.GetColorFormat(), TextureFormat::DefaultColour);
    ASSERT_ENUM_EQUAL(rendererBasis.GetDepthStencilFormat(), TextureFormat::DefaultDepth);

    rendererBasis.SetMultisamplesNumber(7);

    ASSERT_EQUAL(rendererBasis.GetNumMultisamples(), 7);

    rendererBasis.SetTextureFormat(TextureFormat::A8, TextureFormat::D24S8);

    ASSERT_ENUM_EQUAL(rendererBasis.GetColorFormat(), TextureFormat::A8);
    ASSERT_ENUM_EQUAL(rendererBasis.GetDepthStencilFormat(), TextureFormat::D24S8);
}

void Rendering::RendererBasisTesting::ConstructionTest()
{
    const RendererBasis rendererBasis(1024, 768, TextureFormat::A8, TextureFormat::D24S8, 1);

    ASSERT_EQUAL(rendererBasis.GetWidth(), 1024);
    ASSERT_EQUAL(rendererBasis.GetHeight(), 768);
    ASSERT_EQUAL(rendererBasis.GetNumMultisamples(), 1);
    ASSERT_ENUM_EQUAL(rendererBasis.GetColorFormat(), TextureFormat::A8);
    ASSERT_ENUM_EQUAL(rendererBasis.GetDepthStencilFormat(), TextureFormat::D24S8);
}
