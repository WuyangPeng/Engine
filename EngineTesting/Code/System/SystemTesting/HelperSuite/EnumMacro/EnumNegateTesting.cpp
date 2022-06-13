///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 1:02)

#include "EnumNegateTesting.h"
#include "System/Helper/EnumMacro.h"
#include "System/SystemTesting/HelperSuite/Detail/NumberEnum.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#define OPEN_NEGATE_OPERATOR
#undef OPEN_NEGATE_OPERATOR

#ifdef OPEN_NEGATE_OPERATOR

ENUM_NEGATE_OPERATOR_DEFINE(System::Number);

#endif  // OPEN_NEGATE_OPERATOR

ENUM_NEGATE_OPERATOR_DEFINE(System::SignedNumber);

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
    constexpr auto number = -SignedNumber::One;

    static_assert(number == SignedNumber::NegativeOne);
}
