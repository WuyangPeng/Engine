/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/22 21:04)

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
    ASSERT_NOT_THROW_EXCEPTION_0(WeakObjectAssociated0Test);

    const auto boolObject = std::make_shared<BoolObject>(DisableNotThrow::Disable);

    ASSERT_NOT_THROW_EXCEPTION_1(WeakObjectAssociated1Test, boolObject);
    ASSERT_NOT_THROW_EXCEPTION_1(WeakObjectAssociated2Test, boolObject);
}

void CoreTools::WeakObjectAssociatedTesting::WeakObjectAssociated0Test()
{
    const WeakObjectAssociated objectAssociated{};

    ASSERT_EQUAL(objectAssociated.associated, 0);
    ASSERT_EQUAL_NULL_PTR(objectAssociated.object.lock());
}

void CoreTools::WeakObjectAssociatedTesting::WeakObjectAssociated1Test(const BoolObjectSharedPtr& boolObject)
{
    const WeakObjectAssociated objectAssociated{ boolObject };

    ASSERT_EQUAL(objectAssociated.associated, 0);
    ASSERT_EQUAL(objectAssociated.object.lock(), boolObject);
}

void CoreTools::WeakObjectAssociatedTesting::WeakObjectAssociated2Test(const BoolObjectSharedPtr& boolObject)
{
    const WeakObjectAssociated objectAssociated{ boolObject, 9 };

    ASSERT_EQUAL(objectAssociated.associated, 9);
    ASSERT_EQUAL(objectAssociated.object.lock(), boolObject);
}