///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/23 0:08)

#include "CalendarTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Calendar.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/CalendarContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerBaseTesting::CalendarTesting::CalendarTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream },
      ancientBooksContainer{ ancientBooksContainer },
      calendarContainer{ ancientBooksContainer.GetCalendarContainer() }
{
    DATABASE_GENERATE_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerBaseTesting, CalendarTesting)

void DatabaseGenerateServerBaseTesting::CalendarTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void DatabaseGenerateServerBaseTesting::CalendarTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MappingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EffectiveTest);
}

void DatabaseGenerateServerBaseTesting::CalendarTesting::MappingTest()
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

void DatabaseGenerateServerBaseTesting::CalendarTesting::SourceMappingTest(const Calendar& calendar)
{
    ASSERT_EQUAL(calendar.GetSource(ancientBooksContainer).size(), calendar.GetSource().size());
}

void DatabaseGenerateServerBaseTesting::CalendarTesting::CreatorMappingTest(const Calendar& calendar)
{
    ASSERT_EQUAL(calendar.GetCreator(ancientBooksContainer).size(), calendar.GetCreator().size());
}

void DatabaseGenerateServerBaseTesting::CalendarTesting::FormulateMappingTest(const Calendar& calendar)
{
    if (calendar.GetFormulate() != 0)
    {
        ASSERT_UNEQUAL_NULL_PTR(calendar.GetFormulate(ancientBooksContainer));
    }
}

void DatabaseGenerateServerBaseTesting::CalendarTesting::CountryMappingTest(const Calendar& calendar)
{
    if (0 < calendar.GetCountry())
    {
        ASSERT_UNEQUAL_NULL_PTR(calendar.GetCountry(ancientBooksContainer));
    }
}

void DatabaseGenerateServerBaseTesting::CalendarTesting::YearMappingTest(const Calendar& calendar)
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

void DatabaseGenerateServerBaseTesting::CalendarTesting::EffectiveTest()
{
    for (const auto& calendar : calendarContainer->GetContainer())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(NameTest, *calendar);
    }
}

void DatabaseGenerateServerBaseTesting::CalendarTesting::NameTest(const Calendar& calendar)
{
    ASSERT_FALSE(calendar.GetName().empty());
}
