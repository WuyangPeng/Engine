/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/25 22:11)

#ifndef DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_CALENDAR_CONVERT_TESTING_H
#define DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_CALENDAR_CONVERT_TESTING_H

#include "ConvertTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/CalendarContainer.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/DatabaseEntityFwd.h"

namespace DatabaseGenerateCoreTesting
{
    class CalendarConvertTesting final : public ConvertTesting
    {
    public:
        using ClassType = CalendarConvertTesting;
        using ParentType = ConvertTesting;

        using CalendarContainer = AncientBooks::CalendarContainer;

    public:
        CalendarConvertTesting(const OStreamShared& stream, CalendarContainer calendarContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Calendar = AncientBooks::CalendarBase;
        using CalendarEntity = DatabaseEntity::CalendarEntity;

    private:
        void ConvertTest(const DatabaseFlushSharedPtr& databaseFlush) override;
        void EqualTest(const Calendar& calendar, const CalendarEntity& calendarEntity);

    private:
        CalendarContainer calendarContainer;
    };
}

#endif  // DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_CALENDAR_CONVERT_TESTING_H