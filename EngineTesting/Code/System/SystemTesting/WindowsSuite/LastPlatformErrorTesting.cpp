/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 17:22)

#include "LastPlatformErrorTesting.h"
#include "System/Helper/EnumOperator.h"
#include "System/Windows/Flags/PlatformErrorFlags.h"
#include "System/Windows/LastPlatformError.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <vector>

System::LastPlatformErrorTesting::LastPlatformErrorTesting(const OStreamShared& stream)
    : ParentType{ stream },
      errorModes{ ErrorMode::FailCriticalErrors, ErrorMode::NoGeneralProtectionFaultErrorBox, ErrorMode::NoOpenFileErrorBox }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, LastPlatformErrorTesting)

void System::LastPlatformErrorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::LastPlatformErrorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LastErrorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LastErrorModeTest);
}

void System::LastPlatformErrorTesting::LastErrorTest()
{
    ASSERT_ENUM_EQUAL(WindowError::Success, GetPlatformLastError());

    for (auto flag = WindowError::Success; flag <= WindowError::AppHang; ++flag)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoLastErrorTest, flag);
    }
}

void System::LastPlatformErrorTesting::DoLastErrorTest(WindowError flag)
{
    SetPlatformLastError(flag);

    const auto result = GetPlatformLastError();

    ASSERT_ENUM_EQUAL(flag, result);
}

void System::LastPlatformErrorTesting::LastErrorModeTest()
{
    ASSERT_ENUM_EQUAL(defaultFlag, GetPlatformErrorMode());

    for (auto errorMode : errorModes)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoLastErrorModeTest, errorMode);
    }

    ASSERT_NOT_THROW_EXCEPTION_0(NoAlignmentFaultExceptTest);
}

void System::LastPlatformErrorTesting::NoAlignmentFaultExceptTest()
{
    constexpr auto unableRemoveFlag = ErrorMode::NoAlignmentFaultExcept;

    MAYBE_UNUSED const auto result = SetPlatformErrorMode(unableRemoveFlag);

    ASSERT_ENUM_EQUAL(unableRemoveFlag, GetPlatformErrorMode());

    const auto previousMode = SetPlatformErrorMode(defaultFlag);

    ASSERT_ENUM_EQUAL(unableRemoveFlag, GetPlatformErrorMode());
    ASSERT_ENUM_EQUAL(previousMode, GetPlatformErrorMode());
}

void System::LastPlatformErrorTesting::DoLastErrorModeTest(ErrorMode mode)
{
    const auto previousMode = GetPlatformErrorMode();
    const auto testPreviousMode = SetPlatformErrorMode(mode);

    ASSERT_ENUM_EQUAL(previousMode, testPreviousMode);
    ASSERT_ENUM_EQUAL(mode, GetPlatformErrorMode());
}
