// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.0.3 (2019/09/05 11:25)

#include "SpatialTest.h"
#include "SpatialTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/RenderingTesting/ControllersSuite/ControllerTest.h"
#include "Rendering/SceneGraph/CameraManager.h"

#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"

#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26414)
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, SpatialTesting)

void Rendering::SpatialTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    CameraManager::Create();

   // ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TransformTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

    CameraManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::SpatialTesting::InitTest()
{
    auto firstSpatialTest = std::make_shared<SpatialTest>();

    ASSERT_EQUAL(firstSpatialTest->GetNumControllers(), 0);

    ControllerInterfaceSharedPtr controllerTest(new ControllerTest);
    firstSpatialTest->AttachController(controllerTest);

    ASSERT_EQUAL(firstSpatialTest->GetNumControllers(), 1);
    ASSERT_EQUAL(firstSpatialTest->GetController(0), controllerTest);

    ControllerInterfaceSharedPtr secondSpatialTest(new SpatialTest);

    ASSERT_EQUAL_NULL_PTR(secondSpatialTest->GetControllerObject());

    firstSpatialTest->AttachController(secondSpatialTest);

    // 	SpatialTest* ptr = CoreTools::StaticCast<SpatialTest>(secondSpatialTest.GetData());
    //
    // 	ASSERT_EQUAL(secondSpatialTest->GetControllerObject(),&firstSpatialTest);
    // 	ASSERT_EQUAL_NULL_PTR(ptr->GetParent());
    //
    // 	ASSERT_EQUAL(firstSpatialTest.GetNumControllers(),2);
    // 	ASSERT_EQUAL(firstSpatialTest.GetController(0), controllerTest);
    // 	ASSERT_EQUAL(firstSpatialTest.GetController(1), secondSpatialTest);
    //
    // 	firstSpatialTest.DetachController(controllerTest);
    //
    // 	ASSERT_EQUAL(firstSpatialTest.GetNumControllers(),1);
    // 	ASSERT_EQUAL(firstSpatialTest.GetController(0), secondSpatialTest);
    //
    // 	firstSpatialTest.DetachAllControllers();
    //
    // 	ASSERT_EQUAL(firstSpatialTest.GetNumControllers(),0);
}

void Rendering::SpatialTesting::CopyTest()
{
    // 	SpatialTest firstSpatialTest;
    //
    // 	ASSERT_EQUAL(firstSpatialTest.GetNumControllers(),0);
    //
    // 	ControllerInterfaceSharedPtr controllerTest(new ControllerTest);
    //
    // 	ControllerInterfaceSharedPtr secondSpatialTest(new SpatialTest);
    // 	SpatialTest* firstPtr = CoreTools::StaticCast<SpatialTest>(secondSpatialTest.GetData());
    //
    // 	ASSERT_EQUAL_NULL_PTR(secondSpatialTest->GetControllerObject());
    //
    // 	secondSpatialTest->AttachController(controllerTest);
    //
    // 	firstSpatialTest.AttachController(secondSpatialTest);
    //
    // 	Transform firstTransform;
    //
    // 	firstTransform.SetUniformScale(5.0f);
    // 	firstPtr->SetLocalTransform(firstTransform);
    //
    //  	ControllerInterfaceSharedPtr thirdSpatialTest(secondSpatialTest->Clone());
    // 	SpatialTest* secondPtr = CoreTools::StaticCast<SpatialTest>(thirdSpatialTest.GetData());
    //
    // 	Transform secondTransform;
    // 	secondTransform.SetUniformScale(3.0f);
    // 	secondPtr->SetLocalTransform(secondTransform);
    //
    // 	ASSERT_APPROXIMATE(secondPtr->GetLocalTransform().GetUniformScale (),3.0f,1e-8f);
    // 	ASSERT_APPROXIMATE(firstPtr->GetLocalTransform().GetUniformScale (),5.0f,1e-8f);
    //
    // 	firstSpatialTest.AttachController(thirdSpatialTest);
    //
    // 	ASSERT_EQUAL(firstSpatialTest.GetNumControllers(),2);
    // 	ASSERT_EQUAL(firstSpatialTest.GetController(0), secondSpatialTest);
    // 	ASSERT_EQUAL(firstSpatialTest.GetController(1), thirdSpatialTest);
    //
    // 	secondSpatialTest->DetachController(controllerTest);
    //
    // 	thirdSpatialTest->AttachController(controllerTest);
    //
    // 	ASSERT_EQUAL(secondSpatialTest->GetNumControllers(),0);
    //
    // 	// thirdSpatialTest已经复制了一个controllerTest
    // 	ASSERT_EQUAL(thirdSpatialTest->GetNumControllers(),2);
}

void Rendering::SpatialTesting::TransformTest()
{
    // 	SpatialTest firstSpatialTest;
    // 	ControllerInterfaceSharedPtr secondSpatialTest(new SpatialTest);
    // 	firstSpatialTest.AttachController(secondSpatialTest);
    //
    // 	SpatialTest* firstPtr = CoreTools::StaticCast<SpatialTest>(secondSpatialTest.GetData());
    //
    // 	Transform firstTransform;
    // 	firstTransform.SetUniformScale(5.0f);
    //
    // 	Transform secondTransform;
    // 	secondTransform.SetTranslate(Transform::APoint(5.0f,3.0f,5.6f));
    //
    // 	firstSpatialTest.SetLocalTransform(firstTransform);
    // 	firstPtr->SetLocalTransform(secondTransform);
    // 	firstPtr->SetParent(&firstSpatialTest);
    //
    // 	firstSpatialTest.Update();
    //
    // 	ASSERT_TRUE(Approximate(firstSpatialTest.GetLocalTransform(),firstTransform,1e-8f));
    // 	ASSERT_TRUE(Approximate(firstPtr->GetLocalTransform(),secondTransform,1e-8f));
    //
    // 	ASSERT_TRUE(Approximate(firstSpatialTest.GetWorldTransform(), firstTransform,1e-8f));
    // 	ASSERT_TRUE(Approximate(firstPtr->GetWorldTransform(), firstTransform * secondTransform,1e-8f));
}

void Rendering::SpatialTesting::StreamTest()
{
    // 	CoreTools::OutTopLevel outTopLevel;
    // 	CoreTools::ObjectInterfaceSharedPtr firstSpatialTest(new SpatialTest);
    //
    // 	firstSpatialTest->SetUniqueID(5);
    //
    // 	outTopLevel.Insert(firstSpatialTest);
    //
    // 	SpatialTest* secondSpatialTest = CoreTools::PolymorphicCast<SpatialTest>(firstSpatialTest.GetData());
    //
    // 	Transform firstTransform;
    // 	Transform secondTransform;
    // 	Bound firstBound(Bound::APoint(0.2f,5.0f,3.0f),2.0f);
    //
    // 	firstTransform.SetUniformScale(5.0f);
    // 	secondTransform.SetUniformScale(3.0f);
    //
    // 	secondSpatialTest->SetLocalTransform(firstTransform);
    // 	secondSpatialTest->SetWorldTransform(secondTransform);
    // 	secondSpatialTest->SetWorldBound(firstBound);
    // 	secondSpatialTest->SetCullingMode(CullingMode::Always);
    //
    // 	ControllerInterfaceSharedPtr firstControllerTest(new ControllerTest);
    // 	secondSpatialTest->AttachController(firstControllerTest);
    //
    // 	firstControllerTest->SetUniqueID(4);
    //
    // 	ControllerInterfaceSharedPtr secondControllerTest(new ControllerTest);
    // 	secondSpatialTest->AttachController(secondControllerTest);
    //
    // 	secondControllerTest->SetUniqueID(3);
    //
    // 	ControllerInterfaceSharedPtr thirdSpatialTest(new SpatialTest);
    // 	secondSpatialTest->AttachController(thirdSpatialTest);
    //
    // 	thirdSpatialTest->SetUniqueID(2);
    //
    // 	ControllerInterfaceSharedPtr fourthControllerTest(new ControllerTest);
    // 	thirdSpatialTest->AttachController(fourthControllerTest);
    //
    // 	fourthControllerTest->SetUniqueID(1);
    //
    // 	CoreTools::BufferOutStream outStream(outTopLevel);
    //
    // 	CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr = outStream.GetBufferOutStreamInformation();
    //
    // 	CoreTools::BufferInStream inStream(fileBufferPtr);
    //
    // 	CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
    //
    // 	SpatialTestSharedPtr  fourthSpatialTest = inTopLevel[0].PolymorphicDowncastObjectSharedPtr<SpatialTestSharedPtr>();
    //
    // 	ASSERT_EQUAL(fourthSpatialTest->GetNumControllers(),3);
    //
    // 	ASSERT_TRUE(Approximate(fourthSpatialTest->GetLocalTransform(), firstTransform,1e-8f));
    // 	ASSERT_TRUE(Approximate(fourthSpatialTest->GetWorldTransform(),secondTransform,1e-8f));
    // 	ASSERT_TRUE(Approximate(fourthSpatialTest->GetWorldBound(),firstBound,1e-8f));
    // 	ASSERT_ENUM_EQUAL(fourthSpatialTest->GetCullingMode(),CullingMode::Always);
    //
    // 	ControllerTest* fifthControlledTest = CoreTools::DynamicCast<ControllerTest>(fourthSpatialTest->GetController(0).GetData());
    //
    // 	ASSERT_UNEQUAL_NULL_PTR(fifthControlledTest);
    //
    // 	ControllerTest* sixthControlledTest = CoreTools::DynamicCast<ControllerTest>(fourthSpatialTest->GetController(1).GetData());
    //
    // 	ASSERT_UNEQUAL_NULL_PTR(sixthControlledTest);
    //
    // 	SpatialTest* seventhControlledTest = CoreTools::DynamicCast<SpatialTest>(fourthSpatialTest->GetController(2).GetData());
    //
    // 	ASSERT_UNEQUAL_NULL_PTR(seventhControlledTest);
    //
    // 	ASSERT_EQUAL(seventhControlledTest->GetNumControllers(),1);
    //
    // 	ControllerTest* eighthControlledTest = CoreTools::DynamicCast<ControllerTest>(seventhControlledTest->GetController(0).GetData());
    //
    // 	ASSERT_UNEQUAL_NULL_PTR(eighthControlledTest);
}