/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/08 11:03)

#include "EnumXorableTesting.h"
#include "System/Helper/EnumOperator.h"
#include "System/SystemTesting/HelperSuite/Detail/NumberEnum.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::EnumXorableTesting::EnumXorableTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, EnumXorableTesting)

void System::EnumXorableTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::EnumXorableTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SignedOperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SignedConstexprOperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnsignedOperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnsignedConstexprOperatorTest);
}

void System::EnumXorableTesting::SignedOperatorTest()
{
    auto number = SignedNumber::Three;

    number ^= SignedNumber::Five;

    ASSERT_ENUM_EQUAL(number, SignedNumber::Six);
}

void System::EnumXorableTesting::SignedConstexprOperatorTest() const noexcept
{
    constexpr auto number = SignedNumber::Seven ^ SignedNumber::Five;

    static_assert(number == SignedNumber::Two);
}

void System::EnumXorableTesting::UnsignedOperatorTest()
{
    auto number = Number::Six;

    number ^= Number::Three;

    ASSERT_ENUM_EQUAL(number, Number::Five);
}

void System::EnumXorableTesting::UnsignedConstexprOperatorTest() const noexcept
{
    constexpr auto number = Number::Three ^ Number::Six;

    static_assert(number == Number::Five);
}
