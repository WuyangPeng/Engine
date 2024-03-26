/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 10:22)

#include "AllocateVirtualOneStepTesting.h"
#include "System/MemoryTools/VirtualTools.h"
#include "System/Threading/Process.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AllocateVirtualOneStepTesting::AllocateVirtualOneStepTesting(const OStreamShared& stream)
    : ParentType{ stream }
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
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(AllocateVirtualTest);
}

bool System::AllocateVirtualOneStepTesting::AllocateVirtualTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RandomShuffle);

    ASSERT_NOT_THROW_EXCEPTION_0(AllocateVirtualOneStepTestLoop);

    return true;
}

void System::AllocateVirtualOneStepTesting::AllocateVirtualOneStepTestLoop()
{
    for (auto index = 0u; index < GetMaxSize(); ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(AllocateVirtualOneStepTest, index);
    }
}

void System::AllocateVirtualOneStepTesting::AllocateVirtualOneStepTest(size_t index)
{
    ASSERT_NOT_THROW_EXCEPTION_1(DoAllocateVirtualOneStepTest, index);
    ASSERT_NOT_THROW_EXCEPTION_1(DoAllocateVirtualOneStepUseProcessTest, index);
}

void System::AllocateVirtualOneStepTesting::DoAllocateVirtualOneStepTest(size_t index)
{
    const auto memoryAllocation = GetMemoryAllocation(index);
    const auto memoryProtect = GetMemoryProtect(index);

    auto baseVirtual = static_cast<char*>(AllocateVirtual(nullptr, GetPageSize(), memoryAllocation, memoryProtect));

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(baseVirtual, "AllocateVirtual 失败。");

    ASSERT_NOT_THROW_EXCEPTION_2(ReadWriteTest, memoryProtect, baseVirtual);

    ASSERT_NOT_THROW_EXCEPTION_1(FreeVirtualTest, baseVirtual);
}

void System::AllocateVirtualOneStepTesting::DoAllocateVirtualOneStepUseProcessTest(size_t index)
{
    const auto memoryAllocation = GetMemoryAllocation(index);
    const auto memoryProtect = GetMemoryProtect(index);

    auto baseVirtual = static_cast<char*>(AllocateVirtual(GetCurrentProcessHandle(), nullptr, GetPageSize(), memoryAllocation, memoryProtect));

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(baseVirtual, "AllocateVirtual 失败。");

    ASSERT_NOT_THROW_EXCEPTION_2(ReadWriteTest, memoryProtect, baseVirtual);

    ASSERT_NOT_THROW_EXCEPTION_2(FreeVirtualUseProcessTest, GetCurrentProcessHandle(), baseVirtual);
}

void System::AllocateVirtualOneStepTesting::ReadWriteTest(MemoryProtect memoryProtect, char* basePage) const noexcept
{
    if (basePage != nullptr)
    {
        for (auto index = 0u; index < GetPageSize(); ++index)
        {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

            DoReadWriteTest(memoryProtect, basePage[index]);

#include SYSTEM_WARNING_POP
        }
    }
}
