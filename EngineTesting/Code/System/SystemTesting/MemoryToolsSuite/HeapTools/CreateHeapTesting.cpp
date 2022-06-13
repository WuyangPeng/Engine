///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/14 16:54)

#include "CreateHeapTesting.h"
#include "System/MemoryTools/Flags/HeapToolsFlags.h"
#include "System/MemoryTools/HeapTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::numeric_limits;

System::CreateHeapTesting::CreateHeapTesting(const OStreamShared& stream)
    : ParentType{ stream }, heapCreateFlags{ HeapCreate::Default, HeapCreate::NoSerialize, HeapCreate::GenerateExceptions, HeapCreate::CreateEnableExecute }
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
    ASSERT_NOT_THROW_EXCEPTION_0(CreateHeapSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateHeapFailureTest);
}

void System::CreateHeapTesting::CreateHeapSucceedTest()
{
    for (auto flag : heapCreateFlags)
    {
        DoCreateHeapSucceedTest(flag);
    }
}

void System::CreateHeapTesting::DoCreateHeapSucceedTest(HeapCreate flag)
{
    constexpr WindowsSize initialSize{ 256 };
    constexpr WindowsSize maximumSize{ 512 };

    auto handle = CreateProcessHeap(flag, initialSize, maximumSize);

    ASSERT_UNEQUAL_NULL_PTR(handle);

    ASSERT_TRUE(DestroyProcessHeap(handle));

    auto defaultHandle = CreateProcessHeap(flag, 0, 0);

    ASSERT_UNEQUAL_NULL_PTR(defaultHandle);

    ASSERT_TRUE(DestroyProcessHeap(defaultHandle));
}

void System::CreateHeapTesting::CreateHeapFailureTest()
{
    for (auto flag : heapCreateFlags)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoCreateHeapFailureTest, flag);
    }
}

void System::CreateHeapTesting::DoCreateHeapFailureTest(HeapCreate flag)
{
    constexpr WindowsSize initialSize{ numeric_limits<WindowsSize>::max() };
    constexpr WindowsSize maximumSize{ numeric_limits<WindowsSize>::max() };

    auto handle = CreateProcessHeap(flag, initialSize, maximumSize);

    ASSERT_EQUAL_NULL_PTR(handle);

    if (handle != nullptr)
    {
        ASSERT_TRUE(DestroyProcessHeap(handle));
    }
}
