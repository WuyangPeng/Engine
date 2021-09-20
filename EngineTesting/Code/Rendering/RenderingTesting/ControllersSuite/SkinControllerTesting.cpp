// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ²âÊÔ°æ±¾£º0.0.0.3 (2019/09/06 09:45)

#include "SkinControllerTesting.h"
#include "Rendering/Controllers/SkinController.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Rendering/RenderingTesting/SceneGraphSuite/VisualTest.h"
#include "Rendering/DataTypes/Transform.h"
#include "Rendering/SceneGraph/LoadVisual.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/VertexBufferAccessorDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"


#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, SkinControllerTesting) 

void Rendering::SkinControllerTesting
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

void Rendering::SkinControllerTesting
	::InitTest()
{
// 	VisualTest controlledObjectTest;
// 
// 	ControllerInterfaceSharedPtr controllerTest(new SkinController(10,12));
// 
// 	ASSERT_EQUAL_NULL_PTR(controllerTest->GetControllerObject());
// 	
// 	controlledObjectTest.AttachController(controllerTest);
// 
// 	ASSERT_EQUAL(controllerTest->GetControllerObject(),&controlledObjectTest);
// 
// 	controlledObjectTest.DetachController(controllerTest);
// 
// 	ASSERT_EQUAL_NULL_PTR(controllerTest->GetControllerObject());
// 
// 	SkinController* controllerTestPtr =	CoreTools::PolymorphicCast<SkinController>(controllerTest.GetData());
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
// 
// 	ASSERT_EQUAL(controllerTestPtr->GetNumBones(), 12);
// 	ASSERT_EQUAL(controllerTestPtr->GetNumVertices(), 10);
}

void Rendering::SkinControllerTesting
	::CopyTest()
{
// 	VisualTest controlledObjectTest;
// 
// 	ControllerInterfaceSharedPtr firstControllerTest(new SkinController(7,8));
// 	controlledObjectTest.AttachController(firstControllerTest);
// 
// 	SkinController* firstControllerTestPtr = CoreTools::PolymorphicCast<SkinController>(firstControllerTest.GetData());
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
// 	ASSERT_EQUAL(secondControllerTest->GetControllerObject(),&controlledObjectTest);
// 
// 	ASSERT_EQUAL(firstControllerTestPtr->GetRepeat(),ControllerRepeatType::Clamp);
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetMinTime(),0.1,1e-10);
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetMaxTime(),0.3,1e-10);
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetPhase(),1.5,1e-10);
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetFrequency(),2.0,1e-10);
// 	ASSERT_TRUE(firstControllerTestPtr->IsActive());
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetApplicationTime(),5.0,1e-10);
// 
// 	SkinController* secondControllerTestPtr = CoreTools::PolymorphicCast<SkinController>(secondControllerTest.GetData());
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

void Rendering::SkinControllerTesting
	::UpdateTest()
{
// 	LoadVisual firstLoadVisual(SYSTEM_TEXT("Resource/SceneGraphSuite/Visual.trv"));
// 
// 	VisualTest firstVisualTest(firstLoadVisual.GetPrimitiveType(),
// 		                       firstLoadVisual.GetVertexFormat(),
// 							   firstLoadVisual.GetVertexBuffer(),
// 							   firstLoadVisual.GetIndexBuffer());
// 
// 	ControllerInterfaceSharedPtr firstControllerTest(new SkinController(firstVisualTest.GetVertexBuffer()->GetNumElements(),8));
// 
// 	SkinController* firstControllerTestPtr = CoreTools::PolymorphicCast<SkinController>(firstControllerTest.GetData());
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
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetControlTime(6.0),firstControllerTestPtr->GetMaxTime(),1e-10);
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetControlTime(1.0),firstControllerTestPtr->GetMinTime(),1e-10);
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
// 	ASSERT_EQUAL(firstControllerTestPtr->GetNumVertices(), firstVisualTest.GetVertexBuffer()->GetNumElements());
// 	ASSERT_EQUAL(firstControllerTestPtr->GetNumBones(), 8);
// 
// 	vector<ConstNodeSharedPtr> firstNode;
// 	
// 	for (int bonesIndex = 0; bonesIndex < firstControllerTestPtr->GetNumBones(); ++bonesIndex)
// 	{
// 		firstNode.push_back(ConstNodeSharedPtr(new Node));
// 	}
// 
// 	for (int bonesIndex = 0; bonesIndex < firstControllerTestPtr->GetNumBones();++bonesIndex)
// 	{
// 		firstControllerTestPtr->SetBones(bonesIndex,firstNode[bonesIndex]);
// 
// 		for (int verticesIndex = 0; verticesIndex < firstControllerTestPtr->GetNumVertices();++verticesIndex)
// 		{
// 			firstControllerTestPtr->SetWeights(bonesIndex, verticesIndex, static_cast<float>(bonesIndex * verticesIndex));
// 			firstControllerTestPtr->SetOffsets(bonesIndex, verticesIndex, 
// 				                               Mathematics::APointf(static_cast<float>(bonesIndex),
// 											                        static_cast<float>(verticesIndex),
// 																	1.0f));
// 		}
// 	}
// 
// 	for (int bonesIndex = 0; bonesIndex < firstControllerTestPtr->GetNumBones();++bonesIndex)
// 	{
// 		ASSERT_EQUAL(firstControllerTestPtr->GetBones(bonesIndex), firstNode[bonesIndex]);
// 
// 		for (int verticesIndex = 0; verticesIndex < firstControllerTestPtr->GetNumVertices();++verticesIndex)
// 		{
// 			ASSERT_APPROXIMATE(firstControllerTestPtr->GetWeights(bonesIndex,verticesIndex),
// 				               static_cast<float>(bonesIndex * verticesIndex),1e-8f);
// 
// 			ASSERT_TRUE(Approximate(firstControllerTestPtr->GetOffsets(bonesIndex, verticesIndex),
// 				                    Mathematics::APointf(static_cast<float>(bonesIndex),
// 											             static_cast<float>(verticesIndex),
// 														 1.0f),1e-8f));
// 		}
// 	}
// 
// 	vector<ConstNodeSharedPtr> secondNode;
// 
// 	for (int bonesIndex = 0; bonesIndex < firstControllerTestPtr->GetNumBones(); ++bonesIndex)
// 	{
// 		secondNode.push_back(ConstNodeSharedPtr(new Node));
// 	}
// 
// 	vector<vector<float> > weights;
// 
// 	for (int bonesIndex = 0; bonesIndex < firstControllerTestPtr->GetNumBones(); ++bonesIndex)
// 	{
// 		vector<float> unityWeights;
// 
// 		for (int verticesIndex = 0; verticesIndex < firstControllerTestPtr->GetNumVertices(); ++verticesIndex)
// 		{
// 			unityWeights.push_back(static_cast<float>(bonesIndex * verticesIndex + 30.0));
// 		}
// 
// 		weights.push_back(unityWeights);
// 	}
// 
// 	vector<vector<Mathematics::APointf> > offsets;
// 	 
// 	for (int bonesIndex = 0; bonesIndex < firstControllerTestPtr->GetNumBones(); ++bonesIndex)
// 	{
// 		vector<Mathematics::APointf> unityOffsets;
// 
// 		for (int verticesIndex = 0; verticesIndex < firstControllerTestPtr->GetNumVertices(); ++verticesIndex)
// 		{
// 			unityOffsets.push_back( Mathematics::APointf(static_cast<float>(bonesIndex) - 1.0f,
// 											             static_cast<float>(verticesIndex) + 2.0f,
// 														 3.0f));
// 		}
// 
// 		offsets.push_back(unityOffsets);
// 	}
// 
// 	firstControllerTestPtr->SetBones(secondNode);
// 
// 	for (int bonesIndex = 0; bonesIndex < firstControllerTestPtr->GetNumBones(); ++bonesIndex)
// 	{
// 		firstControllerTestPtr->SetWeights(bonesIndex, weights[bonesIndex]);
// 		firstControllerTestPtr->SetOffsets(bonesIndex, offsets[bonesIndex]);
// 	}
// 	
// 	for (int bonesIndex = 0; bonesIndex < firstControllerTestPtr->GetNumBones();++bonesIndex)
// 	{
// 		ASSERT_EQUAL(firstControllerTestPtr->GetBones(bonesIndex), secondNode[bonesIndex]);
// 
// 		for (int verticesIndex = 0; verticesIndex < firstControllerTestPtr->GetNumVertices();++verticesIndex)
// 		{
// 			ASSERT_APPROXIMATE(firstControllerTestPtr->GetWeights(bonesIndex,verticesIndex),
// 					           weights[bonesIndex][verticesIndex], 1e-8f);
// 
// 			ASSERT_TRUE(Approximate(firstControllerTestPtr->GetOffsets(bonesIndex, verticesIndex),
// 				                    offsets[bonesIndex][verticesIndex],1e-8f));
// 		}
// 	}
// 
// 	firstVisualTest.AttachController(firstControllerTest);
// 	firstVisualTest.Update(0.0);
// 
// 	for (int vertex = 0; vertex < firstControllerTestPtr->GetNumVertices(); ++vertex)
// 	{
// 		Mathematics::APointf position = Mathematics::APointf::sm_Origin;
// 		for (int bone = 0; bone < firstControllerTestPtr->GetNumBones(); ++bone)
// 		{
// 			float weight = firstControllerTestPtr->GetWeights(bone, vertex);
// 			if (Mathematics::FloatMath::sm_ZeroTolerance < Mathematics::FloatMath::FAbs(weight))
// 			{
// 				Mathematics::APointf offset = firstControllerTestPtr->GetOffsets(bone, vertex);
// 				Mathematics::APointf worldOffset =
// 					firstControllerTestPtr->GetBones(bone)->GetWorldTransform() * offset;
// 				position += weight * worldOffset;
// 			}
// 		}
// 
// 		VertexBufferAccessor vba(&firstVisualTest);
// 
// 		typedef bool(*Function)(const Mathematics::APointf& lhs, const Mathematics::APointf& rhs,
// 		                        const float epsilon);
// 
// 		Function function = Mathematics::Approximate<float>;
// 
// 		ASSERT_APPROXIMATE_USE_FUNCTION(function, vba.GetPosition<Mathematics::APointf>(vertex), position, 1e-8f);
// 	}
// 	
}

void Rendering::SkinControllerTesting
	::StreamTest()
{
// 	LoadVisual firstLoadVisual(SYSTEM_TEXT("Resource/SceneGraphSuite/Visual.trv"));
// 
// 	CoreTools::OutTopLevel outTopLevel;
// 	CoreTools::ObjectInterfaceSharedPtr firstControlledObjectTest(new VisualTest(firstLoadVisual.GetPrimitiveType(),
// 		                                                                             firstLoadVisual.GetVertexFormat(),
// 																					 firstLoadVisual.GetVertexBuffer(),
// 																					 firstLoadVisual.GetIndexBuffer()));
// 
// 	VisualTest* secondControlledObjectTest =
// 		CoreTools::PolymorphicCast<VisualTest>(firstControlledObjectTest.GetData());
// 
// 	firstControlledObjectTest->SetUniqueID(1);
// 
// 	ControllerInterfaceSharedPtr firstControllerTest(new SkinController(secondControlledObjectTest->GetVertexBuffer()->GetNumElements(),6));
// 	secondControlledObjectTest->AttachController(firstControllerTest);
// 
// 	firstControllerTest->SetUniqueID(2);
// 
// 	SkinController* secondControllerTest =
// 		CoreTools::PolymorphicCast<SkinController>(firstControllerTest.GetData());
// 
// 	secondControllerTest->SetRepeat(ControllerRepeatType::Clamp);
// 	secondControllerTest->SetTime(0.1,0.3);
// 	secondControllerTest->SetPhase(1.5);
// 	secondControllerTest->SetFrequency(2.0);
// 	secondControllerTest->SetActive(true);
// 	secondControllerTest->SetApplicationTime(5.0);
// 
// 	vector<ConstNodeSharedPtr> firstNode;
// 	
// 	for (int bonesIndex = 0; bonesIndex < secondControllerTest->GetNumBones(); ++bonesIndex)
// 	{
// 		firstNode.push_back(ConstNodeSharedPtr(new Node));
// 	}
// 
// 	for (int bonesIndex = 0; bonesIndex < secondControllerTest->GetNumBones(); ++bonesIndex)
// 	{
// 		secondControllerTest->SetBones(bonesIndex, firstNode[bonesIndex]);
// 
// 		for (int verticesIndex = 0; verticesIndex < secondControllerTest->GetNumVertices(); ++verticesIndex)
// 		{
// 			secondControllerTest->SetWeights(bonesIndex, verticesIndex, static_cast<float>(bonesIndex * verticesIndex));
// 			secondControllerTest->SetOffsets(bonesIndex, verticesIndex,
// 				                              Mathematics::APointf(static_cast<float>(bonesIndex),
// 											                       static_cast<float>(verticesIndex),
// 																   1.0f));
// 		}
// 	}
// 
// 	outTopLevel.Insert(firstControlledObjectTest);
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
// 	VisualTestSharedPtr  thirdControlledObjectTest =
// 		inTopLevel[0].PolymorphicDowncastObjectSharedPtr<VisualTestSharedPtr>();
// 
// 	ControllerInterfaceSharedPtr thirdControllerTest = 
// 		thirdControlledObjectTest->GetController(0);
// 
// 	SkinController* fourthControlledTest =
// 		CoreTools::PolymorphicCast<SkinController>(thirdControllerTest.GetData());
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
// 	ASSERT_EQUAL(fourthControlledTest->GetNumBones(), secondControllerTest->GetNumBones());
// 
// 	for (int bonesIndex = 0; bonesIndex < fourthControlledTest->GetNumBones(); ++bonesIndex)
// 	{		 
// 		for (int verticesIndex = 0; verticesIndex < fourthControlledTest->GetNumVertices(); ++verticesIndex)
// 		{
// 			ASSERT_APPROXIMATE(fourthControlledTest->GetWeights(bonesIndex, verticesIndex),
// 				               secondControllerTest->GetWeights(bonesIndex, verticesIndex),1e-8f);
// 
// 			ASSERT_TRUE(Approximate(fourthControlledTest->GetOffsets(bonesIndex, verticesIndex),
// 				                    secondControllerTest->GetOffsets(bonesIndex, verticesIndex),1e-8f));
// 		}
// 	}
}
