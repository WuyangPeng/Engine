///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:17)

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
    const ConstWeakObjectAssociated<Object> constObjectAssociated0{ boolObject };

    ASSERT_EQUAL(constObjectAssociated0.associated, 0);
    ASSERT_EQUAL(constObjectAssociated0.object.lock(), boolObject);

    const ConstWeakObjectAssociated<Object> constObjectAssociated1{ boolObject, 9 };

    ASSERT_EQUAL(constObjectAssociated1.associated, 9);
    ASSERT_EQUAL(constObjectAssociated1.object.lock(), boolObject);
}
