/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/22 17:58)

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
    ASSERT_NOT_THROW_EXCEPTION_0(ConstObjectAssociated0Test);

    const auto boolObject = std::make_shared<BoolObject>(DisableNotThrow::Disable);
    ASSERT_NOT_THROW_EXCEPTION_1(ConstObjectAssociated1Test, boolObject);

    const TestingType constObjectAssociated{ boolObject, associated };
    ASSERT_NOT_THROW_EXCEPTION_2(ConstObjectAssociated2Test, boolObject, constObjectAssociated);

    ASSERT_NOT_THROW_EXCEPTION_1(ConstObjectAssociated3Test, constObjectAssociated);
}

void CoreTools::ConstObjectAssociatedTesting::ConstObjectAssociated0Test()
{
    const TestingType constObjectAssociated{};

    ASSERT_EQUAL(constObjectAssociated.associated, 0);
    ASSERT_EQUAL_NULL_PTR(constObjectAssociated.object);
}

void CoreTools::ConstObjectAssociatedTesting::ConstObjectAssociated1Test(const BoolObjectSharedPtr& boolObject)
{
    const TestingType constObjectAssociated{ boolObject };

    ASSERT_EQUAL(constObjectAssociated.associated, 0);
    ASSERT_EQUAL(constObjectAssociated.object, boolObject);
}

void CoreTools::ConstObjectAssociatedTesting::ConstObjectAssociated2Test(const BoolObjectSharedPtr& boolObject, const TestingType& constObjectAssociated)
{
    ASSERT_EQUAL(constObjectAssociated.associated, associated);
    ASSERT_EQUAL(constObjectAssociated.object, boolObject);

    boolObject->SetUniqueId(uniqueId);
}

void CoreTools::ConstObjectAssociatedTesting::ConstObjectAssociated3Test(const TestingType& constObjectAssociated)
{
    const auto clone = constObjectAssociated.Clone();

    ASSERT_EQUAL(clone->GetUniqueId(), uniqueId);
}
