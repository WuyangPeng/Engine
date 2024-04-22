/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 10:23)

#include "VirtualProtectTesting.h"
#include "System/MemoryTools/Flags/VirtualToolsFlags.h"
#include "System/MemoryTools/VirtualTools.h"
#include "System/Threading/Process.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::VirtualProtectTesting::VirtualProtectTesting(const OStreamShared& stream)
    : ParentType{ stream }
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
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(VirtualProtectTest);
}

bool System::VirtualProtectTesting::VirtualProtectTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RandomShuffle);

    ASSERT_NOT_THROW_EXCEPTION_0(ProtectTest);

    return true;
}

void System::VirtualProtectTesting::ProtectTest()
{
    for (auto index = 0u; index < GetMaxSize(); ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoProtectTest, index);
    }
}

void System::VirtualProtectTesting::DoProtectTest(size_t index)
{
    ASSERT_NOT_THROW_EXCEPTION_1(MemoryProtectTest, index);
    ASSERT_NOT_THROW_EXCEPTION_1(DoProtectUseProcessTest, index);
}

void System::VirtualProtectTesting::MemoryProtectTest(size_t index)
{
    const auto memoryProtect = GetMemoryProtect(index);

    auto baseVirtual = AllocateVirtual(nullptr, GetPageSize(), MemoryAllocation::Commit, memoryProtect);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(baseVirtual, "AllocateVirtual 失败。");

    ASSERT_NOT_THROW_EXCEPTION_2(SetVirtualProtectTest, index, baseVirtual);

    ASSERT_NOT_THROW_EXCEPTION_1(FreeVirtualTest, baseVirtual);
}

void System::VirtualProtectTesting::SetVirtualProtectTest(size_t index, WindowsVoidPtr baseVirtual)
{
    const auto memoryProtect = GetMemoryProtect(index);

    const auto nextIndex = index + 1;
    const auto changeMemoryProtect = GetMemoryProtect(nextIndex);

    auto oldMemoryProtect = MemoryProtect::NoAccess;
    ASSERT_TRUE(SetVirtualProtect(baseVirtual, GetPageSize(), changeMemoryProtect, &oldMemoryProtect));
    ASSERT_EQUAL(oldMemoryProtect & memoryProtect, oldMemoryProtect);
}

void System::VirtualProtectTesting::DoProtectUseProcessTest(size_t index)
{
    const auto memoryProtect = GetMemoryProtect(index);

    auto baseVirtual = AllocateVirtual(GetCurrentProcessHandle(), nullptr, GetPageSize(), MemoryAllocation::Commit, memoryProtect);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(baseVirtual, "AllocateVirtual 失败。");

    ASSERT_NOT_THROW_EXCEPTION_2(SetVirtualProtectUseProcessTest, index, baseVirtual);

    ASSERT_NOT_THROW_EXCEPTION_2(FreeVirtualUseProcessTest, GetCurrentProcessHandle(), baseVirtual);
}

void System::VirtualProtectTesting::SetVirtualProtectUseProcessTest(size_t index, WindowsVoidPtr baseVirtual)
{
    const auto memoryProtect = GetMemoryProtect(index);

    const auto nextIndex = index + 1;
    const auto changeMemoryProtect = GetMemoryProtect(nextIndex);

    auto oldMemoryProtect = MemoryProtect::NoAccess;

    ASSERT_TRUE(SetVirtualProtect(GetCurrentProcessHandle(), baseVirtual, GetPageSize(), changeMemoryProtect, &oldMemoryProtect));
    ASSERT_EQUAL(oldMemoryProtect & memoryProtect, oldMemoryProtect);
}
