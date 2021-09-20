// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:53)

#include "CyclicRedundancyCheckHandleTesting.h"
#include "CoreTools/CyclicRedundancyCheck/CyclicRedundancyCheckHandle.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <array>

using std::array;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, CyclicRedundancyCheckHandleTesting)

void CoreTools::CyclicRedundancyCheckHandleTesting ::MainTest()
{
    CyclicRedundancyCheckHandle::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(HandleTest);

    CyclicRedundancyCheckHandle::Destroy();
}

void CoreTools::CyclicRedundancyCheckHandleTesting ::HandleTest()
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
