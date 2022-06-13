///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
///	ÁªÏµ×÷Õß£º94458936@qq.com
///
///	±ê×¼£ºstd:c++20
///	ÒýÇæ²âÊÔ°æ±¾£º0.8.0.8 (2022/05/14 16:53)

#include "AllocateHeapTesting.h"
#include "System/MemoryTools/HeapToolsDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::numeric_limits;

System::AllocateHeapTesting::AllocateHeapTesting(const OStreamShared& stream)
    : ParentType{ stream }, heapCreateFlags{ HeapCreate::Default, HeapCreate::NoSerialize, HeapCreate::ZeroMemory, HeapCreate::ReallocInPlaceOnly }
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
    auto handle = CreateProcessHeap(HeapCreate::Default, 0, 0);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(handle, "CreateProcessHeap Ê§°Ü¡£");

    for (auto flag : heapCreateFlags)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoAllocateDefaultHeapSucceedTest, handle, flag);
    }

    ASSERT_TRUE(DestroyProcessHeap(handle));
}

void System::AllocateHeapTesting::DoAllocateDefaultHeapSucceedTest(WindowsHandle handle, HeapCreate flag)
{
    constexpr WindowsSize size{ 50 };

    auto memory = AllocateProcessHeap(handle, flag, size);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(memory, "AllocateProcessHeap Ê§°Ü¡£");

    const auto memorySize = GetProcessHeapSize(handle, flag, memory);
    ASSERT_EQUAL(memorySize, size);

    ASSERT_TRUE(FreeProcessHeap(handle, HeapCreate::Default, memory));
}

void System::AllocateHeapTesting::AllocateDefaultHeapFailureTest()
{
    constexpr WindowsSize size{ 50 };
    auto handle = CreateProcessHeap(HeapCreate::Default, size, size);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(handle, "CreateProcessHeap Ê§°Ü¡£");

    for (auto flag : heapCreateFlags)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoAllocateDefaultHeapFailureTest, handle, flag);
    }

    ASSERT_TRUE(DestroyProcessHeap(handle));
}

void System::AllocateHeapTesting::DoAllocateDefaultHeapFailureTest(WindowsHandle handle, HeapCreate flag)
{
    constexpr WindowsSize maximumSize{ numeric_limits<WindowsSize>::max() };

    auto memory = AllocateProcessHeap(handle, flag, maximumSize);

    ASSERT_EQUAL_NULL_PTR(memory);

    if (memory != nullptr)
    {
        ASSERT_TRUE(FreeProcessHeap(handle, HeapCreate::Default, memory));
    }
}

void System::AllocateHeapTesting::AllocateIntegerTest()
{
    constexpr auto size = 100;

    auto integer = AllocateProcessHeap<int>(size);
    ASSERT_UNEQUAL_NULL_PTR(integer);

    ASSERT_TRUE(FreeProcessHeap(integer));
}
