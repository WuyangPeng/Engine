///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 15:25)

#include "MaterialSpecularConstantTesting.h"
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
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Rendering/SceneGraph/LoadVisual.h"
#include "Rendering/ShaderFloats/MaterialSpecularConstant.h"

#include <random>

Rendering::MaterialSpecularConstantTesting::MaterialSpecularConstantTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, MaterialSpecularConstantTesting)

void Rendering::MaterialSpecularConstantTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::MaterialSpecularConstantTesting::MainTest()
{
    CameraManager::Create();
    RendererManager::Create();

    CoreTools::InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UpdateTest);

    CoreTools::InitTerm::ExecuteTerminator();

    RendererManager::Destroy();
    CameraManager::Destroy();
}

void Rendering::MaterialSpecularConstantTesting::InitTest()
{
    std::default_random_engine generator;
    const std::uniform_real<float> firstFloatRandomDistribution(-100.0f, 100.0f);
    const std::uniform_real<float> secondFloatRandomDistribution(0.0f, 1.0f);

    for (int loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        MaterialSharedPtr firstMaterial(Material::Create(Material::Colour(secondFloatRandomDistribution(generator),
                                                                          secondFloatRandomDistribution(generator),
                                                                          secondFloatRandomDistribution(generator),
                                                                          secondFloatRandomDistribution(generator)),
                                                         Material::Colour(secondFloatRandomDistribution(generator),
                                                                          secondFloatRandomDistribution(generator),
                                                                          secondFloatRandomDistribution(generator),
                                                                          secondFloatRandomDistribution(generator)),
                                                         Material::Colour(secondFloatRandomDistribution(generator),
                                                                          secondFloatRandomDistribution(generator),
                                                                          secondFloatRandomDistribution(generator),
                                                                          secondFloatRandomDistribution(generator)),
                                                         Material::Colour(secondFloatRandomDistribution(generator),
                                                                          secondFloatRandomDistribution(generator),
                                                                          secondFloatRandomDistribution(generator),
                                                                          secondFloatRandomDistribution(generator))));

        constexpr int numRegisters = 1;
        MaterialSpecularConstant firstShaderFloat(firstMaterial);
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

        const MaterialSpecularConstant secondShaderFloat(firstMaterial);
        ASSERT_EQUAL(secondShaderFloat.GetNumRegisters(), numRegisters);
        ASSERT_UNEQUAL_NULL_PTR(secondShaderFloat.GetData());
        ASSERT_TRUE(secondShaderFloat.AllowUpdater());

        MaterialSpecularConstant thirdShaderFloat(firstMaterial);
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

        ASSERT_EQUAL(firstShaderFloat.GetMaterial(), firstMaterial);
        ASSERT_EQUAL(secondShaderFloat.GetMaterial(), firstMaterial);
        ASSERT_EQUAL(thirdShaderFloat.GetMaterial(), firstMaterial);
    }
}

void Rendering::MaterialSpecularConstantTesting::CopyTest()
{
    std::default_random_engine generator;
    const std::uniform_real<float> firstFloatRandomDistribution(-100.0f, 100.0f);
    const std::uniform_real<float> secondFloatRandomDistribution(0.0f, 1.0f);

    for (int loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        MaterialSharedPtr firstMaterial(Material::Create(Material::Colour(secondFloatRandomDistribution(generator),
                                                                          secondFloatRandomDistribution(generator),
                                                                          secondFloatRandomDistribution(generator),
                                                                          secondFloatRandomDistribution(generator)),
                                                         Material::Colour(secondFloatRandomDistribution(generator),
                                                                          secondFloatRandomDistribution(generator),
                                                                          secondFloatRandomDistribution(generator),
                                                                          secondFloatRandomDistribution(generator)),
                                                         Material::Colour(secondFloatRandomDistribution(generator),
                                                                          secondFloatRandomDistribution(generator),
                                                                          secondFloatRandomDistribution(generator),
                                                                          secondFloatRandomDistribution(generator)),
                                                         Material::Colour(secondFloatRandomDistribution(generator),
                                                                          secondFloatRandomDistribution(generator),
                                                                          secondFloatRandomDistribution(generator),
                                                                          secondFloatRandomDistribution(generator))));

        MaterialSpecularConstant firstShaderFloat(firstMaterial);
        ASSERT_EQUAL(firstShaderFloat.GetNumRegisters(), 1);

        MaterialSpecularConstant secondShaderFloat(firstShaderFloat);
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

        MaterialSpecularConstant thirdShaderFloat(firstMaterial);
        thirdShaderFloat = firstShaderFloat;
        firstShaderFloat = secondShaderFloat;

        for (int registerIndex = 0; registerIndex < 4; ++registerIndex)
        {
            ASSERT_APPROXIMATE(firstShaderFloat[registerIndex], 0.0f, 1e-8f);
            ASSERT_APPROXIMATE(secondShaderFloat[registerIndex], 0.0f, 1e-8f);
            ASSERT_APPROXIMATE(thirdShaderFloat[registerIndex], static_cast<float>(registerIndex), 1e-8f);
        }

        ASSERT_EQUAL(firstShaderFloat.GetMaterial(), firstMaterial);
        ASSERT_EQUAL(secondShaderFloat.GetMaterial(), firstMaterial);
        ASSERT_EQUAL(thirdShaderFloat.GetMaterial(), firstMaterial);
    }
}

void Rendering::MaterialSpecularConstantTesting::StreamTest() noexcept
{
}

void Rendering::MaterialSpecularConstantTesting::UpdateTest() noexcept
{
}
