/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/23 22:19)

#ifndef DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_CALENDAR_ENTITY_TESTING_H
#define DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_CALENDAR_ENTITY_TESTING_H

#include "DatabaseEntityTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/CalendarContainer.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/DatabaseEntityFwd.h"

namespace DatabaseGenerateBaseTesting
{
    class CalendarEntityTesting final : public DatabaseEntityTesting
    {
    public:
        using ClassType = CalendarEntityTesting;
        using ParentType = DatabaseEntityTesting;

        using CalendarContainer = AncientBooks::CalendarContainer;

    public:
        CalendarEntityTesting(const OStreamShared& stream, CalendarContainer calendarContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Calendar = AncientBooks::CalendarBase;
        using CalendarEntity = DatabaseEntity::CalendarEntity;
        using EntityContainer = std::map<int32_t, CalendarEntity>;

    private:
        void SelectOneTest(DatabaseFlush& databaseFlush) override;
        void SelectAllTest(DatabaseFlush& databaseFlush) override;
        void SelectAllSizeTest(const DatabaseFlush& databaseFlush) override;

        void SetEntity(CalendarEntity& calendarEntity, const Calendar& calendar);

        void DoSelectOneTest(DatabaseFlush& databaseFlush, const Calendar& calendar);
        void DoSelectAllTest(DatabaseFlush& databaseFlush, const Calendar& calendar, const EntityContainer& entityContainer);
        void EqualTest(const Calendar& calendar, const EntityContainer& entityContainer);

    private:
        CalendarContainer calendarContainer;
    };
}

#endif  // DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_CALENDAR_ENTITY_TESTING_H