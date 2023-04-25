///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/24 11:31)

#include "NullObjectTesting.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::NullObjectTesting::NullObjectTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, NullObjectTesting)

void CoreTools::NullObjectTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::NullObjectTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NullObjectTest);
}

void CoreTools::NullObjectTesting::NullObjectTest()
{
    const auto nullObject = Object::GetNullObject();

    ASSERT_UNEQUAL_NULL_PTR(nullObject);

    ASSERT_TRUE(nullObject->IsNullObject());

    ASSERT_EQUAL(nullObject->GetName(), "NullObject");

    ASSERT_EQUAL(Object::GetNullObject(), Object::GetNullObject());
}
