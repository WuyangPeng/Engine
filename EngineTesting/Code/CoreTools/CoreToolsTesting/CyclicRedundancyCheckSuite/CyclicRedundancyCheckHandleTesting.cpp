/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/26 14:39)

#include "CyclicRedundancyCheckHandleTesting.h"
#include "CoreTools/CyclicRedundancyCheck/CyclicRedundancyCheckHandle.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::CyclicRedundancyCheckHandleTesting::CyclicRedundancyCheckHandleTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CyclicRedundancyCheckHandleTesting)

void CoreTools::CyclicRedundancyCheckHandleTesting::DoRunUnitTest()
{
    CyclicRedundancyCheckHandle::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    CyclicRedundancyCheckHandle::Destroy();
}

void CoreTools::CyclicRedundancyCheckHandleTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(HandleTest);
}

void CoreTools::CyclicRedundancyCheckHandleTesting::HandleTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Get16TableTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Get32TableTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetCcittTest);
}

void CoreTools::CyclicRedundancyCheckHandleTesting::Get16TableTest()
{
    for (auto i = 0; i < 16; ++i)
    {
        const auto table16 = CYCLIC_REDUNDANCY_CHECK_HANDLE_SINGLETON.Get16Table(i);

        ASSERT_LESS_EQUAL(0u, table16);
    }
}

void CoreTools::CyclicRedundancyCheckHandleTesting::Get32TableTest()
{
    for (auto i = 0; i < 256; ++i)
    {
        const auto table32 = CYCLIC_REDUNDANCY_CHECK_HANDLE_SINGLETON.Get32Table(i);

        ASSERT_LESS_EQUAL(0u, table32);
    }
}

void CoreTools::CyclicRedundancyCheckHandleTesting::GetCcittTest()
{
    for (auto i = 0; i < 8; ++i)
    {
        const auto ccitt = CYCLIC_REDUNDANCY_CHECK_HANDLE_SINGLETON.GetCcitt(i);

        ASSERT_LESS_EQUAL(0u, ccitt);
    }
}
