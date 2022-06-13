///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 1:00)

#include "EnumIncrementableTesting.h"
#include "System/Helper/EnumMacro.h"
#include "System/SystemTesting/HelperSuite/Detail/NumberEnum.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

ENUM_INCREMENTABLE_OPERATOR_DEFINE(System::Number);
ENUM_INCREMENTABLE_OPERATOR_DEFINE(System::SignedNumber);

System::EnumIncrementableTesting::EnumIncrementableTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, EnumIncrementableTesting)

void System::EnumIncrementableTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::EnumIncrementableTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SignedPrefixOperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SignedSuffixOperator0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(UnsignedPrefixOperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnsignedSuffixOperator0Test);
}

void System::EnumIncrementableTesting::SignedPrefixOperatorTest()
{
    auto number = SignedNumber::NegativeTwo;

    const auto result = ++number;

    ASSERT_ENUM_EQUAL(number, SignedNumber::NegativeOne);
    ASSERT_ENUM_EQUAL(result, SignedNumber::NegativeOne);
}

void System::EnumIncrementableTesting::SignedSuffixOperator0Test()
{
    auto number = SignedNumber::NegativeThree;

    const auto result = number++;

    ASSERT_ENUM_EQUAL(number, SignedNumber::NegativeTwo);
    ASSERT_ENUM_EQUAL(result, SignedNumber::NegativeThree);
}

void System::EnumIncrementableTesting::UnsignedPrefixOperatorTest()
{
    auto number = Number::Two;

    const auto result = ++number;

    ASSERT_ENUM_EQUAL(number, Number::Three);
    ASSERT_ENUM_EQUAL(result, Number::Three);
}

void System::EnumIncrementableTesting::UnsignedSuffixOperator0Test()
{
    auto number = Number::Two;

    const auto result = number++;

    ASSERT_ENUM_EQUAL(number, Number::Three);
    ASSERT_ENUM_EQUAL(result, Number::Two);
}
