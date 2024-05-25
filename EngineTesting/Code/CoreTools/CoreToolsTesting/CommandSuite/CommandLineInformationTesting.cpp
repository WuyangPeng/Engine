/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/24 22:01)

#include "CommandLineInformationTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Command/CommandLineInformation.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

#include <vector>

namespace
{
    const auto* commandLine = "MyProgram -debug -integer 5 -float 6.4 -double 5.2 -string value -fileName filename";
}

CoreTools::CommandLineInformationTesting::CommandLineInformationTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CommandLineInformationTesting)

void CoreTools::CommandLineInformationTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CommandLineInformationTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainCommandLineInformationSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WinMainCommandLineInformationSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetBooleanFalseTest);
    ASSERT_THROW_EXCEPTION_0(GetIntegerExceptionTest);
    ASSERT_THROW_EXCEPTION_0(GetFloatExceptionTest);
    ASSERT_THROW_EXCEPTION_0(GetDoubleExceptionTest);
    ASSERT_THROW_EXCEPTION_0(GetStringExceptionTest);
    ASSERT_THROW_EXCEPTION_0(GetFileNameExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WinMainNullCommandLineInformationSucceedTest);
}

void CoreTools::CommandLineInformationTesting::LineInformationSucceedTest(CommandLineInformation& commandLineInformation)
{
    ASSERT_NOT_THROW_EXCEPTION_1(AnalysisBoolTest, commandLineInformation);
    ASSERT_NOT_THROW_EXCEPTION_1(AnalysisDoubleTest, commandLineInformation);
    ASSERT_NOT_THROW_EXCEPTION_1(AnalysisFileNameTest, commandLineInformation);
    ASSERT_NOT_THROW_EXCEPTION_1(AnalysisFloatTest, commandLineInformation);
    ASSERT_NOT_THROW_EXCEPTION_1(AnalysisIntegerTest, commandLineInformation);
    ASSERT_NOT_THROW_EXCEPTION_1(AnalysisStringTest, commandLineInformation);

    const auto count = commandLineInformation.GetExcessArgumentsCount();
    ASSERT_EQUAL(count, 0);
}

void CoreTools::CommandLineInformationTesting::AnalysisBoolTest(CommandLineInformation& commandLineInformation)
{
    const auto count = commandLineInformation.GetExcessArgumentsCount();
    ASSERT_EQUAL(count, 6);

    const auto excessArguments = commandLineInformation.ExcessArguments();
    ASSERT_EQUAL(excessArguments, "debug");
    ASSERT_TRUE(commandLineInformation.GetBoolean(excessArguments));

    commandLineInformation.SetUsed(excessArguments);
    ASSERT_FALSE(commandLineInformation.GetBoolean("debug1"));
}

void CoreTools::CommandLineInformationTesting::AnalysisDoubleTest(CommandLineInformation& commandLineInformation)
{
    const auto count = commandLineInformation.GetExcessArgumentsCount();
    ASSERT_EQUAL(count, 5);

    const auto excessArguments = commandLineInformation.ExcessArguments();
    ASSERT_EQUAL(excessArguments, "double");
    ASSERT_APPROXIMATE(commandLineInformation.GetDouble(excessArguments), 5.2, Mathematics::MathD::GetZeroTolerance());

    commandLineInformation.SetUsed(excessArguments);
}

void CoreTools::CommandLineInformationTesting::AnalysisFileNameTest(CommandLineInformation& commandLineInformation)
{
    const auto count = commandLineInformation.GetExcessArgumentsCount();
    ASSERT_EQUAL(count, 4);

    const auto excessArguments = commandLineInformation.ExcessArguments();
    ASSERT_EQUAL(excessArguments, "fileName");
    ASSERT_EQUAL(commandLineInformation.GetFileName(), "filename");

    commandLineInformation.SetFileNameUsed();
}

void CoreTools::CommandLineInformationTesting::AnalysisFloatTest(CommandLineInformation& commandLineInformation)
{
    const auto count = commandLineInformation.GetExcessArgumentsCount();
    ASSERT_EQUAL(count, 3);

    const auto excessArguments = commandLineInformation.ExcessArguments();
    ASSERT_EQUAL(excessArguments, "float");
    ASSERT_APPROXIMATE(commandLineInformation.GetFloat(excessArguments), 6.4f, Mathematics::MathF::GetZeroTolerance());

    commandLineInformation.SetUsed(excessArguments);
}

void CoreTools::CommandLineInformationTesting::AnalysisIntegerTest(CommandLineInformation& commandLineInformation)
{
    const auto count = commandLineInformation.GetExcessArgumentsCount();
    ASSERT_EQUAL(count, 2);

    const auto excessArguments = commandLineInformation.ExcessArguments();
    ASSERT_EQUAL(excessArguments, "integer");
    ASSERT_EQUAL(commandLineInformation.GetInteger(excessArguments), 5);

    commandLineInformation.SetUsed(excessArguments);
}

void CoreTools::CommandLineInformationTesting::AnalysisStringTest(CommandLineInformation& commandLineInformation)
{
    const auto count = commandLineInformation.GetExcessArgumentsCount();
    ASSERT_EQUAL(count, 1);

    const auto excessArguments = commandLineInformation.ExcessArguments();
    ASSERT_EQUAL(excessArguments, "string");
    ASSERT_EQUAL(commandLineInformation.GetString(excessArguments), "value");

    commandLineInformation.SetUsed(excessArguments);
}

void CoreTools::CommandLineInformationTesting::MainCommandLineInformationSucceedTest()
{
#include SYSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26492)

    std::vector charVector{ const_cast<char*>("MyProgram"),
                            const_cast<char*>("-debug"),

                            const_cast<char*>("-integer"),
                            const_cast<char*>("5"),

                            const_cast<char*>("-float"),
                            const_cast<char*>("6.4"),

                            const_cast<char*>("-double"),
                            const_cast<char*>("5.2"),

                            const_cast<char*>("-string"),
                            const_cast<char*>("value"),

                            const_cast<char*>("-fileName"),
                            const_cast<char*>("filename") };

#include SYSTEM_WARNING_POP

    CommandLineInformation commandLineInformation{ boost::numeric_cast<int>(charVector.size()), charVector.data() };

    ASSERT_NOT_THROW_EXCEPTION_1(LineInformationSucceedTest, commandLineInformation);
}

void CoreTools::CommandLineInformationTesting::WinMainCommandLineInformationSucceedTest()
{
    CommandLineInformation commandLineInformation{ commandLine };

    ASSERT_NOT_THROW_EXCEPTION_1(LineInformationSucceedTest, commandLineInformation);
}

void CoreTools::CommandLineInformationTesting::GetBooleanFalseTest()
{
#include SYSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26492)

    std::vector charVector{ const_cast<char*>("MyProgram"), const_cast<char*>("-debug") };

#include SYSTEM_WARNING_POP

    const CommandLineInformation commandLineInformation{ boost::numeric_cast<int>(charVector.size()), charVector.data() };

    ASSERT_FALSE(commandLineInformation.GetBoolean("release"));
}

void CoreTools::CommandLineInformationTesting::GetIntegerExceptionTest()
{
    const CommandLineInformation commandLineInformation{ commandLine };

    std::ignore = commandLineInformation.GetInteger("fileName");
}

void CoreTools::CommandLineInformationTesting::GetFloatExceptionTest()
{
    const CommandLineInformation commandLineInformation{ commandLine };

    std::ignore = commandLineInformation.GetFloat("Float");
}

void CoreTools::CommandLineInformationTesting::GetDoubleExceptionTest()
{
    const CommandLineInformation commandLineInformation{ commandLine };

    std::ignore = commandLineInformation.GetDouble("debug");
}

void CoreTools::CommandLineInformationTesting::GetStringExceptionTest()
{
#include SYSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26492)

    std::vector charVector{ const_cast<char*>("MyProgram"),
                            const_cast<char*>("-debug"),
                            const_cast<char*>("-string"),
                            const_cast<char*>("value") };

#include SYSTEM_WARNING_POP

    const CommandLineInformation commandLineInformation{ boost::numeric_cast<int>(charVector.size()), charVector.data() };

    std::ignore = commandLineInformation.GetString("value");
}

void CoreTools::CommandLineInformationTesting::GetFileNameExceptionTest()
{
#include SYSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26492)

    std::vector charVector{ const_cast<char*>("MyProgram"), const_cast<char*>("-debug") };

#include SYSTEM_WARNING_POP

    const CommandLineInformation commandLineInformation{ boost::numeric_cast<int>(charVector.size()), charVector.data() };

    std::ignore = commandLineInformation.GetFileName();
}

void CoreTools::CommandLineInformationTesting::WinMainNullCommandLineInformationSucceedTest()
{
    const auto* path = R"("E:/TCRE/Engine/EngineWindows/Framework/../../DebugWindows/FrameworkTestingD.exe")";

    const CommandLineInformation commandLineInformation{ path };

    ASSERT_EQUAL(commandLineInformation.GetExcessArgumentsCount(), 0);
}
