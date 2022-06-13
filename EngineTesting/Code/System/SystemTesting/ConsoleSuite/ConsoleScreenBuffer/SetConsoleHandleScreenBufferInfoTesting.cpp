///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 13:05)

#include "SetConsoleHandleScreenBufferInfoTesting.h"
#include "System/Console/ConsoleScreenBuffer.h"
#include "System/Console/Flags/ConsoleColoursFlags.h"
#include "System/Console/Flags/ConsoleScreenBufferFlags.h"
#include "System/Helper/WindowsMacro.h"
#include "System/MemoryTools/MemoryHelperDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::SetConsoleHandleScreenBufferInfoTesting::SetConsoleHandleScreenBufferInfoTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SetConsoleHandleScreenBufferInfoTesting)

void System::SetConsoleHandleScreenBufferInfoTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::SetConsoleHandleScreenBufferInfoTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SetConsoleScreenBufferInfoTest);
}

void System::SetConsoleHandleScreenBufferInfoTesting::SetConsoleScreenBufferInfoTest()
{
    constexpr auto size = 96;

    auto attributesConsoleHandle = CreateSystemConsoleScreenBuffer(DesiredAccessGeneric::ReadAndWrite, ConsoleScreenBufferShareMode::ReadAndWrite, nullptr);

    auto originalConsoleScreenBufferInfo = GetWindowsStructDefaultSize<ConsoleScreenBufferInfoEx>();

    ASSERT_TRUE(GetSystemConsoleScreenBufferInfo(attributesConsoleHandle, &originalConsoleScreenBufferInfo));

    auto setConsoleScreenBufferInfo = originalConsoleScreenBufferInfo;

    setConsoleScreenBufferInfo.dwSize.X = size;
    setConsoleScreenBufferInfo.dwSize.Y = size;
    setConsoleScreenBufferInfo.dwCursorPosition.X = 0;
    setConsoleScreenBufferInfo.dwCursorPosition.Y = size / 2;
    setConsoleScreenBufferInfo.wAttributes = static_cast<WindowsWord>(TextColour::Green);
    setConsoleScreenBufferInfo.wPopupAttributes = static_cast<WindowsWord>(TextColour::Blue);
    setConsoleScreenBufferInfo.srWindow.Top = 0;
    setConsoleScreenBufferInfo.srWindow.Bottom = size - 1;
    setConsoleScreenBufferInfo.srWindow.Left = 0;
    setConsoleScreenBufferInfo.srWindow.Right = size - 1;
    setConsoleScreenBufferInfo.dwMaximumWindowSize.X = size;
    setConsoleScreenBufferInfo.dwMaximumWindowSize.Y = size;
    setConsoleScreenBufferInfo.bFullscreenSupported = gTrue;

    ASSERT_TRUE(SetConsoleHandleScreenBufferInfo(attributesConsoleHandle, &setConsoleScreenBufferInfo));

    auto currentConsoleScreenBufferInfo = GetWindowsStructDefaultSize<ConsoleScreenBufferInfoEx>();

    ASSERT_TRUE(GetSystemConsoleScreenBufferInfo(attributesConsoleHandle, &currentConsoleScreenBufferInfo));

    ASSERT_EQUAL(currentConsoleScreenBufferInfo.cbSize, setConsoleScreenBufferInfo.cbSize);
    ASSERT_EQUAL(currentConsoleScreenBufferInfo.dwSize.X, setConsoleScreenBufferInfo.dwSize.X);
    ASSERT_EQUAL(currentConsoleScreenBufferInfo.dwSize.Y, setConsoleScreenBufferInfo.dwSize.Y);
    ASSERT_EQUAL(currentConsoleScreenBufferInfo.wAttributes, setConsoleScreenBufferInfo.wAttributes);
    ASSERT_LESS_EQUAL(currentConsoleScreenBufferInfo.srWindow.Top, setConsoleScreenBufferInfo.srWindow.Top);
    ASSERT_LESS_EQUAL(currentConsoleScreenBufferInfo.srWindow.Bottom, setConsoleScreenBufferInfo.srWindow.Bottom);
    ASSERT_LESS_EQUAL(currentConsoleScreenBufferInfo.srWindow.Left, setConsoleScreenBufferInfo.srWindow.Left);
    ASSERT_LESS_EQUAL(currentConsoleScreenBufferInfo.srWindow.Right, setConsoleScreenBufferInfo.srWindow.Right);
    ASSERT_LESS_EQUAL(currentConsoleScreenBufferInfo.dwMaximumWindowSize.X, setConsoleScreenBufferInfo.dwMaximumWindowSize.X);
    ASSERT_LESS_EQUAL(currentConsoleScreenBufferInfo.dwMaximumWindowSize.Y, setConsoleScreenBufferInfo.dwMaximumWindowSize.Y);
    ASSERT_EQUAL(currentConsoleScreenBufferInfo.wPopupAttributes, setConsoleScreenBufferInfo.wPopupAttributes);

    constexpr auto colorTableSize = 16;
    for (auto i = 0; i < colorTableSize; ++i)
    {

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

        ASSERT_EQUAL(currentConsoleScreenBufferInfo.ColorTable[i], setConsoleScreenBufferInfo.ColorTable[i]);

#include STSTEM_WARNING_POP

    }

    ASSERT_TRUE(SetConsoleHandleScreenBufferInfo(attributesConsoleHandle, &originalConsoleScreenBufferInfo));

    ASSERT_TRUE(CloseSystemConsole(attributesConsoleHandle));
}
