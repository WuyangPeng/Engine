/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 10:23)

#include "AllocateVirtualSeparationTesting.h"
#include "System/MemoryTools/Flags/VirtualToolsFlags.h"
#include "System/MemoryTools/VirtualTools.h"
#include "System/Threading/Process.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AllocateVirtualSeparationTesting::AllocateVirtualSeparationTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AllocateVirtualSeparationTesting)

void System::AllocateVirtualSeparationTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AllocateVirtualSeparationTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(AllocateVirtualTest);
}

bool System::AllocateVirtualSeparationTesting::AllocateVirtualTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RandomShuffle);

    ASSERT_NOT_THROW_EXCEPTION_0(AllocateVirtualSeparationTestLoop);

    return true;
}

void System::AllocateVirtualSeparationTesting::AllocateVirtualSeparationTestLoop()
{
    for (auto index = 0u; index < GetMaxSize(); ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(AllocateVirtualSeparationTest, index);
    }
}

void System::AllocateVirtualSeparationTesting::AllocateVirtualSeparationTest(size_t index)
{
    ASSERT_NOT_THROW_EXCEPTION_1(DoAllocateVirtualSeparationTest, index);
    ASSERT_NOT_THROW_EXCEPTION_1(DoAllocateVirtualSeparationUseProcessTest, index);
}

void System::AllocateVirtualSeparationTesting::DoAllocateVirtualSeparationTest(size_t index)
{
    const auto memoryAllocation = GetMemoryAllocation(index);
    const auto memoryProtect = GetMemoryProtect(index);

    auto baseVirtual = static_cast<char*>(AllocateVirtual(nullptr, GetPageSize(), memoryAllocation, memoryProtect));

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(baseVirtual, "AllocateVirtual 失败。");

    ASSERT_NOT_THROW_EXCEPTION_2(AllocateVirtualOnePageTest, baseVirtual, index);

    ASSERT_NOT_THROW_EXCEPTION_1(FreeVirtualTest, baseVirtual);
}

void System::AllocateVirtualSeparationTesting::AllocateVirtualOnePageTest(char* baseVirtual, size_t index)
{
    const auto memoryProtect = GetMemoryProtect(index);

    auto nextVirtual = baseVirtual;
    for (auto page = 0; page < pageLimit; ++page)
    {
        nextVirtual = static_cast<char*>(AllocateVirtual(nextVirtual, GetOnePageSize(), MemoryAllocation::Commit, memoryProtect));
        ASSERT_UNEQUAL_NULL_PTR(nextVirtual);

        ASSERT_NOT_THROW_EXCEPTION_2(ReadWriteTest, memoryProtect, nextVirtual);
    }
}

void System::AllocateVirtualSeparationTesting::DoAllocateVirtualSeparationUseProcessTest(size_t index)
{
    const auto memoryAllocation = GetMemoryAllocation(index);
    const auto memoryProtect = GetMemoryProtect(index);

    auto baseVirtual = static_cast<char*>(AllocateVirtual(GetCurrentProcessHandle(), nullptr, GetPageSize(), memoryAllocation, memoryProtect));

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(baseVirtual, "AllocateVirtual 失败。");

    ASSERT_NOT_THROW_EXCEPTION_2(AllocateVirtualOnePageUseProcessTest, baseVirtual, index);

    ASSERT_NOT_THROW_EXCEPTION_2(FreeVirtualUseProcessTest, GetCurrentProcessHandle(), baseVirtual);
}

void System::AllocateVirtualSeparationTesting::AllocateVirtualOnePageUseProcessTest(char* baseVirtual, size_t index)
{
    const auto memoryProtect = GetMemoryProtect(index);

    auto nextVirtual = baseVirtual;
    for (auto page = 0; page < pageLimit; ++page)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoAllocateVirtualOnePageUseProcessTest, memoryProtect, nextVirtual);
    }
}

void System::AllocateVirtualSeparationTesting::DoAllocateVirtualOnePageUseProcessTest(MemoryProtect memoryProtect, char*& nextVirtual)
{
    nextVirtual = static_cast<char*>(AllocateVirtual(GetCurrentProcessHandle(), nextVirtual, GetOnePageSize(), MemoryAllocation::Commit, memoryProtect));
    ASSERT_UNEQUAL_NULL_PTR(nextVirtual);

    ASSERT_NOT_THROW_EXCEPTION_2(ReadWriteTest, memoryProtect, nextVirtual);
}

void System::AllocateVirtualSeparationTesting::ReadWriteTest(MemoryProtect memoryProtect, char* basePage) const noexcept
{
    if (basePage != nullptr)
    {
        for (auto index = 0u; index < GetOnePageSize(); ++index)
        {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

            DoReadWriteTest(memoryProtect, basePage[index]);

#include SYSTEM_WARNING_POP
        }
    }
}
