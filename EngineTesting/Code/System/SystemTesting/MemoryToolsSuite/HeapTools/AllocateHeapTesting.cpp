/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
/// ÁªÏµ×÷Õß£º94458936@qq.com
///
/// ±ê×¼£ºstd:c++20
/// °æ±¾£º1.0.0.7 (2024/03/12 10:15)

#include "AllocateHeapTesting.h"
#include "System/MemoryTools/HeapToolsDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AllocateHeapTesting::AllocateHeapTesting(const OStreamShared& stream)
    : ParentType{ stream }, size{ 50 }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AllocateHeapTesting)

void System::AllocateHeapTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AllocateHeapTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AllocateDefaultHeapSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AllocateDefaultHeapFailureTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AllocateIntegerTest);
}

void System::AllocateHeapTesting::AllocateDefaultHeapSucceedTest()
{
    const auto handle = CreateProcessHeap(HeapCreate::Default, 0, 0);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(handle, "CreateProcessHeap Ê§°Ü¡£");

    ASSERT_NOT_THROW_EXCEPTION_1(AllocateDefaultHeapSucceedLoop, handle);

    ASSERT_NOT_THROW_EXCEPTION_1(DestroyHeapTest, handle);
}

void System::AllocateHeapTesting::AllocateDefaultHeapSucceedLoop(WindowsHandle handle)
{
    for (auto heapCreate : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoAllocateDefaultHeapSucceedTest, handle, heapCreate);
    }
}

void System::AllocateHeapTesting::DoAllocateDefaultHeapSucceedTest(WindowsHandle handle, HeapCreate flag)
{
    auto memory = AllocateProcessHeap(handle, flag, size);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(memory, "AllocateProcessHeap Ê§°Ü¡£");

    ASSERT_NOT_THROW_EXCEPTION_3(GetProcessHeapSizeSucceedTest, handle, flag, memory);

    ASSERT_NOT_THROW_EXCEPTION_2(FreeHeapTest, handle, memory);
}

void System::AllocateHeapTesting::GetProcessHeapSizeSucceedTest(WindowsHandle handle, HeapCreate flag, WindowsVoidPtr memory)
{
    const auto memorySize = GetProcessHeapSize(handle, flag, memory);
    ASSERT_EQUAL(memorySize, size);
}

void System::AllocateHeapTesting::AllocateDefaultHeapFailureTest()
{
    const auto handle = CreateProcessHeap(HeapCreate::Default, size, size);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(handle, "CreateProcessHeap Ê§°Ü¡£");

    ASSERT_NOT_THROW_EXCEPTION_1(AllocateDefaultHeapFailureLoop, handle);

    ASSERT_NOT_THROW_EXCEPTION_1(DestroyHeapTest, handle);
}

void System::AllocateHeapTesting::AllocateDefaultHeapFailureLoop(WindowsHandle handle)
{
    for (auto heapCreate : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoAllocateDefaultHeapFailureTest, handle, heapCreate);
    }
}

void System::AllocateHeapTesting::DoAllocateDefaultHeapFailureTest(WindowsHandle handle, HeapCreate flag)
{
    constexpr auto maximumSize = std::numeric_limits<WindowsSize>::max();

    auto memory = AllocateProcessHeap(handle, flag, maximumSize);

    ASSERT_EQUAL_NULL_PTR(memory);

    if (memory != nullptr)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(FreeHeapTest, handle, memory);
    }
}

void System::AllocateHeapTesting::AllocateIntegerTest()
{
    const auto integer = AllocateProcessHeap<int>(size * 2);
    ASSERT_UNEQUAL_NULL_PTR(integer);

    ASSERT_TRUE(FreeProcessHeap(integer));
}
