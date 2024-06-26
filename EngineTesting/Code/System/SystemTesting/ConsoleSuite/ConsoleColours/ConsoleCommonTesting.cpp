/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 18:27)

#include "ConsoleCommonTesting.h"
#include "System/Console/ConsoleColour.h"
#include "System/Console/ConsoleHandle.h"
#include "System/Console/Flags/ConsoleColoursFlags.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ConsoleCommonTesting::ConsoleCommonTesting(const OStreamShared& stream)
    : ParentType{ stream },
      consoleCommons{ ConsoleCommon::Default,
                      ConsoleCommon::LeadingByte,
                      ConsoleCommon::TrailingByte,
                      ConsoleCommon::GridHorizontal,
                      ConsoleCommon::GridLVertical,
                      ConsoleCommon::GridRVertical,
                      ConsoleCommon::ReverseVideo,
                      ConsoleCommon::Underscore,
                      ConsoleCommon::SingleByteCharacterSetDoubleByteCharacterSet },
      randomEngine{ GetEngineRandomSeed() }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ConsoleCommonTesting)

void System::ConsoleCommonTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ConsoleCommonTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
    ASSERT_NOT_THROW_EXCEPTION_0(SetDefaultTextAttribute);
}

bool System::ConsoleCommonTesting::RandomShuffleFlags()
{
    ASSERT_NOT_THROW_EXCEPTION_1(RandomShuffleStandardHandle, randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(ConsoleCommonTest);

    return true;
}

void System::ConsoleCommonTesting::ConsoleCommonTest()
{
    for (auto index = 0u; index < consoleCommons.size(); ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoConsoleCommonTest, index);
    }
}

void System::ConsoleCommonTesting::DoConsoleCommonTest(size_t index)
{
    const auto standardHandle = GetConsoleStandardHandle(index);
    const auto consoleCommon = consoleCommons.at(index % consoleCommons.size());
    constexpr auto textColour = TextColour::White;
    constexpr auto backgroundColour = BackgroundColour::Black;

    ASSERT_TRUE(SetSystemConsoleTextAttribute(GetStandardHandle(standardHandle), textColour, backgroundColour, consoleCommon));

    PrintMessage(standardHandle, textColour, backgroundColour, consoleCommon);
}
