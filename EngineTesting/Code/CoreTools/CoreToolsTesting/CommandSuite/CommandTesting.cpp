// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 17:00)

#include "CommandTesting.h"
#include "CoreTools/Command/Command.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

using std::make_pair;
using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, CommandTesting)

void CoreTools::CommandTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SucceedTest);
    ASSERT_THROW_EXCEPTION_0(SetMinValueExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetMaxValueExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetInfValueExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetSupValueExceptionTest);
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)
void CoreTools::CommandTesting ::SucceedTest()
{
    const char* commandLine{
        "MyProgram -debug   -integer    51 -float 16.4 "
        "-double 5.21     -string value -fileName filename"
    };

    CommandHandle command{ const_cast<char*>(commandLine) };

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
    ASSERT_APPROXIMATE(command.GetDouble(excessArguments), 5.21, 1e-10);
    command.SetUsed(excessArguments);

    command.ClearBoundary();
    command.SetMinValue(16.3);

    count = command.GetExcessArgumentsCount();

    ASSERT_EQUAL(count, 4);

    excessArguments = command.ExcessArguments();
    ASSERT_EQUAL(excessArguments, "fileName");
    ASSERT_EQUAL(command.GetFileName(), "filename");

    command.SetFileNmaeUsed();

    count = command.GetExcessArgumentsCount();

    ASSERT_EQUAL(count, 3);

    excessArguments = command.ExcessArguments();
    ASSERT_EQUAL(excessArguments, "float");
    ASSERT_APPROXIMATE(command.GetFloat(excessArguments), 16.4f, 1e-8f);
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

void CoreTools::CommandTesting ::SetMinValueExceptionTest()
{
    const char* commandLine{
        "MyProgram -debug  -integer 51 -float 16.4 "
        "-double 5.21 -string value   -fileName filename"
    };

    CommandHandle command{ const_cast<char*>(commandLine) };

    command.SetMinValue(17.0);

    [[maybe_unused]] auto value = command.GetFloat("float");
}

void CoreTools::CommandTesting ::SetMaxValueExceptionTest()
{
    const char* commandLine{
        "MyProgram -debug  -integer 51 -float 16.4 "
        "-double 5.21 -string value -fileName filename"
    };

    CommandHandle command{ const_cast<char*>(commandLine) };

    command.SetMaxValue(4.0);

    [[maybe_unused]] auto value = command.GetDouble("double");
}

void CoreTools::CommandTesting ::SetInfValueExceptionTest()
{
    const char* commandLine{
        "MyProgram -debug -integer 51 -float 16.4 "
        "-double 5.21 -string value -fileName filename"
    };

    CommandHandle command{ const_cast<char*>(commandLine) };

    command.SetInfValue(52);

    [[maybe_unused]] auto value = command.GetInteger("integer");
}

void CoreTools::CommandTesting ::SetSupValueExceptionTest()
{
    const char* commandLine{
        "MyProgram -debug -integer 51 -float 16.4 "
        "-double 5.21 -string value -fileName filename"
    };

    CommandHandle command{ const_cast<char*>(commandLine) };

    command.SetSupValue(50);

    [[maybe_unused]] auto value = command.GetInteger("integer");
}

#include STSTEM_WARNING_POP