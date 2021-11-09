///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.2 (2021/08/27 13:13)

#include "UniqueIDManagerTesting.h"
#include "CoreTools/Base/Flags/UniqueIDSelectFlags.h"
#include "CoreTools/Base/UniqueIDManagerDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::UniqueIDManagerTesting::UniqueIDManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, UniqueIDManagerTesting)

void CoreTools::UniqueIDManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::UniqueIDManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(UniqueIDManagerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetUniqueIDTest);
}

void CoreTools::UniqueIDManagerTesting::UniqueIDManagerTest()
{
    const auto defaultUniqueID = UNIQUE_ID_MANAGER_SINGLETON.NextDefaultUniqueID();
    ASSERT_LESS(0, defaultUniqueID);

    ASSERT_EQUAL(UNIQUE_ID_MANAGER_SINGLETON.NextDefaultUniqueID(), defaultUniqueID + 1);

    auto uniqueID = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueID(0);
    ASSERT_LESS(0, uniqueID);

    ASSERT_EQUAL(UNIQUE_ID_MANAGER_SINGLETON.NextUniqueID(0), uniqueID + 1);

    uniqueID = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueID(1);
    ASSERT_LESS(0, uniqueID);

    ASSERT_EQUAL(UNIQUE_ID_MANAGER_SINGLETON.NextUniqueID(1), uniqueID + 1);

    uniqueID = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueID(UniqueIDSelect::Entity);
    ASSERT_LESS(0, uniqueID);

    ASSERT_EQUAL(UNIQUE_ID_MANAGER_SINGLETON.NextUniqueID(UniqueIDSelect::Entity), uniqueID + 1);
}

void CoreTools::UniqueIDManagerTesting::SetUniqueIDTest()
{
    auto uniqueID = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueID(0);
    ASSERT_LESS(0, uniqueID);

    auto initUniqueID = uniqueID + 100;
    UNIQUE_ID_MANAGER_SINGLETON.SetUniqueID(0, initUniqueID);

    uniqueID = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueID(0);
    ASSERT_EQUAL(uniqueID, initUniqueID + 1);

    UNIQUE_ID_MANAGER_SINGLETON.SetUniqueID(0, 99);

    uniqueID = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueID(0);
    ASSERT_EQUAL(uniqueID, initUniqueID + 2);

    uniqueID = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueID(UniqueIDSelect::Entity);
    ASSERT_LESS(0, uniqueID);

    initUniqueID = uniqueID + 110;
    UNIQUE_ID_MANAGER_SINGLETON.SetUniqueID(UniqueIDSelect::Entity, initUniqueID);

    uniqueID = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueID(UniqueIDSelect::Entity);
    ASSERT_EQUAL(uniqueID, initUniqueID + 1);

    UNIQUE_ID_MANAGER_SINGLETON.SetUniqueID(UniqueIDSelect::Entity, 105);

    uniqueID = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueID(UniqueIDSelect::Entity);
    ASSERT_EQUAL(uniqueID, initUniqueID + 2);
}
