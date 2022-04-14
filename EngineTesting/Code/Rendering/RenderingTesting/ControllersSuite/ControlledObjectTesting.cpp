// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.0.3 (2019/09/05 16:31)

#include "ControlledObjectTest.h"
#include "ControlledObjectTesting.h"
#include "ControllerTest.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/Controllers/ControlledObject.h"

#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, ControlledObjectTesting)

void Rendering::ControlledObjectTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::ControlledObjectTesting::InitTest()
{
    ControlledObjectTest firstcontrolledObjectTest;

    ASSERT_EQUAL(firstcontrolledObjectTest.GetNumControllers(), 0);

    ControllerInterfaceSharedPtr controllerTest(std::make_shared<ControllerTest>());
    firstcontrolledObjectTest.AttachController(controllerTest);

    ASSERT_EQUAL(firstcontrolledObjectTest.GetNumControllers(), 1);
    ASSERT_EQUAL(firstcontrolledObjectTest.GetController(0), controllerTest);

    ControllerInterfaceSharedPtr secondcontrolledObjectTest(std::make_shared<ControlledObjectTest>());

    ASSERT_EQUAL_NULL_PTR(secondcontrolledObjectTest->GetControllerObject());

    firstcontrolledObjectTest.AttachController(secondcontrolledObjectTest);

    ASSERT_EQUAL(secondcontrolledObjectTest->GetControllerObject(), &firstcontrolledObjectTest);

    ASSERT_EQUAL(firstcontrolledObjectTest.GetNumControllers(), 2);
    ASSERT_EQUAL(firstcontrolledObjectTest.GetController(0), controllerTest);
    ASSERT_EQUAL(firstcontrolledObjectTest.GetController(1), secondcontrolledObjectTest);

    firstcontrolledObjectTest.DetachController(controllerTest);

    ASSERT_EQUAL(firstcontrolledObjectTest.GetNumControllers(), 1);
    ASSERT_EQUAL(firstcontrolledObjectTest.GetController(0), secondcontrolledObjectTest);

    firstcontrolledObjectTest.DetachAllControllers();

    ASSERT_EQUAL(firstcontrolledObjectTest.GetNumControllers(), 0);
}

void Rendering::ControlledObjectTesting::CopyTest()
{
    ControlledObjectTest firstcontrolledObjectTest;

    ASSERT_EQUAL(firstcontrolledObjectTest.GetNumControllers(), 0);

    ControllerInterfaceSharedPtr controllerTest(std::make_shared<ControllerTest>());

    ControllerInterfaceSharedPtr secondcontrolledObjectTest(std::make_shared<ControlledObjectTest>());

    ASSERT_EQUAL_NULL_PTR(secondcontrolledObjectTest->GetControllerObject());

    secondcontrolledObjectTest->AttachController(controllerTest);

    firstcontrolledObjectTest.AttachController(secondcontrolledObjectTest);

    ControllerInterfaceSharedPtr thirdcontrolledObjectTest(secondcontrolledObjectTest->Clone());

    firstcontrolledObjectTest.AttachController(thirdcontrolledObjectTest);

    ASSERT_EQUAL(firstcontrolledObjectTest.GetNumControllers(), 2);
    ASSERT_EQUAL(firstcontrolledObjectTest.GetController(0), secondcontrolledObjectTest);
    ASSERT_EQUAL(firstcontrolledObjectTest.GetController(1), thirdcontrolledObjectTest);

    secondcontrolledObjectTest->DetachController(controllerTest);

    thirdcontrolledObjectTest->AttachController(controllerTest);

    ASSERT_EQUAL(secondcontrolledObjectTest->GetNumControllers(), 0);

    // thirdcontrolledObjectTest已经复制了一个controllerTest
    ASSERT_EQUAL(thirdcontrolledObjectTest->GetNumControllers(), 2);
}
#include SYSTEM_WARNING_DISABLE(26440)
void Rendering::ControlledObjectTesting::StreamTest()
{
    // 	CoreTools::OutTopLevel outTopLevel;
    // 	CoreTools::ObjectInterfaceSharedPtr firstControlledObjectTest(new ControlledObjectTest);
    //
    // 	firstControlledObjectTest->SetUniqueID(5);
    //
    // 	ControlledObjectTest* secondControlledObjectTest = CoreTools::PolymorphicCast<ControlledObjectTest>(firstControlledObjectTest.GetData());
    //
    // 	outTopLevel.Insert(firstControlledObjectTest);
    //
    // 	ControllerInterfaceSharedPtr firstControllerTest(new ControllerTest);
    // 	secondControlledObjectTest->AttachController(firstControllerTest);
    //
    // 	firstControllerTest->SetUniqueID(4);
    //
    // 	ControllerInterfaceSharedPtr secondControllerTest(new ControllerTest);
    // 	secondControlledObjectTest->AttachController(secondControllerTest);
    //
    // 	secondControllerTest->SetUniqueID(3);
    //
    // 	ControllerInterfaceSharedPtr thirdControllerTest(new ControlledObjectTest);
    // 	secondControlledObjectTest->AttachController(thirdControllerTest);
    //
    // 	thirdControllerTest->SetUniqueID(2);
    //
    // 	ControllerInterfaceSharedPtr fourthControllerTest(new ControllerTest);
    // 	thirdControllerTest->AttachController(fourthControllerTest);
    //
    // 	fourthControllerTest->SetUniqueID(1);
    //
    // 	CoreTools::BufferOutStream outStream(outTopLevel);
    //
    // 	CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr =  outStream.GetBufferOutStreamInformation();
    //
    // 	CoreTools::BufferInStream inStream(fileBufferPtr);
    //
    // 	CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
    //
    // 	ControlledObjectTestSharedPtr thirdControlledObjectTest = inTopLevel[0].PolymorphicDowncastObjectSharedPtr<ControlledObjectTestSharedPtr>();
    //
    // 	ASSERT_EQUAL(thirdControlledObjectTest->GetNumControllers(),3);
    //
    // 	const ControllerTest* fifthControlledTest = CoreTools::DynamicCast<ControllerTest>(thirdControlledObjectTest->GetController(0).GetData());
    //
    // 	ASSERT_UNEQUAL_NULL_PTR(fifthControlledTest);
    //
    // 	const ControllerTest* sixthControlledTest = CoreTools::DynamicCast<ControllerTest>(thirdControlledObjectTest->GetController(1).GetData());
    //
    // 	ASSERT_UNEQUAL_NULL_PTR(sixthControlledTest);
    //
    // 	const ControlledObjectTest* seventhControlledTest = CoreTools::DynamicCast<ControlledObjectTest>(thirdControlledObjectTest->GetController(2).GetData());
    //
    // 	ASSERT_UNEQUAL_NULL_PTR(seventhControlledTest);
    //
    // 	ASSERT_EQUAL(seventhControlledTest->GetNumControllers(),1);
    //
    // 	const ControllerTest* eighthControlledTest = CoreTools::DynamicCast<ControllerTest>(seventhControlledTest->GetConstController(0).GetData());
    //
    // 	ASSERT_UNEQUAL_NULL_PTR(eighthControlledTest);
}
