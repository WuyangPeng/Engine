///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
///	ÁªÏµ×÷Õß£º94458936@qq.com
///
///	±ê×¼£ºstd:c++17
///	ÒýÇæ²âÊÔ°æ±¾£º0.7.1.2 (2021/04/20 18:23)

#include "AllocateVirtualSeparationTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/MemoryTools/Flags/VirtualToolsFlags.h"
#include "System/MemoryTools/VirtualTools.h"
#include "System/Threading/Process.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::default_random_engine;
using std::ostream;
using std::vector;

System::AllocateVirtualSeparationTesting::AllocateVirtualSeparationTesting(const OStreamShared& stream)
    : ParentType{ stream },
      memoryAllocationFlags{ MemoryAllocation::Commit,
                             MemoryAllocation::ReserveAndCommit,
                             MemoryAllocation::TopDown | MemoryAllocation::Commit,
                             MemoryAllocation::TopDown | MemoryAllocation::ReserveAndCommit,
                             MemoryAllocation::WriteWatch | MemoryAllocation::Commit },
      memoryProtectFlags{ MemoryProtect::NoAccess,
                          MemoryProtect::ReadOnly,
                          MemoryProtect::ReadWrite,
                          MemoryProtect::Execute,
                          MemoryProtect::ExecuteRead,
                          MemoryProtect::ExecuteReadWrite },
      randomEngine{ GetEngineRandomSeed() }
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
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::AllocateVirtualSeparationTesting::RandomShuffleFlags()
{
    shuffle(memoryAllocationFlags.begin(), memoryAllocationFlags.end(), randomEngine);
    shuffle(memoryProtectFlags.begin(), memoryProtectFlags.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(AllocateVirtualSeparationTest);

    return true;
}

void System::AllocateVirtualSeparationTesting::AllocateVirtualSeparationTest()
{
    WindowsSystemInfo systemInfo{};
    GetWindowSystemInfo(systemInfo);

    for (auto index = 0u; index < memoryProtectFlags.size(); ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoAllocateVirtualSeparationTest, systemInfo, index);
        ASSERT_NOT_THROW_EXCEPTION_2(DoAllocateVirtualSeparationUseProcessTest, systemInfo, index);
    }
}

void System::AllocateVirtualSeparationTesting::DoAllocateVirtualSeparationTest(const WindowsSystemInfo& systemInfo, size_t index)
{
    auto memoryAllocation = memoryAllocationFlags.at(index % memoryAllocationFlags.size());
    auto memoryProtect = memoryProtectFlags.at(index % memoryProtectFlags.size());

    const auto size = systemInfo.dwPageSize * pageLimit;

    auto baseVirtual = AllocateVirtual(nullptr, size, memoryAllocation, memoryProtect);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(baseVirtual, "AllocateVirtual Ê§°Ü¡£");

    auto nextVirtual = baseVirtual;
    for (auto page = 0; page < pageLimit; ++page)
    {
        nextVirtual = AllocateVirtual(nextVirtual, systemInfo.dwPageSize, MemoryAllocation::Commit, memoryProtect);
        ASSERT_UNEQUAL_NULL_PTR(nextVirtual);

        auto nextPage = static_cast<char*>(nextVirtual);
        ReadWriteTest(systemInfo, memoryProtect, nextPage);
    }

    ASSERT_TRUE(FreeVirtual(baseVirtual));
}

void System::AllocateVirtualSeparationTesting::DoAllocateVirtualSeparationUseProcessTest(const WindowsSystemInfo& systemInfo, size_t index)
{
    auto memoryAllocation = memoryAllocationFlags.at(index % memoryAllocationFlags.size());
    auto memoryProtect = memoryProtectFlags.at(index % memoryProtectFlags.size());

    const auto size = systemInfo.dwPageSize * pageLimit;

    auto baseVirtual = AllocateVirtual(GetCurrentProcessHandle(), nullptr, size, memoryAllocation, memoryProtect);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(baseVirtual, "AllocateVirtual Ê§°Ü¡£");

    auto nextVirtual = baseVirtual;
    for (auto page = 0; page < pageLimit; ++page)
    {
        nextVirtual = AllocateVirtual(GetCurrentProcessHandle(), nextVirtual, systemInfo.dwPageSize, MemoryAllocation::Commit, memoryProtect);
        ASSERT_UNEQUAL_NULL_PTR(nextVirtual);

        auto nextPage = static_cast<char*>(nextVirtual);
        ReadWriteTest(systemInfo, memoryProtect, nextPage);
    }

    ASSERT_TRUE(FreeVirtual(GetCurrentProcessHandle(), baseVirtual));
}

void System::AllocateVirtualSeparationTesting::ReadWriteTest(const WindowsSystemInfo& systemInfo, MemoryProtect memoryProtect, char* basePage) noexcept
{
    if (basePage != nullptr)
    {
        for (auto index = 0u; index < systemInfo.dwPageSize; ++index)
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
            DoReadWriteTest(memoryProtect, basePage[index]);
#include STSTEM_WARNING_POP
        }
    }
}

void System::AllocateVirtualSeparationTesting::DoReadWriteTest(MemoryProtect memoryProtect, char& basePage) noexcept
{
    if ((memoryProtect & MemoryProtect::ReadWrite) != MemoryProtect::Zero ||
        (memoryProtect & MemoryProtect::ExecuteReadWrite) != MemoryProtect::Zero)
    {
        basePage = '\0';
    }

    if ((memoryProtect & MemoryProtect::ReadOnly) != MemoryProtect::Zero ||
        (memoryProtect & MemoryProtect::ExecuteRead) != MemoryProtect::Zero)
    {
        MAYBE_UNUSED const auto value = basePage;
    }
}
