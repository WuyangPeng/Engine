/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 10:15)

#include "YearTesting.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/Time/Date.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::YearTesting::YearTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, YearTesting)

void CoreTools::YearTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::YearTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(YearTest);
}

void CoreTools::YearTesting::YearTest()
{
    const Year year{ 2000 };

    ASSERT_EQUAL(year.GetYear(), 2000);
}
