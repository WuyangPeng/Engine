/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/15 14:34)

#include "UniqueIdManagerTesting.h"
#include "CoreTools/Base/Flags/UniqueIdSelect.h"
#include "CoreTools/Base/UniqueIdManagerDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using System::operator++;

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
    ASSERT_NOT_THROW_EXCEPTION_0(DefaultUniqueIdManagerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UniqueIdManagerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EnumUniqueIdManagerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetUniqueIdTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EnumSetUniqueIdTest);
}

void CoreTools::UniqueIdManagerTesting::DefaultUniqueIdManagerTest()
{
    const auto defaultUniqueId = UNIQUE_ID_MANAGER_SINGLETON.NextDefaultUniqueId();
    ASSERT_LESS(0, defaultUniqueId);

    ASSERT_EQUAL(UNIQUE_ID_MANAGER_SINGLETON.NextDefaultUniqueId(), defaultUniqueId + 1);
}

void CoreTools::UniqueIdManagerTesting::UniqueIdManagerTest()
{
    for (auto index = 0; index < System::EnumCastUnderlying(UniqueIdSelect::Max); ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoUniqueIdManagerTest, index);
    }
}

void CoreTools::UniqueIdManagerTesting::DoUniqueIdManagerTest(int index)
{
    const auto uniqueId = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(index);
    ASSERT_LESS(0, uniqueId);

    ASSERT_EQUAL(UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(index), uniqueId + 1);
}

void CoreTools::UniqueIdManagerTesting::EnumUniqueIdManagerTest()
{
    for (auto index = UniqueIdSelect::Default; index < UniqueIdSelect::Max; ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoEnumUniqueIdManagerTest, index);
    }
}

void CoreTools::UniqueIdManagerTesting::DoEnumUniqueIdManagerTest(UniqueIdSelect index)
{
    const auto uniqueId = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(index);
    ASSERT_LESS(0, uniqueId);

    ASSERT_EQUAL(UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(index), uniqueId + 1);
}

void CoreTools::UniqueIdManagerTesting::SetUniqueIdTest()
{
    for (auto index = 0; index < System::EnumCastUnderlying(UniqueIdSelect::Max); ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoSetUniqueIdTest, index);
    }
}

void CoreTools::UniqueIdManagerTesting::DoSetUniqueIdTest(int index)
{
    auto uniqueId = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(index);
    ASSERT_LESS(0, uniqueId);

    const auto initUniqueId = uniqueId + step;
    UNIQUE_ID_MANAGER_SINGLETON.SetUniqueId(index, initUniqueId);

    uniqueId = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(index);
    ASSERT_EQUAL(uniqueId, initUniqueId + 1);

    UNIQUE_ID_MANAGER_SINGLETON.SetUniqueId(index, step - 1);

    uniqueId = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(index);
    ASSERT_EQUAL(uniqueId, initUniqueId + 2);
}

void CoreTools::UniqueIdManagerTesting::EnumSetUniqueIdTest()
{
    for (auto index = UniqueIdSelect::Default; index < UniqueIdSelect::Max; ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoEnumSetUniqueIdTest, index);
    }
}

void CoreTools::UniqueIdManagerTesting::DoEnumSetUniqueIdTest(UniqueIdSelect index)
{
    auto uniqueId = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(index);
    ASSERT_LESS(0, uniqueId);

    const auto initUniqueId = uniqueId + nextStep;
    UNIQUE_ID_MANAGER_SINGLETON.SetUniqueId(index, initUniqueId);

    uniqueId = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(index);
    ASSERT_EQUAL(uniqueId, initUniqueId + 1);

    UNIQUE_ID_MANAGER_SINGLETON.SetUniqueId(index, nextStep - 5);

    uniqueId = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(index);
    ASSERT_EQUAL(uniqueId, initUniqueId + 2);
}