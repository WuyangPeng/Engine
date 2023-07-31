/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

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

        using ConstDayBaseSharedPtr = std::shared_ptr<const DayBase>;
        using Container = std::vector<ConstDayBaseSharedPtr>;
        using CSVContent = CoreTools::CSVContent;

    public:
        explicit DayContainer(const CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstDayBaseSharedPtr GetFirstDay() const;
        NODISCARD ConstDayBaseSharedPtr GetDay(int key) const;
        NODISCARD Container GetContainer() const;

        NODISCARD int GetContainerSize() const;

        template <typename Function>
        NODISCARD ConstDayBaseSharedPtr GetFirstDay(Function function) const;

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
