///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.2.5 (2021/11/03 21:08)

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
