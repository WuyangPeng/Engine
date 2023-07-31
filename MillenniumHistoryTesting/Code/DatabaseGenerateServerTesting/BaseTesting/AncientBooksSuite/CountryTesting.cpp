///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/23 16:42)

#include "CountryTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Country.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/CountryContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerBaseTesting::CountryTesting::CountryTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream },
      ancientBooksContainer{ ancientBooksContainer },
      countryContainer{ ancientBooksContainer.GetCountryContainer() }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerBaseTesting, CountryTesting)

void DatabaseGenerateServerBaseTesting::CountryTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateServerBaseTesting::CountryTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MappingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EffectiveTest);
}

void DatabaseGenerateServerBaseTesting::CountryTesting::MappingTest()
{
    for (const auto& country : countryContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(ImperialCourtMappingTest, *country);
        ASSERT_NOT_THROW_EXCEPTION_1(BeginMappingTest, *country);
        ASSERT_NOT_THROW_EXCEPTION_1(EndMappingTest, *country);
    }
}

void DatabaseGenerateServerBaseTesting::CountryTesting::ImperialCourtMappingTest(const Country& country)
{
    ASSERT_GREATER(country.GetImperialCourt(), 0);
    ASSERT_UNEQUAL_NULL_PTR(country.GetImperialCourt(ancientBooksContainer));
}

void DatabaseGenerateServerBaseTesting::CountryTesting::BeginMappingTest(const Country& country)
{
    if (0 < country.GetBeginYear())
    {
        ASSERT_UNEQUAL_NULL_PTR(country.GetBeginYear(ancientBooksContainer));
    }

    if (0 < country.GetBeginMonth())
    {
        ASSERT_UNEQUAL_NULL_PTR(country.GetBeginMonth(ancientBooksContainer));
    }

    if (0 < country.GetBeginSexagenaryCycle())
    {
        ASSERT_UNEQUAL_NULL_PTR(country.GetBeginSexagenaryCycle(ancientBooksContainer));
    }

    if (0 < country.GetBeginDay())
    {
        ASSERT_UNEQUAL_NULL_PTR(country.GetBeginDay(ancientBooksContainer));
    }
}

void DatabaseGenerateServerBaseTesting::CountryTesting::EndMappingTest(const Country& country)
{
    if (0 < country.GetEndYear())
    {
        ASSERT_UNEQUAL_NULL_PTR(country.GetEndYear(ancientBooksContainer));
    }

    if (0 < country.GetEndMonth())
    {
        ASSERT_UNEQUAL_NULL_PTR(country.GetEndMonth(ancientBooksContainer));
    }

    if (0 < country.GetEndSexagenaryCycle())
    {
        ASSERT_UNEQUAL_NULL_PTR(country.GetEndSexagenaryCycle(ancientBooksContainer));
    }

    if (0 < country.GetEndDay())
    {
        ASSERT_UNEQUAL_NULL_PTR(country.GetEndDay(ancientBooksContainer));
    }
}

void DatabaseGenerateServerBaseTesting::CountryTesting::EffectiveTest()
{
    for (const auto& country : countryContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(CategoryTest, *country);
        ASSERT_NOT_THROW_EXCEPTION_1(UnansweredQuestionTest, *country);
        ASSERT_NOT_THROW_EXCEPTION_1(IdTest, *country);
    }
}

void DatabaseGenerateServerBaseTesting::CountryTesting::CategoryTest(const Country& country)
{
    ASSERT_FALSE(country.GetCategory().empty());
}

void DatabaseGenerateServerBaseTesting::CountryTesting::UnansweredQuestionTest(const Country& country)
{
    const auto unansweredQuestion = country.GetUnansweredQuestion();

    for (const auto& element : unansweredQuestion)
    {
        ASSERT_TRUE(element == SYSTEM_TEXT("beginYear") ||
                    element == SYSTEM_TEXT("beginMonth") ||
                    element == SYSTEM_TEXT("beginSexagenaryCycle") ||
                    element == SYSTEM_TEXT("beginDay") ||
                    element == SYSTEM_TEXT("endYear") ||
                    element == SYSTEM_TEXT("endMonth") ||
                    element == SYSTEM_TEXT("endSexagenaryCycle") ||
                    element == SYSTEM_TEXT("endDay"));
    }
}

void DatabaseGenerateServerBaseTesting::CountryTesting::IdTest(const Country& country)
{
    ASSERT_EQUAL(country.GetId() / 1000, country.GetImperialCourt());
}
