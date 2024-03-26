/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 18:25)

#include "BackgroundColourTesting.h"
#include "System/Console/ConsoleColour.h"
#include "System/Console/ConsoleHandle.h"
#include "System/Console/Flags/ConsoleColoursFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::BackgroundColourTesting::BackgroundColourTesting(const OStreamShared& stream)
    : ParentType{ stream },
      backgroundColourContainer{ BackgroundColour::Black,
                                 BackgroundColour::IntensifiedBlack,
                                 BackgroundColour::Red,
                                 BackgroundColour::IntensifiedRed,
                                 BackgroundColour::Green,
                                 BackgroundColour::IntensifiedGreen,
                                 BackgroundColour::Blue,
                                 BackgroundColour::IntensifiedBlue,
                                 BackgroundColour::Yellow,
                                 BackgroundColour::IntensifiedYellow,
                                 BackgroundColour::Cyan,
                                 BackgroundColour::IntensifiedCyan,
                                 BackgroundColour::Magenta,
                                 BackgroundColour::IntensifiedMagenta,
                                 BackgroundColour::White,
                                 BackgroundColour::IntensifiedWhite },
      backgroundColourMapping{ { BackgroundColour::Black, TextColour::White },
                               { BackgroundColour::Red, TextColour::White },
                               { BackgroundColour::Green, TextColour::Black },
                               { BackgroundColour::Blue, TextColour::White },
                               { BackgroundColour::Yellow, TextColour::White },
                               { BackgroundColour::Cyan, TextColour::Black },
                               { BackgroundColour::Magenta, TextColour::White },
                               { BackgroundColour::White, TextColour::Black },
                               { BackgroundColour::IntensifiedBlack, TextColour::White },
                               { BackgroundColour::IntensifiedRed, TextColour::White },
                               { BackgroundColour::IntensifiedGreen, TextColour::Black },
                               { BackgroundColour::IntensifiedBlue, TextColour::White },
                               { BackgroundColour::IntensifiedYellow, TextColour::Black },
                               { BackgroundColour::IntensifiedCyan, TextColour::Black },
                               { BackgroundColour::IntensifiedMagenta, TextColour::White },
                               { BackgroundColour::IntensifiedWhite, TextColour::Black } },
      randomEngine{ GetEngineRandomSeed() }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, BackgroundColourTesting)

void System::BackgroundColourTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::BackgroundColourTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
    ASSERT_NOT_THROW_EXCEPTION_0(SetDefaultTextAttribute);
}

bool System::BackgroundColourTesting::RandomShuffleFlags()
{
    ASSERT_NOT_THROW_EXCEPTION_1(RandomShuffleStandardHandle, randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(BackgroundColourTest);

    return true;
}

void System::BackgroundColourTesting::BackgroundColourTest()
{
    for (auto index = 0u; index < backgroundColourContainer.size(); ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoBackgroundColourTest, index);
    }
}

void System::BackgroundColourTesting::DoBackgroundColourTest(size_t index)
{
    const auto standardHandle = GetConsoleStandardHandle(index);
    const auto backgroundColour = backgroundColourContainer.at(index);
    const auto textColour = backgroundColourMapping.at(backgroundColour);
    constexpr auto consoleCommon = ConsoleCommon::Default;

    ASSERT_TRUE(SetSystemConsoleTextAttribute(GetStandardHandle(standardHandle), textColour, backgroundColour, consoleCommon));

    PrintMessage(standardHandle, textColour, backgroundColour, consoleCommon);
}
