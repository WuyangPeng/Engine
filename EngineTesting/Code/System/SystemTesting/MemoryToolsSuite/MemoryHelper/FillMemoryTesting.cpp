///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/14 16:55)

#include "FillMemoryTesting.h"
#include "System/MemoryTools/MemoryHelperDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::FillMemoryTesting::FillMemoryTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FillMemoryTesting)

void System::FillMemoryTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::FillMemoryTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FillMemoryTest);
}

void System::FillMemoryTesting::FillMemoryTest()
{
    int32_t fillValue = 1;

    FillMemoryToZero(fillValue);

    ASSERT_EQUAL(fillValue, 0);
}
