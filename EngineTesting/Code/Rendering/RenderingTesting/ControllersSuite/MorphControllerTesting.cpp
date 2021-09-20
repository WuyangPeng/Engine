// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.0.3 (2019/09/06 09:39)

#include "MorphControllerTesting.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Algebra/APointDetail.h" 
#include "Rendering/Controllers/MorphController.h"
#include "Rendering/SceneGraph/Visual.h"
#include "Rendering/SceneGraph/LoadVisual.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/VertexBufferAccessor.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, MorphControllerTesting) 

void Rendering::MorphControllerTesting
	::MainTest()
{
	CoreTools::InitTerm::ExecuteInitializers();

	RendererManager::Create();

	ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
	ASSERT_NOT_THROW_EXCEPTION_0(UpdateTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

	RendererManager::Destroy();

	CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::MorphControllerTesting
	::InitTest()
{
// 	VisualSharedPtr firstPolypoint = LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/SceneGraphSuite/Polypoint.trv"));
// 
// 	ControllerInterfaceSharedPtr controllerTest(new MorphController(firstPolypoint->GetVertexBuffer()->GetNumElements(),5,10));
// 
// 	ASSERT_EQUAL_NULL_PTR(controllerTest->GetControllerObject());
// 	
// 	firstPolypoint->AttachController(controllerTest);
// 
// 	ASSERT_EQUAL(controllerTest->GetControllerObject(), firstPolypoint);
// 
// 	firstPolypoint->DetachController(controllerTest);
// 
// 	ASSERT_EQUAL_NULL_PTR(controllerTest->GetControllerObject());
// 
// 	MorphController* controllerTestPtr = CoreTools::PolymorphicCast<MorphController>(controllerTest.GetData());
// 
// 	controllerTestPtr->SetRepeat(ControllerRepeatType::Clamp);
// 	controllerTestPtr->SetTime(0.1,0.3);
// 	controllerTestPtr->SetPhase(1.5);
// 	controllerTestPtr->SetFrequency(2.0);
// 	controllerTestPtr->SetActive(true);
// 	controllerTestPtr->SetApplicationTime(5.0);
// 
// 	ASSERT_EQUAL(controllerTestPtr->GetRepeat(),ControllerRepeatType::Clamp);
// 	ASSERT_APPROXIMATE(controllerTestPtr->GetMinTime(),0.1,1e-10);
// 	ASSERT_APPROXIMATE(controllerTestPtr->GetMaxTime(),0.3,1e-10);
// 	ASSERT_APPROXIMATE(controllerTestPtr->GetPhase(),1.5,1e-10);
// 	ASSERT_APPROXIMATE(controllerTestPtr->GetFrequency(),2.0,1e-10);
// 	ASSERT_TRUE(controllerTestPtr->IsActive());
// 	ASSERT_APPROXIMATE(controllerTestPtr->GetApplicationTime(),5.0,1e-10);
}

void Rendering::MorphControllerTesting
	::CopyTest()
{
// 	VisualSharedPtr firstPolypoint = LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/SceneGraphSuite/Polypoint.trv"));
// 	
// 	ControllerInterfaceSharedPtr firstControllerTest(new MorphController(firstPolypoint->GetVertexBuffer()->GetNumElements(), 5, 10));
// 	firstPolypoint->AttachController(firstControllerTest);
// 
// 	MorphController* firstControllerTestPtr = CoreTools::PolymorphicCast<MorphController>(firstControllerTest.GetData());
// 
// 	firstControllerTestPtr->SetRepeat(ControllerRepeatType::Clamp);
// 	firstControllerTestPtr->SetTime(0.1,0.3);
// 	firstControllerTestPtr->SetPhase(1.5);
// 	firstControllerTestPtr->SetFrequency(2.0);
// 	firstControllerTestPtr->SetActive(true);
// 	firstControllerTestPtr->SetApplicationTime(5.0);
// 
// 	ControllerInterfaceSharedPtr secondControllerTest(firstControllerTest->Clone());
// 
// 	ASSERT_EQUAL(secondControllerTest->GetControllerObject(), firstPolypoint);
// 
// 	ASSERT_EQUAL(firstControllerTestPtr->GetRepeat(),ControllerRepeatType::Clamp);
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetMinTime(),0.1,1e-10);
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetMaxTime(),0.3,1e-10);
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetPhase(),1.5,1e-10);
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetFrequency(),2.0,1e-10);
// 	ASSERT_TRUE(firstControllerTestPtr->IsActive());
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetApplicationTime(),5.0,1e-10);
// 
// 	MorphController* secondControllerTestPtr = CoreTools::PolymorphicCast<MorphController>(secondControllerTest.GetData());
// 
// 	ASSERT_EQUAL(secondControllerTestPtr->GetRepeat(),ControllerRepeatType::Clamp);
// 	ASSERT_APPROXIMATE(secondControllerTestPtr->GetMinTime(),0.1,1e-10);
// 	ASSERT_APPROXIMATE(secondControllerTestPtr->GetMaxTime(),0.3,1e-10);
// 	ASSERT_APPROXIMATE(secondControllerTestPtr->GetPhase(),1.5,1e-10);
// 	ASSERT_APPROXIMATE(secondControllerTestPtr->GetFrequency(),2.0,1e-10);
// 	ASSERT_TRUE(secondControllerTestPtr->IsActive());
// 	ASSERT_APPROXIMATE(secondControllerTestPtr->GetApplicationTime(),5.0,1e-10);
// 
// 	firstControllerTestPtr->SetRepeat(ControllerRepeatType::ClampCycle);
// 	firstControllerTestPtr->SetTime(1.1,1.3);
// 	firstControllerTestPtr->SetPhase(2.5);
// 	firstControllerTestPtr->SetFrequency(3.0);
// 	firstControllerTestPtr->SetActive(false);
// 	firstControllerTestPtr->SetApplicationTime(15.0);
// 
// 	ASSERT_EQUAL(firstControllerTestPtr->GetRepeat(), ControllerRepeatType::ClampCycle);
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetMinTime(),1.1,1e-10);
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetMaxTime(),1.3,1e-10);
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetPhase(),2.5,1e-10);
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetFrequency(),3.0,1e-10);
// 	ASSERT_FALSE(firstControllerTestPtr->IsActive());
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetApplicationTime(),15.0,1e-10);
// 
// 	ASSERT_EQUAL(secondControllerTestPtr->GetRepeat(),ControllerRepeatType::Clamp);
// 	ASSERT_APPROXIMATE(secondControllerTestPtr->GetMinTime(),0.1,1e-10);
// 	ASSERT_APPROXIMATE(secondControllerTestPtr->GetMaxTime(),0.3,1e-10);
// 	ASSERT_APPROXIMATE(secondControllerTestPtr->GetPhase(),1.5,1e-10);
// 	ASSERT_APPROXIMATE(secondControllerTestPtr->GetFrequency(),2.0,1e-10);
// 	ASSERT_TRUE(secondControllerTestPtr->IsActive());
// 	ASSERT_APPROXIMATE(secondControllerTestPtr->GetApplicationTime(),5.0,1e-10);
}

void Rendering::MorphControllerTesting
	::UpdateTest()
{
// 	VisualSharedPtr firstPolypoint = LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/SceneGraphSuite/Polypoint.trv"));
// 	
// 	int numVertices = firstPolypoint->GetVertexBuffer()->GetNumElements();
// 	int numTargets = 5;
// 	int numKeys = 10;
// 
// 	ControllerInterfaceSharedPtr firstControllerTest(new MorphController(numVertices, numTargets, numKeys));
// 	firstPolypoint->AttachController(firstControllerTest);
// 
// 	MorphController* firstControllerTestPtr = CoreTools::PolymorphicCast<MorphController>(firstControllerTest.GetData());
// 
// 	firstControllerTestPtr->SetRepeat(ControllerRepeatType::Clamp);
// 	firstControllerTestPtr->SetTime(4.1,12.3);
// 	firstControllerTestPtr->SetPhase(1.5);
// 	firstControllerTestPtr->SetFrequency(2.0);
// 	firstControllerTestPtr->SetActive(true);
// 	firstControllerTestPtr->SetApplicationTime(5.0);
// 
// 	double controlTime = 2.0 * 5.0 + 1.5;
// 
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetControlTime(5.0),controlTime,1e-10);
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetControlTime(6.0),
//                        firstControllerTestPtr->GetMaxTime(),1e-10);
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetControlTime(1.0),
//                        firstControllerTestPtr->GetMinTime(),1e-10);
// 
// 	firstControllerTestPtr->SetRepeat(ControllerRepeatType::Wrap);
// 
// 	double timeRange = firstControllerTestPtr->GetMaxTime() - 
//                        firstControllerTestPtr->GetMinTime();
// 	double multiples = (controlTime - firstControllerTestPtr->GetMinTime()) / timeRange;
// 	double integerTime = Mathematics::Mathd::Floor(multiples);
// 	double fractionTime = multiples - integerTime;
// 
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetControlTime(5.0),
//                        firstControllerTestPtr->GetMinTime() + fractionTime * timeRange,1e-10);
// 
// 	firstControllerTestPtr->SetRepeat(ControllerRepeatType::ClampCycle);
// 
// 	if (static_cast<int>(integerTime) & 1)
// 	{
//  	   ASSERT_APPROXIMATE(firstControllerTestPtr->GetControlTime(5.0),
//                           firstControllerTestPtr->GetMaxTime() - fractionTime * timeRange,
// 						  1e-10); 
// 	}
// 	else
// 	{
//  	   ASSERT_APPROXIMATE(firstControllerTestPtr->GetControlTime(5.0),
//                           firstControllerTestPtr->GetMinTime() + fractionTime * timeRange,1e-10); 
// 	}
// 
// 	ASSERT_EQUAL(numVertices, firstControllerTestPtr->GetNumVertices());
// 	ASSERT_EQUAL(numTargets, firstControllerTestPtr->GetNumTargets());
// 	ASSERT_EQUAL(numKeys, firstControllerTestPtr->GetNumKeys());
// 
// 	for (int targetIndex = 0; targetIndex < numTargets; ++targetIndex)
// 	{
// 		for (int verticesIndex = 0; verticesIndex < numVertices; ++verticesIndex)
// 		{
// 			firstControllerTestPtr->SetVertices(targetIndex, verticesIndex,
// 				                                 Mathematics::APointf(static_cast<float>(targetIndex),
// 												                      static_cast<float>(verticesIndex),
// 																	  2.0f));
// 		}
// 	}
// 
// 	for (int keyIndex = 0; keyIndex < numKeys; ++keyIndex)
// 	{
// 		firstControllerTestPtr->SetTimes(keyIndex, static_cast<float>(keyIndex));
// 
// 		for (int targetIndex = 0; targetIndex < numTargets - 1; ++targetIndex)
// 		{
// 			firstControllerTestPtr->SetWeights(keyIndex, targetIndex, static_cast<float>(targetIndex));
// 		}
// 	}
// 
// 	typedef bool(*Function)(const Mathematics::APointf& lhs, const Mathematics::APointf& rhs,
// 		                    const float epsilon);
// 
// 	Function function = Mathematics::Approximate<float>;
// 
// 	for (int targetIndex = 0; targetIndex < numTargets; ++targetIndex)
// 	{
// 		for (int verticesIndex = 0; verticesIndex < numVertices; ++verticesIndex)
// 		{
// 			ASSERT_APPROXIMATE_USE_FUNCTION(function, firstControllerTestPtr->GetVertices(targetIndex, verticesIndex),
// 				                            Mathematics::APointf(static_cast<float>(targetIndex),
// 												                 static_cast<float>(verticesIndex),
// 																 2.0f),1e-8f);
// 		}
// 	}
// 
// 	for (int keyIndex = 0; keyIndex < numKeys; ++keyIndex)
// 	{
// 		ASSERT_APPROXIMATE(firstControllerTestPtr->GetTimes(keyIndex), static_cast<float>(keyIndex), 1e-8f);
// 
// 		for (int targetIndex = 0; targetIndex < numTargets - 1; ++targetIndex)
// 		{
// 			ASSERT_APPROXIMATE(firstControllerTestPtr->GetWeights(keyIndex, targetIndex), static_cast<float>(targetIndex), 1e-8f);
// 		}
// 	}
// 		
// 	int lastIndex = 0;
// 
// 	for (int loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		firstPolypoint->Update(1.0f);	
// 
// 		vector<Mathematics::APointf> position;
//  			 
// 		for (int i = 0; i < numVertices; ++i)
// 		{
// 			position.push_back(firstControllerTestPtr->GetVertices(0, i));			
// 		}
// 		
// 		// 查找边界键。
// 		float ctrlTime = static_cast<float>(firstControllerTestPtr->GetControlTime(1.0f));
// 		
// 		ControllerKeyInfo info;
// 	
// 		if (firstControllerTestPtr->GetTimes(0) < ctrlTime)
// 		{
// 			if (firstControllerTestPtr->GetTimes(numKeys - 1) <= ctrlTime)
// 			{
// 				lastIndex = numKeys - 1;
// 				
// 				info = ControllerKeyInfo(0.0f, lastIndex, lastIndex);
// 			}
// 			else
// 			{
// 				if (firstControllerTestPtr->GetTimes(lastIndex) < ctrlTime)
// 				{
// 					int nextIndex = lastIndex + 1;
// 					while (firstControllerTestPtr->GetTimes(nextIndex) <= ctrlTime)
// 					{
// 						lastIndex = nextIndex;
// 						++nextIndex;
// 					}
// 					
// 					float normTime = (ctrlTime - firstControllerTestPtr->GetTimes(lastIndex)) / 
// 					                 (firstControllerTestPtr->GetTimes(nextIndex) - firstControllerTestPtr->GetTimes(lastIndex));
// 					
// 					info = ControllerKeyInfo(normTime, lastIndex, nextIndex);
// 				}
// 				else if (ctrlTime < firstControllerTestPtr->GetTimes(lastIndex))
// 				{
// 					int nextIndex = lastIndex - 1;
// 					while (ctrlTime <= firstControllerTestPtr->GetTimes(nextIndex))
// 					{
// 						lastIndex = nextIndex;
// 						--nextIndex;
// 					}
// 					
// 					float normTime = (ctrlTime - firstControllerTestPtr->GetTimes(nextIndex)) /
// 					                 (firstControllerTestPtr->GetTimes(lastIndex) - firstControllerTestPtr->GetTimes(nextIndex));
// 					
// 					info = ControllerKeyInfo(normTime, nextIndex, lastIndex);
// 				}
// 				else
// 				{
// 					info = ControllerKeyInfo(0.0f, lastIndex, lastIndex);
// 				}
// 			}		
// 		}	
// 		
// 		// 加入剩余的组分在凸状组合
// 		for (int i = 1; i < firstControllerTestPtr->GetNumTargets(); ++i)
// 		{
// 			// 添加target[i]在三角形顶点。
// 			float coeff = (1.0f - info.GetNormTime()) * firstControllerTestPtr->GetWeights(info.GetFirstIndex(), i - 1) +
// 			               info.GetNormTime() * firstControllerTestPtr->GetWeights(info.GetSecondIndex(), i - 1);
// 			
// 			for (int j = 0; j < firstControllerTestPtr->GetNumVertices(); ++j)
// 			{
// 				position[j] += coeff * firstControllerTestPtr->GetVertices(i, j);
// 			}
// 		}
// 		
// 		VertexBufferAccessor vba(firstPolypoint.GetData());
// 	
// 		for (int i = 0; i < firstControllerTestPtr->GetNumVertices(); ++i)
// 		{
// 			ASSERT_APPROXIMATE_USE_FUNCTION(function,position[i],
// 			                                vba.GetPosition<Mathematics::APointf>(i), 1e-8f);
// 		}
// 	}	
}

void Rendering::MorphControllerTesting
	::StreamTest()
{
// 	VisualSharedPtr firstPolypoint = LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/SceneGraphSuite/Polypoint.trv"));
// 	
// 	int numVertices = firstPolypoint->GetVertexBuffer()->GetNumElements();
// 	int numTargets = 5;
// 	int numKeys = 10;
// 
// 	CoreTools::OutTopLevel outTopLevel;
// 	CoreTools::ObjectInterfaceSharedPtr firstControlledObjectTest(firstPolypoint.PolymorphicDowncastObjectSharedPtr<CoreTools::ObjectInterfaceSharedPtr>());
// 
// 	Visual* secondControlledObjectTest = CoreTools::PolymorphicCast<Visual>(firstControlledObjectTest.GetData());
// 
// 	firstControlledObjectTest->SetUniqueID(1);
// 
// 	ControllerInterfaceSharedPtr firstControllerTest(new MorphController(numVertices, numTargets, numKeys));
// 	secondControlledObjectTest->AttachController(firstControllerTest);
// 
// 	firstControllerTest->SetUniqueID(2);
// 
// 	MorphController* secondControllerTest = CoreTools::PolymorphicCast<MorphController>(firstControllerTest.GetData());
// 
// 	secondControllerTest->SetRepeat(ControllerRepeatType::Clamp);
// 	secondControllerTest->SetTime(0.1,0.3);
// 	secondControllerTest->SetPhase(1.5);
// 	secondControllerTest->SetFrequency(2.0);
// 	secondControllerTest->SetActive(true);
// 	secondControllerTest->SetApplicationTime(5.0);
// 
// 	for (int targetIndex = 0; targetIndex < numTargets; ++targetIndex)
// 	{
// 		for (int verticesIndex = 0; verticesIndex < numVertices; ++verticesIndex)
// 		{
// 			secondControllerTest->SetVertices(targetIndex, verticesIndex, Mathematics::APointf(static_cast<float>(targetIndex), static_cast<float>(verticesIndex), 2.0f));
// 		}
// 	}
// 
// 	for (int keyIndex = 0; keyIndex < numKeys; ++keyIndex)
// 	{
// 		secondControllerTest->SetTimes(keyIndex, static_cast<float>(keyIndex));
// 
// 		for (int targetIndex = 0; targetIndex < numTargets - 1; ++targetIndex)
// 		{
// 			secondControllerTest->SetWeights(keyIndex, targetIndex, static_cast<float>(targetIndex));
// 		}
// 	}
// 
// 	outTopLevel.Insert(firstControlledObjectTest);
//         
// 	CoreTools::BufferOutStream outStream(outTopLevel);
// 
// 	CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr =  outStream.GetBufferOutStreamInformation();
//         
// 	CoreTools::BufferInStream inStream(fileBufferPtr);
//         
// 	CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
// 
// 	VisualSharedPtr  thirdControlledObjectTest = inTopLevel[0].PolymorphicDowncastObjectSharedPtr<VisualSharedPtr>();
// 
// 	ControllerInterfaceSharedPtr thirdControllerTest =  thirdControlledObjectTest->GetController(0);
// 
// 	MorphController* fourthControlledTest = CoreTools::PolymorphicCast<MorphController>(thirdControllerTest.GetData());
// 
// 	ASSERT_EQUAL(fourthControlledTest->GetRepeat(), secondControllerTest->GetRepeat());
// 	ASSERT_APPROXIMATE(fourthControlledTest->GetMinTime(),
// 	                   secondControllerTest-> GetMinTime(),1e-10);
// 	ASSERT_APPROXIMATE(fourthControlledTest->GetMaxTime(),
// 	                   secondControllerTest-> GetMaxTime(),1e-10);
// 	ASSERT_APPROXIMATE(fourthControlledTest->GetPhase(),
// 	                   secondControllerTest->GetPhase(),1e-10);
// 	ASSERT_APPROXIMATE(fourthControlledTest->GetFrequency(),secondControllerTest-> GetFrequency(),1e-10);
// 	ASSERT_EQUAL(fourthControlledTest->IsActive(),secondControllerTest->IsActive());
// 
// 	ASSERT_EQUAL(fourthControlledTest->GetControllerObject(),thirdControlledObjectTest.GetData()); 
// 
// 	ASSERT_EQUAL(fourthControlledTest->GetNumVertices(), secondControllerTest->GetNumVertices());
// 	ASSERT_EQUAL(fourthControlledTest->GetNumTargets(), secondControllerTest->GetNumTargets());
// 	ASSERT_EQUAL(fourthControlledTest->GetNumKeys(), secondControllerTest->GetNumKeys());
// 
// 	typedef bool(*Function)(const Mathematics::APointf& lhs, const Mathematics::APointf& rhs,
// 		                    const float epsilon);
// 
// 	Function function = Mathematics::Approximate<float>;
// 
// 	for (int targetIndex = 0; targetIndex < numTargets; ++targetIndex)
// 	{
// 		for (int verticesIndex = 0; verticesIndex < numVertices; ++verticesIndex)
// 		{
// 			ASSERT_APPROXIMATE_USE_FUNCTION(function, fourthControlledTest->GetVertices(targetIndex, verticesIndex),
// 				                            secondControllerTest->GetVertices(targetIndex, verticesIndex),1e-8f);
// 		}
// 	}
// 
// 	for (int keyIndex = 0; keyIndex < numKeys; ++keyIndex)
// 	{
// 		ASSERT_APPROXIMATE(fourthControlledTest->GetTimes(keyIndex), secondControllerTest->GetTimes(keyIndex), 1e-8f);
// 
// 		for (int targetIndex = 0; targetIndex < numTargets - 1; ++targetIndex)
// 		{
// 			ASSERT_APPROXIMATE(fourthControlledTest->GetWeights(keyIndex, targetIndex), secondControllerTest->GetWeights(keyIndex, targetIndex), 1e-8f);
// 		}
// 	}
}
