///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.2 (2022/09/22 22:42)

#include "EnumCastTesting.h"
#include "Detail/NumberEnum.h"
#include "System/Helper/EnumCast.h"
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
}

void System::EnumCastTesting::WindowErrorCastTest()
{
    auto windowError = WindowError::Success;

    const auto underlyingTypeValue = EnumCastUnderlying(windowError);

    ASSERT_EQUAL(0, underlyingTypeValue);

    windowError = UnderlyingCastEnum<WindowError>(underlyingTypeValue);

    ASSERT_ENUM_EQUAL(windowError, WindowError::Success);
}

void System::EnumCastTesting::ConstexprCastTest()
{
    constexpr auto windowError0 = WindowError::Success;

    constexpr auto underlyingTypeValue0 = EnumCastUnderlying(windowError0);

    ASSERT_EQUAL(0, underlyingTypeValue0);

    constexpr auto windowError1 = UnderlyingCastEnum<WindowError>(underlyingTypeValue0);

    ASSERT_ENUM_EQUAL(windowError1, WindowError::Success);

    constexpr auto underlyingTypeValue1 = EnumCastUnderlying<int>(windowError1);

    ASSERT_EQUAL(0, underlyingTypeValue1);
}
