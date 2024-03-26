/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/12 18:30)

#include "InterlockedSubtractTestingDetail.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::InterlockedSubtractTesting::InterlockedSubtractTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, InterlockedSubtractTesting)

void System::InterlockedSubtractTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::InterlockedSubtractTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InterlockedSubtractTest<unsigned>);
    ASSERT_NOT_THROW_EXCEPTION_0(InterlockedSubtractTest<unsigned long>);
    ASSERT_NOT_THROW_EXCEPTION_0(InterlockedSubtractTest<uint64_t>);
}
