///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/11 18:51)

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
