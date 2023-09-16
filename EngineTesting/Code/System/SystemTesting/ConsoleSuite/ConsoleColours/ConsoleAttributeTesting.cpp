///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 16:36)

#include "ConsoleAttributeTesting.h"
#include "System/Console/Flags/ConsoleColoursFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/TemplateTools/MaxElement.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ConsoleAttributeTesting::ConsoleAttributeTesting(const OStreamShared& stream)
    : ParentType{ stream },
      textColourContainer{ TextColour::Black,
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
      consoleCommons{ ConsoleCommon::Default,
                      ConsoleCommon::LeadingByte,
                      ConsoleCommon::TrailingByte,
                      ConsoleCommon::GridHorizontal,
                      ConsoleCommon::GridLVertical,
                      ConsoleCommon::GridRVertical,
                      ConsoleCommon::ReverseVideo,
                      ConsoleCommon::Underscore,
                      ConsoleCommon::SbcsDbcs },
      randomEngine{ GetEngineRandomSeed() },
      maxSize{ CoreTools::MaxElement<size_t>({ GetStandardHandleSize(), textColourContainer.size(), backgroundColourContainer.size(), consoleCommons.size() }) }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ConsoleAttributeTesting)

void System::ConsoleAttributeTesting::RandomShuffleConsoleFlags()
{
    ASSERT_NOT_THROW_EXCEPTION_1(RandomShuffleStandardHandle, randomEngine);

    std::ranges::shuffle(textColourContainer, randomEngine);
    std::ranges::shuffle(backgroundColourContainer, randomEngine);
    std::ranges::shuffle(consoleCommons, randomEngine);
}

size_t System::ConsoleAttributeTesting::GetMaxSize() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return maxSize;
}

System::TextColour System::ConsoleAttributeTesting::GetTextColour(size_t index) const
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return textColourContainer.at(index % textColourContainer.size());
}

System::BackgroundColour System::ConsoleAttributeTesting::GetBackgroundColour(size_t index) const
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return backgroundColourContainer.at(index % backgroundColourContainer.size());
}

System::ConsoleCommon System::ConsoleAttributeTesting::GetConsoleCommon(size_t index) const
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return consoleCommons.at(index % consoleCommons.size());
}

bool System::ConsoleAttributeTesting::HasTextColour(TextColour textColour) const
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return std::ranges::find(textColourContainer, textColour) != textColourContainer.cend();
}

bool System::ConsoleAttributeTesting::HasBackgroundColour(BackgroundColour backgroundColour) const
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return std::ranges::find(backgroundColourContainer, backgroundColour) != backgroundColourContainer.cend();
}

bool System::ConsoleAttributeTesting::HasConsoleCommon(ConsoleCommon consoleCommon) const
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return std::ranges::find(consoleCommons, consoleCommon) != consoleCommons.cend();
}

void System::ConsoleAttributeTesting::ColourEqualTest(WindowsWord readAttribute, WindowsWord writeAttribute, int mask)
{
    const auto writeColour = writeAttribute & mask;
    const auto readColour = readAttribute & mask;

    ASSERT_EQUAL(writeColour, readColour);
}
