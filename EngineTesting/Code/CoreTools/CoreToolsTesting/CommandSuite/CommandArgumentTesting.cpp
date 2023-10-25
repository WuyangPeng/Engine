///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:37)

#include "CommandArgumentTesting.h"
#include "CoreTools/Command/CommandArgument.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

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
    ASSERT_NOT_THROW_EXCEPTION_0(NumberTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StringTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NoValueTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_THROW_EXCEPTION_0(NumberExceptionTest);
    ASSERT_THROW_EXCEPTION_0(StringExceptionTest);
    ASSERT_THROW_EXCEPTION_0(NoValueExceptionTest);
}

void CoreTools::CommandArgumentTesting::NumberTest()
{
    CommandArgument commandArgument0{ 5, "Number"s, "1"s };

    ASSERT_EQUAL(commandArgument0.GetIndex(), 5);
    ASSERT_EQUAL(commandArgument0.GetName(), "Number"s);
    ASSERT_EQUAL(commandArgument0.GetInteger(), 1);
    ASSERT_APPROXIMATE(commandArgument0.GetFloat(), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(commandArgument0.GetDouble(), 1.0, 1e-10);

    ASSERT_TRUE(commandArgument0.IsInteger());
    ASSERT_TRUE(commandArgument0.IsFloat());
    ASSERT_TRUE(commandArgument0.IsDouble());
    ASSERT_FALSE(commandArgument0.IsString());
    ASSERT_FALSE(commandArgument0.IsNoValue());

    ASSERT_FALSE(commandArgument0.IsUsed());

    commandArgument0.SetUsed();

    ASSERT_TRUE(commandArgument0.IsUsed());

    const CommandArgument commandArgument1{ 5, "number"s, "2"s };

    ASSERT_EQUAL(commandArgument1.GetName(), "number"s);
}

void CoreTools::CommandArgumentTesting::StringTest()
{
    CommandArgument commandArgument0{ 2, "String"s, "Test"s };

    ASSERT_EQUAL(commandArgument0.GetIndex(), 2);
    ASSERT_EQUAL(commandArgument0.GetName(), "String"s);
    ASSERT_EQUAL(commandArgument0.GetString(), "Test"s);

    ASSERT_FALSE(commandArgument0.IsInteger());
    ASSERT_FALSE(commandArgument0.IsFloat());
    ASSERT_FALSE(commandArgument0.IsDouble());
    ASSERT_TRUE(commandArgument0.IsString());
    ASSERT_FALSE(commandArgument0.IsNoValue());

    ASSERT_FALSE(commandArgument0.IsUsed());

    commandArgument0.SetUsed();

    ASSERT_TRUE(commandArgument0.IsUsed());

    const CommandArgument commandArgument1{ 2, "string"s, "test"s };

    ASSERT_EQUAL(commandArgument1.GetName(), "string"s);
}

void CoreTools::CommandArgumentTesting::NoValueTest()
{
    CommandArgument commandArgument{ 2, "NoValue"s };

    ASSERT_EQUAL(commandArgument.GetIndex(), 2);
    ASSERT_EQUAL(commandArgument.GetName(), "NoValue"s);

    ASSERT_FALSE(commandArgument.IsInteger());
    ASSERT_FALSE(commandArgument.IsFloat());
    ASSERT_FALSE(commandArgument.IsDouble());
    ASSERT_FALSE(commandArgument.IsString());
    ASSERT_TRUE(commandArgument.IsNoValue());

    ASSERT_FALSE(commandArgument.IsUsed());

    commandArgument.SetUsed();

    ASSERT_TRUE(commandArgument.IsUsed());
}

void CoreTools::CommandArgumentTesting::CopyTest()
{
    const CommandArgument commandArgument0{ 5, "Number"s, "Test"s };

    auto commandArgument1 = commandArgument0;

    ASSERT_EQUAL(commandArgument1.GetIndex(), 5);
    ASSERT_EQUAL(commandArgument1.GetName(), "Number"s);
    ASSERT_EQUAL(commandArgument1.GetString(), "Test"s);

    commandArgument1.AddEndArgumentValue("Test");

    ASSERT_EQUAL(commandArgument1.GetString(), "Test Test"s);
    ASSERT_EQUAL(commandArgument0.GetString(), "Test"s);
}

void CoreTools::CommandArgumentTesting::NumberExceptionTest()
{
    const CommandArgument commandArgument{ 5, "Number"s, "1"s };

    MAYBE_UNUSED auto value = commandArgument.GetString();
}

void CoreTools::CommandArgumentTesting::StringExceptionTest()
{
    const CommandArgument commandArgument{ 5, "String"s, "Test"s };

    MAYBE_UNUSED const auto value = commandArgument.GetFloat();
}

void CoreTools::CommandArgumentTesting::NoValueExceptionTest()
{
    const CommandArgument commandArgument{ 5, "NoValue"s };

    MAYBE_UNUSED const auto value = commandArgument.GetInteger();
}
