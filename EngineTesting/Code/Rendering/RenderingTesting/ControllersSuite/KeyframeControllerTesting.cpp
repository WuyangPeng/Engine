// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ²âÊÔ°æ±¾£º0.0.0.3 (2019/09/06 09:34)

#include "KeyframeControllerTesting.h"
#include "Rendering/DataTypes/Transform.h"
#include "Rendering/Controllers/KeyframeController.h"
#include "Rendering/RenderingTesting/SceneGraphSuite/SpatialTest.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AQuaternionDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, KeyframeControllerTesting) 

void Rendering::KeyframeControllerTesting
	::MainTest()
{
	CoreTools::InitTerm::ExecuteInitializers();

	ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
	ASSERT_NOT_THROW_EXCEPTION_0(UpdateTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

	CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::KeyframeControllerTesting
	::InitTest()
{
// 	SpatialTest controlledObjectTest;
// 
// 	ControllerInterfaceSharedPtr controllerTest(new KeyframeController(1,4,3,2,Transform()));
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
// 	KeyframeController* controllerTestPtr =	CoreTools::PolymorphicCast<KeyframeController>(controllerTest.GetData());
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

void Rendering::KeyframeControllerTesting
	::CopyTest()
{
// 	SpatialTest controlledObjectTest;
// 
// 	ControllerInterfaceSharedPtr firstControllerTest(new KeyframeController(1, 4, 3, 2, Transform()));
// 	controlledObjectTest.AttachController(firstControllerTest);
// 
// 	TransformController* firstControllerTestPtr = CoreTools::PolymorphicCast<TransformController>(firstControllerTest.GetData());
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
// 	TransformController* secondControllerTestPtr = CoreTools::PolymorphicCast<TransformController>(secondControllerTest.GetData());
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

void Rendering::KeyframeControllerTesting
	::UpdateTest()
{
// 	Transform firstTransform;
// 	firstTransform.SetScale(Mathematics::APointf(3.0, 6.0, 1.0));
// 	ControllerInterfaceSharedPtr firstControllerTest(new KeyframeController(4, 6, 4, 8, firstTransform));
// 
// 	KeyframeController* firstControllerTestPtr = CoreTools::PolymorphicCast<KeyframeController>(firstControllerTest.GetData());
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
// 	double timeRange = firstControllerTestPtr->GetMaxTime() - firstControllerTestPtr->GetMinTime();
// 	double multiples = (controlTime - firstControllerTestPtr->GetMinTime()) / timeRange;
// 	double integerTime = Mathematics::Mathd::Floor(multiples);
// 	double fractionTime = multiples - integerTime;
// 
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetControlTime(5.0),firstControllerTestPtr->GetMinTime() + fractionTime * timeRange,1e-10);
// 
// 	firstControllerTestPtr->SetRepeat(ControllerRepeatType::ClampCycle);
// 
// 	if (static_cast<int>(integerTime) & 1)
// 	{
//  	   ASSERT_APPROXIMATE(firstControllerTestPtr->GetControlTime(5.0),firstControllerTestPtr->GetMaxTime() - fractionTime * timeRange,1e-10); 
// 	}
// 	else
// 	{
//  	   ASSERT_APPROXIMATE(firstControllerTestPtr->GetControlTime(5.0),firstControllerTestPtr->GetMinTime() + fractionTime * timeRange,1e-10); 
// 	}	
// 
// 	ASSERT_EQUAL(firstControllerTestPtr->GetNumCommonTimes(), 4);
// 	ASSERT_EQUAL(firstControllerTestPtr->GetNumTranslations(), 6);
// 	ASSERT_EQUAL(firstControllerTestPtr->GetNumRotations(), 4);
// 	ASSERT_EQUAL(firstControllerTestPtr->GetNumScales(), 8);
// 
// 	for (int i = 0; i < firstControllerTestPtr->GetNumCommonTimes();++i)
// 	{
// 		firstControllerTestPtr->SetCommonTimes(i, static_cast<float>(i));
// 	}
// 
// 	for (int i = 0; i < firstControllerTestPtr->GetNumTranslations(); ++i)
// 	{
// 		firstControllerTestPtr->SetTranslations(i, Mathematics::APointf(static_cast<float>(i),static_cast<float>(i + 1),static_cast<float>(i - 1)));
// 	}
// 	
// 	for (int i = 0; i < firstControllerTestPtr->GetNumRotations(); ++i)
// 	{
// 		firstControllerTestPtr->SetRotations(i, Mathematics::AQuaternionf(static_cast<float>(i),static_cast<float>(i + 1), static_cast<float>(i - 1), static_cast<float>(i + 2)));
// 	}
// 	 
// 	for (int i = 0; i < firstControllerTestPtr->GetNumScales(); ++i)
// 	{
// 		firstControllerTestPtr->SetScales(i, static_cast<float>(i));
// 	}
// 
// 	for (int i = 0; i < firstControllerTestPtr->GetNumCommonTimes();++i)
// 	{
// 		ASSERT_APPROXIMATE(firstControllerTestPtr->GetCommonTimes(i), static_cast<float>(i),1e-8f);
// 	}
// 
// 	typedef bool(*PointFunction)(const Mathematics::APointf& lhs, const Mathematics::APointf& rhs,const float epsilon);
// 
// 	PointFunction pointFunction = Mathematics::Approximate<float>;
// 
// 	for (int i = 0; i < firstControllerTestPtr->GetNumTranslations(); ++i)
// 	{
// 		ASSERT_APPROXIMATE_USE_FUNCTION(pointFunction, firstControllerTestPtr->GetTranslations(i),
// 			                            Mathematics::APointf(static_cast<float>(i),static_cast<float>(i + 1), static_cast<float>(i - 1)),1e-8f);
// 	}
// 
// 	typedef bool(*QuaternionFunction)(const Mathematics::AQuaternionf& lhs, const Mathematics::AQuaternionf& rhs,const float epsilon);
// 
// 	QuaternionFunction quaternionFunction = Mathematics::Approximate<float>;
// 	
// 	for (int i = 0; i < firstControllerTestPtr->GetNumRotations(); ++i)
// 	{
// 		ASSERT_APPROXIMATE_USE_FUNCTION(quaternionFunction,firstControllerTestPtr->GetRotations(i),
// 			                            Mathematics::AQuaternionf(static_cast<float>(i),static_cast<float>(i + 1), static_cast<float>(i - 1),static_cast<float>(i + 2)),1e-8f);
// 	}
// 	 
// 	for (int i = 0; i < firstControllerTestPtr->GetNumScales(); ++i)
// 	{
// 		ASSERT_APPROXIMATE(firstControllerTestPtr->GetScales(i), static_cast<float>(i),1e-8f);
// 	}
// 
// 	SpatialTest controlledObjectTest;
// 	controlledObjectTest.AttachController(firstControllerTest);	
// 
// 	int lastIndex = 0;
// 
// 	controlledObjectTest.Update(1.0);
// 	
// 	typedef bool (*Function)(const Transform& lhs, const Transform& rhs,
// 		                     const float epsilon);
// 
// 	Function function = Approximate;
// 
// 	Transform secondTransform = firstTransform;
// 
// 	float ctrlTime = static_cast<float>(firstControllerTestPtr->GetControlTime(1.1f));
//  
// 	if (0 < firstControllerTestPtr->GetNumCommonTimes())
// 	{
// 		ControllerKeyInfo controllerKeyInfo;
// 		
// 		if (ctrlTime <= firstControllerTestPtr->GetCommonTimes(0))
// 		{
// 			lastIndex = 0;
// 
// 			controllerKeyInfo = ControllerKeyInfo();
// 		}
// 		else if (firstControllerTestPtr->GetCommonTimes(firstControllerTestPtr->GetNumCommonTimes() - 1) <= ctrlTime)
// 		{
// 			lastIndex = firstControllerTestPtr->GetNumCommonTimes() - 1;
// 
// 			controllerKeyInfo = ControllerKeyInfo(0.0f, lastIndex, lastIndex);
// 		}
// 		else
// 		{
// 			if (firstControllerTestPtr->GetCommonTimes(lastIndex) < ctrlTime)
// 			{
// 				int nextIndex = lastIndex + 1;
// 				while (firstControllerTestPtr->GetCommonTimes(nextIndex) <= ctrlTime)
// 				{
// 					lastIndex = nextIndex;
// 					++nextIndex;
// 				}
// 
// 				float normTime = (ctrlTime - firstControllerTestPtr->GetCommonTimes(lastIndex)) / (firstControllerTestPtr->GetCommonTimes(nextIndex) - firstControllerTestPtr->GetCommonTimes(lastIndex));
// 
// 				controllerKeyInfo = ControllerKeyInfo(normTime, lastIndex, nextIndex);
// 			}
// 			else if (ctrlTime < firstControllerTestPtr->GetCommonTimes(lastIndex))
// 			{
// 				int nextIndex = lastIndex - 1;
// 				while (ctrlTime <= firstControllerTestPtr->GetCommonTimes(nextIndex))
// 				{
// 					lastIndex = nextIndex;
// 					--nextIndex;
// 				}
// 
// 				float normTime = (ctrlTime - firstControllerTestPtr->GetCommonTimes(nextIndex)) / (firstControllerTestPtr->GetCommonTimes(lastIndex) - firstControllerTestPtr->GetCommonTimes(nextIndex));
// 
// 				controllerKeyInfo = ControllerKeyInfo(normTime, nextIndex, lastIndex);
// 			}
// 			else
// 			{
// 				controllerKeyInfo = ControllerKeyInfo(0.0f, lastIndex, lastIndex);
// 			}
// 		}		 
// 
// 		if (0 < firstControllerTestPtr->GetNumTranslations())
// 		{
// 			Mathematics::APointf translate = firstControllerTestPtr->GetTranslations(controllerKeyInfo.GetFirstIndex()) + controllerKeyInfo.GetNormTime() *
// 											 (firstControllerTestPtr->GetTranslations(controllerKeyInfo.GetSecondIndex()) - firstControllerTestPtr->GetTranslations(controllerKeyInfo.GetFirstIndex()));
// 
// 			secondTransform.SetTranslate(translate);
// 		}
// 
// 		if (0 < firstControllerTestPtr->GetNumRotations())
// 		{
// 			Mathematics::AQuaternionf quaternion;
// 			quaternion.Slerp(controllerKeyInfo.GetNormTime(), 
// 				             firstControllerTestPtr->GetRotations(controllerKeyInfo.GetFirstIndex()),
// 							 firstControllerTestPtr->GetRotations(controllerKeyInfo.GetSecondIndex()));
// 
// 			Mathematics::Matrixf rotate = quaternion.ToRotationMatrix();
// 			secondTransform.SetRotate(rotate);
// 		}
// 
// 		if (0 < firstControllerTestPtr->GetNumScales())
// 		{
// 			float scale = firstControllerTestPtr->GetScales(controllerKeyInfo.GetFirstIndex()) +
// 				          controllerKeyInfo.GetNormTime() * (firstControllerTestPtr->GetScales(controllerKeyInfo.GetSecondIndex()) - 
// 						  firstControllerTestPtr->GetScales(controllerKeyInfo.GetFirstIndex()));
// 			secondTransform.SetUniformScale(scale);
// 		}
// 	}
// 
// 	ASSERT_APPROXIMATE_USE_FUNCTION(function, controlledObjectTest.GetLocalTransform(), secondTransform, 1e-8f);
}

void Rendering::KeyframeControllerTesting
	::StreamTest()
{
// 	CoreTools::OutTopLevel outTopLevel;
// 	CoreTools::ObjectInterfaceSharedPtr firstControlledObjectTest(new SpatialTest);
// 
// 	SpatialTest* secondControlledObjectTest = CoreTools::PolymorphicCast<SpatialTest>(firstControlledObjectTest.GetData());
// 
// 	firstControlledObjectTest->SetUniqueID(1);
// 
// 	Transform firstTransform;
// 	firstTransform.SetScale(Mathematics::APointf(3.0, 6.0, 1.0));
// 
// 	ControllerInterfaceSharedPtr firstControllerTest(new KeyframeController(4, 6, 4, 8, firstTransform));
// 	secondControlledObjectTest->AttachController(firstControllerTest);
// 
// 	firstControllerTest->SetUniqueID(2);
// 
// 	KeyframeController* secondControllerTest = CoreTools::PolymorphicCast<KeyframeController>(firstControllerTest.GetData());
// 
// 	secondControllerTest->SetRepeat(ControllerRepeatType::Clamp);
// 	secondControllerTest->SetTime(0.1,0.3);
// 	secondControllerTest->SetPhase(1.5);
// 	secondControllerTest->SetFrequency(2.0);
// 	secondControllerTest->SetActive(true);
// 	secondControllerTest->SetApplicationTime(5.0);
// 
// 	for (int i = 0; i < secondControllerTest->GetNumCommonTimes(); ++i)
// 	{
// 		secondControllerTest->SetCommonTimes(i, static_cast<float>(i));
// 	}
// 
// 	for (int i = 0; i < secondControllerTest->GetNumTranslations(); ++i)
// 	{
// 		secondControllerTest->SetTranslations(i, Mathematics::APointf(static_cast<float>(i),
// 			                                                            static_cast<float>(i + 1), 
// 			                                                            static_cast<float>(i - 1)));
// 	}
// 	
// 	for (int i = 0; i < secondControllerTest->GetNumRotations(); ++i)
// 	{
// 		secondControllerTest->SetRotations(i, Mathematics::AQuaternionf(static_cast<float>(i),
// 			                                                              static_cast<float>(i + 1), 
// 			                                                              static_cast<float>(i - 1),
// 																		  static_cast<float>(i + 2)));
// 	}
// 	 
// 	for (int i = 0; i < secondControllerTest->GetNumScales(); ++i)
// 	{
// 		secondControllerTest->SetScales(i, static_cast<float>(i));
// 	}
// 
// 	outTopLevel.Insert(firstControlledObjectTest);
//         
// 	CoreTools::BufferOutStream outStream(outTopLevel);
// 
// 	CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr = outStream.GetBufferOutStreamInformation();
//         
// 	CoreTools::BufferInStream inStream(fileBufferPtr);
//         
// 	CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
// 
// 	SpatialTestSharedPtr  thirdControlledObjectTest =
// 		inTopLevel[0].PolymorphicDowncastObjectSharedPtr<SpatialTestSharedPtr>();
// 
// 	ControllerInterfaceSharedPtr thirdControllerTest = 
// 		thirdControlledObjectTest->GetController(0);
// 
// 	KeyframeController* fourthControlledTest =
// 		CoreTools::PolymorphicCast<KeyframeController>(thirdControllerTest.GetData());
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
// 	typedef bool(*Function)(const Transform& lhs, const Transform& rhs,const float epsilon);
// 
// 	Function function = Approximate;
// 
// 	ASSERT_APPROXIMATE_USE_FUNCTION(function, fourthControlledTest->GetTransform(), firstTransform, 1e-8f);
// 
// 	ASSERT_EQUAL(fourthControlledTest->GetNumCommonTimes(), secondControllerTest->GetNumCommonTimes());
// 	ASSERT_EQUAL(fourthControlledTest->GetNumTranslations(), secondControllerTest->GetNumTranslations());
// 	ASSERT_EQUAL(fourthControlledTest->GetNumRotations(), secondControllerTest->GetNumRotations());
// 	ASSERT_EQUAL(fourthControlledTest->GetNumScales(), secondControllerTest->GetNumScales());
// 
// 	 
// 	for (int i = 0; i < fourthControlledTest->GetNumCommonTimes(); ++i)
// 	{
// 		ASSERT_APPROXIMATE(fourthControlledTest->GetCommonTimes(i), secondControllerTest->GetCommonTimes(i), 1e-8f);
// 	}
// 
// 	typedef bool(*PointFunction)(const Mathematics::APointf& lhs, const Mathematics::APointf& rhs,const float epsilon);
// 
// 	PointFunction pointFunction = Mathematics::Approximate<float>;
// 
// 	for (int i = 0; i < fourthControlledTest->GetNumTranslations(); ++i)
// 	{
// 		ASSERT_APPROXIMATE_USE_FUNCTION(pointFunction, fourthControlledTest->GetTranslations(i),
// 			                            secondControllerTest->GetTranslations(i),1e-8f);
// 	}
// 
// 	typedef bool(*QuaternionFunction)(const Mathematics::AQuaternionf& lhs, const Mathematics::AQuaternionf& rhs,
// 		                              const float epsilon);
// 
// 	QuaternionFunction quaternionFunction = Mathematics::Approximate<float>;
// 	
// 	for (int i = 0; i < fourthControlledTest->GetNumRotations(); ++i)
// 	{
// 		ASSERT_APPROXIMATE_USE_FUNCTION(quaternionFunction, fourthControlledTest->GetRotations(i),
// 			                            secondControllerTest->GetRotations(i),1e-8f);
// 	}
// 	 
// 	for (int i = 0; i < fourthControlledTest->GetNumScales(); ++i)
// 	{
// 		ASSERT_APPROXIMATE(fourthControlledTest->GetScales(i), secondControllerTest->GetScales(i), 1e-8f);
// 	}

}
