///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/15 22:07)

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
      standardHandleFlags{ StandardHandle::Output, StandardHandle::Error },
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
    shuffle(standardHandleFlags.begin(), standardHandleFlags.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(ConsoleCommonTest);

    return true;
}

void System::ConsoleCommonTesting::ConsoleCommonTest()
{
    for (auto index = 0u; index < consoleCommonFlags.size(); ++index)
    {
        auto standardHandleFlag = standardHandleFlags.at(index % standardHandleFlags.size());
        auto consoleCommonFlag = consoleCommonFlags.at(index % consoleCommonFlags.size());

        const auto textColourFlag = TextColour::White;
        const auto backgroundColourFlag = BackgroundColour::Black;

        ASSERT_TRUE(SetSystemConsoleTextAttribute(GetStandardHandle(standardHandleFlag), textColourFlag, backgroundColourFlag, consoleCommonFlag));

        PrintMessage(standardHandleFlag, textColourFlag, backgroundColourFlag, consoleCommonFlag);
    }
}

void System::ConsoleCommonTesting::SetDefaultTextAttribute()
{
    for (auto value : standardHandleFlags)
    {
        ASSERT_TRUE(SetSystemConsoleDefaultTextAttribute(GetStandardHandle(value)));
    }
}