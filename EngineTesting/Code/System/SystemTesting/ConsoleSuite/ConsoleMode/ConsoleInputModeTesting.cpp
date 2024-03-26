/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 18:29)

#include "ConsoleInputModeTesting.h"
#include "System/Console/ConsoleHandle.h"
#include "System/Console/ConsoleMode.h"
#include "System/Console/Flags/ConsoleHandleFlags.h"
#include "System/Console/Flags/ConsoleModeFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ConsoleInputModeTesting::ConsoleInputModeTesting(const OStreamShared& stream)
    : ParentType{ stream },
      consoleInputModes{ ConsoleInputMode::ProcessedInput,
                         ConsoleInputMode::LineInput,
                         ConsoleInputMode::EchoInput,
                         ConsoleInputMode::WindowInput,
                         ConsoleInputMode::MouseInput,
                         ConsoleInputMode::ExtendedFlags,
                         ConsoleInputMode::InsertMode,
                         ConsoleInputMode::QuickEditMode,
                         ConsoleInputMode::AutoPosition,
                         ConsoleInputMode::VirtualTerminalInput }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ConsoleInputModeTesting)

void System::ConsoleInputModeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ConsoleInputModeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConsoleInputModeTest);
}

void System::ConsoleInputModeTesting::ConsoleInputModeTest()
{
    for (auto consoleInputMode : consoleInputModes)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoConsoleInputModeTest, consoleInputMode);
    }
}

void System::ConsoleInputModeTesting::DoConsoleInputModeTest(ConsoleInputMode consoleInputMode)
{
    const auto consoleHandle = GetStandardHandle(StandardHandle::Input);
    const auto originalMode = GetCurrentMode(consoleHandle);

    ASSERT_TRUE(SetSystemConsoleMode(consoleHandle, consoleInputMode));

    const auto returnConsoleInputMode = GetCurrentMode(consoleHandle);

    ASSERT_EQUAL(EnumCastUnderlying<WindowsDWord>(consoleInputMode), returnConsoleInputMode);

    ASSERT_TRUE(SetSystemConsoleMode(consoleHandle, static_cast<ConsoleInputMode>(originalMode)));
}
