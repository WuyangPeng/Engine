///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:18)

#include "ObjectRegisterTesting.h"
#include "Detail/BoolObject.h"
#include "Detail/EnumObject.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/WeakObjectAssociated.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::ObjectRegisterTesting::ObjectRegisterTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ObjectRegisterTesting)

void CoreTools::ObjectRegisterTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ObjectRegisterTesting::MainTest()
{
    ASSERT_THROW_EXCEPTION_0(UniqueIdExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RegisterRootSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RegisterObjectSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RegisterWeakObjectSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RegisterObjectContainerSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RegisterObjectArraySucceedTest);
}

void CoreTools::ObjectRegisterTesting::UniqueIdExceptionTest()
{
    const auto objectRegister = ObjectRegister::Create();

    MAYBE_UNUSED const auto uniqueId = objectRegister->GetUniqueId(Object::GetNullObject());
}

void CoreTools::ObjectRegisterTesting::RegisterRootSucceedTest()
{
    const auto objectRegister = ObjectRegister::Create();

    ASSERT_EQUAL(objectRegister->GetOrderedSize(), 0);

    const auto boolObject = std::make_shared<BoolObject>(DisableNotThrow::Disable);
    ASSERT_EQUAL(objectRegister->RegisterRoot(boolObject), 1);

    ASSERT_EQUAL(objectRegister->GetOrderedSize(), 1);

    ASSERT_EQUAL(objectRegister->GetUniqueId(boolObject), 1);
}

void CoreTools::ObjectRegisterTesting::RegisterObjectSucceedTest()
{
    const auto objectRegister = ObjectRegister::Create();

    ASSERT_EQUAL(objectRegister->GetOrderedSize(), 0);

    const auto boolObject = std::make_shared<BoolObject>(DisableNotThrow::Disable);
    const ObjectAssociated<Object> objectAssociated{ boolObject };

    ASSERT_EQUAL(objectRegister->Register(objectAssociated), 1);

    ASSERT_EQUAL(objectRegister->GetOrderedSize(), 1);

    for (const auto& value : *objectRegister)
    {
        ASSERT_EQUAL(value.object, boolObject);
    }
}

void CoreTools::ObjectRegisterTesting::RegisterWeakObjectSucceedTest()
{
    const auto objectRegister = ObjectRegister::Create();

    ASSERT_EQUAL(objectRegister->GetOrderedSize(), 0);

    const auto boolObject = std::make_shared<BoolObject>(DisableNotThrow::Disable);
    const WeakObjectAssociated<Object> objectAssociated{ boolObject };

    ASSERT_EQUAL(objectRegister->RegisterWeakPtr(objectAssociated), 1);

    ASSERT_EQUAL(objectRegister->GetOrderedSize(), 1);

    for (const auto& value : *objectRegister)
    {
        ASSERT_EQUAL(value.object, boolObject);
    }
}

void CoreTools::ObjectRegisterTesting::RegisterObjectContainerSucceedTest()
{
    const auto objectRegister = ObjectRegister::Create();

    ASSERT_EQUAL(objectRegister->GetOrderedSize(), 0);

    const auto boolObject = std::make_shared<BoolObject>(DisableNotThrow::Disable);
    const ObjectAssociated<Object> objectAssociated0{ boolObject };

    const auto enumObject = std::make_shared<EnumObject>(DisableNotThrow::Disable);
    const ObjectAssociated<Object> objectAssociated1{ enumObject };

    const std::vector container{ objectAssociated0, objectAssociated1 };

    objectRegister->RegisterContainer(container);

    ASSERT_EQUAL(objectRegister->GetOrderedSize(), 2);

    auto index = 0;
    for (const auto& value : *objectRegister)
    {
        switch (index)
        {
            case 0:
                ASSERT_EQUAL(value.object, boolObject);
                break;
            case 1:
                ASSERT_EQUAL(value.object, enumObject);
                break;

            default:
                break;
        }

        ++index;
    }
}

void CoreTools::ObjectRegisterTesting::RegisterObjectArraySucceedTest()
{
    const auto objectRegister = ObjectRegister::Create();

    ASSERT_EQUAL(objectRegister->GetOrderedSize(), 0);

    const auto boolObject = std::make_shared<BoolObject>(DisableNotThrow::Disable);
    const ObjectAssociated<Object> objectAssociated0{ boolObject };

    const auto enumObject = std::make_shared<EnumObject>(DisableNotThrow::Disable);
    const ObjectAssociated<Object> objectAssociated1{ enumObject };

    const std::array container{ objectAssociated0, objectAssociated1 };

    objectRegister->RegisterContainer(container);

    ASSERT_EQUAL(objectRegister->GetOrderedSize(), 2);

    auto index = 0;
    for (const auto& value : *objectRegister)
    {
        switch (index)
        {
            case 0:
                ASSERT_EQUAL(value.object, boolObject);
                break;
            case 1:
                ASSERT_EQUAL(value.object, enumObject);
                break;

            default:
                break;
        }

        ++index;
    }
}
