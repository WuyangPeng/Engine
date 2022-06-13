///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 13:03)

#include "BackgroundColourTesting.h"
#include "System/Console/ConsoleColours.h"
#include "System/Console/ConsoleHandle.h"
#include "System/Console/Flags/ConsoleColoursFlags.h"
#include "System/Console/Flags/ConsoleHandleFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::BackgroundColourTesting::BackgroundColourTesting(const OStreamShared& stream)
    : ParentType{ stream },
      standardHandleFlags{ StandardHandle::Output, StandardHandle::Error },
      backgroundColourFlags{ BackgroundColour::Black,
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
      backgroundColourFlagsMapping{ { BackgroundColour::Black, TextColour::White },
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
    shuffle(standardHandleFlags.begin(), standardHandleFlags.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(BackgroundColourTest);

    return true;
}

void System::BackgroundColourTesting::BackgroundColourTest()
{
    for (auto index = 0u; index < backgroundColourFlags.size(); ++index)
    {
        const auto standardHandleFlag = standardHandleFlags.at(index % standardHandleFlags.size());
        const auto backgroundColourFlag = backgroundColourFlags.at(index);
        const auto textColourFlag = backgroundColourFlagsMapping.at(backgroundColourFlag);

        const auto consoleCommonFlag = ConsoleCommon::Default;

        ASSERT_TRUE(SetSystemConsoleTextAttribute(GetStandardHandle(standardHandleFlag), textColourFlag, backgroundColourFlag, consoleCommonFlag));

        PrintMessage(standardHandleFlag, textColourFlag, backgroundColourFlag, consoleCommonFlag);
    }
}

void System::BackgroundColourTesting::SetDefaultTextAttribute()
{
    for (auto value : standardHandleFlags)
    {
        ASSERT_TRUE(SetSystemConsoleDefaultTextAttribute(GetStandardHandle(value)));
    }
}
