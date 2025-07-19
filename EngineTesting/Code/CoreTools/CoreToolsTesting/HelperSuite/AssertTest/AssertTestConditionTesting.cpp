/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 21:31)

#include "AssertTestConditionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::AssertTestConditionTesting::AssertTestConditionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, AssertTestConditionTesting)

void CoreTools::AssertTestConditionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::AssertTestConditionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AssertConditionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssertConditionMessageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssertConditionFailureThrowTest);
}

void CoreTools::AssertTestConditionTesting::AssertConditionTest()
{
    constexpr auto condition = true;

    ASSERT_TRUE(condition);
    ASSERT_FALSE(!condition);
}

void CoreTools::AssertTestConditionTesting::AssertConditionMessageTest()
{
    constexpr auto condition = true;

    ASSERT_TRUE_USE_MESSAGE(condition, "测试");
    ASSERT_FALSE_USE_MESSAGE(!condition, "测试");
}

void CoreTools::AssertTestConditionTesting::AssertConditionFailureThrowTest()
{
    constexpr auto condition = true;

    ASSERT_TRUE_FAILURE_THROW(condition, "测试");
    ASSERT_FALSE_FAILURE_THROW(!condition, "测试");
}
