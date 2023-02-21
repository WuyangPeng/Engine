///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 14:34)

#include "CommandArgumentTesting.h"
#include "CoreTools/Command/CommandArgument.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using std::string;
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
    CommandArgument firstCommandArgument{ 5, "Number"s, "1"s };

    ASSERT_EQUAL(firstCommandArgument.GetIndex(), 5);
    ASSERT_EQUAL(firstCommandArgument.GetName(), "Number"s);
    ASSERT_EQUAL(firstCommandArgument.GetInteger(), 1);
    ASSERT_APPROXIMATE(firstCommandArgument.GetFloat(), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstCommandArgument.GetDouble(), 1.0, 1e-10);

    ASSERT_TRUE(firstCommandArgument.IsInteger());
    ASSERT_TRUE(firstCommandArgument.IsFloat());
    ASSERT_TRUE(firstCommandArgument.IsDouble());
    ASSERT_FALSE(firstCommandArgument.IsString());
    ASSERT_FALSE(firstCommandArgument.IsNoValue());

    ASSERT_FALSE(firstCommandArgument.IsUsed());

    firstCommandArgument.SetUsed();

    ASSERT_TRUE(firstCommandArgument.IsUsed());

    CommandArgument secondCommandArgument{ 5, "number"s, "2"s };

    ASSERT_EQUAL(secondCommandArgument.GetName(), "number"s);
}

void CoreTools::CommandArgumentTesting::StringTest()
{
    CommandArgument firstCommandArgument{ 2, "String"s, "Test"s };

    ASSERT_EQUAL(firstCommandArgument.GetIndex(), 2);
    ASSERT_EQUAL(firstCommandArgument.GetName(), "String"s);
    ASSERT_EQUAL(firstCommandArgument.GetString(), "Test"s);

    ASSERT_FALSE(firstCommandArgument.IsInteger());
    ASSERT_FALSE(firstCommandArgument.IsFloat());
    ASSERT_FALSE(firstCommandArgument.IsDouble());
    ASSERT_TRUE(firstCommandArgument.IsString());
    ASSERT_FALSE(firstCommandArgument.IsNoValue());

    ASSERT_FALSE(firstCommandArgument.IsUsed());

    firstCommandArgument.SetUsed();

    ASSERT_TRUE(firstCommandArgument.IsUsed());

    CommandArgument secondCommandArgument{ 2, "string"s, "test"s };

    ASSERT_EQUAL(secondCommandArgument.GetName(), "string"s);
}

void CoreTools::CommandArgumentTesting::NoValueTest()
{
    CommandArgument firstCommandArgument{ 2, "NoValue"s };

    ASSERT_EQUAL(firstCommandArgument.GetIndex(), 2);
    ASSERT_EQUAL(firstCommandArgument.GetName(), "NoValue"s);

    ASSERT_FALSE(firstCommandArgument.IsInteger());
    ASSERT_FALSE(firstCommandArgument.IsFloat());
    ASSERT_FALSE(firstCommandArgument.IsDouble());
    ASSERT_FALSE(firstCommandArgument.IsString());
    ASSERT_TRUE(firstCommandArgument.IsNoValue());

    ASSERT_FALSE(firstCommandArgument.IsUsed());

    firstCommandArgument.SetUsed();

    ASSERT_TRUE(firstCommandArgument.IsUsed());
}

void CoreTools::CommandArgumentTesting::CopyTest()
{
    CommandArgument firstCommandArgument{ 5, "Number"s, "Test"s };

    auto secondCommandArgument = firstCommandArgument;

    ASSERT_EQUAL(secondCommandArgument.GetIndex(), 5);
    ASSERT_EQUAL(secondCommandArgument.GetName(), "Number"s);
    ASSERT_EQUAL(secondCommandArgument.GetString(), "Test"s);

    secondCommandArgument.AddEndArgumentValue("Test");

    ASSERT_EQUAL(secondCommandArgument.GetString(), "Test Test"s);
    ASSERT_EQUAL(firstCommandArgument.GetString(), "Test"s);
}

void CoreTools::CommandArgumentTesting::NumberExceptionTest()
{
    CommandArgument firstCommandArgument{ 5, "Number"s, "1"s };

    MAYBE_UNUSED auto value = firstCommandArgument.GetString();
}

void CoreTools::CommandArgumentTesting::StringExceptionTest()
{
    CommandArgument firstCommandArgument{ 5, "String"s, "Test"s };

    MAYBE_UNUSED const auto value = firstCommandArgument.GetFloat();
}

void CoreTools::CommandArgumentTesting::NoValueExceptionTest()
{
    CommandArgument firstCommandArgument{ 5, "NoValue"s };

    MAYBE_UNUSED const auto value = firstCommandArgument.GetInteger();
}
