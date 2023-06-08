/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

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

    public:
        explicit MonthContainer(const CoreTools::CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstMonthBaseSharedPtr GetFirstMonth() const;
        NODISCARD ConstMonthBaseSharedPtr GetMonth(int key) const;
        NODISCARD Container GetContainer() const;

        template <typename Function>
        NODISCARD ConstMonthBaseSharedPtr GetFirstMonth(Function function) const;

        template <typename Function>
        NODISCARD Container GetMonth(Function function) const;

    private:
        void Parsing(const CoreTools::CSVContent& csvContent);

    private:
        Container month;
    };
}

#endif  // ANCIENT_BOOKS_MONTH_CONTAINER_H
