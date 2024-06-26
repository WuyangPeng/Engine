/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 21:31)

#include "AssertTestExceptionThrowTesting.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/CoreToolsTesting/HelperSuite/Detail/MacroTestEnum.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

CoreTools::AssertTestExceptionThrowTesting::AssertTestExceptionThrowTesting(const OStreamShared& stream)
    : ParentType{ stream }, failedNumber{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, AssertTestExceptionThrowTesting)

void CoreTools::AssertTestExceptionThrowTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::AssertTestExceptionThrowTesting::MainTest()
{
    failedNumber = 0;

    ASSERT_THROW_EXCEPTION_0(AssertTrueFailureThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_0(AssertFalseFailureThrowExceptionTest);

    ASSERT_THROW_EXCEPTION_0(AssertEqualFailureThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_0(AssertEqualDoNotUseMessageFailureThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_0(AssertEnumEqualFailureThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_0(AssertSignedEnumEqualFailureThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_0(AssertFloatingPointCompleteEqualFailureThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_0(AssertThreeEqualFailureThrowExceptionTest);

    ASSERT_THROW_EXCEPTION_0(AssertUnequalFailureThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_0(AssertUnequalDoNotUseMessageFailureThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_0(AssertEnumUnequalFailureThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_0(AssertSignedEnumUnequalFailureThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_0(AssertFloatingPointCompleteUnequalFailureThrowExceptionTest);

    ASSERT_THROW_EXCEPTION_0(AssertApproximateFailureThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_0(AssertApproximateUseFunctionFailureThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_0(AssertApproximateFloatZeroFailureThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_0(AssertApproximateDoubleZeroFailureThrowExceptionTest);

    ASSERT_THROW_EXCEPTION_0(AssertLessFailureThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_0(AssertEnumLessFailureThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_0(AssertSignedEnumLessFailureThrowExceptionTest);

    ASSERT_THROW_EXCEPTION_0(AssertLessEqualFailureThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_0(AssertEnumLessEqualFailureThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_0(AssertSignedEnumLessEqualFailureThrowExceptionTest);

    ASSERT_THROW_EXCEPTION_0(AssertGreaterFailureThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_0(AssertEnumGreaterFailureThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_0(AssertSignedEnumGreaterFailureThrowExceptionTest);

    ASSERT_THROW_EXCEPTION_0(AssertGreaterEqualFailureThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_0(AssertEnumGreaterEqualFailureThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_0(AssertSignedEnumGreaterEqualFailureThrowExceptionTest);

    ASSERT_THROW_EXCEPTION_0(AssertEqualNullptrFailureThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_0(AssertUnequalNullptrFailureThrowExceptionTest);

    ASSERT_THROW_EXCEPTION_0(AssertRangeFailureThrowExceptionTest);

    const auto testFailedNumber = GetFailedNumber();
    const auto testErrorNumber = GetErrorNumber();

    ResetTestData();

    ASSERT_EQUAL(failedNumber, testFailedNumber);
    ASSERT_EQUAL(0, testErrorNumber);

    ASSERT_NOT_THROW_EXCEPTION_0(TestEnd);
}

bool CoreTools::AssertTestExceptionThrowTesting::Approximate(float lhs, float rhs, float epsilon) noexcept
{
    return Mathematics::MathF::FAbs(lhs - rhs) <= epsilon;
}

void CoreTools::AssertTestExceptionThrowTesting::AssertTrueFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto condition = false;

    ASSERT_TRUE_FAILURE_THROW(condition, "测试ASSERT_TRUE未通过的情况抛出异常。存在一个正常的测试失败！");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertFalseFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto condition = true;

    ASSERT_FALSE_FAILURE_THROW(condition, "测试ASSERT_FALSE未通过的情况抛出异常。存在一个正常的测试失败！");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertEqualFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = 5;
    constexpr auto rhsExpression = 6;

    ASSERT_EQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "测试ASSERT_EQUAL未通过的情况抛出异常。存在一个正常的测试失败！");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertEqualDoNotUseMessageFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = 5;
    constexpr auto rhsExpression = 6;

    ASSERT_EQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "测试ASSERT_EQUAL未通过的情况抛出异常。存在一个正常的测试失败！");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertEnumEqualFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = MacroTestEnum::One;
    constexpr auto rhsExpression = MacroTestEnum::Two;

    ASSERT_EQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "测试ASSERT_EQUAL未通过的情况抛出异常。存在一个正常的测试失败！");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertSignedEnumEqualFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = MacroTestSignedEnum::NegativeOne;
    constexpr auto rhsExpression = MacroTestSignedEnum::Zero;

    ASSERT_EQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "测试ASSERT_SIGNED_ENUM_EQUAL未通过的情况抛出异常。存在一个正常的测试失败！");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertThreeEqualFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = 5;
    constexpr auto mhsExpression = 5;
    constexpr auto rhsExpression = 6;

    ASSERT_THREE_EQUAL_FAILURE_THROW(lhsExpression, mhsExpression, rhsExpression, "测试ASSERT_THREE_EQUAL未通过的情况抛出异常。存在一个正常的测试失败！");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertFloatingPointCompleteEqualFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = 20.0f;
    constexpr auto rhsExpression = 20.1f;

    ASSERT_FLOATING_POINT_COMPLETE_EQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "测试ASSERT_FLOATING_POINT_COMPLETE_EQUAL未通过的情况抛出异常。存在一个正常的测试失败！");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertUnequalFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = 5;
    constexpr auto rhsExpression = 5;

    ASSERT_UNEQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "测试ASSERT_UNEQUAL未通过的情况抛出异常。存在一个正常的测试失败！");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertUnequalDoNotUseMessageFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = 5;
    constexpr auto rhsExpression = 5;

    ASSERT_UNEQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "测试ASSERT_UNEQUAL未通过的情况抛出异常。存在一个正常的测试失败！");

    GetStream() << "测试ASSERT_UNEQUAL未通过的情况抛出异常。存在一个正常的测试失败！";
}

void CoreTools::AssertTestExceptionThrowTesting::AssertEnumUnequalFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = MacroTestEnum::One;
    constexpr auto rhsExpression = MacroTestEnum::One;

    ASSERT_UNEQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "测试ASSERT_UNENUM_EQUAL未通过的情况抛出异常。存在一个正常的测试失败！");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertSignedEnumUnequalFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = MacroTestSignedEnum::NegativeOne;
    constexpr auto rhsExpression = MacroTestSignedEnum::NegativeOne;

    ASSERT_UNEQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "测试ASSERT_SIGNED_ENUM_UNEQUAL未通过的情况抛出异常。存在一个正常的测试失败！");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertFloatingPointCompleteUnequalFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = 20.0f;
    constexpr auto rhsExpression = 20.0f;

    ASSERT_FLOATING_POINT_COMPLETE_UNEQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "测试ASSERT_FLOATING_POINT_COMPLETE_UNEQUAL未通过的情况抛出异常。存在一个正常的测试失败！");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertApproximateFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = 20.0f;
    constexpr auto rhsExpression = 20.1f;

    ASSERT_APPROXIMATE_FAILURE_THROW(lhsExpression, rhsExpression, 1e-6f, "测试ASSERT_APPROXIMATE未通过的情况抛出异常。存在一个正常的测试失败！");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertApproximateFloatZeroFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto expression = 10.0f;

    ASSERT_APPROXIMATE_FLOAT_ZERO_FAILURE_THROW(expression, "测试ASSERT_APPROXIMATE_FLOAT_ZERO未通过的情况抛出异常。存在一个正常的测试失败！");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertApproximateDoubleZeroFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto expression = 11.0;

    ASSERT_APPROXIMATE_DOUBLE_ZERO_FAILURE_THROW(expression, "测试ASSERT_APPROXIMATE_DOUBLE_ZERO未通过的情况抛出异常。存在一个正常的测试失败！");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertApproximateUseFunctionFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = 20.0f;
    constexpr auto rhsExpression = 20.1f;

    ASSERT_APPROXIMATE_USE_FUNCTION_FAILURE_THROW(ClassType::Approximate, lhsExpression, rhsExpression, 1e-6f, "测试ASSERT_APPROXIMATE_USE_FUNCTION未通过的情况抛出异常。存在一个正常的测试失败！");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertLessFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = 5;
    constexpr auto rhsExpression = 5;

    ASSERT_LESS_FAILURE_THROW(lhsExpression, rhsExpression, "测试ASSERT_LESS未通过的情况抛出异常。存在一个正常的测试失败！");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertEnumLessFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = MacroTestEnum::One;
    constexpr auto rhsExpression = MacroTestEnum::One;

    ASSERT_LESS_FAILURE_THROW(lhsExpression, rhsExpression, "测试ASSERT_LESS未通过的情况抛出异常。存在一个正常的测试失败！");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertSignedEnumLessFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = MacroTestSignedEnum::NegativeOne;
    constexpr auto rhsExpression = MacroTestSignedEnum::NegativeOne;

    ASSERT_LESS_FAILURE_THROW(lhsExpression, rhsExpression, "测试ASSERT_SIGNED_ENUM_LESS未通过的情况抛出异常。存在一个正常的测试失败！");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertLessEqualFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = 5;
    constexpr auto rhsExpression = 4;

    ASSERT_LESS_EQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "测试ASSERT_LESS_EQUAL未通过的情况抛出异常。存在一个正常的测试失败！");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertEnumLessEqualFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = MacroTestEnum::Two;
    constexpr auto rhsExpression = MacroTestEnum::One;

    ASSERT_LESS_EQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "测试ASSERT_LESS_EQUAL未通过的情况抛出异常。存在一个正常的测试失败！");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertSignedEnumLessEqualFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = MacroTestSignedEnum::Zero;
    constexpr auto rhsExpression = MacroTestSignedEnum::NegativeOne;

    ASSERT_LESS_EQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "测试ASSERT_SIGNED_ENUM_LESS_EQUAL未通过的情况抛出异常。存在一个正常的测试失败！");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertGreaterFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = 3;
    constexpr auto rhsExpression = 4;

    ASSERT_GREATER_FAILURE_THROW(lhsExpression, rhsExpression, "测试ASSERT_GREATER未通过的情况抛出异常。存在一个正常的测试失败！");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertEnumGreaterFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = MacroTestEnum::One;
    constexpr auto rhsExpression = MacroTestEnum::Two;

    ASSERT_GREATER_FAILURE_THROW(lhsExpression, rhsExpression, "测试ASSERT_GREATER未通过的情况抛出异常。存在一个正常的测试失败！");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertSignedEnumGreaterFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = MacroTestSignedEnum::NegativeOne;
    constexpr auto rhsExpression = MacroTestSignedEnum::Zero;

    ASSERT_GREATER_FAILURE_THROW(lhsExpression, rhsExpression, "测试ASSERT_SIGNED_ENUM_GREATER未通过的情况抛出异常。存在一个正常的测试失败！");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertGreaterEqualFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = 3;
    constexpr auto rhsExpression = 4;

    ASSERT_GREATER_EQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "测试ASSERT_GREATER_EQUAL未通过的情况抛出异常。存在一个正常的测试失败！");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertEnumGreaterEqualFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = MacroTestEnum::One;
    constexpr auto rhsExpression = MacroTestEnum::Two;

    ASSERT_GREATER_EQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "测试ASSERT_GREATER_EQUAL未通过的情况抛出异常。存在一个正常的测试失败！");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertSignedEnumGreaterEqualFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = MacroTestSignedEnum::NegativeOne;
    constexpr auto rhsExpression = MacroTestSignedEnum::Zero;

    ASSERT_GREATER_EQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "测试ASSERT_SIGNED_ENUM_GREATER_EQUAL未通过的情况抛出异常。存在一个正常的测试失败！");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertEqualNullptrFailureThrowExceptionTest()
{
    ++failedNumber;

    auto value = 0;
    const auto ptr = &value;

    ASSERT_EQUAL_NULL_PTR_FAILURE_THROW(ptr, "测试ASSERT_EQUAL_NULL_PTR未通过的情况抛出异常。存在一个正常的测试失败！");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertUnequalNullptrFailureThrowExceptionTest()
{
    ++failedNumber;

    int* ptr{ nullptr };

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(ptr, "测试ASSERT_UNEQUAL_NULL_PTR未通过的情况抛出异常。存在一个正常的测试失败！");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertRangeFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = 3;
    constexpr auto mhsExpression = 4;
    constexpr auto rhsExpression = 2;

    ASSERT_RANGE_FAILURE_THROW(mhsExpression, lhsExpression, rhsExpression, "测试ASSERT_RANGE未通过的情况抛出异常。存在一个正常的测试失败！");
}

void CoreTools::AssertTestExceptionThrowTesting::PrintTipsMessage()
{
    GetStream() << "这个测试会出现一些正常的测试失败。\n";

    System::SystemPause();
}

void CoreTools::AssertTestExceptionThrowTesting::TestEnd()
{
    GetStream() << "测试结束，验证测试失败是否正确。\n";

    System::SystemPause();
}
