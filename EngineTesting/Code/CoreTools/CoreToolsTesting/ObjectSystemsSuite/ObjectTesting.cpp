/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/24 17:10)

#include "ObjectTesting.h"
#include "Detail/BoolObject.h"
#include "Detail/TestObject.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLink.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegister.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

namespace
{
    const auto gTestObject = "TestObject";
}

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

    ASSERT_NOT_THROW_EXCEPTION_1(GetNameTest, *testObject);
    ASSERT_NOT_THROW_EXCEPTION_1(GetObjectByNameTest, testObject);
    ASSERT_NOT_THROW_EXCEPTION_1(SetNameTest, *testObject);
}

void CoreTools::ObjectTesting::GetNameTest(const TestObject& testObject)
{
    ASSERT_EQUAL(testObject.GetName(), gTestObject);

    ASSERT_EQUAL(testObject.GetRttiType().GetName(), TestObject::GetCurrentRttiType().GetName());
}

void CoreTools::ObjectTesting::GetObjectByNameTest(const TestObjectSharedPtr& testObject)
{
    ASSERT_EQUAL(testObject->GetObjectByName(gTestObject), testObject);
    ASSERT_EQUAL(testObject->GetConstObjectByName(gTestObject), testObject);

    ASSERT_EQUAL(testObject->GetAllObjectsByName(gTestObject).at(0), testObject);
    ASSERT_EQUAL(testObject->GetAllConstObjectsByName(gTestObject).at(0), testObject);
}

void CoreTools::ObjectTesting::SetNameTest(TestObject& testObject)
{
    testObject.SetName("New");
    ASSERT_EQUAL(testObject.GetName(), "New");
}