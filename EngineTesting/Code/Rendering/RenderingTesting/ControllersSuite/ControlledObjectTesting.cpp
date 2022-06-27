///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/16 20:35)

#include "ControlledObjectTest.h"
#include "ControlledObjectTesting.h"
#include "ControllerTest.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "Rendering/Controllers/ControlledObject.h"

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
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

    auto firstcontrolledObjectTest = std::make_shared<ControlledObjectTest>(CoreTools::DisableNotThrow::Disable);

#include STSTEM_WARNING_POP

    ASSERT_EQUAL(firstcontrolledObjectTest->GetNumControllers(), 0);

    ControllerInterfaceSharedPtr controllerTest(std::make_shared<ControllerTest>(CoreTools::DisableNotThrow::Disable));
    firstcontrolledObjectTest->AttachController(controllerTest);

    ASSERT_EQUAL(firstcontrolledObjectTest->GetNumControllers(), 1);
    ASSERT_EQUAL(firstcontrolledObjectTest->GetController(0), controllerTest);

    ControllerInterfaceSharedPtr secondcontrolledObjectTest(std::make_shared<ControlledObjectTest>(CoreTools::DisableNotThrow::Disable));

    ASSERT_EQUAL_NULL_PTR(secondcontrolledObjectTest->GetControllerObject());

    firstcontrolledObjectTest->AttachController(secondcontrolledObjectTest);

    ASSERT_EQUAL(secondcontrolledObjectTest->GetControllerObject(), firstcontrolledObjectTest.get());

    ASSERT_EQUAL(firstcontrolledObjectTest->GetNumControllers(), 2);
    ASSERT_EQUAL(firstcontrolledObjectTest->GetController(0), controllerTest);
    ASSERT_EQUAL(firstcontrolledObjectTest->GetController(1), secondcontrolledObjectTest);

    firstcontrolledObjectTest->DetachController(controllerTest);

    ASSERT_EQUAL(firstcontrolledObjectTest->GetNumControllers(), 1);
    ASSERT_EQUAL(firstcontrolledObjectTest->GetController(0), secondcontrolledObjectTest);

    firstcontrolledObjectTest->DetachAllControllers();

    ASSERT_EQUAL(firstcontrolledObjectTest->GetNumControllers(), 0);
}

void Rendering::ControlledObjectTesting::CopyTest() noexcept
{
}

void Rendering::ControlledObjectTesting::StreamTest() noexcept
{
}
