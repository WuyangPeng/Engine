/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
/// ÁªÏµ×÷Õß£º94458936@qq.com
///
/// ±ê×¼£ºstd:c++20
/// °æ±¾£º1.0.0.7 (2024/03/12 10:14)

#include "AllocateGenerateExceptionsTesting.h"
#include "System/MemoryTools/HeapToolsDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AllocateGenerateExceptionsTesting::AllocateGenerateExceptionsTesting(const OStreamShared& stream)
    : ParentType{ stream }, size{ 50 }
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
    const auto handle = CreateProcessHeap(HeapCreate::GenerateExceptions, 0, 0);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(handle, "CreateProcessHeap Ê§°Ü¡£");

    ASSERT_NOT_THROW_EXCEPTION_1(AllocateGenerateExceptionsHeapSucceedLoop, handle);

    ASSERT_NOT_THROW_EXCEPTION_1(DestroyHeapTest, handle);
}

void System::AllocateGenerateExceptionsTesting::AllocateGenerateExceptionsHeapSucceedLoop(WindowsHandle handle)
{
    for (auto heapCreate : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoAllocateGenerateExceptionsHeapSucceedTest, handle, heapCreate);
    }
}

void System::AllocateGenerateExceptionsTesting::DoAllocateGenerateExceptionsHeapSucceedTest(WindowsHandle handle, HeapCreate flag)
{
    auto memory = AllocateProcessHeap(handle, flag, size);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(memory, "AllocateProcessHeap Ê§°Ü¡£");

    ASSERT_NOT_THROW_EXCEPTION_3(GetProcessHeapSizeSucceedTest, handle, flag, memory);

    ASSERT_NOT_THROW_EXCEPTION_2(FreeHeapTest, handle, memory);
}

void System::AllocateGenerateExceptionsTesting::GetProcessHeapSizeSucceedTest(WindowsHandle handle, HeapCreate flag, WindowsVoidPtr memory)
{
    const auto memorySize = GetProcessHeapSize(handle, flag, memory);
    ASSERT_EQUAL(memorySize, size);
}

void System::AllocateGenerateExceptionsTesting::AllocateGenerateExceptionsHeapFailureTest()
{
    const auto handle = CreateProcessHeap(HeapCreate::GenerateExceptions, size, size);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(handle, "CreateProcessHeap Ê§°Ü¡£");

    ASSERT_NOT_THROW_EXCEPTION_1(AllocateGenerateExceptionsHeapFailureLoop, handle);

    ASSERT_NOT_THROW_EXCEPTION_1(DestroyHeapTest, handle);
}

void System::AllocateGenerateExceptionsTesting::AllocateGenerateExceptionsHeapFailureLoop(WindowsHandle handle)
{
    for (auto heapCreate : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoAllocateGenerateExceptionsHeapFailureTest, handle, heapCreate);
    }
}

void System::AllocateGenerateExceptionsTesting::DoAllocateGenerateExceptionsHeapFailureTest(WindowsHandle handle, HeapCreate flag)
{
    constexpr auto maximumSize = std::numeric_limits<WindowsSize>::max();

    auto memory = AllocateProcessHeap(handle, flag, maximumSize);

    ASSERT_EQUAL_NULL_PTR(memory);

    if (memory != nullptr)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(FreeHeapTest, handle, memory);
    }
}
