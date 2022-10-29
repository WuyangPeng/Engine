///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
///	ÁªÏµ×÷Õß£º94458936@qq.com
///
///	±ê×¼£ºstd:c++20
///	ÒýÇæ²âÊÔ°æ±¾£º0.8.1.3 (2022/10/16 19:41)

#include "AllocateVirtualOneStepTesting.h"
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

System::AllocateVirtualOneStepTesting::AllocateVirtualOneStepTesting(const OStreamShared& stream)
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

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AllocateVirtualOneStepTesting)

void System::AllocateVirtualOneStepTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AllocateVirtualOneStepTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::AllocateVirtualOneStepTesting::RandomShuffleFlags()
{
    shuffle(memoryAllocationFlags.begin(), memoryAllocationFlags.end(), randomEngine);
    shuffle(memoryProtectFlags.begin(), memoryProtectFlags.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(AllocateVirtualOneStepTest);

    return true;
}

void System::AllocateVirtualOneStepTesting::AllocateVirtualOneStepTest()
{
    WindowsSystemInfo systemInfo{};
    GetWindowSystemInfo(systemInfo);

    for (auto index = 0u; index < memoryProtectFlags.size(); ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoAllocateVirtualOneStepTest, systemInfo, index);
        ASSERT_NOT_THROW_EXCEPTION_2(DoAllocateVirtualOneStepUseProcessTest, systemInfo, index);
    }
}

void System::AllocateVirtualOneStepTesting::DoAllocateVirtualOneStepTest(const WindowsSystemInfo& systemInfo, size_t index)
{
    auto memoryAllocation = memoryAllocationFlags.at(index % memoryAllocationFlags.size());
    auto memoryProtect = memoryProtectFlags.at(index % memoryProtectFlags.size());

    const auto size = systemInfo.dwPageSize * pageLimit;

    auto baseVirtual = AllocateVirtual(nullptr, size, memoryAllocation, memoryProtect);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(baseVirtual, "AllocateVirtual Ê§°Ü¡£");

    auto basePage = static_cast<char*>(baseVirtual);

    ReadWriteTest(systemInfo, memoryProtect, basePage);

    ASSERT_TRUE(FreeVirtual(basePage));
}

void System::AllocateVirtualOneStepTesting::DoAllocateVirtualOneStepUseProcessTest(const WindowsSystemInfo& systemInfo, size_t index)
{
    auto memoryAllocation = memoryAllocationFlags.at(index % memoryAllocationFlags.size());
    auto memoryProtect = memoryProtectFlags.at(index % memoryProtectFlags.size());

    const auto size = systemInfo.dwPageSize * pageLimit;

    auto baseVirtual = AllocateVirtual(GetCurrentProcessHandle(), nullptr, size, memoryAllocation, memoryProtect);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(baseVirtual, "AllocateVirtual Ê§°Ü¡£");

    auto basePage = static_cast<char*>(baseVirtual);

    ReadWriteTest(systemInfo, memoryProtect, basePage);

    ASSERT_TRUE(FreeVirtual(GetCurrentProcessHandle(), basePage));
}

void System::AllocateVirtualOneStepTesting::ReadWriteTest(const WindowsSystemInfo& systemInfo, MemoryProtect memoryProtect, char* basePage) noexcept
{
    if (basePage != nullptr)
    {
        const WindowsDWord maxPageSize{ pageLimit * systemInfo.dwPageSize };
        for (auto index = 0u; index < maxPageSize; ++index)
        {

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

            DoReadWriteTest(memoryProtect, basePage[index]);

#include STSTEM_WARNING_POP

        }
    }
}

void System::AllocateVirtualOneStepTesting::DoReadWriteTest(MemoryProtect memoryProtect, char& basePage) noexcept
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
