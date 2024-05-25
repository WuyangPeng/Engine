/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/23 17:24)

#include "ObjectInterfaceTesting.h"
#include "Detail/TestObject.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

namespace
{
    const auto gTestObject = "TestObject";
}

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

    ASSERT_NOT_THROW_EXCEPTION_1(BaseTest, *testObject);
    ASSERT_NOT_THROW_EXCEPTION_1(GetObjectByNameTest, testObject);
    ASSERT_NOT_THROW_EXCEPTION_1(UniqueIdTest, *testObject);
}

void CoreTools::ObjectInterfaceTesting::BaseTest(const TestObject& testObject)
{
    ASSERT_FALSE(testObject.IsNullObject());

    ASSERT_EQUAL(testObject.GetName(), gTestObject);

    ASSERT_EQUAL(testObject.GetRttiType().GetName(), TestObject::GetCurrentRttiType().GetName());
}

void CoreTools::ObjectInterfaceTesting::GetObjectByNameTest(const TestObjectSharedPtr& testObject)
{
    ASSERT_EQUAL(testObject->GetObjectByName(gTestObject), testObject);
    ASSERT_EQUAL(testObject->GetConstObjectByName(gTestObject), testObject);

    ASSERT_EQUAL(testObject->GetAllObjectsByName(gTestObject).at(0), testObject);
    ASSERT_EQUAL(testObject->GetAllConstObjectsByName(gTestObject).at(0), testObject);
}

void CoreTools::ObjectInterfaceTesting::UniqueIdTest(TestObject& testObject)
{
    testObject.SetUniqueId(uniqueId);
    ASSERT_EQUAL(testObject.GetUniqueId(), uniqueId);

    const auto cloneObject = testObject.CloneObject();

    ASSERT_EQUAL(cloneObject->GetUniqueId(), uniqueId);
}