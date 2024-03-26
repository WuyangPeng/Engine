/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:30)

#include "InterlockedTestingDetail.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::InterlockedTesting::InterlockedTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
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
