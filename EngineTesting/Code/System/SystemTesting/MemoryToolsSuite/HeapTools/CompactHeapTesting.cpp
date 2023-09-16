///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 10:05)

#include "CompactHeapTesting.h"
#include "System/MemoryTools/HeapTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CompactHeapTesting::CompactHeapTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CompactHeapTesting)

void System::CompactHeapTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CompactHeapTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CompactHeapTest);
}

void System::CompactHeapTesting::CompactHeapTest()
{
    for (auto heapCreate : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(CompactTest, heapCreate);
    }
}

void System::CompactHeapTesting::CompactTest(HeapCreate flag)
{
    const auto handle = CreateProcessHeap(flag, 0, 0);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(handle, "CreateProcessHeap ʧ�ܡ�");

    ASSERT_NOT_THROW_EXCEPTION_2(DoCompactTest, handle, flag);

    ASSERT_NOT_THROW_EXCEPTION_1(DestroyHeapTest, handle);
}

void System::CompactHeapTesting::DoCompactTest(WindowsHandle handle, HeapCreate flag)
{
    constexpr WindowsSize size{ 50 };

    auto memory = AllocateProcessHeap(handle, flag, size);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(memory, "AllocateProcessHeap ʧ�ܡ�");

    const auto memorySize = GetProcessHeapCompact(handle, flag);
    ASSERT_LESS(0u, memorySize);

    ASSERT_NOT_THROW_EXCEPTION_2(FreeHeapTest, handle, memory);
}
