///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/21 23:35)

#include "ValidateHeapTesting.h"
#include "System/MemoryTools/HeapTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ValidateHeapTesting::ValidateHeapTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ValidateHeapTesting)

void System::ValidateHeapTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ValidateHeapTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ValidateHeapTest);
}

void System::ValidateHeapTesting::ValidateHeapTest()
{
    for (auto heapCreate : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(ValidateTest, heapCreate);
    }
}

void System::ValidateHeapTesting::ValidateTest(HeapCreate flag)
{
    const auto handle = CreateProcessHeap(flag, 0, 0);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(handle, "CreateProcessHeap 失败。");

    ASSERT_NOT_THROW_EXCEPTION_2(DoValidateTest, handle, flag);

    ASSERT_NOT_THROW_EXCEPTION_1(DestroyHeapTest, handle);
}

void System::ValidateHeapTesting::DoValidateTest(WindowsHandle handle, HeapCreate flag)
{
    constexpr WindowsSize size{ 50 };

    auto memory = AllocateProcessHeap(handle, flag, size);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(memory, "AllocateProcessHeap 失败。");

    ASSERT_TRUE(ValidateProcessHeap(handle, flag, memory));

    ASSERT_NOT_THROW_EXCEPTION_2(FreeHeapTest, handle, memory);
}
