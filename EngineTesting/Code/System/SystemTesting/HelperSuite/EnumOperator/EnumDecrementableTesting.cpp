/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/08 10:58)

#include "EnumDecrementableTesting.h"
#include "System/Helper/EnumOperator.h"
#include "System/SystemTesting/HelperSuite/Detail/NumberEnum.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::EnumDecrementableTesting::EnumDecrementableTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
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

    ASSERT_EQUAL(number, SignedNumber::NegativeThree);
    ASSERT_EQUAL(result, SignedNumber::NegativeThree);
}

void System::EnumDecrementableTesting::SignedSuffixOperator0Test()
{
    auto number = SignedNumber::NegativeOne;

    const auto result = number--;

    ASSERT_EQUAL(number, SignedNumber::NegativeTwo);
    ASSERT_EQUAL(result, SignedNumber::NegativeOne);
}

void System::EnumDecrementableTesting::UnsignedPrefixOperatorTest()
{
    auto number = Number::Three;

    const auto result = --number;

    ASSERT_EQUAL(number, Number::Two);
    ASSERT_EQUAL(result, Number::Two);
}

void System::EnumDecrementableTesting::UnsignedSuffixOperator0Test()
{
    auto number = Number::Two;

    const auto result = number--;

    ASSERT_EQUAL(number, Number::One);
    ASSERT_EQUAL(result, Number::Two);
}
