/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/22 17:28)

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
