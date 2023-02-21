///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.2 (2023/02/06 11:40)

#include "AssertTestRangeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::AssertTestRangeTesting::AssertTestRangeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, AssertTestRangeTesting)

void CoreTools::AssertTestRangeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::AssertTestRangeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AssertRangeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssertRangeMessageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssertRangeFailureThrowTest);
}

void CoreTools::AssertTestRangeTesting::AssertRangeTest()
{
    constexpr auto lhsExpression = 3;
    constexpr auto mhsExpression = 4;
    constexpr auto rhsExpression = 5;

    ASSERT_RANGE(mhsExpression, lhsExpression, rhsExpression);
}

void CoreTools::AssertTestRangeTesting::AssertRangeMessageTest()
{
    constexpr auto lhsExpression = 3;
    constexpr auto mhsExpression = 4;
    constexpr auto rhsExpression = 5;

    ASSERT_RANGE_USE_MESSAGE(mhsExpression, lhsExpression, rhsExpression, "����");
}

void CoreTools::AssertTestRangeTesting::AssertRangeFailureThrowTest()
{
    constexpr auto lhsExpression = 3;
    constexpr auto mhsExpression = 4;
    constexpr auto rhsExpression = 5;

    ASSERT_RANGE_FAILURE_THROW(mhsExpression, lhsExpression, rhsExpression, "����");
}
