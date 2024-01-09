/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/23 22:09)

#include "CalendarTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/Calendar.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/CalendarContainerDetail.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/DatabaseGenerateCoreClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateBaseTesting::CalendarTesting::CalendarTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream },
      ancientBooksContainer{ ancientBooksContainer },
      calendarContainer{ ancientBooksContainer.GetCalendarContainer() }
{
    DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateBaseTesting, CalendarTesting)

void DatabaseGenerateBaseTesting::CalendarTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateBaseTesting::CalendarTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MappingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EffectiveTest);
}

void DatabaseGenerateBaseTesting::CalendarTesting::MappingTest()
{
    for (const auto& calendar : calendarContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(SourceMappingTest, *calendar);
        ASSERT_NOT_THROW_EXCEPTION_1(CreatorMappingTest, *calendar);
        ASSERT_NOT_THROW_EXCEPTION_1(FormulateMappingTest, *calendar);
        ASSERT_NOT_THROW_EXCEPTION_1(CountryMappingTest, *calendar);
        ASSERT_NOT_THROW_EXCEPTION_1(YearMappingTest, *calendar);
    }
}

void DatabaseGenerateBaseTesting::CalendarTesting::SourceMappingTest(const Calendar& calendar)
{
    ASSERT_EQUAL(calendar.GetSource(ancientBooksContainer).size(), calendar.GetSource().size());
}

void DatabaseGenerateBaseTesting::CalendarTesting::CreatorMappingTest(const Calendar& calendar)
{
    ASSERT_EQUAL(calendar.GetCreator(ancientBooksContainer).size(), calendar.GetCreator().size());
}

void DatabaseGenerateBaseTesting::CalendarTesting::FormulateMappingTest(const Calendar& calendar)
{
    if (calendar.GetFormulate() != 0)
    {
        ASSERT_UNEQUAL_NULL_PTR(calendar.GetFormulate(ancientBooksContainer));
    }
}

void DatabaseGenerateBaseTesting::CalendarTesting::CountryMappingTest(const Calendar& calendar)
{
    if (0 < calendar.GetCountry())
    {
        ASSERT_UNEQUAL_NULL_PTR(calendar.GetCountry(ancientBooksContainer));
    }
}

void DatabaseGenerateBaseTesting::CalendarTesting::YearMappingTest(const Calendar& calendar)
{
    if (calendar.GetBegin() != 0)
    {
        ASSERT_UNEQUAL_NULL_PTR(calendar.GetBegin(ancientBooksContainer));
    }

    if (calendar.GetEnd() != 0)
    {
        ASSERT_UNEQUAL_NULL_PTR(calendar.GetEnd(ancientBooksContainer));
    }

    if (calendar.GetAgainBegin() != 0)
    {
        ASSERT_UNEQUAL_NULL_PTR(calendar.GetAgainBegin(ancientBooksContainer));
    }

    if (calendar.GetAgainEnd() != 0)
    {
        ASSERT_UNEQUAL_NULL_PTR(calendar.GetAgainEnd(ancientBooksContainer));
    }
}

void DatabaseGenerateBaseTesting::CalendarTesting::EffectiveTest()
{
    for (const auto& calendar : calendarContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(NameTest, *calendar);
    }
}

void DatabaseGenerateBaseTesting::CalendarTesting::NameTest(const Calendar& calendar)
{
    ASSERT_FALSE(calendar.GetName().empty());
}
