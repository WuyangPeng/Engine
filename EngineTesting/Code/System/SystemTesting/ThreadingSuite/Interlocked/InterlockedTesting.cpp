///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/02/01 1:04)

#include "InterlockedTestingDetail.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::InterlockedTesting::InterlockedTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, InterlockedTesting)

void System::InterlockedTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::InterlockedTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InterlockedTest<long>);
    ASSERT_NOT_THROW_EXCEPTION_0(InterlockedTest<unsigned>);
    ASSERT_NOT_THROW_EXCEPTION_0(InterlockedTest<unsigned long>);
    ASSERT_NOT_THROW_EXCEPTION_0(InterlockedTest<uint64_t>);
}
