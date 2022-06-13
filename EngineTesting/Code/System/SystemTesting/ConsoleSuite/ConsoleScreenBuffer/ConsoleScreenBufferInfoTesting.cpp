///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 13:05)

#include "ConsoleScreenBufferInfoTesting.h"
#include "System/Console/ConsoleHandle.h"
#include "System/Console/ConsoleScreenBuffer.h"
#include "System/Console/Flags/ConsoleColoursFlags.h"
#include "System/Console/Flags/ConsoleScreenBufferFlags.h"
#include "System/MemoryTools/MemoryHelperDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::max;

System::ConsoleScreenBufferInfoTesting::ConsoleScreenBufferInfoTesting(const OStreamShared& stream)
    : ParentType{ stream },
      desiredAccessGenericFlags{ DesiredAccessGeneric::Read, DesiredAccessGeneric::ReadAndWrite },
      consoleScreenBufferShareModeFlags{ ConsoleScreenBufferShareMode::Read, ConsoleScreenBufferShareMode::Write, ConsoleScreenBufferShareMode::ReadAndWrite },
      maxSize{ max(desiredAccessGenericFlags.size(), consoleScreenBufferShareModeFlags.size()) }
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
    shuffle(desiredAccessGenericFlags.begin(), desiredAccessGenericFlags.end(), randomEngine);
    shuffle(consoleScreenBufferShareModeFlags.begin(), consoleScreenBufferShareModeFlags.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(ConsoleScreenBufferInfoTest);

    return true;
}

void System::ConsoleScreenBufferInfoTesting::ConsoleScreenBufferInfoTest()
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        auto desiredAccessGenericFlag = desiredAccessGenericFlags.at(index % desiredAccessGenericFlags.size());

        auto consoleScreenBufferShareModeFlag = consoleScreenBufferShareModeFlags.at(index % consoleScreenBufferShareModeFlags.size());

        auto attributesConsoleHandle = CreateSystemConsoleScreenBuffer(desiredAccessGenericFlag, consoleScreenBufferShareModeFlag, nullptr);

        ConsoleScreenBufferInfo consoleScreenBufferInfo{};
        ASSERT_TRUE(GetSystemConsoleScreenBufferInfo(attributesConsoleHandle, &consoleScreenBufferInfo));

        auto consoleScreenBufferInfoEx = GetWindowsStructDefaultSize<ConsoleScreenBufferInfoEx>();
        ASSERT_TRUE(GetSystemConsoleScreenBufferInfo(attributesConsoleHandle, &consoleScreenBufferInfoEx));

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

        ASSERT_TRUE(CloseSystemConsole(attributesConsoleHandle));
    }
}
