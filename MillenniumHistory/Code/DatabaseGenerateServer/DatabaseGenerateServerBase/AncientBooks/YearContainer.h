/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_YEAR_CONTAINER_H
#define ANCIENT_BOOKS_YEAR_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace AncientBooks
{
    class YearContainer final
    {
    public:
        using ClassType = YearContainer;
        using ConstYearBaseSharedPtr = std::shared_ptr<const YearBase>;
        using Container = std::vector<ConstYearBaseSharedPtr>;

    public:
        explicit YearContainer(const CoreTools::CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstYearBaseSharedPtr GetFirstYear() const;
        NODISCARD ConstYearBaseSharedPtr GetYear(int key) const;
        NODISCARD Container GetContainer() const;

        template <typename Function>
        NODISCARD ConstYearBaseSharedPtr GetFirstYear(Function function) const;

        template <typename Function>
        NODISCARD Container GetYear(Function function) const;

    private:
        void Parsing(const CoreTools::CSVContent& csvContent);

    private:
        Container year;
    };
}

#endif  // ANCIENT_BOOKS_YEAR_CONTAINER_H
