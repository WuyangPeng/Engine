///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/24 13:48)

#include "ObjectTesting.h"
#include "Detail/BoolObject.h"
#include "Detail/EnumObject.h"
#include "Detail/IntObject.h"
#include "Detail/TestObject.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/NullObject.h"
#include "CoreTools/ObjectSystems/ObjectLink.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegister.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::ObjectTesting::ObjectTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ObjectTesting)

void CoreTools::ObjectTesting::DoRunUnitTest()
{
    ObjectManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ObjectManager::Destroy();
}

void CoreTools::ObjectTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ObjectTest);
}

void CoreTools::ObjectTesting::ObjectTest()
{
    const auto testObject = TestObject::Create();

    ASSERT_FALSE(testObject->IsNullObject());

    ASSERT_EQUAL(testObject->GetName(), "TestObject");

    ASSERT_EQUAL(testObject->GetRttiType().GetName(), TestObject::GetCurrentRttiType().GetName());

    ASSERT_EQUAL(testObject->GetObjectByName("TestObject"), testObject);
    ASSERT_EQUAL(testObject->GetConstObjectByName("TestObject"), testObject);

    ASSERT_EQUAL(testObject->GetAllObjectsByName("TestObject").at(0), testObject);
    ASSERT_EQUAL(testObject->GetAllConstObjectsByName("TestObject").at(0), testObject);

    testObject->SetName("New");
    ASSERT_EQUAL(testObject->GetName(), "New");
}