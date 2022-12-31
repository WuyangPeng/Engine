///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/04 14:52)

#include "SetCurrentConsoleFontTesting.h"
#include "System/Console/ConsoleFont.h"
#include "System/Console/ConsoleScreenBuffer.h"
#include "System/Console/Flags/ConsoleScreenBufferFlags.h"
#include "System/MemoryTools/MemoryHelperDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::SetCurrentConsoleFontTesting::SetCurrentConsoleFontTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SetCurrentConsoleFontTesting)

void System::SetCurrentConsoleFontTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::SetCurrentConsoleFontTesting::MainTest()
{
    const auto consoleHandle = CreateSystemConsoleScreenBuffer(DesiredAccessGeneric::ReadAndWrite, ConsoleScreenBufferShareMode::ReadAndWrite, nullptr);

    ASSERT_NOT_THROW_EXCEPTION_1(SetCurrentConsoleFontTest, consoleHandle);

    ASSERT_TRUE(CloseSystemConsole(consoleHandle));
}

void System::SetCurrentConsoleFontTesting::SetCurrentConsoleFontTest(WindowsHandle consoleHandle)
{
    auto originalConsoleFontInfo = GetWindowsStructDefaultSize<ConsoleFontInfoEx>();
    ASSERT_TRUE(GetCurrentSystemConsoleFont(consoleHandle, false, &originalConsoleFontInfo));

    ASSERT_TRUE(SetCurrentSystemConsoleFont(consoleHandle, false, &originalConsoleFontInfo));

    auto currentConsoleFontInfo = GetWindowsStructDefaultSize<ConsoleFontInfoEx>();
    ASSERT_TRUE(GetCurrentSystemConsoleFont(consoleHandle, false, &currentConsoleFontInfo));

    ASSERT_NOT_THROW_EXCEPTION_2(FontEqualTest, originalConsoleFontInfo, currentConsoleFontInfo);
}

void System::SetCurrentConsoleFontTesting::FontEqualTest(const ConsoleFontInfoEx& originalConsoleFontInfo, const ConsoleFontInfoEx& currentConsoleFontInfo)
{
    ASSERT_EQUAL(originalConsoleFontInfo.cbSize, currentConsoleFontInfo.cbSize);
    ASSERT_EQUAL(originalConsoleFontInfo.nFont, currentConsoleFontInfo.nFont);
    ASSERT_EQUAL(originalConsoleFontInfo.dwFontSize.X, currentConsoleFontInfo.dwFontSize.X);
    ASSERT_EQUAL(originalConsoleFontInfo.dwFontSize.Y, currentConsoleFontInfo.dwFontSize.Y);
    ASSERT_EQUAL(originalConsoleFontInfo.FontFamily, currentConsoleFontInfo.FontFamily);
    ASSERT_EQUAL(originalConsoleFontInfo.FontWeight, currentConsoleFontInfo.FontWeight);

    for (auto i = 0; i < gLogicalFontFaceSize; ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

        ASSERT_EQUAL(originalConsoleFontInfo.FaceName[i], currentConsoleFontInfo.FaceName[i]);

#include STSTEM_WARNING_POP
    }
}
