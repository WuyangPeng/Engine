///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.2 (2021/04/20 15:23)

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
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(handle, "CreateProcessHeap ʧ�ܡ�");

    ASSERT_NOT_THROW_EXCEPTION_2(DoValidateTest, handle, flag);

    ASSERT_TRUE(DestroyProcessHeap(handle));
}

void System::ValidateHeapTesting::DoValidateTest(WindowsHandle handle, HeapCreate flag)
{
    constexpr WindowsSize size{ 50 };

    auto memory = AllocateProcessHeap(handle, flag, size);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(memory, "AllocateProcessHeap ʧ�ܡ�");

    ASSERT_TRUE(ValidateProcessHeap(handle, flag, memory));

    ASSERT_TRUE(FreeProcessHeap(handle, flag, memory));
}
