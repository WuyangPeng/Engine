// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/06 09:43)

#include "PointControllerTesting.h"
#include "PointControllerTest.h"
#include "Rendering/SceneGraph/Polypoint.h"
#include "Rendering/Controllers/Controller.h"
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
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, PointControllerTesting) 

void Rendering::PointControllerTesting
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
#include SYSTEM_WARNING_DISABLE(26440)
void Rendering::PointControllerTesting
	::InitTest()
{
// 	VisualSharedPtr firstPolypoint =	LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/SceneGraphSuite/Polypoint.trv"));
// 	PolypointSharedPtr secondPolypoint = firstPolypoint.PolymorphicDowncastObjectSharedPtr<PolypointSharedPtr>();
// 	
// 	ControllerInterfaceSharedPtr controllerTest(new PointControllerTest);
// 
// 	ASSERT_EQUAL_NULL_PTR(controllerTest->GetControllerObject());
// 	
// 	firstPolypoint->AttachController(controllerTest);
// 
// 	ASSERT_EQUAL(controllerTest->GetControllerObject(), firstPolypoint.GetData());
// 
// 	firstPolypoint->DetachController(controllerTest);
// 
// 	ASSERT_EQUAL_NULL_PTR(controllerTest->GetControllerObject());
// 
// 	PointControllerTest* controllerTestPtr = CoreTools::PolymorphicCast<PointControllerTest>(controllerTest.GetData());
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

void Rendering::PointControllerTesting
	::CopyTest()
{
// 	VisualSharedPtr firstPolypoint =	LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/SceneGraphSuite/Polypoint.trv"));
// 	PolypointSharedPtr secondPolypoint = firstPolypoint.PolymorphicDowncastObjectSharedPtr<PolypointSharedPtr>();
// 	
// 	ControllerInterfaceSharedPtr firstControllerTest(new PointControllerTest);
// 	firstPolypoint->AttachController(firstControllerTest);
// 
// 	PointControllerTest* firstControllerTestPtr = CoreTools::PolymorphicCast<PointControllerTest>(firstControllerTest.GetData());
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
// 	ASSERT_EQUAL(secondControllerTest->GetControllerObject(), firstPolypoint.GetData());
// 
// 	ASSERT_EQUAL(firstControllerTestPtr->GetRepeat(),ControllerRepeatType::Clamp);
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetMinTime(),0.1,1e-10);
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetMaxTime(),0.3,1e-10);
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetPhase(),1.5,1e-10);
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetFrequency(),2.0,1e-10);
// 	ASSERT_TRUE(firstControllerTestPtr->IsActive());
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetApplicationTime(),5.0,1e-10);
// 
// 	PointControllerTest* secondControllerTestPtr = CoreTools::PolymorphicCast<PointControllerTest>(secondControllerTest.GetData());
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

void Rendering::PointControllerTesting
	::UpdateTest()
{
// 	VisualSharedPtr firstPolypoint =	LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/SceneGraphSuite/Polypoint.trv"));
// 	PolypointSharedPtr secondPolypoint = firstPolypoint.PolymorphicDowncastObjectSharedPtr<PolypointSharedPtr>();	
// 
// 	ControllerInterfaceSharedPtr firstControllerTest(new PointControllerTest);
// 
// 	PointControllerTest* firstControllerTestPtr = CoreTools::PolymorphicCast<PointControllerTest>(firstControllerTest.GetData());
// 
// 	firstPolypoint->AttachController(firstControllerTest);
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
// 	int numPoints = firstControllerTestPtr->GetNumPoints();
// 
// 	ASSERT_EQUAL(numPoints,firstPolypoint->GetVertexBuffer()->GetNumElements());
// 
// 	firstControllerTestPtr->SetSystemLinearSpeed(1.0f);
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetSystemLinearSpeed(), 1.0f, 1e-8f);
// 
// 	firstControllerTestPtr->SetSystemAngularSpeed(1.1f);
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetSystemAngularSpeed(), 1.1f, 1e-8f);
//  
// 	firstControllerTestPtr->SetSystemLinearAxis(Mathematics::AVectorf::sm_UnitX);
// 	typedef bool(*Function)(const Mathematics::AVectorf& lhs, const Mathematics::AVectorf& rhs,const float epsilon);
// 	
// 	Function function = Mathematics::Approximate<float>;
// 
// 	ASSERT_APPROXIMATE_USE_FUNCTION(function, firstControllerTestPtr->GetSystemLinearAxis(),Mathematics::AVectorf::sm_UnitX,1e-8f);
// 
// 
// 	firstControllerTestPtr->SetSystemAngularAxis(Mathematics::AVectorf::sm_UnitY);
// 	ASSERT_APPROXIMATE_USE_FUNCTION(function, firstControllerTestPtr->GetSystemAngularAxis(),Mathematics::AVectorf::sm_UnitY,1e-8f); 
// 
// 	for (int i = 0; i < numPoints;++i)
// 	{
// 		firstControllerTestPtr->SetPointLinearSpeed(i, static_cast<float>(i * 0.2f));
// 		firstControllerTestPtr->SetPointAngularSpeed(i,static_cast<float>(i * 0.1f));
// 		firstControllerTestPtr->SetPointLinearAxis(i, Mathematics::AVectorf::sm_UnitX);
// 		firstControllerTestPtr->SetPointAngularAxis(i, Mathematics::AVectorf::sm_UnitY);
// 	}
// 
// 	for (int i = 0; i < numPoints; ++i)
// 	{
// 		ASSERT_APPROXIMATE(firstControllerTestPtr->GetPointLinearSpeed(i), static_cast<float>(i * 0.2f),1e-8f);
// 		ASSERT_APPROXIMATE(firstControllerTestPtr->GetPointAngularSpeed(i), static_cast<float>(i * 0.1f), 1e-8f);
// 		ASSERT_APPROXIMATE_USE_FUNCTION(function, firstControllerTestPtr->GetPointLinearAxis(i), Mathematics::AVectorf::sm_UnitX, 1e-8f);
// 		ASSERT_APPROXIMATE_USE_FUNCTION(function, firstControllerTestPtr->GetPointAngularAxis(i), Mathematics::AVectorf::sm_UnitY, 1e-8f);
// 	} 
// 
// 	ControllerInterfaceSharedPtr thirdPolypoint = firstPolypoint->Clone();
// 	PolypointSharedPtr fourthPolypoint = thirdPolypoint.PolymorphicDowncastObjectSharedPtr<PolypointSharedPtr>();
// 
// 	ControllerInterfaceSharedPtr secondControllerTest = fourthPolypoint->GetController(0);
// 	PointControllerTest* secondControllerTestPtr = CoreTools::PolymorphicCast<PointControllerTest>(secondControllerTest.GetData());
// 	thirdPolypoint->AttachController(secondControllerTest);
// 
// 	firstPolypoint->Update(1.0);
// 
// 	float ctrlTime = static_cast<float>(secondControllerTestPtr->GetControlTime(1.0));
// 
// 	float distance = ctrlTime * secondControllerTestPtr->GetSystemLinearSpeed();
// 	Mathematics::AVectorf deltaTrn = distance * secondControllerTestPtr->GetSystemLinearAxis();
// 	Transform localTransform = fourthPolypoint->GetLocalTransform();
// 	Mathematics::APointf translate = localTransform.GetTranslate() + deltaTrn;
// 	localTransform.SetTranslate(translate);
// 
// 	float angle = ctrlTime * secondControllerTestPtr->GetSystemAngularSpeed();
// 	Mathematics::Matrixf deltaRot(secondControllerTestPtr->GetSystemAngularAxis(), angle);
// 	Mathematics::Matrixf rotate = deltaRot * localTransform.GetRotate();
// 	localTransform.SetRotate(rotate);
// 
// 	typedef bool(*TransformFunction)(const Transform& lhs, const Transform& rhs,const float epsilon);
// 
// 	TransformFunction transformFunction = Approximate;
// 
// 	ASSERT_APPROXIMATE_USE_FUNCTION(transformFunction, localTransform, firstPolypoint->GetLocalTransform(), 1e-8f);
// 
// 	typedef bool(*APointFunction)(const Mathematics::APointf& lhs, const Mathematics::APointf& rhs,const float epsilon);
// 
// 	APointFunction aPointFunction = Mathematics::Approximate<float>;
// 
// 	VertexBufferAccessor secondVba(secondPolypoint.GetData());
// 	VertexBufferAccessor fourthVba(fourthPolypoint.GetData());
// 	for (int i = 0; i < numPoints; ++i)
// 	{
// 		float distance1 = ctrlTime * secondControllerTestPtr->GetPointLinearSpeed(i);
// 		Mathematics::APointf position = fourthVba.GetPosition<Mathematics::APointf>(i);
// 		Mathematics::AVectorf deltaTrn1 = distance1 * secondControllerTestPtr->GetPointLinearAxis(i);
// 
// 		ASSERT_APPROXIMATE_USE_FUNCTION(aPointFunction, secondVba.GetPosition<Mathematics::APointf>(i),position + deltaTrn1,1e-8f);
// 	}
// 
// 	if (fourthVba.HasNormal())
// 	{
// 		for (int i = 0; i < numPoints; ++i)
// 		{
// 			float angle1 = ctrlTime * secondControllerTestPtr->GetPointAngularSpeed(i);
// 			Mathematics::AVectorf normal = fourthVba.GetNormal<Mathematics::AVectorf>(i);
// 			normal.Normalize();
// 			Mathematics::Matrixf deltaRot1(secondControllerTestPtr->GetPointAngularAxis(i), angle1);
// 
// 			ASSERT_APPROXIMATE_USE_FUNCTION(function, secondVba.GetPosition<Mathematics::AVectorf>(i),deltaRot1 * normal,1e-8f);		
// 		}
// 	}
}

void Rendering::PointControllerTesting
	::StreamTest()
{
// 	CoreTools::OutTopLevel outTopLevel;
// 
// 	VisualSharedPtr firstPolypoint = LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/SceneGraphSuite/Polypoint.trv"));
// 	PolypointSharedPtr secondPolypoint = firstPolypoint.PolymorphicDowncastObjectSharedPtr<PolypointSharedPtr>();
// 
// 	CoreTools::ObjectInterfaceSharedPtr firstControlledObjectTest(firstPolypoint.PolymorphicDowncastObjectSharedPtr<CoreTools::ObjectInterfaceSharedPtr>());
// 
// 	Polypoint* secondControlledObjectTest = CoreTools::PolymorphicCast<Polypoint>(firstControlledObjectTest.GetData());
// 
// 	firstControlledObjectTest->SetUniqueID(1);
// 
// 	ControllerInterfaceSharedPtr firstControllerTest(new PointControllerTest);
// 	secondControlledObjectTest->AttachController(firstControllerTest);
// 
// 	firstControllerTest->SetUniqueID(2);
// 
// 	PointControllerTest* secondControllerTest = CoreTools::PolymorphicCast<PointControllerTest>(firstControllerTest.GetData());
// 
// 	secondControllerTest->SetRepeat(ControllerRepeatType::Clamp);
// 	secondControllerTest->SetTime(0.1,0.3);
// 	secondControllerTest->SetPhase(1.5);
// 	secondControllerTest->SetFrequency(2.0);
// 	secondControllerTest->SetActive(true);
// 	secondControllerTest->SetApplicationTime(5.0);
// 
// 	secondControllerTest->SetSystemLinearSpeed(1.0f);	 
// 	secondControllerTest->SetSystemAngularSpeed(1.1f);	 
// 	secondControllerTest->SetSystemLinearAxis(Mathematics::AVectorf::sm_UnitX);
// 	secondControllerTest->SetSystemAngularAxis(Mathematics::AVectorf::sm_UnitY);	
// 
// 	int numPoints = secondControllerTest->GetNumPoints();
// 
// 	for (int i = 0; i < numPoints;++i)
// 	{
// 		secondControllerTest->SetPointLinearSpeed(i, static_cast<float>(i * 0.2f));
// 		secondControllerTest->SetPointAngularSpeed(i, static_cast<float>(i * 0.1f));
// 		secondControllerTest->SetPointLinearAxis(i, Mathematics::AVectorf::sm_UnitX);
// 		secondControllerTest->SetPointAngularAxis(i, Mathematics::AVectorf::sm_UnitY);
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
// 	PolypointSharedPtr  thirdControlledObjectTest = inTopLevel[0].PolymorphicDowncastObjectSharedPtr<PolypointSharedPtr>();
// 
// 	ControllerInterfaceSharedPtr thirdControllerTest =  thirdControlledObjectTest->GetController(0);
// 
// 	PointControllerTest* fourthControlledTest = CoreTools::PolymorphicCast<PointControllerTest>(thirdControllerTest.GetData());
// 
// 	ASSERT_EQUAL(fourthControlledTest->GetRepeat(), secondControllerTest->GetRepeat());
// 	ASSERT_APPROXIMATE(fourthControlledTest->GetMinTime(),secondControllerTest-> GetMinTime(),1e-10);
// 	ASSERT_APPROXIMATE(fourthControlledTest->GetMaxTime(),secondControllerTest-> GetMaxTime(),1e-10);
// 	ASSERT_APPROXIMATE(fourthControlledTest->GetPhase(),secondControllerTest->GetPhase(),1e-10);
// 	ASSERT_APPROXIMATE(fourthControlledTest->GetFrequency(),secondControllerTest-> GetFrequency(),1e-10);
// 	ASSERT_EQUAL(fourthControlledTest->IsActive(),secondControllerTest->IsActive());
// 
// 	ASSERT_EQUAL(fourthControlledTest->GetControllerObject(),thirdControlledObjectTest.GetData());
// 
// 	ASSERT_EQUAL(fourthControlledTest->GetNumPoints(), secondControllerTest->GetNumPoints());
// 
// 	typedef bool(*Function)(const Mathematics::AVectorf& lhs, const Mathematics::AVectorf& rhs,const float epsilon);
// 
// 	Function function = Mathematics::Approximate<float>;
// 
// 	ASSERT_APPROXIMATE(fourthControlledTest->GetSystemLinearSpeed(), secondControllerTest->GetSystemLinearSpeed(), 1e-8f);
//  
// 	ASSERT_APPROXIMATE(fourthControlledTest->GetSystemAngularSpeed(), secondControllerTest->GetSystemAngularSpeed(), 1e-8f);
// 	ASSERT_APPROXIMATE_USE_FUNCTION(function, fourthControlledTest->GetSystemLinearAxis(), secondControllerTest->GetSystemLinearAxis(),1e-8f); 
// 	ASSERT_APPROXIMATE_USE_FUNCTION(function, fourthControlledTest->GetSystemAngularAxis(),secondControllerTest->GetSystemAngularAxis(),1e-8f); 
// 
// 	for (int i = 0; i < numPoints; ++i)
// 	{
// 		ASSERT_APPROXIMATE(fourthControlledTest->GetPointLinearSpeed(i), secondControllerTest->GetPointLinearSpeed(i), 1e-8f);
// 		ASSERT_APPROXIMATE(fourthControlledTest->GetPointAngularSpeed(i), secondControllerTest->GetPointAngularSpeed(i), 1e-8f);
// 		ASSERT_APPROXIMATE_USE_FUNCTION(function, fourthControlledTest->GetPointLinearAxis(i), secondControllerTest->GetPointLinearAxis(i), 1e-8f);
// 		ASSERT_APPROXIMATE_USE_FUNCTION(function, fourthControlledTest->GetPointAngularAxis(i), secondControllerTest->GetPointAngularAxis(i), 1e-8f);
// 	} 
}
