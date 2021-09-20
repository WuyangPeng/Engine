///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
///	¡™œµ◊˜’ﬂ£∫94458936@qq.com
///
///	±Í◊º£∫std:c++17
///	“˝«Ê≤‚ ‘∞Ê±æ£∫0.7.2.1 (2021/08/02 19:33)

#include "AssertTestOperatorTesting.h"
#include "CoreTools/CoreToolsTesting/HelperSuite/Detail/MacroTestEnum.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::AssertTestOperatorTesting::AssertTestOperatorTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, AssertTestOperatorTesting)

void CoreTools::AssertTestOperatorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::AssertTestOperatorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AssertOperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssertOperatorMessageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssertOperatorFailureThrowTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssertOperatorDoNotUseMessageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssertOperatorDoNotUseMessageFailureThrowTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssertEnumOperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssertEnumOperatorMessageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssertEnumOperatorFailureThrowTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssertSignedEnumOperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssertSignedEnumOperatorMessageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssertSignedEnumOperatorFailureThrowTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssertFloatingPointCompleteOperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssertFloatingPointCompleteOperatorMessageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssertFloatingPointCompleteOperatorFailureThrowTest);
}

void CoreTools::AssertTestOperatorTesting::AssertOperatorTest()
{
    constexpr auto lhsExpression = 5;
    constexpr auto rhsExpression = 6;

    ASSERT_EQUAL(lhsExpression, lhsExpression);
    ASSERT_UNEQUAL(lhsExpression, rhsExpression);
    ASSERT_LESS(lhsExpression, rhsExpression);
    ASSERT_LESS_EQUAL(lhsExpression, rhsExpression);
    ASSERT_GREATER(rhsExpression, lhsExpression);
    ASSERT_GREATER_EQUAL(rhsExpression, lhsExpression);
}

void CoreTools::AssertTestOperatorTesting::AssertOperatorMessageTest()
{
    constexpr auto lhsExpression = 5;
    constexpr auto rhsExpression = 6;

    ASSERT_EQUAL_USE_MESSAGE(lhsExpression, lhsExpression, "≤‚ ‘");
    ASSERT_UNEQUAL_USE_MESSAGE(lhsExpression, rhsExpression, "≤‚ ‘");
    ASSERT_LESS_USE_MESSAGE(lhsExpression, rhsExpression, "≤‚ ‘");
    ASSERT_LESS_EQUAL_USE_MESSAGE(lhsExpression, rhsExpression, "≤‚ ‘");
    ASSERT_GREATER_USE_MESSAGE(rhsExpression, lhsExpression, "≤‚ ‘");
    ASSERT_GREATER_EQUAL_USE_MESSAGE(rhsExpression, lhsExpression, "≤‚ ‘");
}

void CoreTools::AssertTestOperatorTesting::AssertOperatorFailureThrowTest()
{
    constexpr auto lhsExpression = 5;
    constexpr auto rhsExpression = 6;

    ASSERT_EQUAL_FAILURE_THROW(lhsExpression, lhsExpression, "≤‚ ‘");
    ASSERT_UNEQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "≤‚ ‘");
    ASSERT_LESS_FAILURE_THROW(lhsExpression, rhsExpression, "≤‚ ‘");
    ASSERT_LESS_EQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "≤‚ ‘");
    ASSERT_GREATER_FAILURE_THROW(rhsExpression, lhsExpression, "≤‚ ‘");
    ASSERT_GREATER_EQUAL_FAILURE_THROW(rhsExpression, lhsExpression, "≤‚ ‘");
}

void CoreTools::AssertTestOperatorTesting::AssertOperatorDoNotUseMessageTest()
{
    constexpr auto lhsExpression = 5;
    constexpr auto rhsExpression = 6;

    ASSERT_EQUAL_DO_NOT_USE_MESSAGE(lhsExpression, lhsExpression);
    ASSERT_UNEQUAL_DO_NOT_USE_MESSAGE(lhsExpression, rhsExpression);
}

void CoreTools::AssertTestOperatorTesting::AssertOperatorDoNotUseMessageFailureThrowTest()
{
    constexpr auto lhsExpression = 5;
    constexpr auto rhsExpression = 6;

    ASSERT_EQUAL_DO_NOT_USE_MESSAGE_FAILURE_THROW(lhsExpression, lhsExpression);
    ASSERT_UNEQUAL_DO_NOT_USE_MESSAGE_FAILURE_THROW(lhsExpression, rhsExpression);
}

void CoreTools::AssertTestOperatorTesting::AssertEnumOperatorTest()
{
    constexpr auto lhsExpression = MacroTestEnum::One;
    constexpr auto rhsExpression = MacroTestEnum::Two;

    ASSERT_ENUM_EQUAL(lhsExpression, lhsExpression);
    ASSERT_ENUM_UNEQUAL(lhsExpression, rhsExpression);
    ASSERT_ENUM_LESS(lhsExpression, rhsExpression);
    ASSERT_ENUM_LESS_EQUAL(lhsExpression, rhsExpression);
    ASSERT_ENUM_GREATER(rhsExpression, lhsExpression);
    ASSERT_ENUM_GREATER_EQUAL(rhsExpression, lhsExpression);
}

void CoreTools::AssertTestOperatorTesting::AssertEnumOperatorMessageTest()
{
    constexpr auto lhsExpression = MacroTestEnum::One;
    constexpr auto rhsExpression = MacroTestEnum::Two;

    ASSERT_ENUM_EQUAL_USE_MESSAGE(lhsExpression, lhsExpression, "≤‚ ‘");
    ASSERT_ENUM_UNEQUAL_USE_MESSAGE(lhsExpression, rhsExpression, "≤‚ ‘");
    ASSERT_ENUM_LESS_USE_MESSAGE(lhsExpression, rhsExpression, "≤‚ ‘");
    ASSERT_ENUM_LESS_EQUAL_USE_MESSAGE(lhsExpression, rhsExpression, "≤‚ ‘");
    ASSERT_ENUM_GREATER_USE_MESSAGE(rhsExpression, lhsExpression, "≤‚ ‘");
    ASSERT_ENUM_GREATER_EQUAL_USE_MESSAGE(rhsExpression, lhsExpression, "≤‚ ‘");
}

void CoreTools::AssertTestOperatorTesting::AssertEnumOperatorFailureThrowTest()
{
    constexpr auto lhsExpression = MacroTestEnum::One;
    constexpr auto rhsExpression = MacroTestEnum::Two;

    ASSERT_ENUM_EQUAL_FAILURE_THROW(lhsExpression, lhsExpression, "≤‚ ‘");
    ASSERT_ENUM_UNEQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "≤‚ ‘");
    ASSERT_ENUM_LESS_FAILURE_THROW(lhsExpression, rhsExpression, "≤‚ ‘");
    ASSERT_ENUM_LESS_EQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "≤‚ ‘");
    ASSERT_ENUM_GREATER_FAILURE_THROW(rhsExpression, lhsExpression, "≤‚ ‘");
    ASSERT_ENUM_GREATER_EQUAL_FAILURE_THROW(rhsExpression, lhsExpression, "≤‚ ‘");
}

void CoreTools::AssertTestOperatorTesting::AssertSignedEnumOperatorTest()
{
    constexpr auto lhsExpression = MacroTestSignedEnum::NegativeOne;
    constexpr auto rhsExpression = MacroTestSignedEnum::Zero;

    ASSERT_ENUM_EQUAL(lhsExpression, lhsExpression);
    ASSERT_ENUM_UNEQUAL(lhsExpression, rhsExpression);
    ASSERT_ENUM_LESS(lhsExpression, rhsExpression);
    ASSERT_ENUM_LESS_EQUAL(lhsExpression, rhsExpression);
    ASSERT_ENUM_GREATER(rhsExpression, lhsExpression);
    ASSERT_ENUM_GREATER_EQUAL(rhsExpression, lhsExpression);
}

void CoreTools::AssertTestOperatorTesting::AssertSignedEnumOperatorMessageTest()
{
    constexpr auto lhsExpression = MacroTestSignedEnum::NegativeOne;
    constexpr auto rhsExpression = MacroTestSignedEnum::Zero;

    ASSERT_ENUM_EQUAL_USE_MESSAGE(lhsExpression, lhsExpression, "≤‚ ‘");
    ASSERT_ENUM_UNEQUAL_USE_MESSAGE(lhsExpression, rhsExpression, "≤‚ ‘");
    ASSERT_ENUM_LESS_USE_MESSAGE(lhsExpression, rhsExpression, "≤‚ ‘");
    ASSERT_ENUM_LESS_EQUAL_USE_MESSAGE(lhsExpression, rhsExpression, "≤‚ ‘");
    ASSERT_ENUM_GREATER_USE_MESSAGE(rhsExpression, lhsExpression, "≤‚ ‘");
    ASSERT_ENUM_GREATER_EQUAL_USE_MESSAGE(rhsExpression, lhsExpression, "≤‚ ‘");
}

void CoreTools::AssertTestOperatorTesting::AssertSignedEnumOperatorFailureThrowTest()
{
    constexpr auto lhsExpression = MacroTestSignedEnum::NegativeOne;
    constexpr auto rhsExpression = MacroTestSignedEnum::Zero;

    ASSERT_ENUM_EQUAL_FAILURE_THROW(lhsExpression, lhsExpression, "≤‚ ‘");
    ASSERT_ENUM_UNEQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "≤‚ ‘");
    ASSERT_ENUM_LESS_FAILURE_THROW(lhsExpression, rhsExpression, "≤‚ ‘");
    ASSERT_ENUM_LESS_EQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "≤‚ ‘");
    ASSERT_ENUM_GREATER_FAILURE_THROW(rhsExpression, lhsExpression, "≤‚ ‘");
    ASSERT_ENUM_GREATER_EQUAL_FAILURE_THROW(rhsExpression, lhsExpression, "≤‚ ‘");
}

void CoreTools::AssertTestOperatorTesting::AssertThreeOperatorTest()
{
    constexpr auto lhsExpression = 5;
    constexpr auto mhsExpression = 5;
    constexpr auto rhsExpression = 5;

    ASSERT_THREE_EQUAL(lhsExpression, mhsExpression, rhsExpression);
}

void CoreTools::AssertTestOperatorTesting::AssertThreeOperatorMessageTest()
{
    constexpr auto lhsExpression = 5;
    constexpr auto mhsExpression = 5;
    constexpr auto rhsExpression = 5;

    ASSERT_THREE_EQUAL_USE_MESSAGE(lhsExpression, mhsExpression, rhsExpression, "≤‚ ‘");
}

void CoreTools::AssertTestOperatorTesting::AssertThreeOperatorFailureThrowTest()
{
    constexpr auto lhsExpression = 5;
    constexpr auto mhsExpression = 5;
    constexpr auto rhsExpression = 5;

    ASSERT_THREE_EQUAL_FAILURE_THROW(lhsExpression, mhsExpression, rhsExpression, "≤‚ ‘");
}

void CoreTools::AssertTestOperatorTesting::AssertFloatingPointCompleteOperatorTest()
{
    constexpr auto lhsExpression = 20.0f;
    constexpr auto rhsExpression = 20.1f;

    ASSERT_FLOATING_POINT_COMPLETE_EQUAL(lhsExpression, lhsExpression);
    ASSERT_FLOATING_POINT_COMPLETE_UNEQUAL(lhsExpression, rhsExpression);
}

void CoreTools::AssertTestOperatorTesting::AssertFloatingPointCompleteOperatorMessageTest()
{
    constexpr auto lhsExpression = 20.0f;
    constexpr auto rhsExpression = 20.1f;

    ASSERT_FLOATING_POINT_COMPLETE_EQUAL_USE_MESSAGE(lhsExpression, lhsExpression, "≤‚ ‘");
    ASSERT_FLOATING_POINT_COMPLETE_UNEQUAL_USE_MESSAGE(lhsExpression, rhsExpression, "≤‚ ‘");
}

void CoreTools::AssertTestOperatorTesting::AssertFloatingPointCompleteOperatorFailureThrowTest()
{
    constexpr auto lhsExpression = 20.0f;
    constexpr auto rhsExpression = 20.1f;

    ASSERT_FLOATING_POINT_COMPLETE_EQUAL_FAILURE_THROW(lhsExpression, lhsExpression, "≤‚ ‘");
    ASSERT_FLOATING_POINT_COMPLETE_UNEQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "≤‚ ‘");
}