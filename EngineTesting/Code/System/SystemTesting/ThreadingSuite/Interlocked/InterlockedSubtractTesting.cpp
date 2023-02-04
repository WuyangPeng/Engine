///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/01 1:04)

#include "InterlockedSubtractTestingDetail.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::InterlockedSubtractTesting::InterlockedSubtractTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
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
