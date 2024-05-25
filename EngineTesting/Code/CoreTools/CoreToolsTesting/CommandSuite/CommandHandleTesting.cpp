/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/24 13:17)

#include "CommandHandleTesting.h"
#include "CoreTools/Command/Command.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/Math.h"

namespace  
{
    const auto* commandLine = "MyProgram -debug -integer 51 -float 16.4 -double 5.21 -string value -fileName filename";
}

CoreTools::CommandHandleTesting::CommandHandleTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CommandHandleTesting)

void CoreTools::CommandHandleTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CommandHandleTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SucceedTest);
    ASSERT_THROW_EXCEPTION_0(SetMinValueExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetMaxValueExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetInfimumValueExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetSupremumValueExceptionTest);
}

void CoreTools::CommandHandleTesting::SucceedTest()
{
    CommandHandle command{ commandLine };

    ASSERT_NOT_THROW_EXCEPTION_1(AnalysisBoolTest, command);
    ASSERT_NOT_THROW_EXCEPTION_1(AnalysisDoubleTest, command);
    ASSERT_NOT_THROW_EXCEPTION_1(AnalysisFileNameTest, command);
    ASSERT_NOT_THROW_EXCEPTION_1(AnalysisFloatTest, command);
    ASSERT_NOT_THROW_EXCEPTION_1(AnalysisIntegerTest, command);
    ASSERT_NOT_THROW_EXCEPTION_1(AnalysisStringTest, command);

    const auto count = command.GetExcessArgumentsCount();
    ASSERT_EQUAL(count, 0);
}

void CoreTools::CommandHandleTesting::AnalysisBoolTest(CommandHandle& command)
{
    const auto count = command.GetExcessArgumentsCount();
    ASSERT_EQUAL(count, 6);

    const auto excessArguments = command.ExcessArguments();
    ASSERT_EQUAL(excessArguments, "debug");
    ASSERT_TRUE(command.GetBoolean(excessArguments));

    command.SetUsed(excessArguments);
    ASSERT_FALSE(command.GetBoolean("debug1"));
}

void CoreTools::CommandHandleTesting::AnalysisDoubleTest(CommandHandle& command)
{
    const auto count = command.GetExcessArgumentsCount();
    ASSERT_EQUAL(count, 5);

    command.SetMaxValue(6.0);

    const auto excessArguments = command.ExcessArguments();
    ASSERT_EQUAL(excessArguments, "double");
    ASSERT_APPROXIMATE(command.GetDouble(excessArguments), 5.21, Mathematics::MathD::GetZeroTolerance());

    command.SetUsed(excessArguments);
    command.ClearBoundary();
    command.SetMinValue(16.3);
}

void CoreTools::CommandHandleTesting::AnalysisFileNameTest(CommandHandle& command)
{
    const auto count = command.GetExcessArgumentsCount();
    ASSERT_EQUAL(count, 4);

    const auto excessArguments = command.ExcessArguments();
    ASSERT_EQUAL(excessArguments, "fileName");
    ASSERT_EQUAL(command.GetFileName(), "filename");

    command.SetFileNameUsed();
}

void CoreTools::CommandHandleTesting::AnalysisFloatTest(CommandHandle& command)
{
    const auto count = command.GetExcessArgumentsCount();
    ASSERT_EQUAL(count, 3);

    const auto excessArguments = command.ExcessArguments();
    ASSERT_EQUAL(excessArguments, "float");
    ASSERT_APPROXIMATE(command.GetFloat(excessArguments), 16.4f, Mathematics::MathF::GetZeroTolerance());

    command.SetUsed(excessArguments);
}

void CoreTools::CommandHandleTesting::AnalysisIntegerTest(CommandHandle& command)
{
    const auto count = command.GetExcessArgumentsCount();
    ASSERT_EQUAL(count, 2);

    command.ClearBoundary();
    command.SetSupremumValue(53).SetInfimumValue(50);

    const auto excessArguments = command.ExcessArguments();
    ASSERT_EQUAL(excessArguments, "integer");
    ASSERT_EQUAL(command.GetInteger(excessArguments), 51);

    command.SetUsed(excessArguments);
}

void CoreTools::CommandHandleTesting::AnalysisStringTest(CommandHandle& command)
{
    const auto count = command.GetExcessArgumentsCount();
    ASSERT_EQUAL(count, 1);

    const auto excessArguments = command.ExcessArguments();
    ASSERT_EQUAL(excessArguments, "string");
    ASSERT_EQUAL(command.GetString(excessArguments), "value");

    command.SetUsed(excessArguments);
}

void CoreTools::CommandHandleTesting::SetMinValueExceptionTest()
{
    CommandHandle command{ commandLine };

    command.SetMinValue(17.0);

    std::ignore = command.GetFloat("float");
}

void CoreTools::CommandHandleTesting::SetMaxValueExceptionTest()
{
    CommandHandle command{ commandLine };

    command.SetMaxValue(4.0);

    std::ignore = command.GetDouble("double");
}

void CoreTools::CommandHandleTesting::SetInfimumValueExceptionTest()
{
    CommandHandle command{ commandLine };

    command.SetInfimumValue(52);

    std::ignore = command.GetInteger("integer");
}

void CoreTools::CommandHandleTesting::SetSupremumValueExceptionTest()
{
    CommandHandle command{ commandLine };

    command.SetSupremumValue(50);

    std::ignore = command.GetInteger("integer");
}
