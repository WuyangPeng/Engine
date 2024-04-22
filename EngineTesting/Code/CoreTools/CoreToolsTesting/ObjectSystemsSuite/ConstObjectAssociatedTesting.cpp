/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/22 17:05)

#include "ConstObjectAssociatedTesting.h"
#include "Detail/BoolObject.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/ObjectSystems/ConstObjectAssociated.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::ConstObjectAssociatedTesting::ConstObjectAssociatedTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ConstObjectAssociatedTesting)

void CoreTools::ConstObjectAssociatedTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ConstObjectAssociatedTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstObjectAssociatedTest);
}

void CoreTools::ConstObjectAssociatedTesting::ConstObjectAssociatedTest()
{
    const ConstObjectAssociated<Object> constObjectAssociated0{};

    ASSERT_EQUAL(constObjectAssociated0.associated, 0);
    ASSERT_EQUAL_NULL_PTR(constObjectAssociated0.object);

    const auto boolObject = std::make_shared<BoolObject>(DisableNotThrow::Disable);
    const ConstObjectAssociated<Object> constObjectAssociated1{ boolObject };

    ASSERT_EQUAL(constObjectAssociated1.associated, 0);
    ASSERT_EQUAL(constObjectAssociated1.object, boolObject);

    const ConstObjectAssociated<Object> constObjectAssociated2{ boolObject, 9 };

    ASSERT_EQUAL(constObjectAssociated2.associated, 9);
    ASSERT_EQUAL(constObjectAssociated2.object, boolObject);

    boolObject->SetUniqueId(5);

    const auto constObjectAssociated3 = constObjectAssociated2.Clone();

    ASSERT_EQUAL(constObjectAssociated3->GetUniqueId(), 5);
}
