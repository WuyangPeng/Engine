// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/06 15:19)

#include "CameraWorldPositionConstantTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Rendering/SceneGraph/LoadVisual.h"
#include "Rendering/ShaderFloats/CameraWorldPositionConstant.h"

#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"

#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include <random>
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26496)
using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, CameraWorldPositionConstantTesting)

void Rendering::CameraWorldPositionConstantTesting::MainTest()
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

void Rendering::CameraWorldPositionConstantTesting::InitTest()
{
    constexpr int numRegisters = 1;
    CameraWorldPositionConstant firstShaderFloat{ CoreTools::DisableNotThrow::Disable };
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

    const CameraWorldPositionConstant secondShaderFloat{ CoreTools::DisableNotThrow::Disable };
    ASSERT_EQUAL(secondShaderFloat.GetNumRegisters(), numRegisters);
    ASSERT_UNEQUAL_NULL_PTR(secondShaderFloat.GetData());
    ASSERT_TRUE(secondShaderFloat.AllowUpdater());

    CameraWorldPositionConstant thirdShaderFloat{ CoreTools::DisableNotThrow::Disable };
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
}

void Rendering::CameraWorldPositionConstantTesting::CopyTest()
{
    CameraWorldPositionConstant firstShaderFloat{ CoreTools::DisableNotThrow::Disable };
    ASSERT_EQUAL(firstShaderFloat.GetNumRegisters(), 1);

    CameraWorldPositionConstant secondShaderFloat(firstShaderFloat);
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

    CameraWorldPositionConstant thirdShaderFloat{ CoreTools::DisableNotThrow::Disable };
    thirdShaderFloat = firstShaderFloat;
    firstShaderFloat = secondShaderFloat;

    for (int registerIndex = 0; registerIndex < 4; ++registerIndex)
    {
        ASSERT_APPROXIMATE(firstShaderFloat[registerIndex], 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(secondShaderFloat[registerIndex], 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(thirdShaderFloat[registerIndex], static_cast<float>(registerIndex), 1e-8f);
    }
}

void Rendering::CameraWorldPositionConstantTesting::StreamTest()
{
    // 	CoreTools::OutTopLevel outTopLevel;
    // 	CameraWorldPositionConstantSharedPtr firstShaderFloat(new CameraWorldPositionConstant);
    //
    // 	for (int i = 0; i < 4;++i)
    // 	{
    // 		(*firstShaderFloat)[i] = static_cast<float>(i);
    // 	}
    //
    // 	outTopLevel.Insert(firstShaderFloat);
    //
    // 	CoreTools::BufferOutStream outStream(outTopLevel);
    //
    // 	CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr =  outStream.GetBufferOutStreamInformation();
    //
    // 	CoreTools::BufferInStream inStream(fileBufferPtr);
    //
    // 	CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
    //
    // 	ASSERT_EQUAL(inTopLevel.GetTopLevelSize(),1);
    //
    // 	CameraWorldPositionConstantSharedPtr secondShaderFloat =
    // 		inTopLevel[0].PolymorphicDowncastObjectSharedPtr<CameraWorldPositionConstantSharedPtr>();
    //
    // 	ASSERT_UNEQUAL_NULL_PTR(secondShaderFloat);
    //
    // 	ASSERT_EQUAL(firstShaderFloat->GetRegisters().size(),secondShaderFloat->GetRegisters().size());
    //
    // 	for (unsigned registerIndex = 0; registerIndex < firstShaderFloat->GetRegisters().size(); ++registerIndex)
    // 	{
    // 		ASSERT_APPROXIMATE(firstShaderFloat->GetRegisters()[registerIndex],secondShaderFloat->GetRegisters()[registerIndex], 1e-8f);
    // 	}
}

void Rendering::CameraWorldPositionConstantTesting::UpdateTest()
{
    // 	std::default_random_engine generator;
    // 	std::uniform_real<float> firstFloatRandomDistribution(-100.0f,100.0f);
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
    //         Mathematics::AVectorOrthonormalizef orthonormalize = Orthonormalize(firstVector, secondVector, thirdVector,1e-5f);
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
    // 		CameraWorldPositionConstant firstShaderFloat;
    //
    // 		VisualSharedPtr firstTrianglesMesh = LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/SceneGraphSuite/TrianglesMesh.trv"));
    //
    // 		firstShaderFloat.Update(firstTrianglesMesh.GetData(), &firstCamera);
    //
    // 		const Mathematics::APointf worldPosition = firstCamera.GetPosition();
    //
    // 		ASSERT_APPROXIMATE(worldPosition[0], firstShaderFloat[0], 1e-8f);
    // 		ASSERT_APPROXIMATE(worldPosition[1], firstShaderFloat[1], 1e-8f);
    // 		ASSERT_APPROXIMATE(worldPosition[2], firstShaderFloat[2], 1e-8f);
    // 		ASSERT_APPROXIMATE(1.0f, firstShaderFloat[3], 1e-8f);
    // 	}
}
