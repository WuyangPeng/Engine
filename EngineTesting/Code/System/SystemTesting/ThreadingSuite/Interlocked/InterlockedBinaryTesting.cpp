///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/22 19:29)

#include "InterlockedBinaryTestingDetail.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::InterlockedBinaryTesting::InterlockedBinaryTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, InterlockedBinaryTesting)

void System::InterlockedBinaryTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::InterlockedBinaryTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InterlockedBinaryTest<long>);
    ASSERT_NOT_THROW_EXCEPTION_0(InterlockedBinaryTest<uint64_t>);
}
