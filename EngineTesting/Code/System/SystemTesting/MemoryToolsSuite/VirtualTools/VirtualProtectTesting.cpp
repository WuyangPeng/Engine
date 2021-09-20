///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/04/21 17:14)

#include "VirtualProtectTesting.h"
#include "System/MemoryTools/Flags/VirtualToolsFlags.h"
#include "System/MemoryTools/VirtualTools.h"
#include "System/Threading/Process.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::VirtualProtectTesting::VirtualProtectTesting(const OStreamShared& stream)
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

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, VirtualProtectTesting)

void System::VirtualProtectTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::VirtualProtectTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::VirtualProtectTesting::RandomShuffleFlags()
{
    shuffle(memoryProtectFlags.begin(), memoryProtectFlags.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(ProtectTest);

    return true;
}

void System::VirtualProtectTesting::ProtectTest()
{
    WindowsSystemInfo systemInfo{};
    GetWindowSystemInfo(systemInfo);

    for (auto index = 0u; index < memoryProtectFlags.size(); ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoProtectTest, index, systemInfo);
        ASSERT_NOT_THROW_EXCEPTION_2(DoProtectUseProcessTest, index, systemInfo);
    }
}

void System::VirtualProtectTesting::DoProtectTest(size_t index, const WindowsSystemInfo& systemInfo)
{
    auto memoryProtect = memoryProtectFlags.at(index % memoryProtectFlags.size());

    const auto size = systemInfo.dwPageSize * pageLimit;
    auto baseVirtual = AllocateVirtual(nullptr, size, MemoryAllocation::Commit, memoryProtect);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(baseVirtual, "AllocateVirtual 失败。");

    auto oldMemoryProtectFlags = MemoryProtect::NoAccess;

    const auto nextIndex = index + 1;
    auto changeMemoryProtectFlag = memoryProtectFlags.at(nextIndex % memoryProtectFlags.size());

    ASSERT_TRUE(SetVirtualProtect(baseVirtual, size, changeMemoryProtectFlag, &oldMemoryProtectFlags));
    ASSERT_ENUM_EQUAL(oldMemoryProtectFlags & memoryProtect, oldMemoryProtectFlags);

    ASSERT_TRUE(FreeVirtual(baseVirtual));
}

void System::VirtualProtectTesting::DoProtectUseProcessTest(size_t index, const WindowsSystemInfo& systemInfo)
{
    auto memoryProtect = memoryProtectFlags.at(index % memoryProtectFlags.size());

    const auto size = systemInfo.dwPageSize * pageLimit;
    auto baseVirtual = AllocateVirtual(GetCurrentProcessHandle(), nullptr, size, MemoryAllocation::Commit, memoryProtect);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(baseVirtual, "AllocateVirtual 失败。");

    const auto nextIndex = index + 1;
    auto changeMemoryProtectFlag = memoryProtectFlags.at(nextIndex % memoryProtectFlags.size());

    auto oldMemoryProtectFlags = MemoryProtect::NoAccess;

    ASSERT_TRUE(SetVirtualProtect(GetCurrentProcessHandle(), baseVirtual, size, changeMemoryProtectFlag, &oldMemoryProtectFlags));
    ASSERT_ENUM_EQUAL(oldMemoryProtectFlags & memoryProtect, oldMemoryProtectFlags);

    ASSERT_TRUE(FreeVirtual(GetCurrentProcessHandle(), baseVirtual));
}
