///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/23 0:08)

#ifndef DATABASE_GENERATE_SERVER_BASE_TESTING_ANCIENT_BOOKS_SUITE_CALENDAR_TESTING_H
#define DATABASE_GENERATE_SERVER_BASE_TESTING_ANCIENT_BOOKS_SUITE_CALENDAR_TESTING_H

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/AncientBooksContainer.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace DatabaseGenerateServerBaseTesting
{
    class CalendarTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CalendarTesting;
        using ParentType = UnitTest;

        using AncientBooksContainer = AncientBooks::AncientBooksContainer;

    public:
        CalendarTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Calendar = AncientBooks::CalendarBase;
        using ConstCalendarContainerSharedPtr = AncientBooksContainer::ConstCalendarContainerSharedPtr;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void MappingTest();
        void EffectiveTest();

        void SourceMappingTest(const Calendar& calendar);
        void CreatorMappingTest(const Calendar& calendar);
        void FormulateMappingTest(const Calendar& calendar);
        void CountryMappingTest(const Calendar& calendar);
        void YearMappingTest(const Calendar& calendar);

        void NameTest(const Calendar& calendar);

    private:
        AncientBooksContainer ancientBooksContainer;
        ConstCalendarContainerSharedPtr calendarContainer;
    };
}

#endif  // DATABASE_GENERATE_SERVER_BASE_TESTING_ANCIENT_BOOKS_SUITE_CALENDAR_TESTING_H