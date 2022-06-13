///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/14 16:54)

#include "CurrentProcessHeapTesting.h"
#include "System/MemoryTools/Flags/HeapToolsFlags.h"
#include "System/MemoryTools/HeapTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

using std::array;

System::CurrentProcessHeapTesting::CurrentProcessHeapTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CurrentProcessHeapTesting)

void System::CurrentProcessHeapTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CurrentProcessHeapTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CurrentProcessHeapTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CurrentProcessHeapsTest);
}

void System::CurrentProcessHeapTesting::CurrentProcessHeapTest()
{
    auto processHandle = GetCurrentProcessHeap();
    ASSERT_UNEQUAL_NULL_PTR(processHandle);
}

void System::CurrentProcessHeapTesting::CurrentProcessHeapsTest()
{
    auto processHandle = GetCurrentProcessHeap();
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(processHandle, "GetCurrentProcessHeap 错误。");

    ASSERT_NOT_THROW_EXCEPTION_1(DefaultHeapTest, processHandle);

    auto newHandle = CreateProcessHeap(HeapCreate::Default, 0, 0);
    ASSERT_UNEQUAL_NULL_PTR(newHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(AfterCreateHeapTest, newHandle);

    ASSERT_TRUE(DestroyProcessHeap(newHandle));

    ASSERT_NOT_THROW_EXCEPTION_1(DefaultHeapTest, processHandle);
}

void System::CurrentProcessHeapTesting::AfterCreateHeapTest(WindowsHandle processHandle)
{
    array<WindowsHandle, bufferSize> heaps{};

    const auto heapSize = GetCurrentProcessHeaps(bufferSize, heaps.data());
    ASSERT_LESS(2u, heapSize);

    ASSERT_EQUAL(heaps.at(heapSize - 1), processHandle);
}

void System::CurrentProcessHeapTesting::DefaultHeapTest(WindowsHandle processHandle)
{
    array<WindowsHandle, bufferSize> heaps{};

    const auto heapSize = GetCurrentProcessHeaps(bufferSize, heaps.data());
    ASSERT_LESS(1u, heapSize);
    ASSERT_EQUAL(heaps.at(0), processHandle);
}
