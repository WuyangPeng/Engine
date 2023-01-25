///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
///	ÁªÏµ×÷Õß£º94458936@qq.com
///
///	±ê×¼£ºstd:c++20
///	ÒýÇæ²âÊÔ°æ±¾£º0.9.0.0 (2023/01/06 21:39)

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

    ASSERT_NOT_THROW_EXCEPTION_0(AllocateVirtualSeparationTest);

    return true;
}

void System::AllocateVirtualSeparationTesting::AllocateVirtualSeparationTest()
{
    for (auto index = 0u; index < GetMaxSize(); ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoAllocateVirtualSeparationTest, index);
        ASSERT_NOT_THROW_EXCEPTION_1(DoAllocateVirtualSeparationUseProcessTest, index);
    }
}

void System::AllocateVirtualSeparationTesting::DoAllocateVirtualSeparationTest(size_t index)
{
    const auto memoryAllocation = GetMemoryAllocation(index);
    const auto memoryProtect = GetMemoryProtect(index);

    auto baseVirtual = static_cast<char*>(AllocateVirtual(nullptr, GetPageSize(), memoryAllocation, memoryProtect));

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(baseVirtual, "AllocateVirtual Ê§°Ü¡£");

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

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(baseVirtual, "AllocateVirtual Ê§°Ü¡£");

    ASSERT_NOT_THROW_EXCEPTION_2(AllocateVirtualOnePageUseProcessTest, baseVirtual, index);

    ASSERT_NOT_THROW_EXCEPTION_2(FreeVirtualUseProcessTest, GetCurrentProcessHandle(), baseVirtual);
}

void System::AllocateVirtualSeparationTesting::AllocateVirtualOnePageUseProcessTest(char* baseVirtual, size_t index)
{
    const auto memoryProtect = GetMemoryProtect(index);

    auto nextVirtual = baseVirtual;
    for (auto page = 0; page < pageLimit; ++page)
    {
        nextVirtual = static_cast<char*>(AllocateVirtual(GetCurrentProcessHandle(), nextVirtual, GetOnePageSize(), MemoryAllocation::Commit, memoryProtect));
        ASSERT_UNEQUAL_NULL_PTR(nextVirtual);

        ASSERT_NOT_THROW_EXCEPTION_2(ReadWriteTest, memoryProtect, nextVirtual);
    }
}

void System::AllocateVirtualSeparationTesting::ReadWriteTest(MemoryProtect memoryProtect, char* basePage) noexcept
{
    if (basePage != nullptr)
    {
        for (auto index = 0u; index < GetOnePageSize(); ++index)
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

            DoReadWriteTest(memoryProtect, basePage[index]);

#include STSTEM_WARNING_POP
        }
    }
}
