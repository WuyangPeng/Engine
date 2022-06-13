///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/14 16:54)

#include "LocalMemoryAllocTesting.h"
#include "System/MemoryTools/Flags/LocalMemoryFlags.h"
#include "System/MemoryTools/LocalTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::LocalMemoryAllocTesting::LocalMemoryAllocTesting(const OStreamShared& stream)
    : ParentType{ stream },
      localMemoryCollection{ LocalMemory::Fixed,
                             LocalMemory::Moveable,
                             LocalMemory::NoCompact,
                             LocalMemory::NoDiscard,
                             LocalMemory::ZeroInit,
                             LocalMemory::Discardable,
                             LocalMemory::ValidFlags,
                             LocalMemory::LHnd,
                             LocalMemory::LPtr,
                             LocalMemory::NonZeroLHnd,
                             LocalMemory::NonZeroLPtr }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, LocalMemoryAllocTesting)

void System::LocalMemoryAllocTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::LocalMemoryAllocTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LocalMemoryAllocTest);
}

void System::LocalMemoryAllocTesting::LocalMemoryAllocTest()
{
    constexpr WindowsSize localSize{ 256 * sizeof(TChar) };

    for (const auto localMemory : localMemoryCollection)
    {
        auto local = LocalMemoryAlloc(localMemory, localSize);
        ASSERT_UNEQUAL_NULL_PTR(local);

        ASSERT_TRUE(LocalMemoryFree(local));
    }
}
