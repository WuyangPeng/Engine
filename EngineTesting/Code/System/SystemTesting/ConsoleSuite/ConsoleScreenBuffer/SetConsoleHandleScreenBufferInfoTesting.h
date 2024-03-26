/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 18:25)

#ifndef SYSTEM_CONSOLE_SUITE_SET_CONSOLE_HANDLE_SCREEN_BUFFER_INFO_TESTING_H
#define SYSTEM_CONSOLE_SUITE_SET_CONSOLE_HANDLE_SCREEN_BUFFER_INFO_TESTING_H

#include "System/Console/Flags/ConsoleColoursFlags.h"
#include "System/Console/Using/ConsoleScreenBufferUsing.h"
#include "System/Helper/WindowsMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class SetConsoleHandleScreenBufferInfoTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SetConsoleHandleScreenBufferInfoTesting;
        using ParentType = UnitTest;

    public:
        explicit SetConsoleHandleScreenBufferInfoTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void SetConsoleScreenBufferInfoTest(WindowsHandle attributesConsoleHandle);
        void DoSetConsoleScreenBufferInfoTest(WindowsHandle attributesConsoleHandle, const ConsoleScreenBufferInfoEx& consoleScreenBufferInfo);
        void EqualTest(const ConsoleScreenBufferInfoEx& consoleScreenBufferInfo, const ConsoleScreenBufferInfoEx& currentConsoleScreenBufferInfo);

        NODISCARD constexpr static ConsoleScreenBufferInfoEx GetConsoleScreenBufferInfoEx(ConsoleScreenBufferInfoEx consoleScreenBufferInfo) noexcept
        {
            constexpr auto size = 36;

            consoleScreenBufferInfo.dwSize.X = size;
            consoleScreenBufferInfo.dwSize.Y = size;
            consoleScreenBufferInfo.dwCursorPosition.X = 0;
            consoleScreenBufferInfo.dwCursorPosition.Y = size / 2;
            consoleScreenBufferInfo.wAttributes = static_cast<WindowsWord>(TextColour::Green);
            consoleScreenBufferInfo.wPopupAttributes = static_cast<WindowsWord>(TextColour::Blue);
            consoleScreenBufferInfo.srWindow.Top = 0;
            consoleScreenBufferInfo.srWindow.Bottom = size;
            consoleScreenBufferInfo.srWindow.Left = 0;
            consoleScreenBufferInfo.srWindow.Right = size;
            consoleScreenBufferInfo.dwMaximumWindowSize.X = size;
            consoleScreenBufferInfo.dwMaximumWindowSize.Y = size;
            consoleScreenBufferInfo.bFullscreenSupported = gTrue;

            return consoleScreenBufferInfo;
        }

        void PrintTipsMessage() override;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_SET_CONSOLE_HANDLE_SCREEN_BUFFER_INFO_TESTING_H