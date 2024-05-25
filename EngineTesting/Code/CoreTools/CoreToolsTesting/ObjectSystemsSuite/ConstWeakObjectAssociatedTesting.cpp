/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/22 18:08)

#include "ConstWeakObjectAssociatedTesting.h"
#include "Detail/BoolObject.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/ObjectSystems/ConstWeakObjectAssociated.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::ConstWeakObjectAssociatedTesting::ConstWeakObjectAssociatedTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ConstWeakObjectAssociatedTesting)

void CoreTools::ConstWeakObjectAssociatedTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ConstWeakObjectAssociatedTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstWeakObjectAssociatedTest);
}

void CoreTools::ConstWeakObjectAssociatedTesting::ConstWeakObjectAssociatedTest()
{
    const auto boolObject = std::make_shared<BoolObject>(DisableNotThrow::Disable);

    ASSERT_NOT_THROW_EXCEPTION_1(ConstWeakObjectAssociated0Test, boolObject);
    ASSERT_NOT_THROW_EXCEPTION_1(ConstWeakObjectAssociated1Test, boolObject);
}

void CoreTools::ConstWeakObjectAssociatedTesting::ConstWeakObjectAssociated0Test(const BoolObjectSharedPtr& boolObject)
{
    const TestingType constObjectAssociated{ boolObject };

    ASSERT_EQUAL(constObjectAssociated.associated, 0);
    ASSERT_EQUAL(constObjectAssociated.object.lock(), boolObject);
}

void CoreTools::ConstWeakObjectAssociatedTesting::ConstWeakObjectAssociated1Test(const BoolObjectSharedPtr& boolObject)
{
    const TestingType constObjectAssociated{ boolObject, 9 };

    ASSERT_EQUAL(constObjectAssociated.associated, 9);
    ASSERT_EQUAL(constObjectAssociated.object.lock(), boolObject);
}
