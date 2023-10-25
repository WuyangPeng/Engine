/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_COUNTRY_CONTAINER_H
#define ANCIENT_BOOKS_COUNTRY_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace AncientBooks
{
    class CountryContainer final
    {
    public:
        using ClassType = CountryContainer;

        using ConstCountrySharedPtr = std::shared_ptr<const CountryMappingType>;
        using Container = std::vector<ConstCountrySharedPtr>;
        using CSVContent = CoreTools::CSVContent;

    public:
        explicit CountryContainer(const CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstCountrySharedPtr GetFirstCountry() const;
        NODISCARD ConstCountrySharedPtr GetCountry(int key) const;
        NODISCARD Container GetContainer() const;

        NODISCARD int GetContainerSize() const;

        template <typename Function>
        NODISCARD ConstCountrySharedPtr GetFirstCountry(Function function) const;

        template <typename Function>
        NODISCARD Container GetCountry(Function function) const;

    private:
        void Parsing(const CSVContent& csvContent);
        void Load(const CSVContent& csvContent);
        void Unique();

    private:
        Container country;
    };
}

#endif  // ANCIENT_BOOKS_COUNTRY_CONTAINER_H
