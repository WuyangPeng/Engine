/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

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
        using ConstCountryBaseSharedPtr = std::shared_ptr<const CountryBase>;
        using Container = std::vector<ConstCountryBaseSharedPtr>;

    public:
        explicit CountryContainer(const CoreTools::CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstCountryBaseSharedPtr GetFirstCountry() const;
        NODISCARD ConstCountryBaseSharedPtr GetCountry(int key) const;
        NODISCARD Container GetContainer() const;

        template <typename Function>
        NODISCARD ConstCountryBaseSharedPtr GetFirstCountry(Function function) const;

        template <typename Function>
        NODISCARD Container GetCountry(Function function) const;

    private:
        void Parsing(const CoreTools::CSVContent& csvContent);

    private:
        Container country;
    };
}

#endif  // ANCIENT_BOOKS_COUNTRY_CONTAINER_H
