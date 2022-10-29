///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/15 21:55)

#include "ConsoleModeTesting.h"
#include "System/Console/ConsoleHandle.h"
#include "System/Console/ConsoleMode.h"
#include "System/Console/Flags/ConsoleHandleFlags.h"
#include "System/Console/Flags/ConsoleModeFlags.h"
#include "System/Helper/EnumCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ConsoleModeTesting::ConsoleModeTesting(const OStreamShared& stream)
    : ParentType{ stream },
      standardOutputHandleFlags{ StandardHandle::Output, StandardHandle::Error },
      consoleInputModeFlags{ ConsoleInputMode::ProcessedInput,
                             ConsoleInputMode::LineInput,
                             ConsoleInputMode::EchoInput,
                             ConsoleInputMode::WindowInput,
                             ConsoleInputMode::MouseInput,
                             ConsoleInputMode::InsertMode,
                             ConsoleInputMode::QuickEditMode,
                             ConsoleInputMode::ExtendedFlags },
      consoleOutputModeFlags{ ConsoleOutputMode::ProcessedOutput,
                              ConsoleOutputMode::WeapAtEolOutput }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ConsoleModeTesting)

void System::ConsoleModeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ConsoleModeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConsoleInputModeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ConsoleOutputModeTest);
}

void System::ConsoleModeTesting::ConsoleInputModeTest()
{
    auto consoleHandle = GetStandardHandle(StandardHandle::Input);

    WindowsDWord originalMode{ 0 };
    ASSERT_TRUE(GetSystemConsoleMode(consoleHandle, &originalMode));

    for (auto flag : consoleInputModeFlags)
    {
        ASSERT_TRUE(SetSystemConsoleMode(consoleHandle, flag));

        WindowsDWord testMode{ 0 };
        ASSERT_TRUE(GetSystemConsoleMode(consoleHandle, &testMode));

        ASSERT_EQUAL(EnumCastUnderlying<WindowsDWord>(flag), testMode);
    }

    ASSERT_TRUE(SetSystemConsoleMode(consoleHandle, static_cast<ConsoleInputMode>(originalMode)));
}

void System::ConsoleModeTesting::ConsoleOutputModeTest()
{
    for (auto standardHandleFlag : standardOutputHandleFlags)
    {
        auto consoleHandle = GetStandardHandle(standardHandleFlag);

        WindowsDWord originalMode{ 0 };
        ASSERT_TRUE(GetSystemConsoleMode(consoleHandle, &originalMode));

        for (auto flag : consoleOutputModeFlags)
        {
            ASSERT_TRUE(SetSystemConsoleMode(consoleHandle, flag));

            WindowsDWord testMode{ 0 };
            ASSERT_TRUE(GetSystemConsoleMode(consoleHandle, &testMode));

            ASSERT_EQUAL(EnumCastUnderlying<WindowsDWord>(flag), testMode);
        }

        ASSERT_TRUE(SetSystemConsoleMode(consoleHandle, UnderlyingCastEnum<ConsoleInputMode>(originalMode)));
    }
}
