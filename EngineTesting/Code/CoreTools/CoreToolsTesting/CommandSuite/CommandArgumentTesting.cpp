/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/24 21:26)

#include "CommandArgumentTesting.h"
#include "CoreTools/Command/CommandArgument.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::CommandArgumentTesting::CommandArgumentTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CommandArgumentTesting)

void CoreTools::CommandArgumentTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CommandArgumentTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Number0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Number1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(String0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(String1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(NoValueTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_THROW_EXCEPTION_0(NumberExceptionTest);
    ASSERT_THROW_EXCEPTION_0(StringExceptionTest);
    ASSERT_THROW_EXCEPTION_0(NoValueExceptionTest);
}

void CoreTools::CommandArgumentTesting::IsUsedTest(CommandArgument& commandArgument0)
{
    ASSERT_FALSE(commandArgument0.IsUsed());

    commandArgument0.SetUsed();

    ASSERT_TRUE(commandArgument0.IsUsed());
}

void CoreTools::CommandArgumentTesting::Number0Test()
{
    CommandArgument commandArgument{ 5, "Number", "1" };

    ASSERT_EQUAL(commandArgument.GetIndex(), 5);
    ASSERT_EQUAL(commandArgument.GetName(), "Number");
    ASSERT_EQUAL(commandArgument.GetInteger(), 1);
    ASSERT_APPROXIMATE(commandArgument.GetFloat(), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(commandArgument.GetDouble(), 1.0, 1e-10);

    ASSERT_TRUE(commandArgument.IsInteger());
    ASSERT_TRUE(commandArgument.IsFloat());
    ASSERT_TRUE(commandArgument.IsDouble());
    ASSERT_FALSE(commandArgument.IsString());
    ASSERT_FALSE(commandArgument.IsNoValue());

    ASSERT_NOT_THROW_EXCEPTION_1(IsUsedTest, commandArgument);
}

void CoreTools::CommandArgumentTesting::Number1Test()
{
    const CommandArgument commandArgument{ 5, "number", "2" };

    ASSERT_EQUAL(commandArgument.GetName(), "number");
}

void CoreTools::CommandArgumentTesting::String0Test()
{
    CommandArgument commandArgument{ 2, "String", "Test" };

    ASSERT_EQUAL(commandArgument.GetIndex(), 2);
    ASSERT_EQUAL(commandArgument.GetName(), "String");
    ASSERT_EQUAL(commandArgument.GetString(), "Test");

    ASSERT_FALSE(commandArgument.IsInteger());
    ASSERT_FALSE(commandArgument.IsFloat());
    ASSERT_FALSE(commandArgument.IsDouble());
    ASSERT_TRUE(commandArgument.IsString());
    ASSERT_FALSE(commandArgument.IsNoValue());

    ASSERT_NOT_THROW_EXCEPTION_1(IsUsedTest, commandArgument);
}

void CoreTools::CommandArgumentTesting::String1Test()
{
    const CommandArgument commandArgument{ 2, "string", "test" };

    ASSERT_EQUAL(commandArgument.GetName(), "string");
}

void CoreTools::CommandArgumentTesting::NoValueTest()
{
    CommandArgument commandArgument{ 2, "NoValue" };

    ASSERT_EQUAL(commandArgument.GetIndex(), 2);
    ASSERT_EQUAL(commandArgument.GetName(), "NoValue");

    ASSERT_FALSE(commandArgument.IsInteger());
    ASSERT_FALSE(commandArgument.IsFloat());
    ASSERT_FALSE(commandArgument.IsDouble());
    ASSERT_FALSE(commandArgument.IsString());
    ASSERT_TRUE(commandArgument.IsNoValue());

    ASSERT_NOT_THROW_EXCEPTION_1(IsUsedTest, commandArgument);
}

void CoreTools::CommandArgumentTesting::CopyTest()
{
    const CommandArgument commandArgument0{ 5, "Number", "Test" };

    auto commandArgument1 = commandArgument0;

    ASSERT_EQUAL(commandArgument1.GetIndex(), 5);
    ASSERT_EQUAL(commandArgument1.GetName(), "Number");
    ASSERT_EQUAL(commandArgument1.GetString(), "Test");

    commandArgument1.AddEndArgumentValue("Test");

    ASSERT_EQUAL(commandArgument1.GetString(), "Test Test");
    ASSERT_EQUAL(commandArgument0.GetString(), "Test");
}

void CoreTools::CommandArgumentTesting::NumberExceptionTest()
{
    const CommandArgument commandArgument{ 5, "Number", "1" };

    std::ignore = commandArgument.GetString();
}

void CoreTools::CommandArgumentTesting::StringExceptionTest()
{
    const CommandArgument commandArgument{ 5, "String", "Test" };

    std::ignore = commandArgument.GetFloat();
}

void CoreTools::CommandArgumentTesting::NoValueExceptionTest()
{
    const CommandArgument commandArgument{ 5, "NoValue" };

    std::ignore = commandArgument.GetInteger();
}
