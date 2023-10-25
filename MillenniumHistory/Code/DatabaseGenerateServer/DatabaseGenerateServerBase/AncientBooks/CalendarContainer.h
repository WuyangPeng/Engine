/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_CALENDAR_CONTAINER_H
#define ANCIENT_BOOKS_CALENDAR_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace AncientBooks
{
    class CalendarContainer final
    {
    public:
        using ClassType = CalendarContainer;

        using ConstCalendarSharedPtr = std::shared_ptr<const CalendarMappingType>;
        using Container = std::vector<ConstCalendarSharedPtr>;
        using CSVContent = CoreTools::CSVContent;

    public:
        explicit CalendarContainer(const CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstCalendarSharedPtr GetFirstCalendar() const;
        NODISCARD ConstCalendarSharedPtr GetCalendar(int key) const;
        NODISCARD Container GetContainer() const;

        NODISCARD int GetContainerSize() const;

        template <typename Function>
        NODISCARD ConstCalendarSharedPtr GetFirstCalendar(Function function) const;

        template <typename Function>
        NODISCARD Container GetCalendar(Function function) const;

    private:
        void Parsing(const CSVContent& csvContent);
        void Load(const CSVContent& csvContent);
        void Unique();

    private:
        Container calendar;
    };
}

#endif  // ANCIENT_BOOKS_CALENDAR_CONTAINER_H
