// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/07 14:35)

#include "SingleShaderSamplerDataTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/DataTypes/ColourDetail.h"
#include "Rendering/Shaders/SingleShaderSamplerData.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, SingleShaderSamplerDataTesting)

void Rendering::SingleShaderSamplerDataTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
}

void Rendering::SingleShaderSamplerDataTesting::InitTest()
{
    SingleShaderSamplerData firstSingleShaderSamplerData{ CoreTools::DisableNotThrow::Disable };

    ASSERT_EQUAL(firstSingleShaderSamplerData.GetSamplerName(), "");
    ASSERT_ENUM_EQUAL(firstSingleShaderSamplerData.GetSamplerType(), ShaderFlags::SamplerType::None);
    ASSERT_ENUM_EQUAL(firstSingleShaderSamplerData.GetFilter(), ShaderFlags::SamplerFilter::Nearest);
    ASSERT_APPROXIMATE(firstSingleShaderSamplerData.GetLodBias(), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstSingleShaderSamplerData.GetAnisotropy(), 1.0f, 1e-8f);

    ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, firstSingleShaderSamplerData.GetBorderColor(), Colour<float>(0.0f, 0.0f, 0.0f, 0.0f), 1e-8f);

    ASSERT_ENUM_EQUAL(firstSingleShaderSamplerData.GetCoordinate(0), ShaderFlags::SamplerCoordinate::ClampEdge);
    ASSERT_ENUM_EQUAL(firstSingleShaderSamplerData.GetCoordinate(1), ShaderFlags::SamplerCoordinate::ClampEdge);
    ASSERT_ENUM_EQUAL(firstSingleShaderSamplerData.GetCoordinate(2), ShaderFlags::SamplerCoordinate::ClampEdge);

    firstSingleShaderSamplerData.SetSampler("Sampler", ShaderFlags::SamplerType::Sampler1D);

    ASSERT_EQUAL(firstSingleShaderSamplerData.GetSamplerName(), "Sampler");
    ASSERT_ENUM_EQUAL(firstSingleShaderSamplerData.GetSamplerType(), ShaderFlags::SamplerType::Sampler1D);

    firstSingleShaderSamplerData.SetFilter(ShaderFlags::SamplerFilter::LinearNeares);
    ASSERT_ENUM_EQUAL(firstSingleShaderSamplerData.GetFilter(), ShaderFlags::SamplerFilter::LinearNeares);

    firstSingleShaderSamplerData.SetLodBias(0.5f);
    ASSERT_APPROXIMATE(firstSingleShaderSamplerData.GetLodBias(), 0.5f, 1e-8f);

    firstSingleShaderSamplerData.SetAnisotropy(0.44f);
    ASSERT_APPROXIMATE(firstSingleShaderSamplerData.GetAnisotropy(), 0.44f, 1e-8f);

    firstSingleShaderSamplerData.SetBorderColor(Colour<float>(1.0f, 1.0f, 1.0f, 1.0f));
    ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, firstSingleShaderSamplerData.GetBorderColor(), Colour<float>(1.0f, 1.0f, 1.0f, 1.0f), 1e-8f);

    firstSingleShaderSamplerData.SetCoordinate(0, ShaderFlags::SamplerCoordinate::ClampBorder);
    firstSingleShaderSamplerData.SetCoordinate(1, ShaderFlags::SamplerCoordinate::Repeat);
    firstSingleShaderSamplerData.SetCoordinate(2, ShaderFlags::SamplerCoordinate::Clamp);
    ASSERT_ENUM_EQUAL(firstSingleShaderSamplerData.GetCoordinate(0), ShaderFlags::SamplerCoordinate::ClampBorder);
    ASSERT_ENUM_EQUAL(firstSingleShaderSamplerData.GetCoordinate(1), ShaderFlags::SamplerCoordinate::Repeat);
    ASSERT_ENUM_EQUAL(firstSingleShaderSamplerData.GetCoordinate(2), ShaderFlags::SamplerCoordinate::Clamp);
}

void Rendering::SingleShaderSamplerDataTesting::CopyTest()
{
    SingleShaderSamplerData firstSingleShaderSamplerData{ CoreTools::DisableNotThrow::Disable };
    firstSingleShaderSamplerData.SetSampler("Sampler0", ShaderFlags::SamplerType::Sampler2D);
    firstSingleShaderSamplerData.SetLodBias(0.15f);
    firstSingleShaderSamplerData.SetAnisotropy(0.144f);
    firstSingleShaderSamplerData.SetBorderColor(Colour<float>(1.0f, 1.0f, 0.5f, 1.0f));
    firstSingleShaderSamplerData.SetCoordinate(0, ShaderFlags::SamplerCoordinate::Repeat);
    firstSingleShaderSamplerData.SetCoordinate(1, ShaderFlags::SamplerCoordinate::MirroredRepeat);
    firstSingleShaderSamplerData.SetCoordinate(2, ShaderFlags::SamplerCoordinate::ClampBorder);

    SingleShaderSamplerData secondSingleShaderSamplerData(firstSingleShaderSamplerData);

    ASSERT_EQUAL(firstSingleShaderSamplerData.GetSamplerName(), secondSingleShaderSamplerData.GetSamplerName());
    ASSERT_ENUM_EQUAL(firstSingleShaderSamplerData.GetSamplerType(), secondSingleShaderSamplerData.GetSamplerType());
    ASSERT_ENUM_EQUAL(firstSingleShaderSamplerData.GetFilter(), secondSingleShaderSamplerData.GetFilter());
    ASSERT_APPROXIMATE(firstSingleShaderSamplerData.GetLodBias(), secondSingleShaderSamplerData.GetLodBias(), 1e-8f);
    ASSERT_APPROXIMATE(firstSingleShaderSamplerData.GetAnisotropy(), secondSingleShaderSamplerData.GetAnisotropy(), 1e-8f);

    ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, firstSingleShaderSamplerData.GetBorderColor(), secondSingleShaderSamplerData.GetBorderColor(), 1e-8f);

    ASSERT_ENUM_EQUAL(firstSingleShaderSamplerData.GetCoordinate(0), secondSingleShaderSamplerData.GetCoordinate(0));
    ASSERT_ENUM_EQUAL(firstSingleShaderSamplerData.GetCoordinate(1), secondSingleShaderSamplerData.GetCoordinate(1));
    ASSERT_ENUM_EQUAL(firstSingleShaderSamplerData.GetCoordinate(2), secondSingleShaderSamplerData.GetCoordinate(2));

    firstSingleShaderSamplerData.SetCoordinate(0, ShaderFlags::SamplerCoordinate::ClampBorder);
    ASSERT_ENUM_EQUAL(firstSingleShaderSamplerData.GetCoordinate(0), ShaderFlags::SamplerCoordinate::ClampBorder);
    ASSERT_ENUM_EQUAL(ShaderFlags::SamplerCoordinate::Repeat, secondSingleShaderSamplerData.GetCoordinate(0));

    SingleShaderSamplerData thirdSingleShaderSamplerData{ CoreTools::DisableNotThrow::Disable };

    secondSingleShaderSamplerData = thirdSingleShaderSamplerData;

    ASSERT_EQUAL(thirdSingleShaderSamplerData.GetSamplerName(), secondSingleShaderSamplerData.GetSamplerName());
    ASSERT_ENUM_EQUAL(thirdSingleShaderSamplerData.GetSamplerType(), secondSingleShaderSamplerData.GetSamplerType());
    ASSERT_ENUM_EQUAL(thirdSingleShaderSamplerData.GetFilter(), secondSingleShaderSamplerData.GetFilter());
    ASSERT_APPROXIMATE(thirdSingleShaderSamplerData.GetLodBias(), secondSingleShaderSamplerData.GetLodBias(), 1e-8f);
    ASSERT_APPROXIMATE(thirdSingleShaderSamplerData.GetAnisotropy(), secondSingleShaderSamplerData.GetAnisotropy(), 1e-8f);

    ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, thirdSingleShaderSamplerData.GetBorderColor(), secondSingleShaderSamplerData.GetBorderColor(), 1e-8f);

    ASSERT_ENUM_EQUAL(thirdSingleShaderSamplerData.GetCoordinate(0), secondSingleShaderSamplerData.GetCoordinate(0));
    ASSERT_ENUM_EQUAL(thirdSingleShaderSamplerData.GetCoordinate(1), secondSingleShaderSamplerData.GetCoordinate(1));
    ASSERT_ENUM_EQUAL(thirdSingleShaderSamplerData.GetCoordinate(2), secondSingleShaderSamplerData.GetCoordinate(2));

    thirdSingleShaderSamplerData.SetAnisotropy(0.2f);

    ASSERT_APPROXIMATE(thirdSingleShaderSamplerData.GetAnisotropy(), 0.2f, 1e-8f);
    ASSERT_APPROXIMATE(secondSingleShaderSamplerData.GetAnisotropy(), 1.0f, 1e-8f);
}
