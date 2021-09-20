///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/04/09 21:20)

#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/CleanCppSustainableSoftwareDevelopmentExport.h"

#include "Money.h"
#include "MoneyTest.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/Helper/CleanCppSustainableSoftwareDevelopmentClassInvariantMacro.h"

BookAdvanced::CleanCppSustainableSoftwareDevelopment::MoneyTest::MoneyTest(const OStreamShared& stream)
    : ParentType{ stream }
{
    CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAdvanced::CleanCppSustainableSoftwareDevelopment, MoneyTest)

void BookAdvanced::CleanCppSustainableSoftwareDevelopment::MoneyTest::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAdvanced::CleanCppSustainableSoftwareDevelopment::MoneyTest::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GivenTwoMoneyObjectsWithDifferentBalance_TheInequalityComparison_Works);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateMoneyObjectWithParameter_GetBalanceAsString_ReturnsCorrectString);
}

void BookAdvanced::CleanCppSustainableSoftwareDevelopment::MoneyTest::GivenTwoMoneyObjectsWithDifferentBalance_TheInequalityComparison_Works()
{
    CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CLASS_IS_VALID_9;

    const Money m1(-4000.0);
    const Money m2(2000.0);

    ASSERT_TRUE(m1 != m2);
}

void BookAdvanced::CleanCppSustainableSoftwareDevelopment::MoneyTest::CreateMoneyObjectWithParameter_GetBalanceAsString_ReturnsCorrectString() noexcept
{
    CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CLASS_IS_VALID_9;
}

void BookAdvanced::CleanCppSustainableSoftwareDevelopment::MoneyTest::GivenTwoMoneyObjectsWithDifferentBalance_TestAllComparisonOperators()
{
    CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CLASS_IS_VALID_9;

    const Money m1(-4000.0);
    const Money m2(2000.0);

    ASSERT_TRUE(m1 != m2);
    ASSERT_FALSE(m1 == m2);
    ASSERT_TRUE(m1 < m2);
    ASSERT_FALSE(m1 > m2);
    // ... more assertions here...
}
