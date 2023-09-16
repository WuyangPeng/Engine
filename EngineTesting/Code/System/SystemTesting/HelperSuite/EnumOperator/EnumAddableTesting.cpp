///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 09:44)

#include "EnumAddableTesting.h"
#include "System/Helper/EnumOperator.h"
#include "System/SystemTesting/HelperSuite/Detail/NumberEnum.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::EnumAddableTesting::EnumAddableTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, EnumAddableTesting)

void System::EnumAddableTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::EnumAddableTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SignedOperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SignedConstexprOperator0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(SignedConstexprOperator1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(UnsignedOperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnsignedConstexprOperator0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(UnsignedConstexprOperator1Test);
}

void System::EnumAddableTesting::SignedOperatorTest()
{
    auto number = SignedNumber::NegativeOne;

    number += 4;

    ASSERT_ENUM_EQUAL(number, SignedNumber::Three);
}

void System::EnumAddableTesting::SignedConstexprOperator0Test() noexcept
{
    constexpr auto number = SignedNumber::NegativeThree + 6;

    static_assert(number == SignedNumber::Three);
}

void System::EnumAddableTesting::SignedConstexprOperator1Test() noexcept
{
    constexpr auto number = 9 + SignedNumber::NegativeTwo;

    static_assert(number == SignedNumber::Seven);
}

void System::EnumAddableTesting::UnsignedOperatorTest()
{
    auto number = Number::Two;

    number += 5;

    ASSERT_ENUM_EQUAL(number, Number::Seven);
}

void System::EnumAddableTesting::UnsignedConstexprOperator0Test() noexcept
{
    constexpr auto number = Number::One + 7;

    static_assert(number == Number::Eight);
}

void System::EnumAddableTesting::UnsignedConstexprOperator1Test() noexcept
{
    constexpr auto number = 6 + Number::Two;

    static_assert(number == Number::Eight);
}