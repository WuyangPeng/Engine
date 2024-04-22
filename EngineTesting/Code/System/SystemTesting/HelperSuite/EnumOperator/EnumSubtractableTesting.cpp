/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/08 11:02)

#include "EnumSubtractableTesting.h"
#include "System/Helper/EnumOperator.h"
#include "System/SystemTesting/HelperSuite/Detail/NumberEnum.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::EnumSubtractableTesting::EnumSubtractableTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
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

    ASSERT_EQUAL(number, SignedNumber::NegativeOne);
}

void System::EnumSubtractableTesting::SignedConstexprOperatorTest() const noexcept
{
    constexpr auto number = SignedNumber::NegativeOne - 2;

    static_assert(number == SignedNumber::NegativeThree);
}

void System::EnumSubtractableTesting::UnsignedOperatorTest()
{
    auto number = Number::Seven;

    number -= 4;

    ASSERT_EQUAL(number, Number::Three);
}

void System::EnumSubtractableTesting::UnsignedConstexprOperatorTest() const noexcept
{
    constexpr auto number = Number::Eight - 7;

    static_assert(number == Number::One);
}