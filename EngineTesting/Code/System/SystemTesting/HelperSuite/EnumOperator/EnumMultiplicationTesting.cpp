///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 09:45)

#include "EnumMultiplicationTesting.h"
#include "System/Helper/EnumOperator.h"
#include "System/SystemTesting/HelperSuite/Detail/NumberEnum.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::EnumMultiplicationTesting::EnumMultiplicationTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, EnumMultiplicationTesting)

void System::EnumMultiplicationTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::EnumMultiplicationTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SignedConstexprOperator0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(SignedConstexprOperator1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(UnsignedConstexprOperator0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(UnsignedConstexprOperator1Test);
}

void System::EnumMultiplicationTesting::SignedConstexprOperator0Test() noexcept
{
    constexpr auto number = SignedNumber::NegativeThree * 6;

    static_assert(number == -18);
}

void System::EnumMultiplicationTesting::SignedConstexprOperator1Test() noexcept
{
    constexpr auto number = 9 * SignedNumber::NegativeTwo;

    static_assert(number == -18);
}

void System::EnumMultiplicationTesting::UnsignedConstexprOperator0Test() noexcept
{
    constexpr auto number = Number::One * 7;

    static_assert(number == 7);
}

void System::EnumMultiplicationTesting::UnsignedConstexprOperator1Test() noexcept
{
    constexpr auto number = 3 * Number::Two;

    static_assert(number == 6);
}