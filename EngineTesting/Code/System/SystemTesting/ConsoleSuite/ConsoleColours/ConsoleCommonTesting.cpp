///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/03 19:50)

#include "ConsoleCommonTesting.h"
#include "System/Console/ConsoleColours.h"
#include "System/Console/ConsoleHandle.h"
#include "System/Console/Flags/ConsoleColoursFlags.h"
#include "System/Console/Flags/ConsoleHandleFlags.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ConsoleCommonTesting::ConsoleCommonTesting(const OStreamShared& stream)
    : ParentType{ stream },
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
    for (auto index = 0u; index < consoleCommonFlags.size(); ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoConsoleCommonTest, index);
    }
}

void System::ConsoleCommonTesting::DoConsoleCommonTest(size_t index)
{
    const auto standardHandle = GetConsoleStandardHandle(index);
    const auto consoleCommon = consoleCommonFlags.at(index % consoleCommonFlags.size());
    constexpr auto textColour = TextColour::White;
    constexpr auto backgroundColour = BackgroundColour::Black;

    ASSERT_TRUE(SetSystemConsoleTextAttribute(GetStandardHandle(standardHandle), textColour, backgroundColour, consoleCommon));

    PrintMessage(standardHandle, textColour, backgroundColour, consoleCommon);
}
