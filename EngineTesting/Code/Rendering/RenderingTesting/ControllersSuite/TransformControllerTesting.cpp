// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ²âÊÔ°æ±¾£º0.0.0.3 (2019/09/06 09:46)

#include "TransformControllerTesting.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Rendering/Controllers/TransformController.h"
#include "Rendering/RenderingTesting/SceneGraphSuite/SpatialTest.h"
#include "Rendering/DataTypes/Transform.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, TransformControllerTesting) 

void Rendering::TransformControllerTesting
	::MainTest()
{
	CoreTools::InitTerm::ExecuteInitializers();

	ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
	ASSERT_NOT_THROW_EXCEPTION_0(UpdateTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

	CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::TransformControllerTesting
	::InitTest()
{
// 	SpatialTest controlledObjectTest;
// 
// 	ControllerInterfaceSharedPtr controllerTest(new TransformController(Transform()));
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
// 	TransformController* controllerTestPtr = CoreTools::PolymorphicCast<TransformController>(controllerTest.GetData());
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

void Rendering::TransformControllerTesting
	::CopyTest()
{
// 	SpatialTest controlledObjectTest;
// 
// 	ControllerInterfaceSharedPtr firstControllerTest(new TransformController(Transform()));
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

void Rendering::TransformControllerTesting
	::UpdateTest()
{
// 	Transform firstTransform;
// 	firstTransform.SetScale(Mathematics::APointf(3.0, 6.0, 1.0));
// 	ControllerInterfaceSharedPtr firstControllerTest(new TransformController(firstTransform));
// 
// 	TransformController* firstControllerTestPtr = CoreTools::PolymorphicCast<TransformController>(firstControllerTest.GetData());
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
// 	double timeRange = firstControllerTestPtr->GetMaxTime() - firstControllerTestPtr->GetMinTime();
// 	double multiples = (controlTime - firstControllerTestPtr->GetMinTime()) / timeRange;
// 	double integerTime = Mathematics::Mathd::Floor(multiples);
// 	double fractionTime = multiples - integerTime;
// 
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetControlTime(5.0), firstControllerTestPtr->GetMinTime() + fractionTime * timeRange,1e-10);
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
// 	SpatialTest controlledObjectTest;
// 	controlledObjectTest.AttachController(firstControllerTest);
// 	controlledObjectTest.Update(0.0);
// 
// 	typedef bool (*Function)(const Transform& lhs, const Transform& rhs,const float epsilon);
// 
// 	Function function = Approximate;
// 
// 	ASSERT_APPROXIMATE_USE_FUNCTION(function, controlledObjectTest.GetLocalTransform(), firstTransform, 1e-8f);
}

void Rendering::TransformControllerTesting
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
// 	ControllerInterfaceSharedPtr firstControllerTest(new TransformController(firstTransform));
// 	secondControlledObjectTest->AttachController(firstControllerTest);
// 
// 	firstControllerTest->SetUniqueID(2);
// 
// 	TransformController* secondControllerTest = CoreTools::PolymorphicCast<TransformController>(firstControllerTest.GetData());
// 
// 	secondControllerTest->SetRepeat(ControllerRepeatType::Clamp);
// 	secondControllerTest->SetTime(0.1,0.3);
// 	secondControllerTest->SetPhase(1.5);
// 	secondControllerTest->SetFrequency(2.0);
// 	secondControllerTest->SetActive(true);
// 	secondControllerTest->SetApplicationTime(5.0);
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
// 	SpatialTestSharedPtr  thirdControlledObjectTest = inTopLevel[0].PolymorphicDowncastObjectSharedPtr<SpatialTestSharedPtr>();
// 
// 	ControllerInterfaceSharedPtr thirdControllerTest =  thirdControlledObjectTest->GetController(0);
// 
// 	TransformController* fourthControlledTest = CoreTools::PolymorphicCast<TransformController>(thirdControllerTest.GetData());
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
}
