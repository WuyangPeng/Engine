///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
///	ÁªÏµ×÷Õß£º94458936@qq.com
///
///	±ê×¼£ºstd:c++20
///	ÒýÇæ²âÊÔ°æ±¾£º0.8.0.8 (2022/05/14 16:54)

#include "ReAllocateHeapTesting.h"
#include "System/MemoryTools/HeapToolsDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::numeric_limits;

System::ReAllocateHeapTesting::ReAllocateHeapTesting(const OStreamShared& stream)
    : ParentType{ stream }, heapCreateFlags{ HeapCreate::Default, HeapCreate::NoSerialize, HeapCreate::ZeroMemory, HeapCreate::ReallocInPlaceOnly }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ReAllocateHeapTesting)

void System::ReAllocateHeapTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ReAllocateHeapTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ReAllocateProcessHeapSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ReAllocateProcessHeapFailureTest);
}

void System::ReAllocateHeapTesting::ReAllocateProcessHeapSucceedTest()
{
    auto handle = CreateProcessHeap(HeapCreate::Default, 0, 0);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(handle, "CreateProcessHeap Ê§°Ü¡£");

    for (auto flag : heapCreateFlags)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoReAllocateProcessHeapSucceedTest, handle, flag);
    }

    ASSERT_TRUE(DestroyProcessHeap(handle));
}

void System::ReAllocateHeapTesting::DoReAllocateProcessHeapSucceedTest(WindowsHandle handle, HeapCreate flag)
{
    constexpr WindowsSize reAllocatSize{ windowSize * 2 };

    auto memory = AllocateProcessHeap(handle, flag, windowSize);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(memory, "AllocateProcessHeap Ê§°Ü¡£");

    auto memorySize = GetProcessHeapSize(handle, flag, memory);
    ASSERT_EQUAL(memorySize, windowSize);

    auto newMemory = ReAllocateProcessHeap(handle, flag, memory, reAllocatSize);
    ASSERT_UNEQUAL_NULL_PTR(newMemory);

    if (newMemory == nullptr)
    {
        newMemory = memory;
    }

    memorySize = GetProcessHeapSize(handle, flag, newMemory);
    ASSERT_EQUAL(memorySize, reAllocatSize);

    ASSERT_TRUE(FreeProcessHeap(handle, HeapCreate::Default, newMemory));
}

void System::ReAllocateHeapTesting::ReAllocateProcessHeapFailureTest()
{
    auto handle = CreateProcessHeap(HeapCreate::Default, windowSize, windowSize);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(handle, "CreateProcessHeap Ê§°Ü¡£");

    for (auto flag : heapCreateFlags)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoReAllocateProcessHeapFailureTest, handle, flag);
    }

    ASSERT_TRUE(DestroyProcessHeap(handle));
}

void System::ReAllocateHeapTesting::DoReAllocateProcessHeapFailureTest(WindowsHandle handle, HeapCreate flag)
{
    constexpr WindowsSize maximumSize{ 10000 };

    auto memory = AllocateProcessHeap(handle, flag, windowSize);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(memory, "AllocateProcessHeap Ê§°Ü¡£");

    auto memorySize = GetProcessHeapSize(handle, flag, memory);
    ASSERT_EQUAL(memorySize, windowSize);

    auto newMemory = ReAllocateProcessHeap(handle, flag, memory, maximumSize);
    ASSERT_EQUAL_NULL_PTR(newMemory);

    if (newMemory != nullptr)
    {
        memory = newMemory;
    }

    memorySize = GetProcessHeapSize(handle, flag, memory);
    ASSERT_EQUAL(memorySize, windowSize);

    ASSERT_TRUE(FreeProcessHeap(handle, HeapCreate::Default, memory));
}
