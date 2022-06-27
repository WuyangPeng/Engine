///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/15 16:52)

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
