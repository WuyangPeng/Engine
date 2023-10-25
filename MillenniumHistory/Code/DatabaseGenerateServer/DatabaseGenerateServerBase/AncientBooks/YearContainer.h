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

        using ConstYearSharedPtr = std::shared_ptr<const YearMappingType>;
        using Container = std::vector<ConstYearSharedPtr>;
        using CSVContent = CoreTools::CSVContent;

    public:
        explicit YearContainer(const CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstYearSharedPtr GetFirstYear() const;
        NODISCARD ConstYearSharedPtr GetYear(int key) const;
        NODISCARD Container GetContainer() const;

        NODISCARD int GetContainerSize() const;

        template <typename Function>
        NODISCARD ConstYearSharedPtr GetFirstYear(Function function) const;

        template <typename Function>
        NODISCARD Container GetYear(Function function) const;

    private:
        void Parsing(const CSVContent& csvContent);
        void Load(const CSVContent& csvContent);
        void Unique();

    private:
        Container year;
    };
}

#endif  // ANCIENT_BOOKS_YEAR_CONTAINER_H
