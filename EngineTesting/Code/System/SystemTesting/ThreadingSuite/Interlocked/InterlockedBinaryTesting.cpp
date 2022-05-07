///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.3 (2021/05/10 11:50)

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