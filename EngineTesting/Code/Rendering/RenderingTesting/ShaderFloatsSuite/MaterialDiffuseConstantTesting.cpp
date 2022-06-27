///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/14 17:22)

#include "MaterialDiffuseConstantTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Rendering/SceneGraph/LoadVisual.h"
#include "Rendering/ShaderFloats/MaterialDiffuseConstant.h"

#include <random>

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, MaterialDiffuseConstantTesting)

void Rendering::MaterialDiffuseConstantTesting::MainTest()
{
    CameraManager::Create();
    RendererManager::Create();

    CoreTools::InitTerm::ExecuteInitializers();

    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UpdateTest);

    CoreTools::InitTerm::ExecuteTerminators();

    RendererManager::Destroy();
    CameraManager::Destroy();
}

void Rendering::MaterialDiffuseConstantTesting::InitTest()
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
        MaterialDiffuseConstant firstShaderFloat(firstMaterial);
        ASSERT_EQUAL(firstShaderFloat.GetNumRegisters(), numRegisters);

        firstShaderFloat.SetNumRegisters(numRegisters);
        ASSERT_EQUAL(firstShaderFloat.GetNumRegisters(), numRegisters);

        ASSERT_UNEQUAL_NULL_PTR(firstShaderFloat.GetData());

        ASSERT_TRUE(firstShaderFloat.AllowUpdater());
        firstShaderFloat.DisableUpdater();
        ASSERT_FALSE(firstShaderFloat.AllowUpdater());
        firstShaderFloat.EnableUpdater();
        ASSERT_TRUE(firstShaderFloat.AllowUpdater());

        vector<float> firstData(4, 1);
        firstShaderFloat.SetRegisters(firstData);

        for (int i = 0; i < 4; ++i)
        {
            ASSERT_APPROXIMATE(firstData.at(i), firstShaderFloat.GetRegisters().at(i), 1e-8f);
        }

        const MaterialDiffuseConstant secondShaderFloat(firstMaterial);
        ASSERT_EQUAL(secondShaderFloat.GetNumRegisters(), numRegisters);
        ASSERT_UNEQUAL_NULL_PTR(secondShaderFloat.GetData());
        ASSERT_TRUE(secondShaderFloat.AllowUpdater());

        MaterialDiffuseConstant thirdShaderFloat(firstMaterial);
        ASSERT_EQUAL(thirdShaderFloat.GetNumRegisters(), numRegisters);

        ASSERT_UNEQUAL_NULL_PTR(thirdShaderFloat.GetData());

        ASSERT_TRUE(thirdShaderFloat.AllowUpdater());
        thirdShaderFloat.DisableUpdater();
        ASSERT_FALSE(thirdShaderFloat.AllowUpdater());
        thirdShaderFloat.EnableUpdater();
        ASSERT_TRUE(thirdShaderFloat.AllowUpdater());

        vector<float> secondData;
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

void Rendering::MaterialDiffuseConstantTesting::CopyTest()
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

        MaterialDiffuseConstant firstShaderFloat(firstMaterial);
        ASSERT_EQUAL(firstShaderFloat.GetNumRegisters(), 1);

        MaterialDiffuseConstant secondShaderFloat(firstShaderFloat);
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

        MaterialDiffuseConstant thirdShaderFloat(firstMaterial);
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

void Rendering::MaterialDiffuseConstantTesting::StreamTest() noexcept
{
}

void Rendering::MaterialDiffuseConstantTesting::UpdateTest() noexcept
{
}
