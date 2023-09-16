///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 16:40)

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
      // ���ﲻ����VirtualTerminalProcessing��DisableNewlineAutoReturn��LvbGridWorldwide��
      consoleOutputModes{ ConsoleOutputMode::ProcessedOutput,
                          ConsoleOutputMode::WrapAtEolOutput }
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
