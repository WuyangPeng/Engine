///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 14:20)

#include "CyclicRedundancyCheckHandleTesting.h"
#include "CoreTools/CyclicRedundancyCheck/CyclicRedundancyCheckHandle.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <array>

using std::array;

CoreTools::CyclicRedundancyCheckHandleTesting::CyclicRedundancyCheckHandleTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CyclicRedundancyCheckHandleTesting)

void CoreTools::CyclicRedundancyCheckHandleTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CyclicRedundancyCheckHandleTesting::MainTest()
{
    CyclicRedundancyCheckHandle::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(HandleTest);

    CyclicRedundancyCheckHandle::Destroy();
}

void CoreTools::CyclicRedundancyCheckHandleTesting::HandleTest()
{
    for (auto i = 0; i < 16; ++i)
    {
        const auto table16 = CYCLIC_REDUNDANCY_CHECK_HANDLE_SINGLETON.Get16Table(i);

        ASSERT_LESS_EQUAL(0u, table16);
    }

    for (auto i = 0; i < 256; ++i)
    {
        const auto table32 = CYCLIC_REDUNDANCY_CHECK_HANDLE_SINGLETON.Get32Table(i);

        ASSERT_LESS_EQUAL(0u, table32);
    }

    for (auto i = 0; i < 8; ++i)
    {
        const auto cCITT = CYCLIC_REDUNDANCY_CHECK_HANDLE_SINGLETON.GetCCITT(i);

        ASSERT_LESS_EQUAL(0u, cCITT);
    }
}
