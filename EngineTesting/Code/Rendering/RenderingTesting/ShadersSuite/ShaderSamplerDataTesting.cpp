// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/07 14:33)

#include "ShaderSamplerDataTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/Shaders/ShaderSamplerData.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, ShaderSamplerDataTesting)

void Rendering::ShaderSamplerDataTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
}

void Rendering::ShaderSamplerDataTesting::InitTest()
{
    ShaderSamplerData firstShaderSamplerData{ 0 };

    ASSERT_EQUAL(firstShaderSamplerData.GetNumSamplers(), 0);

    firstShaderSamplerData.Resize(10);

    ASSERT_EQUAL(firstShaderSamplerData.GetNumSamplers(), 10);

    for (int i = 0; i < firstShaderSamplerData.GetNumSamplers(); ++i)
    {
        ASSERT_EQUAL(firstShaderSamplerData.GetSamplerName(i), "");
        ASSERT_ENUM_EQUAL(firstShaderSamplerData.GetSamplerType(i), ShaderFlags::SamplerType::None);
        ASSERT_ENUM_EQUAL(firstShaderSamplerData.GetFilter(i), ShaderFlags::SamplerFilter::Nearest);
        ASSERT_ENUM_EQUAL(firstShaderSamplerData.GetCoordinate(i, 0), ShaderFlags::SamplerCoordinate::ClampEdge);
        ASSERT_ENUM_EQUAL(firstShaderSamplerData.GetCoordinate(i, 1), ShaderFlags::SamplerCoordinate::ClampEdge);
        ASSERT_ENUM_EQUAL(firstShaderSamplerData.GetCoordinate(i, 2), ShaderFlags::SamplerCoordinate::ClampEdge);
        ASSERT_APPROXIMATE(firstShaderSamplerData.GetLodBias(0), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(firstShaderSamplerData.GetAnisotropy(0), 1.0f, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, firstShaderSamplerData.GetBorderColor(i), Colour<float>(0.0f, 0.0f, 0.0f, 0.0f), 1e-8f);
    }

    firstShaderSamplerData.SetSampler(0, "Sampler", ShaderFlags::SamplerType::Sampler2D);

    ASSERT_EQUAL(firstShaderSamplerData.GetSamplerName(0), "Sampler");
    ASSERT_ENUM_EQUAL(firstShaderSamplerData.GetSamplerType(0), ShaderFlags::SamplerType::Sampler2D);

    firstShaderSamplerData.SetFilter(1, ShaderFlags::SamplerFilter::NearesLinear);

    ASSERT_ENUM_EQUAL(firstShaderSamplerData.GetFilter(1), ShaderFlags::SamplerFilter::NearesLinear);

    firstShaderSamplerData.SetCoordinate(2, 0, ShaderFlags::SamplerCoordinate::ClampBorder);
    firstShaderSamplerData.SetCoordinate(3, 1, ShaderFlags::SamplerCoordinate::Repeat);
    firstShaderSamplerData.SetCoordinate(4, 2, ShaderFlags::SamplerCoordinate::Clamp);

    ASSERT_ENUM_EQUAL(firstShaderSamplerData.GetCoordinate(2, 0), ShaderFlags::SamplerCoordinate::ClampBorder);
    ASSERT_ENUM_EQUAL(firstShaderSamplerData.GetCoordinate(3, 1), ShaderFlags::SamplerCoordinate::Repeat);
    ASSERT_ENUM_EQUAL(firstShaderSamplerData.GetCoordinate(4, 2), ShaderFlags::SamplerCoordinate::Clamp);

    firstShaderSamplerData.SetLodBias(5, 0.4f);

    ASSERT_APPROXIMATE(firstShaderSamplerData.GetLodBias(5), 0.4f, 1e-8f);

    firstShaderSamplerData.SetAnisotropy(6, 9.0f);
    ASSERT_APPROXIMATE(firstShaderSamplerData.GetAnisotropy(6), 9.0f, 1e-8f);

    firstShaderSamplerData.SetBorderColor(7, Colour<float>(1.0f, 1.0f, 0.0f, 0.0f));

    ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, firstShaderSamplerData.GetBorderColor(7), Colour<float>(1.0f, 1.0f, 0.0f, 0.0f), 1e-8f);

    ShaderSamplerData secondShaderSamplerData(12);

    ASSERT_EQUAL(secondShaderSamplerData.GetNumSamplers(), 12);
}

void Rendering::ShaderSamplerDataTesting::CopyTest()
{
    ShaderSamplerData firstShaderSamplerData(2);
    ShaderSamplerData secondShaderSamplerData(firstShaderSamplerData);

    firstShaderSamplerData.SetAnisotropy(0, 9.0f);

    ASSERT_APPROXIMATE(firstShaderSamplerData.GetAnisotropy(0), 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondShaderSamplerData.GetAnisotropy(0), 1.0f, 1e-8f);

    ShaderSamplerData thirdShaderSamplerData(20);

    secondShaderSamplerData = thirdShaderSamplerData;

    thirdShaderSamplerData.SetBorderColor(0, Colour<float>(1.0f, 1.0f, 0.0f, 0.0f));

    ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, thirdShaderSamplerData.GetBorderColor(0), Colour<float>(1.0f, 1.0f, 0.0f, 0.0f), 1e-8f);
    ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, secondShaderSamplerData.GetBorderColor(0), Colour<float>(0.0f, 0.0f, 0.0f, 0.0f), 1e-8f);
}
