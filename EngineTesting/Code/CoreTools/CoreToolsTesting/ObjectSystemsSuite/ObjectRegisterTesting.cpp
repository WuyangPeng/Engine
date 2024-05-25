/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/24 14:23)

#include "ObjectRegisterTesting.h"
#include "Detail/BoolObject.h"
#include "Detail/EnumObject.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/WeakObjectAssociated.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::ObjectRegisterTesting::ObjectRegisterTesting(const OStreamShared& stream)
    : ParentType{ stream },
      boolObject{ std::make_shared<BoolObject>(DisableNotThrow::Disable) },
      enumObject{ std::make_shared<EnumObject>(DisableNotThrow::Disable) }
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

    std::ignore = objectRegister->GetUniqueId(Object::GetNullObject());
}

void CoreTools::ObjectRegisterTesting::RegisterRootSucceedTest()
{
    const auto objectRegister = ObjectRegister::Create();

    ASSERT_EQUAL(objectRegister->GetOrderedSize(), 0);

    ASSERT_EQUAL(objectRegister->RegisterRoot(boolObject), 1);

    ASSERT_NOT_THROW_EXCEPTION_1(RegisterRootSucceedResultTest, *objectRegister);
}

void CoreTools::ObjectRegisterTesting::RegisterRootSucceedResultTest(const ObjectRegister& objectRegister)
{
    ASSERT_EQUAL(objectRegister.GetOrderedSize(), 1);

    ASSERT_EQUAL(objectRegister.GetUniqueId(boolObject), 1);
}

void CoreTools::ObjectRegisterTesting::RegisterObjectSucceedTest()
{
    const auto objectRegister = ObjectRegister::Create();

    ASSERT_EQUAL(objectRegister->GetOrderedSize(), 0);

    const ObjectAssociated objectAssociated{ boolObject };

    ASSERT_EQUAL(objectRegister->Register(objectAssociated), 1);

    ASSERT_NOT_THROW_EXCEPTION_1(RegisterObjectSucceedResultTest, *objectRegister);
}

void CoreTools::ObjectRegisterTesting::RegisterObjectSucceedResultTest(const ObjectRegister& objectRegister)
{
    ASSERT_EQUAL(objectRegister.GetOrderedSize(), 1);

    for (const auto& element : objectRegister)
    {
        ASSERT_EQUAL(element.object, boolObject);
    }
}

void CoreTools::ObjectRegisterTesting::RegisterWeakObjectSucceedTest()
{
    const auto objectRegister = ObjectRegister::Create();

    ASSERT_EQUAL(objectRegister->GetOrderedSize(), 0);

    const WeakObjectAssociated objectAssociated{ boolObject };

    ASSERT_EQUAL(objectRegister->RegisterWeakPtr(objectAssociated), 1);

    ASSERT_NOT_THROW_EXCEPTION_1(RegisterWeakObjectSucceedResultTest, *objectRegister);
}

void CoreTools::ObjectRegisterTesting::RegisterWeakObjectSucceedResultTest(const ObjectRegister& objectRegister)
{
    ASSERT_EQUAL(objectRegister.GetOrderedSize(), 1);

    for (const auto& element : objectRegister)
    {
        ASSERT_EQUAL(element.object, boolObject);
    }
}

void CoreTools::ObjectRegisterTesting::RegisterObjectContainerSucceedTest()
{
    const auto objectRegister = ObjectRegister::Create();

    ASSERT_EQUAL(objectRegister->GetOrderedSize(), 0);

    const ObjectAssociated objectAssociated0{ boolObject };
    const ObjectAssociated objectAssociated1{ enumObject };

    const std::vector container{ objectAssociated0, objectAssociated1 };

    objectRegister->RegisterContainer(container);

    ASSERT_NOT_THROW_EXCEPTION_1(RegisterObjectContainerSucceedResultTest, *objectRegister);
}

void CoreTools::ObjectRegisterTesting::RegisterObjectContainerSucceedResultTest(const ObjectRegister& objectRegister)
{
    ASSERT_EQUAL(objectRegister.GetOrderedSize(), 2);

    auto index = 0;
    for (const auto& element : objectRegister)
    {
        switch (index)
        {
            case 0:
                ASSERT_EQUAL(element.object, boolObject);
                break;
            case 1:
                ASSERT_EQUAL(element.object, enumObject);
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

    const ObjectAssociated objectAssociated0{ boolObject };
    const ObjectAssociated objectAssociated1{ enumObject };

    const std::array container{ objectAssociated0, objectAssociated1 };

    objectRegister->RegisterContainer(container);

    ASSERT_NOT_THROW_EXCEPTION_1(RegisterObjectArraySucceedResultTest, *objectRegister);
}

void CoreTools::ObjectRegisterTesting::RegisterObjectArraySucceedResultTest(const ObjectRegister& objectRegister)
{
    ASSERT_EQUAL(objectRegister.GetOrderedSize(), 2);

    auto index = 0;
    for (const auto& element : objectRegister)
    {
        switch (index)
        {
            case 0:
                ASSERT_EQUAL(element.object, boolObject);
                break;
            case 1:
                ASSERT_EQUAL(element.object, enumObject);
                break;

            default:
                break;
        }

        ++index;
    }
}
