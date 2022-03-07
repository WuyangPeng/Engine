///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/02 16:37)

#include "AssertTestExceptionThrowTesting.h"
#include "CoreTools/CoreToolsTesting/HelperSuite/Detail/MacroTestEnum.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

using std::string;

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
    ASSERT_THROW_EXCEPTION_0(AssertSignedEqualFailureThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_0(AssertFloatingPointCompleteEquallFailureThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_0(AssertUnequalFailureThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_0(AssertUnequalDoNotUseMessageFailureThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_0(AssertEnumUnequalFailureThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_0(AssertSignedUnequalFailureThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_0(AssertFloatingPointCompleteUnequalFailureThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_0(AssertApproximateFailureThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_0(AssertApproximateUseFunctionFailureThrowExceptionTest);
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
    ASSERT_THROW_EXCEPTION_0(AssertEnumLessGreaterEqualFailureThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_0(AssertSignedEnumGreaterEqualFailureThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_0(AssertEqualNullptrFailureThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_0(AssertUnequalNullptrFailureThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_0(AssertRangeFailureThrowExceptionTest);

    const auto testFailedNumber = GetFailedNumber();
    const auto testErrorNumber = GetErrorNumber();

    ResetTestData();

    ASSERT_EQUAL(failedNumber, testFailedNumber);
    ASSERT_EQUAL(0, testErrorNumber);
}

bool CoreTools::AssertTestExceptionThrowTesting::Approximate(float lhs, float rhs, float epsilon) noexcept
{
    return Mathematics::MathF::FAbs(lhs - rhs) <= epsilon;
}

void CoreTools::AssertTestExceptionThrowTesting::AssertTrueFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto condition = false;

    ASSERT_TRUE_FAILURE_THROW(condition, "����ASSERT_TRUEδͨ��������׳��쳣������һ�������Ĳ���ʧ�ܣ�");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertFalseFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto condition = true;

    ASSERT_FALSE_FAILURE_THROW(condition, "����ASSERT_FALSEδͨ��������׳��쳣������һ�������Ĳ���ʧ�ܣ�");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertEqualFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = 5;
    constexpr auto rhsExpression = 6;

    ASSERT_EQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "����ASSERT_EQUALδͨ��������׳��쳣������һ�������Ĳ���ʧ�ܣ�");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertEqualDoNotUseMessageFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = 5;
    constexpr auto rhsExpression = 6;

    ASSERT_EQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "����ASSERT_EQUALδͨ��������׳��쳣������һ�������Ĳ���ʧ�ܣ�");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertEnumEqualFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = MacroTestEnum::One;
    constexpr auto rhsExpression = MacroTestEnum::Two;

    ASSERT_ENUM_EQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "����ASSERT_ENUM_EQUALδͨ��������׳��쳣������һ�������Ĳ���ʧ�ܣ�");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertSignedEqualFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = MacroTestSignedEnum::NegativeOne;
    constexpr auto rhsExpression = MacroTestSignedEnum::Zero;

    ASSERT_ENUM_EQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "����ASSERT_SIGNED_ENUM_EQUALδͨ��������׳��쳣������һ�������Ĳ���ʧ�ܣ�");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertThreeEqualFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = 5;
    constexpr auto mhsExpression = 5;
    constexpr auto rhsExpression = 6;

    ASSERT_THREE_EQUAL_FAILURE_THROW(lhsExpression, mhsExpression, rhsExpression, "����ASSERT_THREE_EQUALδͨ��������׳��쳣������һ�������Ĳ���ʧ�ܣ�");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertFloatingPointCompleteEquallFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = 20.0f;
    constexpr auto rhsExpression = 20.1f;

    ASSERT_FLOATING_POINT_COMPLETE_EQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "����ASSERT_FLOATING_POINT_COMPLETE_EQUALδͨ��������׳��쳣������һ�������Ĳ���ʧ�ܣ�");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertUnequalFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = 5;
    constexpr auto rhsExpression = 5;

    ASSERT_UNEQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "����ASSERT_UNEQUALδͨ��������׳��쳣������һ�������Ĳ���ʧ�ܣ�");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertUnequalDoNotUseMessageFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = 5;
    constexpr auto rhsExpression = 5;

    ASSERT_UNEQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "����ASSERT_UNEQUALδͨ��������׳��쳣������һ�������Ĳ���ʧ�ܣ�");

    GetStream() << "����ASSERT_UNEQUALδͨ��������׳��쳣������һ�������Ĳ���ʧ�ܣ�";
}

void CoreTools::AssertTestExceptionThrowTesting::AssertEnumUnequalFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = MacroTestEnum::One;
    constexpr auto rhsExpression = MacroTestEnum::One;

    ASSERT_ENUM_UNEQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "����ASSERT_UNENUM_EQUALδͨ��������׳��쳣������һ�������Ĳ���ʧ�ܣ�");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertSignedUnequalFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = MacroTestSignedEnum::NegativeOne;
    constexpr auto rhsExpression = MacroTestSignedEnum::NegativeOne;

    ASSERT_ENUM_UNEQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "����ASSERT_SIGNED_ENUM_UNEQUALδͨ��������׳��쳣������һ�������Ĳ���ʧ�ܣ�");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertFloatingPointCompleteUnequalFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = 20.0f;
    constexpr auto rhsExpression = 20.0f;

    ASSERT_FLOATING_POINT_COMPLETE_UNEQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "����ASSERT_FLOATING_POINT_COMPLETE_UNEQUALδͨ��������׳��쳣������һ�������Ĳ���ʧ�ܣ�");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertApproximateFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = 20.0f;
    constexpr auto rhsExpression = 20.1f;

    ASSERT_APPROXIMATE_FAILURE_THROW(lhsExpression, rhsExpression, 1e-6f, "����ASSERT_APPROXIMATEδͨ��������׳��쳣������һ�������Ĳ���ʧ�ܣ�");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertApproximateUseFunctionFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = 20.0f;
    constexpr auto rhsExpression = 20.1f;

    ASSERT_APPROXIMATE_USE_FUNCTION_FAILURE_THROW(ClassType::Approximate, lhsExpression, rhsExpression, 1e-6f, "����ASSERT_APPROXIMATE_USE_FUNCTIONδͨ��������׳��쳣������һ�������Ĳ���ʧ�ܣ�");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertLessFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = 5;
    constexpr auto rhsExpression = 5;

    ASSERT_LESS_FAILURE_THROW(lhsExpression, rhsExpression, "����ASSERT_LESSδͨ��������׳��쳣������һ�������Ĳ���ʧ�ܣ�");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertEnumLessFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = MacroTestEnum::One;
    constexpr auto rhsExpression = MacroTestEnum::One;

    ASSERT_ENUM_LESS_FAILURE_THROW(lhsExpression, rhsExpression, "����ASSERT_ENUM_LESSδͨ��������׳��쳣������һ�������Ĳ���ʧ�ܣ�");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertSignedEnumLessFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = MacroTestSignedEnum::NegativeOne;
    constexpr auto rhsExpression = MacroTestSignedEnum::NegativeOne;

    ASSERT_ENUM_LESS_FAILURE_THROW(lhsExpression, rhsExpression, "����ASSERT_SIGNED_ENUM_LESSδͨ��������׳��쳣������һ�������Ĳ���ʧ�ܣ�");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertLessEqualFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = 5;
    constexpr auto rhsExpression = 4;

    ASSERT_LESS_EQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "����ASSERT_LESS_EQUALδͨ��������׳��쳣������һ�������Ĳ���ʧ�ܣ�");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertEnumLessEqualFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = MacroTestEnum::Two;
    constexpr auto rhsExpression = MacroTestEnum::One;

    ASSERT_ENUM_LESS_EQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "����ASSERT_ENUM_LESS_EQUALδͨ��������׳��쳣������һ�������Ĳ���ʧ�ܣ�");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertSignedEnumLessEqualFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = MacroTestSignedEnum::Zero;
    constexpr auto rhsExpression = MacroTestSignedEnum::NegativeOne;

    ASSERT_ENUM_LESS_EQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "����ASSERT_SIGNED_ENUM_LESS_EQUALδͨ��������׳��쳣������һ�������Ĳ���ʧ�ܣ�");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertGreaterFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = 3;
    constexpr auto rhsExpression = 4;

    ASSERT_GREATER_FAILURE_THROW(lhsExpression, rhsExpression, "����ASSERT_GREATERδͨ��������׳��쳣������һ�������Ĳ���ʧ�ܣ�");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertEnumGreaterFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = MacroTestEnum::One;
    constexpr auto rhsExpression = MacroTestEnum::Two;

    ASSERT_ENUM_GREATER_FAILURE_THROW(lhsExpression, rhsExpression, "����ASSERT_ENUM_GREATERδͨ��������׳��쳣������һ�������Ĳ���ʧ�ܣ�");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertSignedEnumGreaterFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = MacroTestSignedEnum::NegativeOne;
    constexpr auto rhsExpression = MacroTestSignedEnum::Zero;

    ASSERT_ENUM_GREATER_FAILURE_THROW(lhsExpression, rhsExpression, "����ASSERT_SIGNED_ENUM_GREATERδͨ��������׳��쳣������һ�������Ĳ���ʧ�ܣ�");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertGreaterEqualFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = 3;
    constexpr auto rhsExpression = 4;

    ASSERT_GREATER_EQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "����ASSERT_GREATER_EQUALδͨ��������׳��쳣������һ�������Ĳ���ʧ�ܣ�");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertEnumLessGreaterEqualFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = MacroTestEnum::One;
    constexpr auto rhsExpression = MacroTestEnum::Two;

    ASSERT_ENUM_GREATER_EQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "����ASSERT_ENUM_GREATER_EQUALδͨ��������׳��쳣������һ�������Ĳ���ʧ�ܣ�");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertSignedEnumGreaterEqualFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = MacroTestSignedEnum::NegativeOne;
    constexpr auto rhsExpression = MacroTestSignedEnum::Zero;

    ASSERT_ENUM_GREATER_EQUAL_FAILURE_THROW(lhsExpression, rhsExpression, "����ASSERT_SIGNED_ENUM_GREATER_EQUALδͨ��������׳��쳣������һ�������Ĳ���ʧ�ܣ�");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertEqualNullptrFailureThrowExceptionTest()
{
    ++failedNumber;

    auto value = 0;
    auto ptr = &value;

    ASSERT_EQUAL_NULL_PTR_FAILURE_THROW(ptr, "����ASSERT_EQUAL_NULL_PTRδͨ��������׳��쳣������һ�������Ĳ���ʧ�ܣ�");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertUnequalNullptrFailureThrowExceptionTest()
{
    ++failedNumber;

    int* ptr{ nullptr };

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(ptr, "����ASSERT_UNEQUAL_NULL_PTRδͨ��������׳��쳣������һ�������Ĳ���ʧ�ܣ�");
}

void CoreTools::AssertTestExceptionThrowTesting::AssertRangeFailureThrowExceptionTest()
{
    ++failedNumber;

    constexpr auto lhsExpression = 3;
    constexpr auto mhsExpression = 4;
    constexpr auto rhsExpression = 2;

    ASSERT_RANGE_FAILURE_THROW(mhsExpression, lhsExpression, rhsExpression, "����ASSERT_RANGEδͨ��������׳��쳣������һ�������Ĳ���ʧ�ܣ�");
}
