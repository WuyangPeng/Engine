// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 16:59)

#include "CommandLineInformationTesting.h"
#include "CoreTools/Command/CommandLineInformation.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include <vector>

using std::make_pair;
using std::string;
using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, CommandLineInformationTesting)

void CoreTools::CommandLineInformationTesting ::MainTest()
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
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26465)
#include SYSTEM_WARNING_DISABLE(26492)
#include SYSTEM_WARNING_DISABLE(26446)
void CoreTools::CommandLineInformationTesting ::MainCommandLineInformationSucceedTest()
{
    vector<char*> charVector{ const_cast<char*>("MyProgram"), const_cast<char*>("-debug"), const_cast<char*>("-integer"),
                              const_cast<char*>("5"), const_cast<char*>("-float"), const_cast<char*>("6.4"),
                              const_cast<char*>("-double"), const_cast<char*>("5.2"), const_cast<char*>("-string"),
                              const_cast<char*>("value"), const_cast<char*>("-fileName"), const_cast<char*>("filename") };

    CommandLineInformation commandLineInformation{ boost::numeric_cast<int>(charVector.size()), charVector.data() };

    auto count = commandLineInformation.GetExcessArgumentsCount();

    ASSERT_EQUAL(count, 6);

    auto excessArguments = commandLineInformation.ExcessArguments();
    ASSERT_EQUAL(excessArguments, "debug");
    ASSERT_TRUE(commandLineInformation.GetBoolean(excessArguments));
    commandLineInformation.SetUsed(excessArguments);

    ASSERT_FALSE(commandLineInformation.GetBoolean("debug1"));

    count = commandLineInformation.GetExcessArgumentsCount();

    ASSERT_EQUAL(count, 5);

    excessArguments = commandLineInformation.ExcessArguments();
    ASSERT_EQUAL(excessArguments, "double");
    ASSERT_APPROXIMATE(commandLineInformation.GetDouble(excessArguments), 5.2, 1e-10);
    commandLineInformation.SetUsed(excessArguments);

    count = commandLineInformation.GetExcessArgumentsCount();

    ASSERT_EQUAL(count, 4);

    excessArguments = commandLineInformation.ExcessArguments();
    ASSERT_EQUAL(excessArguments, "fileName");
    ASSERT_EQUAL(commandLineInformation.GetFileName(), "filename");

    commandLineInformation.SetFileNameUsed();

    count = commandLineInformation.GetExcessArgumentsCount();

    ASSERT_EQUAL(count, 3);

    excessArguments = commandLineInformation.ExcessArguments();
    ASSERT_EQUAL(excessArguments, "float");
    ASSERT_APPROXIMATE(commandLineInformation.GetFloat(excessArguments), 6.4f, 1e-8f);
    commandLineInformation.SetUsed(excessArguments);

    count = commandLineInformation.GetExcessArgumentsCount();

    ASSERT_EQUAL(count, 2);

    excessArguments = commandLineInformation.ExcessArguments();
    ASSERT_EQUAL(excessArguments, "integer");
    ASSERT_EQUAL(commandLineInformation.GetInteger(excessArguments), 5);
    commandLineInformation.SetUsed(excessArguments);

    count = commandLineInformation.GetExcessArgumentsCount();

    ASSERT_EQUAL(count, 1);

    excessArguments = commandLineInformation.ExcessArguments();
    ASSERT_EQUAL(excessArguments, "string");
    ASSERT_EQUAL(commandLineInformation.GetString(excessArguments), "value");
    commandLineInformation.SetUsed(excessArguments);

    count = commandLineInformation.GetExcessArgumentsCount();

    ASSERT_EQUAL(count, 0);
}

void CoreTools::CommandLineInformationTesting ::WinMainCommandLineInformationSucceedTest()
{
    const char* commandLine{
        "MyProgram -debug -integer  51 -float  16.4 "
        "-double 5.21  -string  value  -fileName filename"
    };

    CommandLineInformation commandLineInformation{ const_cast<char*>(commandLine) };

    auto count = commandLineInformation.GetExcessArgumentsCount();

    ASSERT_EQUAL(count, 6);

    auto excessArguments = commandLineInformation.ExcessArguments();
    ASSERT_EQUAL(excessArguments, "debug");
    ASSERT_TRUE(commandLineInformation.GetBoolean(excessArguments));
    commandLineInformation.SetUsed(excessArguments);

    ASSERT_FALSE(commandLineInformation.GetBoolean("debug1"));

    count = commandLineInformation.GetExcessArgumentsCount();

    ASSERT_EQUAL(count, 5);

    excessArguments = commandLineInformation.ExcessArguments();
    ASSERT_EQUAL(excessArguments, "double");
    ASSERT_APPROXIMATE(commandLineInformation.GetDouble(excessArguments), 5.21, 1e-10);
    commandLineInformation.SetUsed(excessArguments);

    count = commandLineInformation.GetExcessArgumentsCount();

    ASSERT_EQUAL(count, 4);

    excessArguments = commandLineInformation.ExcessArguments();
    ASSERT_EQUAL(excessArguments, "fileName");
    ASSERT_EQUAL(commandLineInformation.GetFileName(), "filename");

    commandLineInformation.SetFileNameUsed();

    count = commandLineInformation.GetExcessArgumentsCount();

    ASSERT_EQUAL(count, 3);

    excessArguments = commandLineInformation.ExcessArguments();
    ASSERT_EQUAL(excessArguments, "float");
    ASSERT_APPROXIMATE(commandLineInformation.GetFloat(excessArguments), 16.4f, 1e-8f);
    commandLineInformation.SetUsed(excessArguments);

    count = commandLineInformation.GetExcessArgumentsCount();

    ASSERT_EQUAL(count, 2);

    excessArguments = commandLineInformation.ExcessArguments();
    ASSERT_EQUAL(excessArguments, "integer");
    ASSERT_EQUAL(commandLineInformation.GetInteger(excessArguments), 51);
    commandLineInformation.SetUsed(excessArguments);

    count = commandLineInformation.GetExcessArgumentsCount();

    ASSERT_EQUAL(count, 1);

    excessArguments = commandLineInformation.ExcessArguments();
    ASSERT_EQUAL(excessArguments, "string");
    ASSERT_EQUAL(commandLineInformation.GetString(excessArguments), "value");
    commandLineInformation.SetUsed(excessArguments);

    count = commandLineInformation.GetExcessArgumentsCount();

    ASSERT_EQUAL(count, 0);
}

void CoreTools::CommandLineInformationTesting ::GetBooleanFalseTest()
{
    vector<char*> charVector{ const_cast<char*>("MyProgram"), const_cast<char*>("-debug") };

    CommandLineInformation commandLineInformation{ boost::numeric_cast<int>(charVector.size()), &charVector[0] };

    ASSERT_FALSE(commandLineInformation.GetBoolean("release"));
}

void CoreTools::CommandLineInformationTesting ::GetIntegerExceptionTest()
{
    const char* commandLine{
        "MyProgram -debug -integer 51 -float 16.4 "
        "-double 5.21 -string value -fileName value"
    };

    CommandLineInformation commandLineInformation{ const_cast<char*>(commandLine) };

    [[maybe_unused]] auto value = commandLineInformation.GetInteger("fileName");
}

void CoreTools::CommandLineInformationTesting ::GetFloatExceptionTest()
{
    const char* commandLine{
        "MyProgram -debug -integer 51 -float 16.4 "
        "-double 5.21 -string value fileName"
    };

    CommandLineInformation commandLineInformation{ const_cast<char*>(commandLine) };

    [[maybe_unused]] auto value = commandLineInformation.GetFloat("Float");
}

void CoreTools::CommandLineInformationTesting ::GetDoubleExceptionTest()
{
    const char* commandLine{
        "MyProgram -debug -integer   51 -float 16.4 "
        "-double 5.21 -string value -fileName value"
    };

    CommandLineInformation commandLineInformation{ const_cast<char*>(commandLine) };

    [[maybe_unused]] auto value = commandLineInformation.GetDouble("debug");
}

void CoreTools::CommandLineInformationTesting ::GetStringExceptionTest()
{
    vector<char*> charVector{ const_cast<char*>("MyProgram"), const_cast<char*>("-debug"),
                              const_cast<char*>("-string"), const_cast<char*>("value") };

    CommandLineInformation commandLineInformation{ boost::numeric_cast<int>(charVector.size()), charVector.data() };

    [[maybe_unused]] auto value = commandLineInformation.GetString("value");
}

void CoreTools::CommandLineInformationTesting ::GetFileNameExceptionTest()
{
    vector<char*> charVector{ const_cast<char*>("MyProgram"), const_cast<char*>("-debug") };

    CommandLineInformation commandLineInformation{ boost::numeric_cast<int>(charVector.size()), charVector.data() };

    [[maybe_unused]] auto value = commandLineInformation.GetFileName();
}

void CoreTools::CommandLineInformationTesting ::WinMainNullCommandLineInformationSucceedTest()
{
    const char* commandLine{ "\"E:\\TCRE\\Engine\\EngineWindows\\Framework\\..\\..\\Debug_Windows\\FrameworkTestingD.exe\" " };

    CommandLineInformation commandLineInformation{ const_cast<char*>(commandLine) };

    ASSERT_EQUAL(commandLineInformation.GetExcessArgumentsCount(), 0);
}
#include STSTEM_WARNING_POP