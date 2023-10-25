/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_DAY_CONTAINER_H
#define ANCIENT_BOOKS_DAY_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace AncientBooks
{
    class DayContainer final
    {
    public:
        using ClassType = DayContainer;

        using ConstDaySharedPtr = std::shared_ptr<const DayMappingType>;
        using Container = std::vector<ConstDaySharedPtr>;
        using CSVContent = CoreTools::CSVContent;

    public:
        explicit DayContainer(const CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstDaySharedPtr GetFirstDay() const;
        NODISCARD ConstDaySharedPtr GetDay(int key) const;
        NODISCARD Container GetContainer() const;

        NODISCARD int GetContainerSize() const;

        template <typename Function>
        NODISCARD ConstDaySharedPtr GetFirstDay(Function function) const;

        template <typename Function>
        NODISCARD Container GetDay(Function function) const;

    private:
        void Parsing(const CSVContent& csvContent);
        void Load(const CSVContent& csvContent);
        void Unique();

    private:
        Container day;
    };
}

#endif  // ANCIENT_BOOKS_DAY_CONTAINER_H
