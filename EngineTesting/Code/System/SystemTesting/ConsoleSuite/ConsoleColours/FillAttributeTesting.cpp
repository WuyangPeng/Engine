///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 13:04)

#include "FillAttributeTesting.h"
#include "System/Console/ConsoleColours.h"
#include "System/Console/ConsoleHandle.h"
#include "System/Console/Flags/ConsoleColoursFlags.h"
#include "System/Console/Flags/ConsoleHandleFlags.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/TemplateTools/MaxElement.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

using std::array;

System::FillAttributeTesting::FillAttributeTesting(const OStreamShared& stream)
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
      consoleCommonFlags{ ConsoleCommon::Default,
                          ConsoleCommon::LeadingByte,
                          ConsoleCommon::TrailingByte,
                          ConsoleCommon::GridHorizontal,
                          ConsoleCommon::GridLvertical,
                          ConsoleCommon::GridRvertical,
                          ConsoleCommon::ReverseVideo,
                          ConsoleCommon::Underscore,
                          ConsoleCommon::SbcsDbcs },
      randomEngine{ GetEngineRandomSeed() },
      maxSize{ CoreTools::MaxElement<size_t>({ standardHandleFlags.size(), textColourFlags.size(), backgroundColourFlags.size(), consoleCommonFlags.size() }) }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FillAttributeTesting)

void System::FillAttributeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::FillAttributeTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::FillAttributeTesting::RandomShuffleFlags()
{
    shuffle(standardHandleFlags.begin(), standardHandleFlags.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(FillAttributeTest);

    return true;
}

void System::FillAttributeTesting::FillAttributeTest()
{
    constexpr auto bufferSize = 256u;
    array<WindowsWord, bufferSize> readAttribute{};

    constexpr ConsoleCoord coord{ 0, 0 };

    for (auto index = 0u; index < maxSize; ++index)
    {
        const auto standardHandle = standardHandleFlags.at(index % standardHandleFlags.size());

        const auto textColour = textColourFlags.at(index % textColourFlags.size());
        const auto backgroundColour = backgroundColourFlags.at(index % backgroundColourFlags.size());
        const auto consoleCommon = consoleCommonFlags.at(index % consoleCommonFlags.size());
        const auto attribute = EnumCastUnderlying(textColour) | EnumCastUnderlying(backgroundColour) | EnumCastUnderlying(consoleCommon);

        auto consoleHandle = GetStandardHandle(standardHandle);

        WindowsDWord numberOfAttributesWrite{ 0 };
        ASSERT_TRUE(FillSystemConsoleOutputAttribute(consoleHandle, boost::numeric_cast<WindowsWord>(attribute), bufferSize, coord, &numberOfAttributesWrite));

        ASSERT_EQUAL(numberOfAttributesWrite, bufferSize);

        WindowsDWord numberOfAttributesRead{ 0 };
        ASSERT_TRUE(ReadSystemConsoleOutputAttribute(consoleHandle, readAttribute.data(), bufferSize, coord, &numberOfAttributesRead));

        for (auto value : readAttribute)
        {
            const auto writeTextColour = attribute & 0x000F;
            const auto readTextColour = value & 0x000F;

            ASSERT_EQUAL(writeTextColour, readTextColour);

            const auto writeBackgroundColour = attribute & 0x00F0;
            const auto readBackgroundColour = value & 0x00F0;

            ASSERT_EQUAL(writeBackgroundColour, readBackgroundColour);
        }
    }
}
