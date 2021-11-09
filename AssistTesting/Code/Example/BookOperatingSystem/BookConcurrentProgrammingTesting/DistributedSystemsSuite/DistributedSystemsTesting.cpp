///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.2.5 (2021/11/03 21:08)

#include "DistributedSystemsTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookOperatingSystem/DistributedSystems/Helper/DistributedSystemsClassInvariantMacro.h"

BookConcurrentProgramming::DistributedSystems::DistributedSystemsTesting::DistributedSystemsTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DISTRIBUTED_SYSTEMS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookConcurrentProgramming::DistributedSystems, DistributedSystemsTesting)

void BookConcurrentProgramming::DistributedSystems::DistributedSystemsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookConcurrentProgramming::DistributedSystems::DistributedSystemsTesting::MainTest() noexcept
{
}
