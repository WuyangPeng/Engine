///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/27 22:45)

#include "CalendarTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/Calendar.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/CalendarContainerDetail.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Helper/DatabaseGenerateServerCoreClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

DatabaseGenerateServerBaseTesting::CalendarTesting::CalendarTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer)
    : ParentType{ stream }, ancientBooksContainer{ ancientBooksContainer }
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
    const auto calendarContainer = ancientBooksContainer.GetCalendarContainer();

    for (const auto& calendar : calendarContainer->GetContainer())
    {
        ASSERT_EQUAL(calendar->GetSource(ancientBooksContainer).size(), calendar->GetSource().size());
        ASSERT_EQUAL(calendar->GetCreator(ancientBooksContainer).size(), calendar->GetCreator().size());

        if (calendar->GetFormulate() != 0)
        {
            ASSERT_UNEQUAL_NULL_PTR(calendar->GetFormulate(ancientBooksContainer));
        }

        if (0 < calendar->GetCountry())
        {
            ASSERT_UNEQUAL_NULL_PTR(calendar->GetCountry(ancientBooksContainer));
        }

        if (calendar->GetBegin() != 0)
        {
            ASSERT_UNEQUAL_NULL_PTR(calendar->GetBegin(ancientBooksContainer));
        }

        if (calendar->GetEnd() != 0)
        {
            ASSERT_UNEQUAL_NULL_PTR(calendar->GetEnd(ancientBooksContainer));
        }

        if (calendar->GetAgainBegin() != 0)
        {
            ASSERT_UNEQUAL_NULL_PTR(calendar->GetAgainBegin(ancientBooksContainer));
        }

        if (calendar->GetAgainEnd() != 0)
        {
            ASSERT_UNEQUAL_NULL_PTR(calendar->GetAgainEnd(ancientBooksContainer));
        }
    }
}

void DatabaseGenerateServerBaseTesting::CalendarTesting::EffectiveTest()
{
    const auto calendarContainer = ancientBooksContainer.GetCalendarContainer();

    for (const auto& calendar : calendarContainer->GetContainer())
    {
        ASSERT_FALSE(calendar->GetName().empty());
    }
}
