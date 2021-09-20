// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/06 15:45)

#include "ProjectionViewMatrixConstantTesting.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/LoadVisual.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/ShaderFloats/ProjectionViewMatrixConstant.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/BufferInStream.h" 

#include "Mathematics/Algebra/MatrixDetail.h"

#include <random>

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, ProjectionViewMatrixConstantTesting) 

void Rendering::ProjectionViewMatrixConstantTesting
	::MainTest()
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
 
void Rendering::ProjectionViewMatrixConstantTesting
	::InitTest()
{
	const int numRegisters = 4;
	ProjectionViewMatrixConstant firstShaderFloat;
	ASSERT_EQUAL(firstShaderFloat.GetNumRegisters(), numRegisters);

	firstShaderFloat.SetNumRegisters(numRegisters);
	ASSERT_EQUAL(firstShaderFloat.GetNumRegisters(), numRegisters);

	ASSERT_UNEQUAL_NULL_PTR(firstShaderFloat.GetData());

	ASSERT_TRUE(firstShaderFloat.AllowUpdater());
	firstShaderFloat.DisableUpdater();
	ASSERT_FALSE(firstShaderFloat.AllowUpdater());
	firstShaderFloat.EnableUpdater();
	ASSERT_TRUE(firstShaderFloat.AllowUpdater());

	vector<float> firstData(16,1);
	firstShaderFloat.SetRegisters(firstData);

	for (int i = 0;i < 16;++i)
	{
		ASSERT_APPROXIMATE(firstData[i], firstShaderFloat.GetRegisters()[i], 1e-8f);
	}
	
	const ProjectionViewMatrixConstant secondShaderFloat;
	ASSERT_EQUAL(secondShaderFloat.GetNumRegisters(), numRegisters);
	ASSERT_UNEQUAL_NULL_PTR(secondShaderFloat.GetData());
	ASSERT_TRUE(secondShaderFloat.AllowUpdater());	
 
	ProjectionViewMatrixConstant thirdShaderFloat;
	ASSERT_EQUAL(thirdShaderFloat.GetNumRegisters(), numRegisters);

	ASSERT_UNEQUAL_NULL_PTR(thirdShaderFloat.GetData());

	ASSERT_TRUE(thirdShaderFloat.AllowUpdater());
	thirdShaderFloat.DisableUpdater();
	ASSERT_FALSE(thirdShaderFloat.AllowUpdater());
	thirdShaderFloat.EnableUpdater();
	ASSERT_TRUE(thirdShaderFloat.AllowUpdater());	
	
	vector<vector<float> > secondData;
	
	for (int dataIndex = 0; dataIndex < 4; ++dataIndex)
	{
		vector<float> data;

		for (int registerIndex = 0; registerIndex < 4; ++registerIndex)
		{
			data.push_back(static_cast<float>(registerIndex + dataIndex * 4));			
		}

		secondData.push_back(data);
	}

	for (unsigned dataIndex = 0; dataIndex < secondData.size(); ++dataIndex)
	{
		thirdShaderFloat.SetRegister(dataIndex, secondData[dataIndex]);
	}

	for (unsigned dataIndex = 0; dataIndex < secondData.size(); ++dataIndex)
	{
		ASSERT_EQUAL_DO_NOT_USE_MESSAGE(secondData[dataIndex], thirdShaderFloat.GetRegister(dataIndex));
	}
	
	for (int registerIndex = 0; registerIndex < 16;++registerIndex)
	{
		ASSERT_APPROXIMATE(thirdShaderFloat[registerIndex], registerIndex,1e-8f);
	}	
}

void Rendering::ProjectionViewMatrixConstantTesting
	::CopyTest()
{
	ProjectionViewMatrixConstant firstShaderFloat;
	ASSERT_EQUAL(firstShaderFloat.GetNumRegisters(), 4);

	ProjectionViewMatrixConstant secondShaderFloat(firstShaderFloat);
	ASSERT_EQUAL(secondShaderFloat.GetNumRegisters(), 4);

	for (int registerIndex = 0; registerIndex < 16; ++registerIndex)
	{
		firstShaderFloat[registerIndex] = static_cast<float>(registerIndex);
	}

	for (int registerIndex = 0; registerIndex < 16; ++registerIndex)
	{
		ASSERT_APPROXIMATE(secondShaderFloat[registerIndex], 0.0f,1e-8f);
		ASSERT_APPROXIMATE(firstShaderFloat[registerIndex], static_cast<float>(registerIndex), 1e-8f);
	}
	
	ProjectionViewMatrixConstant thirdShaderFloat;
	thirdShaderFloat = firstShaderFloat;	
	firstShaderFloat = secondShaderFloat;

	for (int registerIndex = 0; registerIndex < 16; ++registerIndex)
	{
		ASSERT_APPROXIMATE(firstShaderFloat[registerIndex], 0.0f, 1e-8f);
		ASSERT_APPROXIMATE(secondShaderFloat[registerIndex], 0.0f, 1e-8f);
		ASSERT_APPROXIMATE(thirdShaderFloat[registerIndex], static_cast<float>(registerIndex), 1e-8f);
	}
} 

void Rendering::ProjectionViewMatrixConstantTesting
	::StreamTest()
{
// 	CoreTools::OutTopLevel outTopLevel;
// 	ProjectionViewMatrixConstantSharedPtr firstShaderFloat(new ProjectionViewMatrixConstant);
// 
// 	for (int i = 0; i < 16;++i)
// 	{	 
// 		(*firstShaderFloat)[i] = static_cast<float>(i);
// 	}
// 
// 	outTopLevel.Insert(firstShaderFloat);	 
// 
// 	CoreTools::BufferOutStream outStream(outTopLevel);
// 
// 	CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr =
// 		    outStream.GetBufferOutStreamInformation();
//         
// 	CoreTools::BufferInStream inStream(fileBufferPtr);
//         
// 	CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
// 
// 	ASSERT_EQUAL(inTopLevel.GetTopLevelSize(),1);
// 
// 	ProjectionViewMatrixConstantSharedPtr secondShaderFloat =
// 		inTopLevel[0].PolymorphicDowncastObjectSharedPtr<ProjectionViewMatrixConstantSharedPtr>();
// 
// 	ASSERT_UNEQUAL_NULL_PTR(secondShaderFloat);
// 
// 	ASSERT_EQUAL(firstShaderFloat->GetRegisters().size(),
// 		         secondShaderFloat->GetRegisters().size());
// 
// 	for (unsigned registerIndex = 0; registerIndex < firstShaderFloat->GetRegisters().size(); ++registerIndex)
// 	{
// 		ASSERT_APPROXIMATE(firstShaderFloat->GetRegisters()[registerIndex], 
// 			               secondShaderFloat->GetRegisters()[registerIndex], 1e-8f);
// 	}
}

void Rendering::ProjectionViewMatrixConstantTesting
	::UpdateTest()
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
//         Mathematics::AVectorOrthonormalizef orthonormalize =
//               Orthonormalize(firstVector, secondVector, thirdVector,1e-5f);
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
// 		ProjectionViewMatrixConstant firstShaderFloat;
// 
// 		VisualSharedPtr firstTrianglesMesh =
// 			LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/SceneGraphSuite/TrianglesMesh.trv"));
// 
// 		firstShaderFloat.Update(firstTrianglesMesh.GetData(), &firstCamera);
// 
// 		const Mathematics::Matrixf projectionViewMatrix = firstCamera.GetProjectionViewMatrix();	
// 		
// 		for(int i = 0;i < 16;++i)
// 		{
// 			ASSERT_APPROXIMATE(projectionViewMatrix[i / 16][i % 16], firstShaderFloat[i], 1e-8f);
// 		}
// 	}
}
