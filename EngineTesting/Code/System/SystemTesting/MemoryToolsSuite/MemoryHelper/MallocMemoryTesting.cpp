///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/04 21:21)

#include "MallocMemoryTesting.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::MallocMemoryTesting::MallocMemoryTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, MallocMemoryTesting)

void System::MallocMemoryTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::MallocMemoryTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MallocMemoryTest);
}

void System::MallocMemoryTesting::MallocMemoryTest()
{
    auto memory = MallocMemory(256);
    ASSERT_UNEQUAL_NULL_PTR(memory);

    FreeMemory(memory);
}
