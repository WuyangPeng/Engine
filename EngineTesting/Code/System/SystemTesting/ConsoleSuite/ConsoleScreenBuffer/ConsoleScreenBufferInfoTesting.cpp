///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 16:40)

#include "ConsoleScreenBufferInfoTesting.h"
#include "System/Console/ConsoleScreenBuffer.h"
#include "System/Console/Flags/ConsoleColoursFlags.h"
#include "System/Console/Flags/ConsoleScreenBufferFlags.h"
#include "System/MemoryTools/MemoryHelperDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ConsoleScreenBufferInfoTesting::ConsoleScreenBufferInfoTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ConsoleScreenBufferInfoTesting)

void System::ConsoleScreenBufferInfoTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ConsoleScreenBufferInfoTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::ConsoleScreenBufferInfoTesting::RandomShuffleFlags()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RandomShuffleConsoleFlags);

    ASSERT_NOT_THROW_EXCEPTION_0(ConsoleScreenBufferInfoTest);

    return true;
}

void System::ConsoleScreenBufferInfoTesting::ConsoleScreenBufferInfoTest()
{
    for (auto index = 0u; index < GetMaxSize(); ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoConsoleScreenBufferInfoTest, index);
    }
}

void System::ConsoleScreenBufferInfoTesting::DoConsoleScreenBufferInfoTest(size_t index)
{
    const auto desiredAccessGeneric = GetDesiredAccessGeneric(index) | DesiredAccessGeneric::Read;
    const auto consoleScreenBufferShareMode = GetConsoleScreenBufferShareMode(index);

    const auto attributesConsoleHandle = CreateSystemConsoleScreenBuffer(desiredAccessGeneric, consoleScreenBufferShareMode, nullptr);

    ASSERT_NOT_THROW_EXCEPTION_1(GetSystemConsoleScreenBufferInfoTest, attributesConsoleHandle);

    ASSERT_TRUE(CloseSystemConsole(attributesConsoleHandle));
}

void System::ConsoleScreenBufferInfoTesting::GetSystemConsoleScreenBufferInfoTest(WindowsHandle attributesConsoleHandle)
{
    ConsoleScreenBufferInfo consoleScreenBufferInfo{};
    ASSERT_TRUE(GetSystemConsoleScreenBufferInfo(attributesConsoleHandle, &consoleScreenBufferInfo));

    auto consoleScreenBufferInfoEx = GetWindowsStructDefaultSize<ConsoleScreenBufferInfoEx>();
    ASSERT_TRUE(GetSystemConsoleScreenBufferInfo(attributesConsoleHandle, &consoleScreenBufferInfoEx));

    ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, consoleScreenBufferInfo, consoleScreenBufferInfoEx);
}

void System::ConsoleScreenBufferInfoTesting::EqualTest(const ConsoleScreenBufferInfo& consoleScreenBufferInfo, const ConsoleScreenBufferInfoEx& consoleScreenBufferInfoEx)
{
    ASSERT_ENUM_EQUAL(UnderlyingCastEnum<TextColour>(consoleScreenBufferInfo.wAttributes), TextColour::White);
    ASSERT_ENUM_EQUAL(UnderlyingCastEnum<TextColour>(consoleScreenBufferInfoEx.wAttributes), TextColour::White);
    ASSERT_ENUM_EQUAL(UnderlyingCastEnum<TextColour>(consoleScreenBufferInfoEx.wPopupAttributes), TextColour::White);

    ASSERT_EQUAL(consoleScreenBufferInfo.dwCursorPosition.X, consoleScreenBufferInfoEx.dwCursorPosition.X);
    ASSERT_EQUAL(consoleScreenBufferInfo.dwCursorPosition.Y, consoleScreenBufferInfoEx.dwCursorPosition.Y);
    ASSERT_EQUAL(consoleScreenBufferInfo.dwSize.X, consoleScreenBufferInfoEx.dwSize.X);
    ASSERT_EQUAL(consoleScreenBufferInfo.dwSize.Y, consoleScreenBufferInfoEx.dwSize.Y);
    ASSERT_EQUAL(consoleScreenBufferInfo.dwMaximumWindowSize.X, consoleScreenBufferInfoEx.dwMaximumWindowSize.X);
    ASSERT_EQUAL(consoleScreenBufferInfo.dwMaximumWindowSize.Y, consoleScreenBufferInfoEx.dwMaximumWindowSize.Y);
    ASSERT_EQUAL(consoleScreenBufferInfo.srWindow.Bottom, consoleScreenBufferInfoEx.srWindow.Bottom);
    ASSERT_EQUAL(consoleScreenBufferInfo.srWindow.Left, consoleScreenBufferInfoEx.srWindow.Left);
    ASSERT_EQUAL(consoleScreenBufferInfo.srWindow.Right, consoleScreenBufferInfoEx.srWindow.Right);
    ASSERT_EQUAL(consoleScreenBufferInfo.srWindow.Top, consoleScreenBufferInfoEx.srWindow.Top);
}
