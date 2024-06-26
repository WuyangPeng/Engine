/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 18:31)

#include "SetConsoleHandleScreenBufferInfoTesting.h"
#include "System/Console/ConsoleScreenBuffer.h"
#include "System/Console/Flags/ConsoleScreenBufferFlags.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"
#include "System/MemoryTools/MemoryHelperDetail.h"
#include "System/Time/DeltaTime.h"
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
    const auto attributesConsoleHandle = CreateSystemConsoleScreenBuffer(DesiredAccessGeneric::ReadAndWrite, ConsoleScreenBufferShareMode::ReadAndWrite, nullptr);

    ASSERT_NOT_THROW_EXCEPTION_1(SetConsoleScreenBufferInfoTest, attributesConsoleHandle);

    ASSERT_TRUE(CloseSystemConsole(attributesConsoleHandle));
}

void System::SetConsoleHandleScreenBufferInfoTesting::SetConsoleScreenBufferInfoTest(WindowsHandle attributesConsoleHandle)
{
    auto originalConsoleScreenBufferInfo = GetWindowsStructDefaultSize<ConsoleScreenBufferInfoEx>();
    ASSERT_TRUE(GetSystemConsoleScreenBufferInfo(attributesConsoleHandle, &originalConsoleScreenBufferInfo));

    ASSERT_NOT_THROW_EXCEPTION_2(DoSetConsoleScreenBufferInfoTest, attributesConsoleHandle, originalConsoleScreenBufferInfo);

    ASSERT_TRUE(SetSystemConsoleScreenBufferInfo(attributesConsoleHandle, &originalConsoleScreenBufferInfo));
}

void System::SetConsoleHandleScreenBufferInfoTesting::DoSetConsoleScreenBufferInfoTest(WindowsHandle attributesConsoleHandle, const ConsoleScreenBufferInfoEx& consoleScreenBufferInfo)
{
    auto setConsoleScreenBufferInfo = GetConsoleScreenBufferInfoEx(consoleScreenBufferInfo);

    ASSERT_TRUE(SetSystemConsoleScreenBufferInfo(attributesConsoleHandle, &setConsoleScreenBufferInfo));

    auto currentConsoleScreenBufferInfo = GetWindowsStructDefaultSize<ConsoleScreenBufferInfoEx>();

    ASSERT_TRUE(GetSystemConsoleScreenBufferInfo(attributesConsoleHandle, &currentConsoleScreenBufferInfo));

    ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, setConsoleScreenBufferInfo, currentConsoleScreenBufferInfo);
}

void System::SetConsoleHandleScreenBufferInfoTesting::EqualTest(const ConsoleScreenBufferInfoEx& consoleScreenBufferInfo, const ConsoleScreenBufferInfoEx& currentConsoleScreenBufferInfo)
{
    ASSERT_EQUAL(currentConsoleScreenBufferInfo.cbSize, consoleScreenBufferInfo.cbSize);
    ASSERT_EQUAL(currentConsoleScreenBufferInfo.dwSize.X, consoleScreenBufferInfo.dwSize.X);
    ASSERT_EQUAL(currentConsoleScreenBufferInfo.dwSize.Y, consoleScreenBufferInfo.dwSize.Y);
    ASSERT_EQUAL(currentConsoleScreenBufferInfo.wAttributes, consoleScreenBufferInfo.wAttributes);
    ASSERT_LESS_EQUAL(currentConsoleScreenBufferInfo.srWindow.Top, consoleScreenBufferInfo.srWindow.Top);
    ASSERT_LESS_EQUAL(currentConsoleScreenBufferInfo.srWindow.Bottom, consoleScreenBufferInfo.srWindow.Bottom);
    ASSERT_LESS_EQUAL(currentConsoleScreenBufferInfo.srWindow.Left, consoleScreenBufferInfo.srWindow.Left);
    ASSERT_LESS_EQUAL(currentConsoleScreenBufferInfo.srWindow.Right, consoleScreenBufferInfo.srWindow.Right);
    ASSERT_LESS_EQUAL(currentConsoleScreenBufferInfo.dwMaximumWindowSize.X, consoleScreenBufferInfo.dwMaximumWindowSize.X);
    ASSERT_LESS_EQUAL(currentConsoleScreenBufferInfo.dwMaximumWindowSize.Y, consoleScreenBufferInfo.dwMaximumWindowSize.Y);
    ASSERT_EQUAL(currentConsoleScreenBufferInfo.wPopupAttributes, consoleScreenBufferInfo.wPopupAttributes);

    const auto colorTableSize = GetArraySize(currentConsoleScreenBufferInfo.ColorTable);
    for (auto i = 0u; i < colorTableSize; ++i)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

        ASSERT_EQUAL(currentConsoleScreenBufferInfo.ColorTable[i], consoleScreenBufferInfo.ColorTable[i]);

#include SYSTEM_WARNING_POP
    }
}

void System::SetConsoleHandleScreenBufferInfoTesting::PrintTipsMessage()
{
    GetStream() << "这个测试会改变控制台的大小。\n";

    SystemPause();
}