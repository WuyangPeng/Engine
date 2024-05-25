/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 10:12)

#include "DayTesting.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/Time/Date.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::DayTesting::DayTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, DayTesting)

void CoreTools::DayTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::DayTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DayTest);
}

void CoreTools::DayTesting::DayTest()
{
    const Day day{ 11 };

    ASSERT_EQUAL(day.GetDay(), 11);
}
