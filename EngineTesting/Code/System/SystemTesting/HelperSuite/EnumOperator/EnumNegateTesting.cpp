///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/17 20:19)

#include "EnumNegateTesting.h"
#include "System/Helper/EnumOperator.h"
#include "System/SystemTesting/HelperSuite/Detail/NumberEnum.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#define OPEN_NEGATE_OPERATOR
#undef OPEN_NEGATE_OPERATOR

System::EnumNegateTesting::EnumNegateTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, EnumNegateTesting)

void System::EnumNegateTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::EnumNegateTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SignedConstexprOperatorTest);
}

void System::EnumNegateTesting::SignedConstexprOperatorTest() noexcept
{
    constexpr auto signedNumber = -SignedNumber::One;

    static_assert(signedNumber == SignedNumber::NegativeOne);

#ifdef OPEN_NEGATE_OPERATOR

    constexpr auto number = -Number::One;

#endif  // OPEN_NEGATE_OPERATOR
}
