///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/25 16:45)

#include "DateTesting.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/Time/Date.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::DateTesting::DateTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, DateTesting)

void CoreTools::DateTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::DateTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DateTest);
}

void CoreTools::DateTesting::DateTest()
{
    const Date date{ Year{ 2000 }, Month::Apr(), Day{ 11 } };

    ASSERT_EQUAL(date.GetYear().GetYear(), 2000);
    ASSERT_EQUAL(date.GetMonth().GetMonth(), Month::Apr().GetMonth());
    ASSERT_EQUAL(date.GetDay().GetDay(), 11);
}
