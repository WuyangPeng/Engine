///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 16:40)

#include "CurrentConsoleFontTesting.h"
#include "System/Console/ConsoleFont.h"
#include "System/Console/ConsoleHandle.h"
#include "System/Console/Flags/ConsoleHandleFlags.h"
#include "System/MemoryTools/MemoryHelperDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CurrentConsoleFontTesting::CurrentConsoleFontTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CurrentConsoleFontTesting)

void System::CurrentConsoleFontTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CurrentConsoleFontTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_1(CurrentConsoleFontTest, false);
    ASSERT_NOT_THROW_EXCEPTION_1(CurrentConsoleFontTest, true);
}

void System::CurrentConsoleFontTesting::CurrentConsoleFontTest(bool maximumWindow)
{
    const auto consoleHandle = GetStandardHandle(StandardHandle::Output);

    ConsoleFontInfo consoleFontInfo{};
    ASSERT_TRUE(GetCurrentSystemConsoleFont(consoleHandle, maximumWindow, &consoleFontInfo));

    auto consoleFontInfoEx = GetWindowsStructDefaultSize<ConsoleFontInfoEx>();
    ASSERT_TRUE(GetCurrentSystemConsoleFont(consoleHandle, maximumWindow, &consoleFontInfoEx));

    FontEqualTest(consoleFontInfo, consoleFontInfoEx);
}

void System::CurrentConsoleFontTesting::FontEqualTest(const ConsoleFontInfo& consoleFontInfo, const ConsoleFontInfoEx& consoleFontInfoEx)
{
    ASSERT_EQUAL(consoleFontInfo.nFont, consoleFontInfoEx.nFont);
    ASSERT_EQUAL(consoleFontInfo.dwFontSize.X, consoleFontInfoEx.dwFontSize.X);
    ASSERT_EQUAL(consoleFontInfo.dwFontSize.Y, consoleFontInfoEx.dwFontSize.Y);
}
