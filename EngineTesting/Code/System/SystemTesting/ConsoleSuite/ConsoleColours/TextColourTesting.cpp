///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/03 20:18)

#include "TextColourTesting.h"
#include "System/Console/ConsoleColours.h"
#include "System/Console/ConsoleHandle.h"
#include "System/Console/Flags/ConsoleColoursFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::TextColourTesting::TextColourTesting(const OStreamShared& stream)
    : ParentType{ stream },
      textColours{ TextColour::Black,
                   TextColour::IntensifiedBlack,
                   TextColour::Red,
                   TextColour::IntensifiedRed,
                   TextColour::Green,
                   TextColour::IntensifiedGreen,
                   TextColour::Blue,
                   TextColour::IntensifiedBlue,
                   TextColour::Yellow,
                   TextColour::IntensifiedYellow,
                   TextColour::Cyan,
                   TextColour::IntensifiedCyan,
                   TextColour::Magenta,
                   TextColour::IntensifiedMagenta,
                   TextColour::White,
                   TextColour::IntensifiedWhite },
      textColourMapping{ { TextColour::Black, BackgroundColour::White },
                         { TextColour::Red, BackgroundColour::Black },
                         { TextColour::Green, BackgroundColour::Black },
                         { TextColour::Blue, BackgroundColour::White },
                         { TextColour::Yellow, BackgroundColour::Black },
                         { TextColour::Cyan, BackgroundColour::Black },
                         { TextColour::Magenta, BackgroundColour::Black },
                         { TextColour::White, BackgroundColour::Black },
                         { TextColour::IntensifiedBlack, BackgroundColour::White },
                         { TextColour::IntensifiedRed, BackgroundColour::Black },
                         { TextColour::IntensifiedGreen, BackgroundColour::Black },
                         { TextColour::IntensifiedBlue, BackgroundColour::White },
                         { TextColour::IntensifiedYellow, BackgroundColour::Black },
                         { TextColour::IntensifiedCyan, BackgroundColour::Black },
                         { TextColour::IntensifiedMagenta, BackgroundColour::Black },
                         { TextColour::IntensifiedWhite, BackgroundColour::Black } },
      randomEngine{ GetEngineRandomSeed() }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, TextColourTesting)

void System::TextColourTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::TextColourTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
    ASSERT_NOT_THROW_EXCEPTION_0(SetDefaultTextAttribute);
}

bool System::TextColourTesting::RandomShuffleFlags()
{
    ASSERT_NOT_THROW_EXCEPTION_1(RandomShuffleStandardHandle, randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(TextColourTest);

    return true;
}

void System::TextColourTesting::TextColourTest()
{
    for (auto index = 0u; index < textColours.size(); ++index)
    {
        DoTextColourTest(index);
    }
}

void System::TextColourTesting::DoTextColourTest(size_t index)
{
    const auto standardHandle = GetConsoleStandardHandle(index);
    const auto textColour = textColours.at(index);
    const auto backgroundColour = textColourMapping.at(textColour);
    const auto consoleCommon = ConsoleCommon::Default;

    ASSERT_TRUE(SetSystemConsoleTextAttribute(GetStandardHandle(standardHandle), textColour, backgroundColour, consoleCommon));

    PrintMessage(standardHandle, textColour, backgroundColour, consoleCommon);
}
