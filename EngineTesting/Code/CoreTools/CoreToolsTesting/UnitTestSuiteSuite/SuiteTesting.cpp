// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 15:20)

#include "SuiteTesting.h"
#include "CoreTools/CoreToolsTesting/ContractSuite/FunctionDescribedTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/Suite.h"

using std::cout;
using std::make_shared;
using std::string;
using namespace std::literals;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, SuiteTesting)

void CoreTools::SuiteTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NameTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AddTestTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AddSuiteTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TestDataTest);
}

void CoreTools::SuiteTesting ::NameTest()
{
    string suiteName{ "SuiteName"s };

    Suite suite{ suiteName, OStreamShared{ true }, true };

    ASSERT_EQUAL(suite.GetName(), suiteName);
}

void CoreTools::SuiteTesting ::StreamTest()
{
    string suiteName{ "SuiteName"s };

    Suite suite{ suiteName, OStreamShared{ true }, true };
}

void CoreTools::SuiteTesting ::AddTestTest()
{
    string suiteName{ "SuiteName"s };

    Suite suite{ suiteName, GetStream(), true };

    suite.AddTest(make_shared<FunctionDescribedTesting>(GetStream()));

    ASSERT_EQUAL(suite.GetPassedNumber(), 0);
    ASSERT_EQUAL(suite.GetFailedNumber(), 0);
    ASSERT_EQUAL(suite.GetErrorNumber(), 0);

    suite.ResetTestData();
}

void CoreTools::SuiteTesting ::AddSuiteTest()
{
    string suiteName{ "SuiteName"s };

    Suite firstSuite{ suiteName, GetStream(), true };

    firstSuite.AddTest(make_shared<FunctionDescribedTesting>(GetStream()));

    ASSERT_EQUAL(firstSuite.GetPassedNumber(), 0);
    ASSERT_EQUAL(firstSuite.GetFailedNumber(), 0);
    ASSERT_EQUAL(firstSuite.GetErrorNumber(), 0);

    Suite secondSuite{ suiteName, GetStream(), true };
    secondSuite.AddSuite(firstSuite);

    ASSERT_EQUAL(firstSuite.GetPassedNumber(), 0);
    ASSERT_EQUAL(firstSuite.GetFailedNumber(), 0);
    ASSERT_EQUAL(firstSuite.GetErrorNumber(), 0);
    ASSERT_EQUAL(secondSuite.GetPassedNumber(), 0);
    ASSERT_EQUAL(secondSuite.GetFailedNumber(), 0);
    ASSERT_EQUAL(secondSuite.GetErrorNumber(), 0);

    secondSuite.PrintReport();

    secondSuite.ClearUnitTestCollection();
    firstSuite.ClearUnitTestCollection();
}

void CoreTools::SuiteTesting ::TestDataTest()
{
    string suiteName{ "SuiteName"s };

    Suite suite{ suiteName, GetStream(), true };

    suite.AddTest(make_shared<FunctionDescribedTesting>(GetStream()));

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
