///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/05 21:30)

#include "ConsoleOutputModeTesting.h"
#include "System/Console/ConsoleHandle.h"
#include "System/Console/ConsoleMode.h"
#include "System/Console/Flags/ConsoleHandleFlags.h"
#include "System/Console/Flags/ConsoleModeFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ConsoleOutputModeTesting::ConsoleOutputModeTesting(const OStreamShared& stream)
    : ParentType{ stream },
      standardOutputs{ StandardHandle::Output,
                       StandardHandle::Error },
      // 这里不测试VirtualTerminalProcessing、DisableNewlineAutoReturn、LvbGridWorldwide。
      consoleOutputModes{ ConsoleOutputMode::ProcessedOutput,
                          ConsoleOutputMode::WeapAtEolOutput }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ConsoleOutputModeTesting)

void System::ConsoleOutputModeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ConsoleOutputModeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConsoleOutputModeTest);
}

void System::ConsoleOutputModeTesting::ConsoleOutputModeTest()
{
    for (auto standardOutput : standardOutputs)
    {
        for (auto consoleOutputMode : consoleOutputModes)
        {
            ASSERT_NOT_THROW_EXCEPTION_2(DoConsoleOutputModeTest, standardOutput, consoleOutputMode);
        }
    }
}

void System::ConsoleOutputModeTesting::DoConsoleOutputModeTest(StandardHandle standardOutput, ConsoleOutputMode consoleOutputMode)
{
    const auto consoleHandle = GetStandardHandle(standardOutput);
    const auto originalMode = GetCurrentMode(consoleHandle);

    ASSERT_TRUE(SetSystemConsoleMode(consoleHandle, consoleOutputMode));

    const auto returnConsoleOutputMode = GetCurrentMode(consoleHandle);

    ASSERT_EQUAL(EnumCastUnderlying<WindowsDWord>(consoleOutputMode), returnConsoleOutputMode);

    ASSERT_TRUE(SetSystemConsoleMode(consoleHandle, UnderlyingCastEnum<ConsoleOutputMode>(originalMode)));
}
