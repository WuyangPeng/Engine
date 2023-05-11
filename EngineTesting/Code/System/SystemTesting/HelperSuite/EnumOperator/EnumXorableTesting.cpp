///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/17 20:22)

#include "EnumXorableTesting.h"
#include "System/Helper/EnumOperator.h"
#include "System/SystemTesting/HelperSuite/Detail/NumberEnum.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::EnumXorableTesting::EnumXorableTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
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

void System::EnumXorableTesting::SignedConstexprOperatorTest() noexcept
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

void System::EnumXorableTesting::UnsignedConstexprOperatorTest() noexcept
{
    constexpr auto number = Number::Three ^ Number::Six;

    static_assert(number == Number::Five);
}