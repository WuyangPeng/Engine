///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 13:04)

#include "TextColourTesting.h"
#include "System/Console/ConsoleColours.h"
#include "System/Console/ConsoleHandle.h"
#include "System/Console/Flags/ConsoleColoursFlags.h"
#include "System/Console/Flags/ConsoleHandleFlags.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::TextColourTesting::TextColourTesting(const OStreamShared& stream)
    : ParentType{ stream },
      standardHandleFlags{ StandardHandle::Output, StandardHandle::Error },
      textColourFlags{ TextColour::Black,
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
      textColourFlagsMapping{ { TextColour::Black, BackgroundColour::White },
                              { TextColour::Red, BackgroundColour::Black },
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
    shuffle(standardHandleFlags.begin(), standardHandleFlags.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(TextColourTest);

    return true;
}

void System::TextColourTesting::TextColourTest()
{
    for (auto index = 0u; index < textColourFlags.size(); ++index)
    {
        const auto standardHandleFlag = standardHandleFlags.at(index % standardHandleFlags.size());
        const auto textColourFlag = textColourFlags.at(index);

        const auto backgroundColourFlag = textColourFlagsMapping[textColourFlag];
        const auto consoleCommonFlag = ConsoleCommon::Default;

        ASSERT_TRUE(SetSystemConsoleTextAttribute(GetStandardHandle(standardHandleFlag), textColourFlag, backgroundColourFlag, consoleCommonFlag));

        PrintMessage(standardHandleFlag, textColourFlag, backgroundColourFlag, consoleCommonFlag);
    }
}

void System::TextColourTesting::SetDefaultTextAttribute()
{
    for (auto value : standardHandleFlags)
    {
        ASSERT_TRUE(SetSystemConsoleDefaultTextAttribute(GetStandardHandle(value)));
    }
}
