/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_GENUS_CONTAINER_H
#define ANCIENT_BOOKS_GENUS_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace AncientBooks
{
    class GenusContainer final
    {
    public:
        using ClassType = GenusContainer;

        using ConstGenusBaseSharedPtr = std::shared_ptr<const GenusBase>;
        using Container = std::vector<ConstGenusBaseSharedPtr>;
        using CSVContent = CoreTools::CSVContent;

    public:
        explicit GenusContainer(const CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstGenusBaseSharedPtr GetFirstGenus() const;
        NODISCARD ConstGenusBaseSharedPtr GetGenus(int key) const;
        NODISCARD Container GetContainer() const;

        NODISCARD int GetContainerSize() const;

        template <typename Function>
        NODISCARD ConstGenusBaseSharedPtr GetFirstGenus(Function function) const;

        template <typename Function>
        NODISCARD Container GetGenus(Function function) const;

    private:
        void Parsing(const CSVContent& csvContent);
        void Load(const CSVContent& csvContent);
        void Unique();

    private:
        Container genus;
    };
}

#endif  // ANCIENT_BOOKS_GENUS_CONTAINER_H
