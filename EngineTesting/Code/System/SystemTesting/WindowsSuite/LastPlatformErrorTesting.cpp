///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.6 (2021/07/06 13:48)

#include "LastPlatformErrorTesting.h"
#include "System/Helper/EnumMacro.h"
#include "System/Windows/Flags/PlatformErrorFlags.h"
#include "System/Windows/LastPlatformError.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <vector>

using std::vector;

ENUM_INCREMENTABLE_OPERATOR_DEFINE(System::WindowError);

System::LastPlatformErrorTesting::LastPlatformErrorTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
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
        SetPlatformLastError(flag);

        const auto testFlag = GetPlatformLastError();

        ASSERT_ENUM_EQUAL(flag, testFlag);
    }
}

void System::LastPlatformErrorTesting::LastErrorModeTest()
{
    constexpr auto defaultFlag = ErrorMode::Default;

    ASSERT_ENUM_EQUAL(defaultFlag, GetPlatformErrorMode());

    vector<ErrorMode> modeCollection{ ErrorMode::FailCriticaleErrors, ErrorMode::NoGPFaultErrorBox, ErrorMode::NoOpenFileErrorBox };

    for (auto mode : modeCollection)
    {
        const auto previousMode = GetPlatformErrorMode();
        const auto testPreviousMode = SetPlatformErrorMode(mode);

        ASSERT_ENUM_EQUAL(previousMode, testPreviousMode);
        ASSERT_ENUM_EQUAL(mode, GetPlatformErrorMode());
    }

    constexpr auto unableRemoveFlag = ErrorMode::NoAlignmentFaultExcept;

    MAYBE_UNUSED const auto result = SetPlatformErrorMode(unableRemoveFlag);

    ASSERT_ENUM_EQUAL(unableRemoveFlag, GetPlatformErrorMode());

    const auto previousMode = SetPlatformErrorMode(defaultFlag);

    ASSERT_ENUM_EQUAL(unableRemoveFlag, GetPlatformErrorMode());
    ASSERT_ENUM_EQUAL(previousMode, GetPlatformErrorMode());
}
