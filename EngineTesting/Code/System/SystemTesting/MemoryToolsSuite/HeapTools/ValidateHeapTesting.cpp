///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/04/20 15:23)

#include "ValidateHeapTesting.h"
#include "System/MemoryTools/Flags/HeapToolsFlags.h"
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
    ASSERT_NOT_THROW_EXCEPTION_1(ValidateTest, HeapCreate::Default);
    ASSERT_NOT_THROW_EXCEPTION_1(ValidateTest, HeapCreate::NoSerialize);
}

void System::ValidateHeapTesting::ValidateTest(HeapCreate flag)
{
    auto handle = CreateProcessHeap(flag, 0, 0);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(handle, "CreateProcessHeap 失败。");

    ASSERT_NOT_THROW_EXCEPTION_2(DoValidateTest, handle, flag);

    ASSERT_TRUE(DestroyProcessHeap(handle));
}

void System::ValidateHeapTesting::DoValidateTest(WindowsHandle handle, HeapCreate flag)
{
    constexpr WindowsSize size{ 50 };

    auto memory = AllocateProcessHeap(handle, flag, size);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(memory, "AllocateProcessHeap 失败。");

    ASSERT_TRUE(ValidateProcessHeap(handle, flag, memory));

    ASSERT_TRUE(FreeProcessHeap(handle, flag, memory));
}
