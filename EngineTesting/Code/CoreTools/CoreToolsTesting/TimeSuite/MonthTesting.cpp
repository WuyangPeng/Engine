/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 10:13)

#include "MonthTesting.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/Time/Date.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::MonthTesting::MonthTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, MonthTesting)

void CoreTools::MonthTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::MonthTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MonthTest);
}

void CoreTools::MonthTesting::MonthTest()
{
    ASSERT_EQUAL(Month::Jan().GetMonth(), 1);
    ASSERT_EQUAL(Month::Feb().GetMonth(), 2);
    ASSERT_EQUAL(Month::Mar().GetMonth(), 3);
    ASSERT_EQUAL(Month::Apr().GetMonth(), 4);
    ASSERT_EQUAL(Month::May().GetMonth(), 5);
    ASSERT_EQUAL(Month::Jun().GetMonth(), 6);
    ASSERT_EQUAL(Month::Jul().GetMonth(), 7);
    ASSERT_EQUAL(Month::Aug().GetMonth(), 8);
    ASSERT_EQUAL(Month::Sep().GetMonth(), 9);
    ASSERT_EQUAL(Month::Oct().GetMonth(), 10);
    ASSERT_EQUAL(Month::Nov().GetMonth(), 11);
    ASSERT_EQUAL(Month::Dec().GetMonth(), 12);
}
