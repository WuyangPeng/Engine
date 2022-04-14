// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ²âÊÔ°æ±¾£º0.0.0.3 (2019/09/05 16:26)

#include "BlendTransformControllerTesting.h"
#include "Rendering/DataTypes/Transform.h"
#include "Rendering/Controllers/BlendTransformController.h"
#include "Rendering/RenderingTesting/SceneGraphSuite/SpatialTest.h"
#include "Mathematics/Base/MathDetail.h"
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


UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, BlendTransformControllerTesting) 
#include SYSTEM_WARNING_DISABLE(26440)
void Rendering::BlendTransformControllerTesting
	::MainTest()
{
	CoreTools::InitTerm::ExecuteInitializers();

	ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
	ASSERT_NOT_THROW_EXCEPTION_0(UpdateTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

	CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::BlendTransformControllerTesting
	::InitTest()  
{
// 	SpatialTest controlledObjectTest;
// 
// 	TransformControllerSharedPtr firstTransformController(new TransformController(Transform()));
// 	TransformControllerSharedPtr secondTransformController(new TransformController(Transform()));
// 
// 	ControllerInterfaceSharedPtr controllerTest(new BlendTransformController(firstTransformController,secondTransformController,true));
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

void Rendering::BlendTransformControllerTesting
	::CopyTest()
{
// 	SpatialTest controlledObjectTest;
// 
// 	TransformControllerSharedPtr firstTransformController(new TransformController(Transform()));
// 	TransformControllerSharedPtr secondTransformController(new TransformController(Transform()));
// 
// 	ControllerInterfaceSharedPtr firstControllerTest(new BlendTransformController(firstTransformController, secondTransformController, true));
// 
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
// 	TransformController* secondControllerTestPtr =	CoreTools::PolymorphicCast<TransformController>(secondControllerTest.GetData());
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

void Rendering::BlendTransformControllerTesting
	::UpdateTest()
{
// 	Transform firstTransform;
// 	firstTransform.SetScale(Mathematics::APointf(3.0, 6.0, 1.0));
// 	firstTransform.SetTranslate(Mathematics::APointf(1.0, 16.0, 2.0));
// 	firstTransform.SetRotate(Mathematics::Matrixf(Mathematics::AVectorf::sm_UnitX, 30.0f));
// 	TransformControllerSharedPtr firstControllerTest(new TransformController(firstTransform));
// 
// 	Transform secondTransform;
// 	secondTransform.SetScale(Mathematics::APointf(13.0, 16.0, 11.0));
// 	secondTransform.SetTranslate(Mathematics::APointf(11.0, 26.0, 12.0));
// 	secondTransform.SetRotate(Mathematics::Matrixf(Mathematics::AVectorf::sm_UnitY, 20.0f));
// 	TransformControllerSharedPtr secondControllerTest(new TransformController(secondTransform));
// 
// 	ControllerInterfaceSharedPtr thirdControllerTest(new BlendTransformController(firstControllerTest,secondControllerTest,true));
// 
// 	BlendTransformController* firstControllerTestPtr =	CoreTools::PolymorphicCast<BlendTransformController>(thirdControllerTest.GetData());
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
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetControlTime(6.0), firstControllerTestPtr->GetMaxTime(),1e-10);
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
//  	   ASSERT_APPROXIMATE(firstControllerTestPtr->GetControlTime(5.0), firstControllerTestPtr->GetMinTime() + fractionTime * timeRange,1e-10); 
// 	}
// 
// 	SpatialTest controlledObjectTest;
// 	controlledObjectTest.AttachController(thirdControllerTest);
// 	controlledObjectTest.Update(0.0);
// 
// 	typedef bool (*Function)(const Transform& lhs, const Transform& rhs,const float epsilon);
// 
// 	Function function = Approximate;
// 
// 	ASSERT_APPROXIMATE_USE_FUNCTION(function, controlledObjectTest.GetLocalTransform(), firstTransform, 1e-6f);
// 
// 	ASSERT_EQUAL(firstControllerTestPtr->GetFirstController(), firstControllerTest);
// 	ASSERT_EQUAL(firstControllerTestPtr->GetSecondController(), secondControllerTest);
// 	ASSERT_TRUE(firstControllerTestPtr->IsRotationScaleMatrices());
// 	ASSERT_FALSE(firstControllerTestPtr->IsGeometricRotation());
// 	ASSERT_FALSE(firstControllerTestPtr->IsGeometricScale());
// 
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetWeight(), 0.0f, 1e-8f);
// 
// 	firstControllerTestPtr->SetWeight(1.0);
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetWeight(), 1.0f,1e-8f);
// 	controlledObjectTest.Update(0.0);
// 	ASSERT_APPROXIMATE_USE_FUNCTION(function, controlledObjectTest.GetLocalTransform(), secondTransform, 1e-6f);
// 
// 	float weight = 0.3f;
// 	firstControllerTestPtr->SetWeight(weight);
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetWeight(), weight, 1e-8f);
// 
// 	Transform thirdTransform;
//  
// 	float oneMinusWeight = 1.0f - weight;
//  
// 	const Mathematics::APointf firstTranslate = firstTransform.GetTranslate();
// 	const Mathematics::APointf secondTranslate = secondTransform.GetTranslate();
// 	Mathematics::APointf blendTranslate = oneMinusWeight * firstTranslate + weight * secondTranslate;
// 	thirdTransform.SetTranslate(blendTranslate);
// 
// 	const Mathematics::Matrixf firstRotate = firstTransform.GetRotate();
// 	const Mathematics::Matrixf secondRotate = secondTransform.GetRotate();
// 
// 	Mathematics::AQuaternionf firstQuaternion(firstRotate);
// 	Mathematics::AQuaternionf secondQuaternion(secondRotate);
// 	if (Dot(firstQuaternion, secondQuaternion) < 0.0f)
// 	{
// 		secondQuaternion = -secondQuaternion;
// 	}
// 
// 	Mathematics::AQuaternionf blendQuaternion;
// 	
// 	blendQuaternion = oneMinusWeight * firstQuaternion + weight * secondQuaternion;
// 	blendQuaternion.Normalize();
// 	thirdTransform.SetRotate(blendQuaternion.ToRotationMatrix());
// 
// 	Mathematics::APointf firstScale = firstTransform.GetScale();
// 	Mathematics::APointf secondScale = secondTransform.GetScale();
// 
// 	Mathematics::APointf blendScale = oneMinusWeight * firstScale + weight * secondScale;
// 	thirdTransform.SetScale(blendScale);
// 
// 	controlledObjectTest.Update(0.0);
// 	ASSERT_APPROXIMATE_USE_FUNCTION(function, controlledObjectTest.GetLocalTransform(), thirdTransform, 1e-8f);
}

void Rendering::BlendTransformControllerTesting
	::StreamTest()
{
// 	CoreTools::OutTopLevel outTopLevel;
// 
// 	Transform firstTransform;
// 	firstTransform.SetScale(Mathematics::APointf(3.0, 6.0, 1.0));
// 	firstTransform.SetTranslate(Mathematics::APointf(1.0, 16.0, 2.0));
// 	firstTransform.SetRotate(Mathematics::Matrixf(Mathematics::AVectorf::sm_UnitX, 30.0f));
// 	TransformControllerSharedPtr firstControllerTest(new TransformController(firstTransform));
// 	outTopLevel.Insert(firstControllerTest);
// 
// 	Transform secondTransform;
// 	secondTransform.SetScale(Mathematics::APointf(13.0, 16.0, 11.0));
// 	secondTransform.SetTranslate(Mathematics::APointf(11.0, 26.0, 12.0));
// 	secondTransform.SetRotate(Mathematics::Matrixf(Mathematics::AVectorf::sm_UnitY, 20.0f));
// 	TransformControllerSharedPtr secondControllerTest(new TransformController(secondTransform));
// 	outTopLevel.Insert(secondControllerTest);
// 
// 	BlendTransformControllerSharedPtr thirdControllerTest(new BlendTransformController(firstControllerTest, secondControllerTest, true));
// 	outTopLevel.Insert(thirdControllerTest);
// 
// 	thirdControllerTest->SetRepeat(ControllerRepeatType::Clamp);
// 	thirdControllerTest->SetTime(0.1, 0.3);
// 	thirdControllerTest->SetPhase(1.5);
// 	thirdControllerTest->SetFrequency(2.0);
// 	thirdControllerTest->SetActive(true);
// 	thirdControllerTest->SetApplicationTime(5.0);
//         
// 	CoreTools::BufferOutStream outStream(outTopLevel);
// 
// 	CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr = outStream.GetBufferOutStreamInformation();
//         
// 	CoreTools::BufferInStream inStream(fileBufferPtr);
//         
// 	CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
// 
// 	BlendTransformControllerSharedPtr  thirdControlledObjectTest = inTopLevel[inTopLevel.GetTopLevelSize() - 1].PolymorphicDowncastObjectSharedPtr<BlendTransformControllerSharedPtr>();
// 
// 	ASSERT_EQUAL(thirdControlledObjectTest->GetRepeat(), thirdControllerTest->GetRepeat());
// 	ASSERT_APPROXIMATE(thirdControlledObjectTest->GetMinTime(),thirdControllerTest-> GetMinTime(),1e-10);
// 	ASSERT_APPROXIMATE(thirdControlledObjectTest->GetMaxTime(),thirdControllerTest-> GetMaxTime(),1e-10);
// 	ASSERT_APPROXIMATE(thirdControlledObjectTest->GetPhase(),thirdControllerTest->GetPhase(),1e-10);
// 	ASSERT_APPROXIMATE(thirdControlledObjectTest->GetFrequency(), thirdControllerTest->GetFrequency(), 1e-10);
// 	ASSERT_EQUAL(thirdControlledObjectTest->IsActive(), thirdControllerTest->IsActive());
// 	 
// 	typedef bool(*Function)(const Transform& lhs, const Transform& rhs,const float epsilon);
// 
// 	Function function = Approximate;
// 
// 	ASSERT_APPROXIMATE_USE_FUNCTION(function, thirdControlledObjectTest->GetTransform(), thirdControllerTest->GetTransform(), 1e-8f); 
// 
// 	ASSERT_APPROXIMATE_USE_FUNCTION(function, thirdControlledObjectTest->GetFirstController()->GetTransform(), thirdControllerTest->GetFirstController()->GetTransform(), 1e-8f);
// 	ASSERT_APPROXIMATE_USE_FUNCTION(function, thirdControlledObjectTest->GetSecondController()->GetTransform(), thirdControllerTest->GetSecondController()->GetTransform(), 1e-8f);
// 	ASSERT_EQUAL(thirdControlledObjectTest->IsRotationScaleMatrices(), thirdControllerTest->IsRotationScaleMatrices());
// 	ASSERT_EQUAL(thirdControlledObjectTest->IsGeometricRotation(), thirdControllerTest->IsGeometricRotation());
// 	ASSERT_EQUAL(thirdControlledObjectTest->IsGeometricScale(), thirdControllerTest->IsGeometricScale());
// 
// 	ASSERT_APPROXIMATE(thirdControlledObjectTest->GetWeight(), thirdControllerTest->GetWeight(), 1e-8f);
}
