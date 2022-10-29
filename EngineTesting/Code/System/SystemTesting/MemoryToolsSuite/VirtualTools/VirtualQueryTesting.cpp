///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
///	ÁªÏµ×÷Õß£º94458936@qq.com
///
///	±ê×¼£ºstd:c++20
///	ÒýÇæ²âÊÔ°æ±¾£º0.8.1.3 (2022/10/16 19:41)

#include "VirtualQueryTesting.h"
#include "System/MemoryTools/Flags/VirtualToolsFlags.h"
#include "System/MemoryTools/VirtualTools.h"
#include "System/Threading/Process.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::VirtualQueryTesting::VirtualQueryTesting(const OStreamShared& stream)
    : ParentType{ stream },
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

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, VirtualQueryTesting)

void System::VirtualQueryTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::VirtualQueryTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RandomShuffleFlags);
}

bool System::VirtualQueryTesting::RandomShuffleFlags()
{
    shuffle(memoryProtectFlags.begin(), memoryProtectFlags.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(QueryTest);

    return true;
}

void System::VirtualQueryTesting::QueryTest()
{
    WindowsSystemInfo systemInfo{};
    GetWindowSystemInfo(systemInfo);

    for (auto index = 0u; index < memoryProtectFlags.size(); ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoQueryTest, index, systemInfo);
        ASSERT_NOT_THROW_EXCEPTION_2(DoQueryUseProcessTest, index, systemInfo);
    }
}

void System::VirtualQueryTesting::DoQueryTest(size_t index, const WindowsSystemInfo& systemInfo)
{
    auto memoryProtect = memoryProtectFlags.at(index % memoryProtectFlags.size());

    const auto size = systemInfo.dwPageSize * pageLimit;
    auto baseVirtual = AllocateVirtual(nullptr, size, MemoryAllocation::ReserveAndCommit, memoryProtect);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(baseVirtual, "AllocateVirtual Ê§°Ü¡£");

    MemoryBasicInformation memoryBasicInformation{};

    ASSERT_TRUE(GetVirtualQuery(baseVirtual, &memoryBasicInformation));

    ASSERT_EQUAL(memoryBasicInformation.BaseAddress, baseVirtual);
    ASSERT_EQUAL(memoryBasicInformation.AllocationBase, baseVirtual);
    ASSERT_EQUAL(memoryBasicInformation.AllocationProtect, EnumCastUnderlying<WindowsDWord>(memoryProtect));
    ASSERT_EQUAL(memoryBasicInformation.Protect, EnumCastUnderlying<WindowsDWord>(memoryProtect));
    ASSERT_EQUAL(memoryBasicInformation.RegionSize, size);
    ASSERT_LESS(0u, memoryBasicInformation.State);
    ASSERT_LESS(0u, memoryBasicInformation.Type);

    ASSERT_TRUE(FreeVirtual(baseVirtual));
}

void System::VirtualQueryTesting::DoQueryUseProcessTest(size_t index, const WindowsSystemInfo& systemInfo)
{
    auto memoryProtect = memoryProtectFlags.at(index % memoryProtectFlags.size());

    const auto size = systemInfo.dwPageSize * pageLimit;
    auto baseVirtual = AllocateVirtual(GetCurrentProcessHandle(), nullptr, size, MemoryAllocation::ReserveAndCommit, memoryProtect);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(baseVirtual, "AllocateVirtual Ê§°Ü¡£");

    MemoryBasicInformation memoryBasicInformation{};

    ASSERT_TRUE(GetVirtualQuery(GetCurrentProcessHandle(), baseVirtual, &memoryBasicInformation));

    ASSERT_EQUAL(memoryBasicInformation.BaseAddress, baseVirtual);
    ASSERT_EQUAL(memoryBasicInformation.AllocationBase, baseVirtual);
    ASSERT_EQUAL(memoryBasicInformation.AllocationProtect, EnumCastUnderlying<WindowsDWord>(memoryProtect));
    ASSERT_EQUAL(memoryBasicInformation.Protect, EnumCastUnderlying<WindowsDWord>(memoryProtect));
    ASSERT_EQUAL(memoryBasicInformation.RegionSize, size);
    ASSERT_LESS(0u, memoryBasicInformation.State);
    ASSERT_LESS(0u, memoryBasicInformation.Type);

    ASSERT_TRUE(FreeVirtual(GetCurrentProcessHandle(), baseVirtual));
}
