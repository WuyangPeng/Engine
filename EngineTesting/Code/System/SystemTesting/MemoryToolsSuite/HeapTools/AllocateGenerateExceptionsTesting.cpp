///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
///	ÁªÏµ×÷Õß£º94458936@qq.com
///
///	±ê×¼£ºstd:c++17
///	ÒýÇæ²âÊÔ°æ±¾£º0.7.1.2 (2021/04/20 13:40)

#include "AllocateGenerateExceptionsTesting.h"
#include "System/MemoryTools/HeapToolsDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::numeric_limits;

System::AllocateGenerateExceptionsTesting::AllocateGenerateExceptionsTesting(const OStreamShared& stream)
    : ParentType{ stream }, heapCreateFlags{ HeapCreate::Default, HeapCreate::NoSerialize, HeapCreate::ZeroMemory, HeapCreate::ReallocInPlaceOnly }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AllocateGenerateExceptionsTesting)

void System::AllocateGenerateExceptionsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AllocateGenerateExceptionsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AllocateGenerateExceptionsHeapSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AllocateGenerateExceptionsHeapFailureTest);
}

void System::AllocateGenerateExceptionsTesting::AllocateGenerateExceptionsHeapSucceedTest()
{
    auto handle = CreateProcessHeap(HeapCreate::GenerateExceptions, 0, 0);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(handle, "CreateProcessHeap Ê§°Ü¡£");

    for (auto flag : heapCreateFlags)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoAllocateGenerateExceptionsHeapSucceedTest, handle, flag);
    }

    ASSERT_TRUE(DestroyProcessHeap(handle));
}

void System::AllocateGenerateExceptionsTesting::DoAllocateGenerateExceptionsHeapSucceedTest(WindowsHandle handle, HeapCreate flag)
{
    constexpr WindowsSize size{ 50 };
    auto memory = AllocateProcessHeap(handle, flag, size);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(memory, "AllocateProcessHeap Ê§°Ü¡£");

    const auto memorySize = GetProcessHeapSize(handle, flag, memory);
    ASSERT_EQUAL(memorySize, size);

    ASSERT_TRUE(FreeProcessHeap(handle, HeapCreate::NoSerialize, memory));
}

void System::AllocateGenerateExceptionsTesting::AllocateGenerateExceptionsHeapFailureTest()
{
    constexpr WindowsSize size{ 50 };

    auto handle = CreateProcessHeap(HeapCreate::GenerateExceptions, size, size);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(handle, "CreateProcessHeap Ê§°Ü¡£");

    for (auto flag : heapCreateFlags)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoAllocateGenerateExceptionsHeapFailureTest, handle, flag);
    }

    ASSERT_TRUE(DestroyProcessHeap(handle));
}

void System::AllocateGenerateExceptionsTesting::DoAllocateGenerateExceptionsHeapFailureTest(WindowsHandle handle, HeapCreate flag)
{
    constexpr WindowsSize maximumSize{ numeric_limits<WindowsSize>::max() };

    auto memory = AllocateProcessHeap(handle, flag, maximumSize);

    ASSERT_EQUAL_NULL_PTR(memory);

    if (memory != nullptr)
    {
        ASSERT_TRUE(FreeProcessHeap(handle, HeapCreate::Default, memory));
    }
}
