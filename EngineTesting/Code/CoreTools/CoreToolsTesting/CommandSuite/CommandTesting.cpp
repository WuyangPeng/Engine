///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:37)

#include "CommandTesting.h"
#include "CoreTools/Command/Command.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/Math.h"

CoreTools::CommandTesting::CommandTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CommandTesting)

void CoreTools::CommandTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CommandTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SucceedTest);
    ASSERT_THROW_EXCEPTION_0(SetMinValueExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetMaxValueExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetInfValueExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetSupValueExceptionTest);
}

void CoreTools::CommandTesting::SucceedTest()
{
    const auto* commandLine = "MyProgram -debug -integer 51 -float 16.4 -double 5.21 -string value -fileName filename";

    CommandHandle command{ commandLine };

    auto count = command.GetExcessArgumentsCount();

    ASSERT_EQUAL(count, 6);

    auto excessArguments = command.ExcessArguments();
    ASSERT_EQUAL(excessArguments, "debug");
    ASSERT_TRUE(command.GetBoolean(excessArguments));
    command.SetUsed(excessArguments);

    ASSERT_FALSE(command.GetBoolean("debug1"));

    count = command.GetExcessArgumentsCount();

    ASSERT_EQUAL(count, 5);

    command.SetMaxValue(6.0);

    excessArguments = command.ExcessArguments();
    ASSERT_EQUAL(excessArguments, "double");
    ASSERT_APPROXIMATE(command.GetDouble(excessArguments), 5.21, Mathematics::MathD::GetZeroTolerance());
    command.SetUsed(excessArguments);

    command.ClearBoundary();
    command.SetMinValue(16.3);

    count = command.GetExcessArgumentsCount();

    ASSERT_EQUAL(count, 4);

    excessArguments = command.ExcessArguments();
    ASSERT_EQUAL(excessArguments, "fileName");
    ASSERT_EQUAL(command.GetFileName(), "filename");

    command.SetFileNameUsed();

    count = command.GetExcessArgumentsCount();

    ASSERT_EQUAL(count, 3);

    excessArguments = command.ExcessArguments();
    ASSERT_EQUAL(excessArguments, "float");
    ASSERT_APPROXIMATE(command.GetFloat(excessArguments), 16.4f, Mathematics::MathF::GetZeroTolerance());
    command.SetUsed(excessArguments);

    count = command.GetExcessArgumentsCount();

    ASSERT_EQUAL(count, 2);

    command.ClearBoundary();
    command.SetSupValue(53).SetInfValue(50);

    excessArguments = command.ExcessArguments();
    ASSERT_EQUAL(excessArguments, "integer");
    ASSERT_EQUAL(command.GetInteger(excessArguments), 51);
    command.SetUsed(excessArguments);

    count = command.GetExcessArgumentsCount();

    ASSERT_EQUAL(count, 1);

    excessArguments = command.ExcessArguments();
    ASSERT_EQUAL(excessArguments, "string");
    ASSERT_EQUAL(command.GetString(excessArguments), "value");
    command.SetUsed(excessArguments);

    count = command.GetExcessArgumentsCount();

    ASSERT_EQUAL(count, 0);
}

void CoreTools::CommandTesting::SetMinValueExceptionTest()
{
    const auto* commandLine = "MyProgram -debug -integer 51 -float 16.4 -double 5.21 -string value -fileName filename";

    CommandHandle command{ commandLine };

    command.SetMinValue(17.0);

    MAYBE_UNUSED const auto value = command.GetFloat("float");
}

void CoreTools::CommandTesting::SetMaxValueExceptionTest()
{
    const auto* commandLine = "MyProgram -debug -integer 51 -float 16.4 -double 5.21 -string value -fileName filename";

    CommandHandle command{ commandLine };

    command.SetMaxValue(4.0);

    MAYBE_UNUSED const auto value = command.GetDouble("double");
}

void CoreTools::CommandTesting::SetInfValueExceptionTest()
{
    const auto* commandLine = "MyProgram -debug -integer 51 -float 16.4 -double 5.21 -string value -fileName filename";

    CommandHandle command{ commandLine };

    command.SetInfValue(52);

    MAYBE_UNUSED const auto value = command.GetInteger("integer");
}

void CoreTools::CommandTesting::SetSupValueExceptionTest()
{
    const auto* commandLine = "MyProgram -debug -integer 51 -float 16.4 -double 5.21 -string value -fileName filename";

    CommandHandle command{ commandLine };

    command.SetSupValue(50);

    MAYBE_UNUSED const auto value = command.GetInteger("integer");
}
