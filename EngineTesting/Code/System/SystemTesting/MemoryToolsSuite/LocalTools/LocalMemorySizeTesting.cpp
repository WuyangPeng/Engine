///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/04/24 14:36)

#include "LocalMemorySizeTesting.h"
#include "System/MemoryTools/Flags/LocalMemoryFlags.h"
#include "System/MemoryTools/LocalTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::LocalMemorySizeTesting::LocalMemorySizeTesting(const OStreamShared& stream)
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

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, LocalMemorySizeTesting)

void System::LocalMemorySizeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::LocalMemorySizeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LocalMemorySizeTest);
}

void System::LocalMemorySizeTesting::LocalMemorySizeTest()
{
    for (const auto localMemory : localMemoryCollection)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoLocalMemorySizeTest, localMemory);
    }
}

void System::LocalMemorySizeTesting::DoLocalMemorySizeTest(LocalMemory localMemory)
{
    constexpr WindowsSize localSize{ 256 * sizeof(TChar) };

    auto local = LocalMemoryAlloc(localMemory, localSize);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(local, "LocalMemoryAlloc 失败。");

    ASSERT_EQUAL(GetLocalMemorySize(local), localSize);

    ASSERT_TRUE(LocalMemoryFree(local));
}
