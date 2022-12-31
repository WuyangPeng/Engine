///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/17 18:56)

#include "EnumCastTesting.h"
#include "Detail/NumberEnum.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/EnumOperator.h"
#include "System/Windows/Flags/PlatformErrorFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::EnumCastTesting::EnumCastTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, EnumCastTesting)

void System::EnumCastTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::EnumCastTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CastTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WindowErrorCastTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ConstexprCastTest);
}

void System::EnumCastTesting::CastTest()
{
    ASSERT_EQUAL(EnumCastUnderlying(Number::One), 1u);
    ASSERT_ENUM_EQUAL(UnderlyingCastEnum<SignedNumber>(-1), SignedNumber::NegativeOne);
    ASSERT_EQUAL(EnumCastUnderlying<int>(Number::Two), 2);

    auto value = Number::One;

    UnderlyingCastEnumPtr(2, &value);

    ASSERT_ENUM_EQUAL(value, Number::Two);

    UnderlyingCastEnumPtr<SignedNumber>(2, nullptr);
}

void System::EnumCastTesting::WindowErrorCastTest()
{
    auto originalWindowError = WindowError::Success;
    ++originalWindowError;

    const auto underlyingTypeValue = EnumCastUnderlying(originalWindowError);

    ASSERT_EQUAL(1, underlyingTypeValue);

    const auto resultWindowError = UnderlyingCastEnum<WindowError>(underlyingTypeValue);

    ASSERT_ENUM_EQUAL(originalWindowError, resultWindowError);
}

void System::EnumCastTesting::ConstexprCastTest()
{
    constexpr auto originalWindowError = WindowError::Success;

    constexpr auto originalUnderlyingTypeValue = EnumCastUnderlying(originalWindowError);

    ASSERT_EQUAL(0, originalUnderlyingTypeValue);

    constexpr auto resultWindowError = UnderlyingCastEnum<WindowError>(originalUnderlyingTypeValue);

    ASSERT_ENUM_EQUAL(resultWindowError, WindowError::Success);

    constexpr auto resultUnderlyingTypeValue = EnumCastUnderlying<int>(resultWindowError);

    ASSERT_EQUAL(0, resultUnderlyingTypeValue);
}
