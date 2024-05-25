/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/23 19:47)

#include "ObjectLinkTesting.h"
#include "Detail/BoolObject.h"
#include "Detail/EnumObject.h"
#include "Detail/IntObject.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/NullObject.h"
#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::ObjectLinkTesting::ObjectLinkTesting(const OStreamShared& stream)
    : ParentType{ stream },
      boolObject{ std::make_shared<BoolObject>(DisableNotThrow::Disable) },
      enumObject{ std::make_shared<EnumObject>(DisableNotThrow::Disable) },
      intObject{ std::make_shared<IntObject>(DisableNotThrow::Disable) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ObjectLinkTesting)

void CoreTools::ObjectLinkTesting::DoRunUnitTest()
{
    ObjectManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ObjectManager::Destroy();
}

void CoreTools::ObjectLinkTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InsertObjectTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SortTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ResolveLinkTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ResolveLinkContainerTest);
}

void CoreTools::ObjectLinkTesting::InsertObjectTest()
{
    const auto objectLink = CreateObjectLink();

    ASSERT_EQUAL(objectLink->GetOrderedSize(), 3);

    ASSERT_EQUAL(objectLink->GetObjectInterface(1), boolObject);
    ASSERT_EQUAL(objectLink->GetObjectInterface(2), enumObject);
    ASSERT_EQUAL(objectLink->GetObjectInterface(3), intObject);
}

CoreTools::ObjectLinkTesting::ObjectLinkSharedPtr CoreTools::ObjectLinkTesting::CreateObjectLink()
{
    const auto objectLink = ObjectLink::Create();

    ASSERT_EQUAL(objectLink->GetOrderedSize(), 0);

    objectLink->Insert(1, boolObject);
    objectLink->Insert(3, intObject);
    objectLink->Insert(2, enumObject);

    return objectLink;
}

void CoreTools::ObjectLinkTesting::SortTest()
{
    const auto objectLink = CreateObjectLink();

    ASSERT_NOT_THROW_EXCEPTION_1(BeforeSortTest, *objectLink);

    objectLink->Sort();

    ASSERT_NOT_THROW_EXCEPTION_1(SortResultTest, *objectLink);
}

void CoreTools::ObjectLinkTesting::BeforeSortTest(const ObjectLink& objectLink)
{
    auto index = 0;
    for (const auto& element : objectLink)
    {
        switch (index)
        {
            case 0:
                ASSERT_EQUAL(element->GetRttiType().GetName(), BoolObject::GetCurrentRttiType().GetName());
                break;
            case 1:
                ASSERT_EQUAL(element->GetRttiType().GetName(), IntObject::GetCurrentRttiType().GetName());
                break;
            case 2:
                ASSERT_EQUAL(element->GetRttiType().GetName(), EnumObject::GetCurrentRttiType().GetName());
                break;
            default:
                break;
        }

        ++index;
    }
}

void CoreTools::ObjectLinkTesting::SortResultTest(const ObjectLink& objectLink)
{
    auto index = 0;
    for (const auto& element : objectLink)
    {
        switch (index)
        {
            case 0:
                ASSERT_EQUAL(element->GetRttiType().GetName(), BoolObject::GetCurrentRttiType().GetName());
                break;
            case 1:
                ASSERT_EQUAL(element->GetRttiType().GetName(), EnumObject::GetCurrentRttiType().GetName());
                break;
            case 2:
                ASSERT_EQUAL(element->GetRttiType().GetName(), IntObject::GetCurrentRttiType().GetName());
                break;
            default:
                break;
        }

        ++index;
    }
}

void CoreTools::ObjectLinkTesting::ResolveLinkTest()
{
    const auto objectLink = CreateObjectLink();

    ObjectAssociated objectAssociated{ 2 };

    objectLink->ResolveLink(objectAssociated);

    ASSERT_EQUAL(objectAssociated.object->GetRttiType().GetName(), EnumObject::GetCurrentRttiType().GetName());
}

void CoreTools::ObjectLinkTesting::ResolveLinkContainerTest()
{
    const auto objectLink = CreateObjectLink();

    ObjectAssociatedContainer object{ ObjectAssociated{ 2 }, ObjectAssociated{ 3 }, ObjectAssociated{ 1 } };

    objectLink->ResolveLinkContainer(object);

    ASSERT_EQUAL(object.at(0).object->GetRttiType().GetName(), EnumObject::GetCurrentRttiType().GetName());
    ASSERT_EQUAL(object.at(1).object->GetRttiType().GetName(), IntObject::GetCurrentRttiType().GetName());
    ASSERT_EQUAL(object.at(2).object->GetRttiType().GetName(), BoolObject::GetCurrentRttiType().GetName());
}
