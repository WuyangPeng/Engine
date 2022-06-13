///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 13:05)

#include "ConsoleFontTesting.h"
#include "System/Console/ConsoleFont.h"
#include "System/Console/ConsoleHandle.h"
#include "System/Console/ConsoleScreenBuffer.h"
#include "System/Console/Flags/ConsoleHandleFlags.h"
#include "System/Console/Flags/ConsoleScreenBufferFlags.h"
#include "System/Console/Using/ConsoleFontUsing.h"
#include "System/MemoryTools/MemoryHelperDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ConsoleFontTesting::ConsoleFontTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ConsoleFontTesting)

void System::ConsoleFontTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ConsoleFontTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CurrentConsoleFontSizeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MaximumConsoleFontTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetCurrentConsoleFontTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CurrentConsoleFontTest);
}

void System::ConsoleFontTesting::CurrentConsoleFontTest()
{
    auto consoleHandle = GetStandardHandle(StandardHandle::Output);

    ConsoleFontInfo consoleFontInfo{};
    ASSERT_TRUE(GetCurrentSystemConsoleFont(consoleHandle, false, &consoleFontInfo));

    auto consoleFontInfoEx = GetWindowsStructDefaultSize<ConsoleFontInfoEx>();
    ASSERT_TRUE(GetCurrentSystemConsoleFont(consoleHandle, false, &consoleFontInfoEx));

    ASSERT_EQUAL(consoleFontInfoEx.nFont, consoleFontInfo.nFont);
    ASSERT_EQUAL(consoleFontInfoEx.dwFontSize.X, consoleFontInfo.dwFontSize.X);
    ASSERT_EQUAL(consoleFontInfoEx.dwFontSize.Y, consoleFontInfo.dwFontSize.Y);
}

void System::ConsoleFontTesting::MaximumConsoleFontTest()
{
    auto consoleHandle = GetStandardHandle(StandardHandle::Output);

    ConsoleFontInfo consoleFontInfo{};
    ASSERT_TRUE(GetCurrentSystemConsoleFont(consoleHandle, true, &consoleFontInfo));

    auto consoleFontInfoEx = GetWindowsStructDefaultSize<ConsoleFontInfoEx>();
    ASSERT_TRUE(GetCurrentSystemConsoleFont(consoleHandle, true, &consoleFontInfoEx));

    ASSERT_EQUAL(consoleFontInfoEx.nFont, consoleFontInfo.nFont);
    ASSERT_EQUAL(consoleFontInfoEx.dwFontSize.X, consoleFontInfo.dwFontSize.X);
    ASSERT_EQUAL(consoleFontInfoEx.dwFontSize.Y, consoleFontInfo.dwFontSize.Y);
}

void System::ConsoleFontTesting::SetCurrentConsoleFontTest()
{
    auto consoleHandle = CreateSystemConsoleScreenBuffer(DesiredAccessGeneric::ReadAndWrite, ConsoleScreenBufferShareMode::ReadAndWrite, nullptr);

    auto originalConsoleFontInfo = GetWindowsStructDefaultSize<ConsoleFontInfoEx>();
    ASSERT_TRUE(GetCurrentSystemConsoleFont(consoleHandle, false, &originalConsoleFontInfo));

    ASSERT_TRUE(SetCurrentSystemConsoleFont(consoleHandle, false, &originalConsoleFontInfo));

    auto currentConsoleFontInfo = GetWindowsStructDefaultSize<ConsoleFontInfoEx>();
    ASSERT_TRUE(GetCurrentSystemConsoleFont(consoleHandle, false, &currentConsoleFontInfo));

    ASSERT_EQUAL(originalConsoleFontInfo.cbSize, currentConsoleFontInfo.cbSize);
    ASSERT_EQUAL(originalConsoleFontInfo.nFont, currentConsoleFontInfo.nFont);
    ASSERT_EQUAL(originalConsoleFontInfo.dwFontSize.X, currentConsoleFontInfo.dwFontSize.X);
    ASSERT_EQUAL(originalConsoleFontInfo.dwFontSize.Y, currentConsoleFontInfo.dwFontSize.Y);
    ASSERT_EQUAL(originalConsoleFontInfo.FontFamily, currentConsoleFontInfo.FontFamily);
    ASSERT_EQUAL(originalConsoleFontInfo.FontWeight, currentConsoleFontInfo.FontWeight);

    for (int i = 0; i < gLogicalFontFaceSize; ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

        ASSERT_EQUAL(originalConsoleFontInfo.FaceName[i], currentConsoleFontInfo.FaceName[i]);

#include STSTEM_WARNING_POP
    }

    ASSERT_TRUE(CloseSystemConsole(consoleHandle));
}

void System::ConsoleFontTesting::CurrentConsoleFontSizeTest()
{
    auto consoleHandle = GetStandardHandle(StandardHandle::Output);

    ConsoleFontInfo consoleFontInfo{};
    ASSERT_TRUE(GetCurrentSystemConsoleFont(consoleHandle, false, &consoleFontInfo));

    const auto consoleCoord = GetSystemConsoleFontSize(consoleHandle, consoleFontInfo.nFont);

    ASSERT_EQUAL(consoleCoord.X, consoleFontInfo.dwFontSize.X);
    ASSERT_EQUAL(consoleCoord.Y, consoleFontInfo.dwFontSize.Y);
}
