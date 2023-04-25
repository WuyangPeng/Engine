///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/20 15:18)

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
    const ObjectAssociated<Object> objectAssociated0{};

    ASSERT_EQUAL(objectAssociated0.associated, 0);
    ASSERT_EQUAL_NULL_PTR(objectAssociated0.object);

    const auto boolObject = std::make_shared<BoolObject>(DisableNotThrow::Disable);
    const ObjectAssociated<Object> objectAssociated1{ boolObject };

    ASSERT_EQUAL(objectAssociated1.associated, 0);
    ASSERT_EQUAL(objectAssociated1.object, boolObject);

    ASSERT_EQUAL(objectAssociated1->GetRttiType().GetName(), BoolObject::GetCurrentRttiType().GetName());

    const ObjectAssociated<Object> objectAssociated2{ boolObject, 9 };

    ASSERT_EQUAL(objectAssociated2.associated, 9);
    ASSERT_EQUAL(objectAssociated2.object, boolObject);

    ASSERT_EQUAL((*objectAssociated2).GetRttiType().GetName(), BoolObject::GetCurrentRttiType().GetName());
}
