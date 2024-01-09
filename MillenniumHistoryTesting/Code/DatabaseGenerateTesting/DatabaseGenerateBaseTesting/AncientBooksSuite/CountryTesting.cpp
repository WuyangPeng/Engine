/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/23 22:11)

#include "CountryTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Country.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/CountryContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateBaseTesting::CountryTesting::CountryTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream },
      ancientBooksContainer{ ancientBooksContainer },
      countryContainer{ ancientBooksContainer.GetCountryContainer() }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateBaseTesting, CountryTesting)

void DatabaseGenerateBaseTesting::CountryTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateBaseTesting::CountryTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MappingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EffectiveTest);
}

void DatabaseGenerateBaseTesting::CountryTesting::MappingTest()
{
    for (const auto& country : countryContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(ImperialCourtMappingTest, *country);
        ASSERT_NOT_THROW_EXCEPTION_1(BeginMappingTest, *country);
        ASSERT_NOT_THROW_EXCEPTION_1(EndMappingTest, *country);
    }
}

void DatabaseGenerateBaseTesting::CountryTesting::ImperialCourtMappingTest(const Country& country)
{
    ASSERT_GREATER(country.GetImperialCourt(), 0);
    ASSERT_UNEQUAL_NULL_PTR(country.GetImperialCourt(ancientBooksContainer));
}

void DatabaseGenerateBaseTesting::CountryTesting::BeginMappingTest(const Country& country)
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

void DatabaseGenerateBaseTesting::CountryTesting::EndMappingTest(const Country& country)
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

void DatabaseGenerateBaseTesting::CountryTesting::EffectiveTest()
{
    for (const auto& country : countryContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(CategoryTest, *country);
        ASSERT_NOT_THROW_EXCEPTION_1(UnansweredQuestionTest, *country);
        ASSERT_NOT_THROW_EXCEPTION_1(IdTest, *country);
    }
}

void DatabaseGenerateBaseTesting::CountryTesting::CategoryTest(const Country& country)
{
    ASSERT_FALSE(country.GetCategory().empty());
}

void DatabaseGenerateBaseTesting::CountryTesting::UnansweredQuestionTest(const Country& country)
{
    for (const auto unansweredQuestion = country.GetUnansweredQuestion();
         const auto& element : unansweredQuestion)
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

void DatabaseGenerateBaseTesting::CountryTesting::IdTest(const Country& country)
{
    ASSERT_EQUAL(country.GetId() / 1000, country.GetImperialCourt());
}
