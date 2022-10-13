///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.2 (2022/09/25 20:02)

#include "EnumSubtractableTesting.h"
#include "System/Helper/EnumMacro.h"
#include "System/SystemTesting/HelperSuite/Detail/NumberEnum.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

ENUM_SUBTRACTABLE_OPERATOR_DEFINE(System::Number);
ENUM_SUBTRACTABLE_OPERATOR_DEFINE(System::SignedNumber);

System::EnumSubtractableTesting::EnumSubtractableTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, EnumSubtractableTesting)

void System::EnumSubtractableTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::EnumSubtractableTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SignedOperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SignedConstexprOperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnsignedOperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnsignedConstexprOperatorTest);
}

void System::EnumSubtractableTesting::SignedOperatorTest()
{
    auto number = SignedNumber::Three;

    number -= 4;

    ASSERT_ENUM_EQUAL(number, SignedNumber::NegativeOne);
}

void System::EnumSubtractableTesting::SignedConstexprOperatorTest() noexcept
{
    constexpr auto number = SignedNumber::NegativeOne - 2;

    static_assert(number == SignedNumber::NegativeThree);
}

void System::EnumSubtractableTesting::UnsignedOperatorTest()
{
    auto number = Number::Seven;

    number -= 4;

    ASSERT_ENUM_EQUAL(number, Number::Three);
}

void System::EnumSubtractableTesting::UnsignedConstexprOperatorTest() noexcept
{
    constexpr auto number = Number::Eight - 7;

    static_assert(number == Number::One);
}