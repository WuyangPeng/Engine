/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_MONTH_CONTAINER_H
#define ANCIENT_BOOKS_MONTH_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace AncientBooks
{
    class MonthContainer final
    {
    public:
        using ClassType = MonthContainer;

        using ConstMonthBaseSharedPtr = std::shared_ptr<const MonthBase>;
        using Container = std::vector<ConstMonthBaseSharedPtr>;
        using CSVContent = CoreTools::CSVContent;

    public:
        explicit MonthContainer(const CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstMonthBaseSharedPtr GetFirstMonth() const;
        NODISCARD ConstMonthBaseSharedPtr GetMonth(int key) const;
        NODISCARD Container GetContainer() const;

        NODISCARD int GetContainerSize() const;

        template <typename Function>
        NODISCARD ConstMonthBaseSharedPtr GetFirstMonth(Function function) const;

        template <typename Function>
        NODISCARD Container GetMonth(Function function) const;

    private:
        void Parsing(const CSVContent& csvContent);
        void Load(const CSVContent& csvContent);
        void Unique();

    private:
        Container month;
    };
}

#endif  // ANCIENT_BOOKS_MONTH_CONTAINER_H
