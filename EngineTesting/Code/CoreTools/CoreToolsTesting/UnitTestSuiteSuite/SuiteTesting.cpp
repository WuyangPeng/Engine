///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.7 (2023/04/25 17:11)

#include "SuiteTesting.h"
#include "CoreTools/CoreToolsTesting/ContractSuite/FunctionDescribedTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/Suite.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::SuiteTesting::SuiteTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, SuiteTesting)

void CoreTools::SuiteTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::SuiteTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NameTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AddTestTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AddSuiteTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TestDataTest);
}

void CoreTools::SuiteTesting::NameTest()
{
    const auto suiteName = "SuiteName"s;

    const Suite suite{ suiteName, OStreamShared{ true }, true };

    ASSERT_EQUAL(suite.GetName(), suiteName);
}

void CoreTools::SuiteTesting::StreamTest()
{
    const auto suiteName = "SuiteName"s;

    Suite suite{ suiteName, OStreamShared{ true }, true };
}

void CoreTools::SuiteTesting::AddTestTest()
{
    const auto suiteName = "SuiteName"s;

    Suite suite{ suiteName, GetStream(), true };

    suite.AddTest(std::make_shared<FunctionDescribedTesting>(GetStream()));

    ASSERT_EQUAL(suite.GetPassedNumber(), 0);
    ASSERT_EQUAL(suite.GetFailedNumber(), 0);
    ASSERT_EQUAL(suite.GetErrorNumber(), 0);

    suite.ResetTestData();
}

void CoreTools::SuiteTesting::AddSuiteTest()
{
    const auto suiteName = "SuiteName"s;

    Suite suite0{ suiteName, GetStream(), true };

    suite0.AddTest(std::make_shared<FunctionDescribedTesting>(GetStream()));

    ASSERT_EQUAL(suite0.GetPassedNumber(), 0);
    ASSERT_EQUAL(suite0.GetFailedNumber(), 0);
    ASSERT_EQUAL(suite0.GetErrorNumber(), 0);

    Suite suite1{ suiteName, GetStream(), true };
    suite1.AddSuite(suite0);

    ASSERT_EQUAL(suite0.GetPassedNumber(), 0);
    ASSERT_EQUAL(suite0.GetFailedNumber(), 0);
    ASSERT_EQUAL(suite0.GetErrorNumber(), 0);
    ASSERT_EQUAL(suite1.GetPassedNumber(), 0);
    ASSERT_EQUAL(suite1.GetFailedNumber(), 0);
    ASSERT_EQUAL(suite1.GetErrorNumber(), 0);

    suite1.PrintReport();

    suite1.ClearUnitTestCollection();
    suite0.ClearUnitTestCollection();
}

void CoreTools::SuiteTesting::TestDataTest()
{
    const auto suiteName = "SuiteName"s;

    Suite suite{ suiteName, GetStream(), true };

    suite.AddTest(std::make_shared<FunctionDescribedTesting>(GetStream()));

    ASSERT_EQUAL(suite.GetPassedNumber(), 0);
    ASSERT_EQUAL(suite.GetFailedNumber(), 0);
    ASSERT_EQUAL(suite.GetErrorNumber(), 0);

    suite.RunUnitTest();

    ASSERT_EQUAL(suite.GetPassedNumber(), 2);
    ASSERT_EQUAL(suite.GetFailedNumber(), 0);
    ASSERT_EQUAL(suite.GetErrorNumber(), 0);

    suite.ResetTestData();

    ASSERT_EQUAL(suite.GetPassedNumber(), 0);
    ASSERT_EQUAL(suite.GetFailedNumber(), 0);
    ASSERT_EQUAL(suite.GetErrorNumber(), 0);

    suite.RunUnitTest();

    ASSERT_EQUAL(suite.GetPassedNumber(), 2);
    ASSERT_EQUAL(suite.GetFailedNumber(), 0);
    ASSERT_EQUAL(suite.GetErrorNumber(), 0);

    suite.ClearUnitTestCollection();

    ASSERT_EQUAL(suite.GetPassedNumber(), 0);
    ASSERT_EQUAL(suite.GetFailedNumber(), 0);
    ASSERT_EQUAL(suite.GetErrorNumber(), 0);
}
