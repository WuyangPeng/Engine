///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 15:18)

#include "LightAmbientConstantTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Rendering/SceneGraph/LoadVisual.h"
#include "Rendering/ShaderFloats/LightAmbientConstant.h"

#include <random>

Rendering::LightAmbientConstantTesting::LightAmbientConstantTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, LightAmbientConstantTesting)

void Rendering::LightAmbientConstantTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::LightAmbientConstantTesting::MainTest()
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

void Rendering::LightAmbientConstantTesting::InitTest()
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
        LightAmbientConstant firstShaderFloat(firstLight);
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

        const LightAmbientConstant secondShaderFloat(firstLight);
        ASSERT_EQUAL(secondShaderFloat.GetNumRegisters(), numRegisters);
        ASSERT_UNEQUAL_NULL_PTR(secondShaderFloat.GetData());
        ASSERT_TRUE(secondShaderFloat.AllowUpdater());

        LightAmbientConstant thirdShaderFloat(firstLight);
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

void Rendering::LightAmbientConstantTesting::CopyTest()
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

        LightAmbientConstant firstShaderFloat(firstLight);
        ASSERT_EQUAL(firstShaderFloat.GetNumRegisters(), 1);

        LightAmbientConstant secondShaderFloat(firstShaderFloat);
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

        LightAmbientConstant thirdShaderFloat(firstLight);
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

void Rendering::LightAmbientConstantTesting::StreamTest() noexcept
{
}

void Rendering::LightAmbientConstantTesting::UpdateTest() noexcept
{
}
