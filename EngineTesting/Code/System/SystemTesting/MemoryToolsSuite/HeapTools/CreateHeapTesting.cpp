/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 10:15)

#include "CreateHeapTesting.h"
#include "System/MemoryTools/HeapTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CreateHeapTesting::CreateHeapTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateHeapTesting)

void System::CreateHeapTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreateHeapTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateHeapSucceedTestLoop);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateHeapFailureTest);
}

void System::CreateHeapTesting::CreateHeapSucceedTestLoop()
{
    for (const auto heapCreate : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(CreateHeapSucceedTest, heapCreate);
    }
}

void System::CreateHeapTesting::CreateHeapSucceedTest(HeapCreate heapCreate)
{
    ASSERT_NOT_THROW_EXCEPTION_1(DoCreateHeapSucceedTest, heapCreate);
    ASSERT_NOT_THROW_EXCEPTION_1(CreateDefaultHeapSucceedTest, heapCreate);
}

void System::CreateHeapTesting::DoCreateHeapSucceedTest(HeapCreate flag)
{
    constexpr WindowsSize initialSize{ 256u };
    constexpr WindowsSize maximumSize{ 512u };

    const auto handle = CreateProcessHeap(flag, initialSize, maximumSize);

    ASSERT_UNEQUAL_NULL_PTR(handle);

    ASSERT_NOT_THROW_EXCEPTION_1(DestroyHeapTest, handle);
}

void System::CreateHeapTesting::CreateDefaultHeapSucceedTest(HeapCreate flag)
{
    const auto defaultHandle = CreateProcessHeap(flag, 0, 0);

    ASSERT_UNEQUAL_NULL_PTR(defaultHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(DestroyHeapTest, defaultHandle);
}

void System::CreateHeapTesting::CreateHeapFailureTest()
{
    for (auto flag : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoCreateHeapFailureTest, flag);
    }
}

void System::CreateHeapTesting::DoCreateHeapFailureTest(HeapCreate flag)
{
    constexpr auto initialSize = std::numeric_limits<WindowsSize>::max();
    constexpr auto maximumSize = std::numeric_limits<WindowsSize>::max();

    const auto handle = CreateProcessHeap(flag, initialSize, maximumSize);

    ASSERT_EQUAL_NULL_PTR(handle);

    ASSERT_NOT_THROW_EXCEPTION_1(DestroyHeapTest, handle);
}
