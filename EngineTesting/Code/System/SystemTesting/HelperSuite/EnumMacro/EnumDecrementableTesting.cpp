///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/15 1:00)

#include "EnumDecrementableTesting.h"
#include "System/Helper/EnumMacro.h"
#include "System/SystemTesting/HelperSuite/Detail/NumberEnum.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

ENUM_DECREMENTABLE_OPERATOR_DEFINE(System::Number);
ENUM_DECREMENTABLE_OPERATOR_DEFINE(System::SignedNumber);

System::EnumDecrementableTesting::EnumDecrementableTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, EnumDecrementableTesting)

void System::EnumDecrementableTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::EnumDecrementableTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SignedPrefixOperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SignedSuffixOperator0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(UnsignedPrefixOperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnsignedSuffixOperator0Test);
}

void System::EnumDecrementableTesting::SignedPrefixOperatorTest()
{
    auto number = SignedNumber::NegativeTwo;

    const auto result = --number;

    ASSERT_ENUM_EQUAL(number, SignedNumber::NegativeThree);
    ASSERT_ENUM_EQUAL(result, SignedNumber::NegativeThree);
}

void System::EnumDecrementableTesting::SignedSuffixOperator0Test()
{
    auto number = SignedNumber::NegativeOne;

    const auto result = number--;

    ASSERT_ENUM_EQUAL(number, SignedNumber::NegativeTwo);
    ASSERT_ENUM_EQUAL(result, SignedNumber::NegativeOne);
}

void System::EnumDecrementableTesting::UnsignedPrefixOperatorTest()
{
    auto number = Number::Three;

    const auto result = --number;

    ASSERT_ENUM_EQUAL(number, Number::Two);
    ASSERT_ENUM_EQUAL(result, Number::Two);
}

void System::EnumDecrementableTesting::UnsignedSuffixOperator0Test()
{
    auto number = Number::Two;

    const auto result = number--;

    ASSERT_ENUM_EQUAL(number, Number::One);
    ASSERT_ENUM_EQUAL(result, Number::Two);
}
