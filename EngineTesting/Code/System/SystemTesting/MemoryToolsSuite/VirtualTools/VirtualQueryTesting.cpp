///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/06 22:14)

#include "VirtualQueryTesting.h"
#include "System/MemoryTools/Flags/VirtualToolsFlags.h"
#include "System/MemoryTools/VirtualTools.h"
#include "System/Threading/Process.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::VirtualQueryTesting::VirtualQueryTesting(const OStreamShared& stream)
    : ParentType{ stream }
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
    ASSERT_NOT_THROW_EXCEPTION_0(VirtualQueryTest);
}

bool System::VirtualQueryTesting::VirtualQueryTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RandomShuffle);

    ASSERT_NOT_THROW_EXCEPTION_0(QueryTest);

    return true;
}

void System::VirtualQueryTesting::QueryTest()
{
    for (auto index = 0u; index < GetMaxSize(); ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoQueryTest, index);
        ASSERT_NOT_THROW_EXCEPTION_1(DoQueryUseProcessTest, index);
    }
}

void System::VirtualQueryTesting::DoQueryTest(size_t index)
{
    const auto memoryProtect = GetMemoryProtect(index);

    auto baseVirtual = AllocateVirtual(nullptr, GetPageSize(), MemoryAllocation::ReserveAndCommit, memoryProtect);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(baseVirtual, "AllocateVirtual 失败。");

    ASSERT_NOT_THROW_EXCEPTION_2(QueryMemoryBasicInformationTest, index, baseVirtual);

    ASSERT_NOT_THROW_EXCEPTION_1(FreeVirtualTest, baseVirtual);
}

void System::VirtualQueryTesting::QueryMemoryBasicInformationTest(size_t index, WindowsVoidPtr baseVirtual)
{
    MemoryBasicInformation memoryBasicInformation{};
    ASSERT_TRUE(GetVirtualQuery(baseVirtual, &memoryBasicInformation));

    ASSERT_NOT_THROW_EXCEPTION_3(MemoryBasicInformationTest, memoryBasicInformation, index, baseVirtual);
}

void System::VirtualQueryTesting::DoQueryUseProcessTest(size_t index)
{
    const auto memoryProtect = GetMemoryProtect(index);

    auto baseVirtual = AllocateVirtual(GetCurrentProcessHandle(), nullptr, GetPageSize(), MemoryAllocation::ReserveAndCommit, memoryProtect);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(baseVirtual, "AllocateVirtual 失败。");

    ASSERT_NOT_THROW_EXCEPTION_2(QueryMemoryBasicInformationUseProcessTest, index, baseVirtual);

    ASSERT_NOT_THROW_EXCEPTION_2(FreeVirtualUseProcessTest, GetCurrentProcessHandle(), baseVirtual);
}

void System::VirtualQueryTesting::QueryMemoryBasicInformationUseProcessTest(size_t index, WindowsVoidPtr baseVirtual)
{
    MemoryBasicInformation memoryBasicInformation{};
    ASSERT_TRUE(GetVirtualQuery(GetCurrentProcessHandle(), baseVirtual, &memoryBasicInformation));

    ASSERT_NOT_THROW_EXCEPTION_3(MemoryBasicInformationTest, memoryBasicInformation, index, baseVirtual);
}

void System::VirtualQueryTesting::MemoryBasicInformationTest(const MemoryBasicInformation& memoryBasicInformation, size_t index, WindowsVoidPtr baseVirtual)
{
    const auto memoryProtect = GetMemoryProtect(index);

    ASSERT_EQUAL(memoryBasicInformation.BaseAddress, baseVirtual);
    ASSERT_EQUAL(memoryBasicInformation.AllocationBase, baseVirtual);
    ASSERT_EQUAL(memoryBasicInformation.AllocationProtect, EnumCastUnderlying<WindowsDWord>(memoryProtect));
    ASSERT_EQUAL(memoryBasicInformation.Protect, EnumCastUnderlying<WindowsDWord>(memoryProtect));
    ASSERT_EQUAL(memoryBasicInformation.RegionSize, GetPageSize());
    ASSERT_LESS(0u, memoryBasicInformation.State);
    ASSERT_LESS(0u, memoryBasicInformation.Type);
}
