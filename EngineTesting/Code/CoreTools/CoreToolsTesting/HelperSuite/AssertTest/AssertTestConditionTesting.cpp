///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
///	¡™œµ◊˜’ﬂ£∫94458936@qq.com
///
///	±Í◊º£∫std:c++20
///	∞Ê±æ£∫0.9.1.5 (2023/10/24 15:30)

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

    ASSERT_TRUE_USE_MESSAGE(condition, "≤‚ ‘");
    ASSERT_FALSE_USE_MESSAGE(!condition, "≤‚ ‘");
}

void CoreTools::AssertTestConditionTesting::AssertConditionFailureThrowTest()
{
    constexpr auto condition = true;

    ASSERT_TRUE_FAILURE_THROW(condition, "≤‚ ‘");
    ASSERT_FALSE_FAILURE_THROW(!condition, "≤‚ ‘");
}
