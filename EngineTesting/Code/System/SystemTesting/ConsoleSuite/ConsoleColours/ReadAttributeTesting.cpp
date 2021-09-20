///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/04/09 16:04)

#include "ReadAttributeTesting.h"
#include "System/Console/ConsoleColours.h"
#include "System/Console/ConsoleHandle.h"
#include "System/Console/Flags/ConsoleColoursFlags.h"
#include "System/Console/Flags/ConsoleHandleFlags.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

using std::array;

System::ReadAttributeTesting::ReadAttributeTesting(const OStreamShared& stream)
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
      randomEngine{ GetEngineRandomSeed() }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ReadAttributeTesting)

void System::ReadAttributeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ReadAttributeTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::ReadAttributeTesting::RandomShuffleFlags()
{
    shuffle(standardHandleFlags.begin(), standardHandleFlags.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(ReadAttributeTest);

    return true;
}

void System::ReadAttributeTesting::ReadAttributeTest()
{
    constexpr auto bufferSize = 256u;
    array<WindowsWord, bufferSize> attribute{};
    constexpr ConsoleCoord readCoord{ 0, 0 };

    for (auto value : standardHandleFlags)
    {
        auto consoleHandle = GetStandardHandle(value);

        WindowsDWord numberOfAttributesRead{ 0 };
        ASSERT_TRUE(ReadSystemConsoleOutputAttribute(consoleHandle, attribute.data(), bufferSize, readCoord, &numberOfAttributesRead));

        ASSERT_EQUAL(numberOfAttributesRead, bufferSize);

        for (auto word : attribute)
        {
            // 根据TextColour、BackgroundColour和ConsoleCommon枚举的实际值所占的位得出0x000F、0x00F0和0xFF00的值。
            ASSERT_UNEQUAL_DO_NOT_USE_MESSAGE(textColourFlags.find(UnderlyingCastEnum<TextColour>(word & 0x000F)), textColourFlags.end());
            ASSERT_UNEQUAL_DO_NOT_USE_MESSAGE(backgroundColourFlags.find(UnderlyingCastEnum<BackgroundColour>(word & 0x00F0)), backgroundColourFlags.end());
            ASSERT_UNEQUAL_DO_NOT_USE_MESSAGE(consoleCommonFlags.find(UnderlyingCastEnum<ConsoleCommon>(word & 0xFF00)), consoleCommonFlags.end());
        }
    }
}
