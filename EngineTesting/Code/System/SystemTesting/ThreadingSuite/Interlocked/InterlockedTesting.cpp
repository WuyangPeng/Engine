///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/12 18:47)

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
