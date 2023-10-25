///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 17:07)

#include "UniqueIdManagerTesting.h"
#include "CoreTools/Base/Flags/UniqueIdSelect.h"
#include "CoreTools/Base/UniqueIdManagerDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::UniqueIdManagerTesting::UniqueIdManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, UniqueIdManagerTesting)

void CoreTools::UniqueIdManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::UniqueIdManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(UniqueIdManagerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetUniqueIdTest);
}

void CoreTools::UniqueIdManagerTesting::UniqueIdManagerTest()
{
    const auto defaultUniqueId = UNIQUE_ID_MANAGER_SINGLETON.NextDefaultUniqueId();
    ASSERT_LESS(0, defaultUniqueId);

    ASSERT_EQUAL(UNIQUE_ID_MANAGER_SINGLETON.NextDefaultUniqueId(), defaultUniqueId + 1);

    auto uniqueId = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(0);
    ASSERT_LESS(0, uniqueId);

    ASSERT_EQUAL(UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(0), uniqueId + 1);

    uniqueId = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(1);
    ASSERT_LESS(0, uniqueId);

    ASSERT_EQUAL(UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(1), uniqueId + 1);

    uniqueId = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(UniqueIdSelect::Entity);
    ASSERT_LESS(0, uniqueId);

    ASSERT_EQUAL(UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(UniqueIdSelect::Entity), uniqueId + 1);
}

void CoreTools::UniqueIdManagerTesting::SetUniqueIdTest()
{
    auto uniqueId = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(0);
    ASSERT_LESS(0, uniqueId);

    auto initUniqueId = uniqueId + 100;
    UNIQUE_ID_MANAGER_SINGLETON.SetUniqueId(0, initUniqueId);

    uniqueId = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(0);
    ASSERT_EQUAL(uniqueId, initUniqueId + 1);

    UNIQUE_ID_MANAGER_SINGLETON.SetUniqueId(0, 99);

    uniqueId = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(0);
    ASSERT_EQUAL(uniqueId, initUniqueId + 2);

    uniqueId = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(UniqueIdSelect::Entity);
    ASSERT_LESS(0, uniqueId);

    initUniqueId = uniqueId + 110;
    UNIQUE_ID_MANAGER_SINGLETON.SetUniqueId(UniqueIdSelect::Entity, initUniqueId);

    uniqueId = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(UniqueIdSelect::Entity);
    ASSERT_EQUAL(uniqueId, initUniqueId + 1);

    UNIQUE_ID_MANAGER_SINGLETON.SetUniqueId(UniqueIdSelect::Entity, 105);

    uniqueId = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(UniqueIdSelect::Entity);
    ASSERT_EQUAL(uniqueId, initUniqueId + 2);
}
