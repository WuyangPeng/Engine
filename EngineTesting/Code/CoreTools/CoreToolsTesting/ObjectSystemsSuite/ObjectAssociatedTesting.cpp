/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/22 17:29)

#include "ObjectAssociatedTesting.h"
#include "Detail/BoolObject.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::ObjectAssociatedTesting::ObjectAssociatedTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ObjectAssociatedTesting)

void CoreTools::ObjectAssociatedTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ObjectAssociatedTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ObjectAssociatedTest);
}

void CoreTools::ObjectAssociatedTesting::ObjectAssociatedTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ObjectAssociated0Test);

    const auto boolObject = std::make_shared<BoolObject>(DisableNotThrow::Disable);
    ASSERT_NOT_THROW_EXCEPTION_1(ObjectAssociated1Test, boolObject);

    const ObjectAssociated objectAssociated{ boolObject, associated };

    ASSERT_NOT_THROW_EXCEPTION_2(ObjectAssociated2Test, boolObject, objectAssociated);

    ASSERT_NOT_THROW_EXCEPTION_1(ObjectAssociated3Test, objectAssociated);

    ASSERT_NOT_THROW_EXCEPTION_0(ObjectAssociated4Test);
}

void CoreTools::ObjectAssociatedTesting::ObjectAssociated0Test()
{
    const ObjectAssociated objectAssociated{};

    ASSERT_EQUAL(objectAssociated.associated, 0);
    ASSERT_EQUAL_NULL_PTR(objectAssociated.object);
}

void CoreTools::ObjectAssociatedTesting::ObjectAssociated1Test(const BoolObjectSharedPtr& boolObject)
{
    const ObjectAssociated objectAssociated{ boolObject };

    ASSERT_EQUAL(objectAssociated.associated, 0);
    ASSERT_EQUAL(objectAssociated.object, boolObject);

    ASSERT_EQUAL(objectAssociated->GetRttiType().GetName(), BoolObject::GetCurrentRttiType().GetName());
}

void CoreTools::ObjectAssociatedTesting::ObjectAssociated2Test(const BoolObjectSharedPtr& boolObject, const ObjectAssociated& objectAssociated)
{
    ASSERT_EQUAL(objectAssociated.associated, associated);
    ASSERT_EQUAL(objectAssociated.object, boolObject);

    ASSERT_EQUAL((*objectAssociated).GetRttiType().GetName(), BoolObject::GetCurrentRttiType().GetName());

    boolObject->SetUniqueId(uniqueId);
}

void CoreTools::ObjectAssociatedTesting::ObjectAssociated3Test(const ObjectAssociated& objectAssociated)
{
    const auto clone = objectAssociated.Clone();

    ASSERT_EQUAL(clone->GetUniqueId(), uniqueId);
}

void CoreTools::ObjectAssociatedTesting::ObjectAssociated4Test()
{
    const ObjectAssociated objectAssociated{ associated };

    ASSERT_EQUAL(objectAssociated.associated, associated);
    ASSERT_EQUAL_NULL_PTR(objectAssociated.object);
}