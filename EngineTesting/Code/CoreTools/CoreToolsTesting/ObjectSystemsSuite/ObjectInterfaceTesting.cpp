///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:18)

#include "ObjectInterfaceTesting.h"
#include "Detail/TestObject.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::ObjectInterfaceTesting::ObjectInterfaceTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ObjectInterfaceTesting)

void CoreTools::ObjectInterfaceTesting::DoRunUnitTest()
{
    ObjectManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ObjectManager::Destroy();
}

void CoreTools::ObjectInterfaceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ObjectInterfaceTest);
}

void CoreTools::ObjectInterfaceTesting::ObjectInterfaceTest()
{
    const auto testObject = TestObject::Create();

    ASSERT_FALSE(testObject->IsNullObject());

    ASSERT_EQUAL(testObject->GetName(), "TestObject");

    ASSERT_EQUAL(testObject->GetRttiType().GetName(), TestObject::GetCurrentRttiType().GetName());

    ASSERT_EQUAL(testObject->GetObjectByName("TestObject"), testObject);
    ASSERT_EQUAL(testObject->GetConstObjectByName("TestObject"), testObject);

    ASSERT_EQUAL(testObject->GetAllObjectsByName("TestObject").at(0), testObject);
    ASSERT_EQUAL(testObject->GetAllConstObjectsByName("TestObject").at(0), testObject);

    testObject->SetUniqueId(11);
    ASSERT_EQUAL(testObject->GetUniqueId(), 11);

    const auto cloneObject = testObject->CloneObject();

    ASSERT_EQUAL(cloneObject->GetUniqueId(), 11);
}