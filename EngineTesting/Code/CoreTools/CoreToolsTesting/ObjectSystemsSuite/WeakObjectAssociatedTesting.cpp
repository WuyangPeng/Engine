///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:19)

#include "WeakObjectAssociatedTesting.h"
#include "Detail/BoolObject.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/ObjectSystems/WeakObjectAssociated.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::WeakObjectAssociatedTesting::WeakObjectAssociatedTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, WeakObjectAssociatedTesting)

void CoreTools::WeakObjectAssociatedTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::WeakObjectAssociatedTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WeakObjectAssociatedTest);
}

void CoreTools::WeakObjectAssociatedTesting::WeakObjectAssociatedTest()
{
    const WeakObjectAssociated<Object> objectAssociated0{};

    ASSERT_EQUAL(objectAssociated0.associated, 0);
    ASSERT_EQUAL_NULL_PTR(objectAssociated0.object.lock());

    const auto boolObject = std::make_shared<BoolObject>(DisableNotThrow::Disable);
    const WeakObjectAssociated<Object> objectAssociated1{ boolObject };

    ASSERT_EQUAL(objectAssociated1.associated, 0);
    ASSERT_EQUAL(objectAssociated1.object.lock(), boolObject);

    const WeakObjectAssociated<Object> objectAssociated2{ boolObject, 9 };

    ASSERT_EQUAL(objectAssociated2.associated, 9);
    ASSERT_EQUAL(objectAssociated2.object.lock(), boolObject);
}