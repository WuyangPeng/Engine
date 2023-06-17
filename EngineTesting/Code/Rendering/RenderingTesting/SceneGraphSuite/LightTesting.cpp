///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:32)

#include "LightTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Rendering/SceneGraph/Light.h"

#include <random>
#include <vector>

Rendering::LightTesting::LightTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, LightTesting)

void Rendering::LightTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::LightTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

    CoreTools::InitTerm::ExecuteTerminator();
}

void Rendering::LightTesting::BaseTest()
{
    std::default_random_engine generator;
    const std::uniform_real<float> firstFloatRandomDistribution(-100.0f, 100.0f);

    const std::uniform_real<float> secondFloatRandomDistribution(0.0f, 1.0f);

    Light firstLight(LightType::Ambient);

    ASSERT_ENUM_EQUAL(firstLight.GetType(), LightType::Ambient);

    firstLight.SetType(LightType::Directional);

    ASSERT_ENUM_EQUAL(firstLight.GetType(), LightType::Directional);

    for (int loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        const float exponent = secondFloatRandomDistribution(generator);

        firstLight.SetExponent(exponent);

        ASSERT_APPROXIMATE(exponent, firstLight.GetExponent(), 1e-8f);

        const Colour<float> ambient(firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator));
        const Colour<float> diffuse(firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator));
        const Colour<float> specular(firstFloatRandomDistribution(generator),
                                     firstFloatRandomDistribution(generator),
                                     firstFloatRandomDistribution(generator),
                                     firstFloatRandomDistribution(generator));

        firstLight.SetAmbient(ambient);
        firstLight.SetDiffuse(diffuse);
        firstLight.SetSpecular(specular);

        ASSERT_TRUE(Approximate(firstLight.GetAmbient(), ambient, 1e-8f));
        ASSERT_TRUE(Approximate(firstLight.GetDiffuse(), diffuse, 1e-8f));
        ASSERT_TRUE(Approximate(firstLight.GetSpecular(), specular, 1e-8f));

        const Light::APoint firstPosition(firstFloatRandomDistribution(generator),
                                          firstFloatRandomDistribution(generator),
                                          firstFloatRandomDistribution(generator));

        firstLight.SetPosition(firstPosition);

        ASSERT_TRUE(Approximate(firstPosition, firstLight.GetPosition(), 1e-8f));

        const float constant = secondFloatRandomDistribution(generator);
        const float linear = secondFloatRandomDistribution(generator);
        const float quadratic = secondFloatRandomDistribution(generator);
        const float intensity = secondFloatRandomDistribution(generator);

        firstLight.SetAttenuation(constant, linear, quadratic, intensity);

        ASSERT_APPROXIMATE(firstLight.GetConstant(), constant, 1e-8f);
        ASSERT_APPROXIMATE(firstLight.GetLinear(), linear, 1e-8f);
        ASSERT_APPROXIMATE(firstLight.GetQuadratic(), quadratic, 1e-8f);
        ASSERT_APPROXIMATE(firstLight.GetIntensity(), intensity, 1e-8f);
    }
}

void Rendering::LightTesting::CalculateTest()
{
    std::default_random_engine generator;
    const std::uniform_real<float> firstFloatRandomDistribution(-100.0f, 100.0f);
    const std::uniform_real<float> secondFloatRandomDistribution(0.0f, Mathematics::MathF::GetPI());

    for (int loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        Light firstLight(LightType::Ambient, 1e-5f);

        const float angle(Mathematics::MathF::FAbs(secondFloatRandomDistribution(generator)));

        firstLight.SetAngle(angle);

        ASSERT_APPROXIMATE(angle, firstLight.GetAngle(), 1e-8f);
        ASSERT_APPROXIMATE(Mathematics::MathF::Cos(angle), firstLight.GetCosAngle(), 1e-8f);
        ASSERT_APPROXIMATE(Mathematics::MathF::Sin(angle), firstLight.GetSinAngle(), 1e-8f);

        Light::AVector firstVector(firstFloatRandomDistribution(generator),
                                   firstFloatRandomDistribution(generator),
                                   firstFloatRandomDistribution(generator));

        firstVector.Normalize();

        Light::AVector secondVector(firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator));

        secondVector.Normalize();

        Light::AVector thirdVector(firstFloatRandomDistribution(generator),
                                   firstFloatRandomDistribution(generator),
                                   firstFloatRandomDistribution(generator));

        thirdVector.Normalize();
    }
}

void Rendering::LightTesting::CopyTest()
{
    std::default_random_engine generator;
    const std::uniform_real<float> firstFloatRandomDistribution(-100.0f, 100.0f);
    const std::uniform_real<float> secondFloatRandomDistribution(0.0f, Mathematics::MathF::GetPI());
    const std::uniform_real<float> thirdFloatRandomDistribution(0.0f, 1.0f);

    for (int loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        Light firstLight(LightType::Ambient);

        const float exponent = secondFloatRandomDistribution(generator);

        firstLight.SetExponent(exponent);

        const Colour<float> ambient(firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator));
        const Colour<float> diffuse(firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator));
        const Colour<float> specular(firstFloatRandomDistribution(generator),
                                     firstFloatRandomDistribution(generator),
                                     firstFloatRandomDistribution(generator),
                                     firstFloatRandomDistribution(generator));

        firstLight.SetAmbient(ambient);
        firstLight.SetDiffuse(diffuse);
        firstLight.SetSpecular(specular);

        const Light::APoint firstPosition(firstFloatRandomDistribution(generator),
                                          firstFloatRandomDistribution(generator),
                                          firstFloatRandomDistribution(generator));

        firstLight.SetPosition(firstPosition);

        const float constant = thirdFloatRandomDistribution(generator);
        const float linear = thirdFloatRandomDistribution(generator);
        const float quadratic = thirdFloatRandomDistribution(generator);
        const float intensity = thirdFloatRandomDistribution(generator);

        firstLight.SetAttenuation(constant, linear, quadratic, intensity);

        const float angle(Mathematics::MathF::FAbs(secondFloatRandomDistribution(generator)));

        firstLight.SetAngle(angle);

        Light::AVector firstVector(firstFloatRandomDistribution(generator),
                                   firstFloatRandomDistribution(generator),
                                   firstFloatRandomDistribution(generator));

        firstVector.Normalize();

        firstLight.SetDirection(firstVector);

        Light secondLight(firstLight);

        ASSERT_ENUM_EQUAL(firstLight.GetType(), secondLight.GetType());
        ASSERT_APPROXIMATE(firstLight.GetAngle(), secondLight.GetAngle(), 1e-8f);
        ASSERT_APPROXIMATE(firstLight.GetCosAngle(), secondLight.GetCosAngle(), 1e-8f);
        ASSERT_APPROXIMATE(firstLight.GetSinAngle(), secondLight.GetSinAngle(), 1e-8f);
        ASSERT_APPROXIMATE(firstLight.GetExponent(), secondLight.GetExponent(), 1e-8f);
        ASSERT_TRUE(Approximate(firstLight.GetAmbient(), secondLight.GetAmbient(), 1e-8f));
        ASSERT_TRUE(Approximate(firstLight.GetDiffuse(), secondLight.GetDiffuse(), 1e-8f));
        ASSERT_TRUE(Approximate(firstLight.GetSpecular(), secondLight.GetSpecular(), 1e-8f));
        ASSERT_TRUE(Approximate(firstLight.GetPosition(), secondLight.GetPosition(), 1e-8f));
        ASSERT_TRUE(Approximate(firstLight.GetDirectionVector(), secondLight.GetDirectionVector(), 1e-8f));
        ASSERT_TRUE(Approximate(firstLight.GetUpVector(), secondLight.GetUpVector(), 1e-8f));
        ASSERT_TRUE(Approximate(firstLight.GetRightVector(), secondLight.GetRightVector(), 1e-8f));
        ASSERT_APPROXIMATE(firstLight.GetConstant(), secondLight.GetConstant(), 1e-8f);
        ASSERT_APPROXIMATE(firstLight.GetLinear(), secondLight.GetLinear(), 1e-8f);
        ASSERT_APPROXIMATE(firstLight.GetQuadratic(), secondLight.GetQuadratic(), 1e-8f);
        ASSERT_APPROXIMATE(firstLight.GetIntensity(), secondLight.GetIntensity(), 1e-8f);

        Light thirdLight{ LightType::Ambient };
        thirdLight = secondLight;

        ASSERT_ENUM_EQUAL(thirdLight.GetType(), secondLight.GetType());
        ASSERT_APPROXIMATE(thirdLight.GetAngle(), secondLight.GetAngle(), 1e-8f);
        ASSERT_APPROXIMATE(thirdLight.GetCosAngle(), secondLight.GetCosAngle(), 1e-8f);
        ASSERT_APPROXIMATE(thirdLight.GetSinAngle(), secondLight.GetSinAngle(), 1e-8f);
        ASSERT_APPROXIMATE(thirdLight.GetExponent(), secondLight.GetExponent(), 1e-8f);
        ASSERT_TRUE(Approximate(thirdLight.GetAmbient(), secondLight.GetAmbient(), 1e-8f));
        ASSERT_TRUE(Approximate(thirdLight.GetDiffuse(), secondLight.GetDiffuse(), 1e-8f));
        ASSERT_TRUE(Approximate(thirdLight.GetSpecular(), secondLight.GetSpecular(), 1e-8f));
        ASSERT_TRUE(Approximate(thirdLight.GetPosition(), secondLight.GetPosition(), 1e-8f));
        ASSERT_TRUE(Approximate(thirdLight.GetDirectionVector(), secondLight.GetDirectionVector(), 1e-8f));
        ASSERT_TRUE(Approximate(thirdLight.GetUpVector(), secondLight.GetUpVector(), 1e-8f));
        ASSERT_TRUE(Approximate(thirdLight.GetRightVector(), secondLight.GetRightVector(), 1e-8f));
        ASSERT_APPROXIMATE(thirdLight.GetConstant(), secondLight.GetConstant(), 1e-8f);
        ASSERT_APPROXIMATE(thirdLight.GetLinear(), secondLight.GetLinear(), 1e-8f);
        ASSERT_APPROXIMATE(thirdLight.GetQuadratic(), secondLight.GetQuadratic(), 1e-8f);
        ASSERT_APPROXIMATE(thirdLight.GetIntensity(), secondLight.GetIntensity(), 1e-8f);

        secondLight.SetType(LightType::Directional);

        ASSERT_ENUM_UNEQUAL(secondLight.GetType(), firstLight.GetType());
        ASSERT_ENUM_UNEQUAL(secondLight.GetType(), thirdLight.GetType());
        ASSERT_ENUM_EQUAL(firstLight.GetType(), thirdLight.GetType());
        ASSERT_ENUM_EQUAL(firstLight.GetType(), LightType::Ambient);
    }
}

void Rendering::LightTesting::StreamTest() noexcept
{
}
