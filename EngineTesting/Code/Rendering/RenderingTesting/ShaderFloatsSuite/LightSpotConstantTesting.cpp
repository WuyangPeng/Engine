///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:23)

#include "LightSpotConstantTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Rendering/SceneGraph/LoadVisual.h"
#include "Rendering/ShaderFloats/LightSpotConstant.h"

#include <random>

Rendering::LightSpotConstantTesting::LightSpotConstantTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, LightSpotConstantTesting)

void Rendering::LightSpotConstantTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::LightSpotConstantTesting::MainTest()
{
    CameraManager::Create();

    CoreTools::InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UpdateTest);

    CoreTools::InitTerm::ExecuteTerminator();

    CameraManager::Destroy();
}

void Rendering::LightSpotConstantTesting::InitTest()
{
    std::default_random_engine generator;
    const std::uniform_real<float> firstFloatRandomDistribution(-100.0f, 100.0f);
    std::uniform_real<float> secondFloatRandomDistribution(0.0f, 1.0f);

    for (int loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        const LightSharedPtr firstLight(std::make_shared<Light>(Mathematics::MathF::GetZeroTolerance()));

        const float exponent = secondFloatRandomDistribution(generator);
        firstLight->SetExponent(exponent);

        const Colour<float> ambient(secondFloatRandomDistribution(generator),
                                    secondFloatRandomDistribution(generator),
                                    secondFloatRandomDistribution(generator),
                                    secondFloatRandomDistribution(generator));
        const Colour<float> diffuse(secondFloatRandomDistribution(generator),
                                    secondFloatRandomDistribution(generator),
                                    secondFloatRandomDistribution(generator),
                                    secondFloatRandomDistribution(generator));
        const Colour<float> specular(secondFloatRandomDistribution(generator),
                                     secondFloatRandomDistribution(generator),
                                     secondFloatRandomDistribution(generator),
                                     secondFloatRandomDistribution(generator));

        firstLight->SetAmbient(ambient);
        firstLight->SetDiffuse(diffuse);
        firstLight->SetSpecular(specular);

        const float constant = secondFloatRandomDistribution(generator);
        const float linear = secondFloatRandomDistribution(generator);
        const float quadratic = secondFloatRandomDistribution(generator);
        const float intensity = secondFloatRandomDistribution(generator);

        firstLight->SetAttenuation(constant, linear, quadratic, intensity);

        constexpr int numRegisters = 1;
        LightSpotConstant firstShaderFloat(firstLight);
        ASSERT_EQUAL(firstShaderFloat.GetNumRegisters(), numRegisters);

        firstShaderFloat.SetNumRegisters(numRegisters);
        ASSERT_EQUAL(firstShaderFloat.GetNumRegisters(), numRegisters);

        ASSERT_UNEQUAL_NULL_PTR(firstShaderFloat.GetData());

        ASSERT_TRUE(firstShaderFloat.AllowUpdater());
        firstShaderFloat.DisableUpdater();
        ASSERT_FALSE(firstShaderFloat.AllowUpdater());
        firstShaderFloat.EnableUpdater();
        ASSERT_TRUE(firstShaderFloat.AllowUpdater());

        std::vector<float> firstData(4, 1);
        firstShaderFloat.SetRegisters(firstData);

        for (int i = 0; i < 4; ++i)
        {
            ASSERT_APPROXIMATE(firstData.at(i), firstShaderFloat.GetRegisters().at(i), 1e-8f);
        }

        const LightSpotConstant secondShaderFloat(firstLight);
        ASSERT_EQUAL(secondShaderFloat.GetNumRegisters(), numRegisters);
        ASSERT_UNEQUAL_NULL_PTR(secondShaderFloat.GetData());
        ASSERT_TRUE(secondShaderFloat.AllowUpdater());

        LightSpotConstant thirdShaderFloat(firstLight);
        ASSERT_EQUAL(thirdShaderFloat.GetNumRegisters(), numRegisters);

        ASSERT_UNEQUAL_NULL_PTR(thirdShaderFloat.GetData());

        ASSERT_TRUE(thirdShaderFloat.AllowUpdater());
        thirdShaderFloat.DisableUpdater();
        ASSERT_FALSE(thirdShaderFloat.AllowUpdater());
        thirdShaderFloat.EnableUpdater();
        ASSERT_TRUE(thirdShaderFloat.AllowUpdater());

        std::vector<float> secondData;
        for (int registerIndex = 0; registerIndex < 4; ++registerIndex)
        {
            secondData.push_back(static_cast<float>(registerIndex));
        }

        thirdShaderFloat.SetRegister(0, secondData);

        ASSERT_EQUAL(secondData, thirdShaderFloat.GetRegister(0));

        for (int registerIndex = 0; registerIndex < 4; ++registerIndex)
        {
            ASSERT_APPROXIMATE(thirdShaderFloat[registerIndex], registerIndex, 1e-8f);
        }

        ASSERT_EQUAL(firstShaderFloat.GetLight(), firstLight);
        ASSERT_EQUAL(secondShaderFloat.GetLight(), firstLight);
        ASSERT_EQUAL(thirdShaderFloat.GetLight(), firstLight);
    }
}

void Rendering::LightSpotConstantTesting::CopyTest()
{
    std::default_random_engine generator;
    const std::uniform_real<float> firstFloatRandomDistribution(-100.0f, 100.0f);
    std::uniform_real<float> secondFloatRandomDistribution(0.0f, 1.0f);

    for (int loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        const LightSharedPtr firstLight(std::make_shared<Light>(Mathematics::MathF::GetZeroTolerance()));

        const float exponent = secondFloatRandomDistribution(generator);
        firstLight->SetExponent(exponent);

        const Colour<float> ambient(secondFloatRandomDistribution(generator),
                                    secondFloatRandomDistribution(generator),
                                    secondFloatRandomDistribution(generator),
                                    secondFloatRandomDistribution(generator));
        const Colour<float> diffuse(secondFloatRandomDistribution(generator),
                                    secondFloatRandomDistribution(generator),
                                    secondFloatRandomDistribution(generator),
                                    secondFloatRandomDistribution(generator));
        const Colour<float> specular(secondFloatRandomDistribution(generator),
                                     secondFloatRandomDistribution(generator),
                                     secondFloatRandomDistribution(generator),
                                     secondFloatRandomDistribution(generator));

        firstLight->SetAmbient(ambient);
        firstLight->SetDiffuse(diffuse);
        firstLight->SetSpecular(specular);

        const float constant = secondFloatRandomDistribution(generator);
        const float linear = secondFloatRandomDistribution(generator);
        const float quadratic = secondFloatRandomDistribution(generator);
        const float intensity = secondFloatRandomDistribution(generator);

        firstLight->SetAttenuation(constant, linear, quadratic, intensity);

        LightSpotConstant firstShaderFloat(firstLight);
        ASSERT_EQUAL(firstShaderFloat.GetNumRegisters(), 1);

        LightSpotConstant secondShaderFloat(firstShaderFloat);
        ASSERT_EQUAL(secondShaderFloat.GetNumRegisters(), 1);

        for (int registerIndex = 0; registerIndex < 4; ++registerIndex)
        {
            firstShaderFloat[registerIndex] = static_cast<float>(registerIndex);
        }

        for (int registerIndex = 0; registerIndex < 4; ++registerIndex)
        {
            ASSERT_APPROXIMATE(secondShaderFloat[registerIndex], 0.0f, 1e-8f);
            ASSERT_APPROXIMATE(firstShaderFloat[registerIndex], static_cast<float>(registerIndex), 1e-8f);
        }

        LightSpotConstant thirdShaderFloat(firstLight);
        thirdShaderFloat = firstShaderFloat;
        firstShaderFloat = secondShaderFloat;

        for (int registerIndex = 0; registerIndex < 4; ++registerIndex)
        {
            ASSERT_APPROXIMATE(firstShaderFloat[registerIndex], 0.0f, 1e-8f);
            ASSERT_APPROXIMATE(secondShaderFloat[registerIndex], 0.0f, 1e-8f);
            ASSERT_APPROXIMATE(thirdShaderFloat[registerIndex], static_cast<float>(registerIndex), 1e-8f);
        }

        ASSERT_EQUAL(firstShaderFloat.GetLight(), firstLight);
        ASSERT_EQUAL(secondShaderFloat.GetLight(), firstLight);
        ASSERT_EQUAL(thirdShaderFloat.GetLight(), firstLight);
    }
}

void Rendering::LightSpotConstantTesting::StreamTest() noexcept
{
}

void Rendering::LightSpotConstantTesting::UpdateTest() noexcept
{
}
