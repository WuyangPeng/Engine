// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/06 15:28)

#include "MaterialDiffuseConstantTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Rendering/SceneGraph/LoadVisual.h"
#include "Rendering/ShaderFloats/MaterialDiffuseConstant.h"

#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"

#include <random>

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, MaterialDiffuseConstantTesting)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26496)
void Rendering::MaterialDiffuseConstantTesting ::MainTest()
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

void Rendering::MaterialDiffuseConstantTesting ::InitTest()
{
    std::default_random_engine generator;
    std::uniform_real<float> firstFloatRandomDistribution(-100.0f, 100.0f);
    std::uniform_real<float> secondFloatRandomDistribution(0.0f, 1.0f);

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
            ASSERT_APPROXIMATE(firstData[i], firstShaderFloat.GetRegisters()[i], 1e-8f);
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

void Rendering::MaterialDiffuseConstantTesting ::CopyTest()
{
    std::default_random_engine generator;
    std::uniform_real<float> firstFloatRandomDistribution(-100.0f, 100.0f);
    std::uniform_real<float> secondFloatRandomDistribution(0.0f, 1.0f);

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

void Rendering::MaterialDiffuseConstantTesting ::StreamTest()
{
    // 	std::default_random_engine generator;
    // 	std::uniform_real<float> firstFloatRandomDistribution(-100.0f, 100.0f);
    // 	std::uniform_real<float> secondFloatRandomDistribution(0.0f, 1.0f);
    //
    // 	for (int loop = 0; loop < GetTestLoopCount(); ++loop)
    // 	{
    // 		MaterialSharedPtr firstMaterial
    // 			(new Material(Material::Colour(secondFloatRandomDistribution(generator),
    // 			                                secondFloatRandomDistribution(generator),
    // 											secondFloatRandomDistribution(generator),
    // 											secondFloatRandomDistribution(generator)),
    // 					       Material::Colour(secondFloatRandomDistribution(generator),
    // 			                                secondFloatRandomDistribution(generator),
    // 											secondFloatRandomDistribution(generator),
    // 											secondFloatRandomDistribution(generator)),
    // 						   Material::Colour(secondFloatRandomDistribution(generator),
    // 			                                secondFloatRandomDistribution(generator),
    // 											secondFloatRandomDistribution(generator),
    // 											secondFloatRandomDistribution(generator)),
    // 						   Material::Colour(secondFloatRandomDistribution(generator),
    // 			                                secondFloatRandomDistribution(generator),
    // 											secondFloatRandomDistribution(generator),
    // 											secondFloatRandomDistribution(generator))));
    //
    //
    // 		CoreTools::OutTopLevel outTopLevel;
    // 		MaterialDiffuseConstantSharedPtr firstShaderFloat(new MaterialDiffuseConstant(firstMaterial));
    //
    // 		for (int i = 0; i < 4;++i)
    // 		{
    // 			(*firstShaderFloat)[i] = static_cast<float>(i);
    // 		}
    //
    // 		outTopLevel.Insert(firstShaderFloat);
    //
    // 		CoreTools::BufferOutStream outStream(outTopLevel);
    //
    // 		CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr =
    // 			outStream.GetBufferOutStreamInformation();
    //
    // 		CoreTools::BufferInStream inStream(fileBufferPtr);
    //
    // 		CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
    //
    // 		ASSERT_EQUAL(inTopLevel.GetTopLevelSize(),1);
    //
    // 		MaterialDiffuseConstantSharedPtr secondShaderFloat =
    // 			inTopLevel[0].PolymorphicDowncastObjectSharedPtr<MaterialDiffuseConstantSharedPtr>();
    //
    // 		ASSERT_UNEQUAL_NULL_PTR(secondShaderFloat);
    //
    // 		ASSERT_EQUAL(firstShaderFloat->GetRegisters().size(),
    // 		             secondShaderFloat->GetRegisters().size());
    //
    // 		for (unsigned registerIndex = 0; registerIndex < firstShaderFloat->GetRegisters().size(); ++registerIndex)
    // 		{
    // 			ASSERT_APPROXIMATE(firstShaderFloat->GetRegisters()[registerIndex],
    // 			                   secondShaderFloat->GetRegisters()[registerIndex], 1e-8f);
    // 		}
    //
    // 		ConstMaterialSharedPtr secondMaterial = secondShaderFloat->GetMaterial();
    //
    // 		ASSERT_TRUE(Approximate(firstMaterial->GetAmbient(), secondMaterial->GetAmbient(), 1e-8f));
    // 		ASSERT_TRUE(Approximate(firstMaterial->GetDiffuse(), secondMaterial->GetDiffuse(), 1e-8f));
    // 		ASSERT_TRUE(Approximate(firstMaterial->GetSpecular(), secondMaterial->GetSpecular(), 1e-8f));
    // 		ASSERT_TRUE(Approximate(firstMaterial->GetEmissive(), secondMaterial->GetEmissive(), 1e-8f));
    //
    // 	}
}

void Rendering::MaterialDiffuseConstantTesting ::UpdateTest()
{
    // 	std::default_random_engine generator;
    // 	std::uniform_real<float> firstFloatRandomDistribution(-100.0f,100.0f);
    // 	std::uniform_real<float> secondFloatRandomDistribution(0.0f, 1.0f);
    //
    // 	for(int loop = 0;loop < GetTestLoopCount();++loop)
    // 	{
    //         Camera::APoint firstPosition(firstFloatRandomDistribution(generator),
    //                                      firstFloatRandomDistribution(generator),
    //                                      firstFloatRandomDistribution(generator));
    //
    //         Camera::AVector firstVector(firstFloatRandomDistribution(generator),
    //                                     firstFloatRandomDistribution(generator),
    //                                     firstFloatRandomDistribution(generator));
    //
    //         firstVector.Normalize();
    //
    //         Camera::AVector secondVector(firstFloatRandomDistribution(generator),
    //                                      firstFloatRandomDistribution(generator),
    //                                      firstFloatRandomDistribution(generator));
    //
    //         secondVector.Normalize();
    //
    //         Camera::AVector thirdVector(firstFloatRandomDistribution(generator),
    //                                     firstFloatRandomDistribution(generator),
    //                                     firstFloatRandomDistribution(generator));
    //
    //         thirdVector.Normalize();
    //
    //         Mathematics::AVectorOrthonormalizef orthonormalize =
    //               Orthonormalize(firstVector, secondVector, thirdVector,1e-4f);
    //
    //         firstVector = orthonormalize.GetUVector();
    //         secondVector = orthonormalize.GetVVector();
    //         thirdVector = orthonormalize.GetWVector();
    //
    //         Camera firstCamera(true,1e-5f);
    //
    //         firstCamera.SetFrame(firstPosition, firstVector,
    //                              secondVector, thirdVector);
    //
    // 		MaterialSharedPtr firstMaterial
    // 			(new Material(Material::Colour(secondFloatRandomDistribution(generator),
    // 			                                secondFloatRandomDistribution(generator),
    // 											secondFloatRandomDistribution(generator),
    // 											secondFloatRandomDistribution(generator)),
    // 					       Material::Colour(secondFloatRandomDistribution(generator),
    // 			                                secondFloatRandomDistribution(generator),
    // 											secondFloatRandomDistribution(generator),
    // 											secondFloatRandomDistribution(generator)),
    // 						   Material::Colour(secondFloatRandomDistribution(generator),
    // 			                                secondFloatRandomDistribution(generator),
    // 											secondFloatRandomDistribution(generator),
    // 											secondFloatRandomDistribution(generator)),
    // 						   Material::Colour(secondFloatRandomDistribution(generator),
    // 			                                secondFloatRandomDistribution(generator),
    // 											secondFloatRandomDistribution(generator),
    // 											secondFloatRandomDistribution(generator))));
    //
    // 		MaterialDiffuseConstant firstShaderFloat(firstMaterial);
    //
    // 		VisualSharedPtr firstTrianglesMesh =
    // 			LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/SceneGraphSuite/TrianglesMesh.trv"));
    //
    // 		firstShaderFloat.Update(firstTrianglesMesh.GetData(), &firstCamera);
    //
    //
    // 		ASSERT_APPROXIMATE(firstMaterial->GetDiffuse().GetRed(), firstShaderFloat[0], 1e-8f);
    // 		ASSERT_APPROXIMATE(firstMaterial->GetDiffuse().GetGreen(), firstShaderFloat[1], 1e-8f);
    // 		ASSERT_APPROXIMATE(firstMaterial->GetDiffuse().GetBlue(), firstShaderFloat[2], 1e-8f);
    // 		ASSERT_APPROXIMATE(firstMaterial->GetDiffuse().GetAlpha(), firstShaderFloat[3], 1e-8f);
    // 	}
}
