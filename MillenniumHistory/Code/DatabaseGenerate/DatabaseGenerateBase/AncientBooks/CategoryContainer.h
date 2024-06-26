/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_CATEGORY_CONTAINER_H
#define ANCIENT_BOOKS_CATEGORY_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace AncientBooks
{
    class CategoryContainer final
    {
    public:
        using ClassType = CategoryContainer;

        using ConstCategorySharedPtr = std::shared_ptr<const CategoryMappingType>;
        using Container = std::vector<ConstCategorySharedPtr>;
        using CSVContent = CoreTools::CSVContent;

    public:
        explicit CategoryContainer(const CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstCategorySharedPtr GetFirstCategory() const;
        NODISCARD ConstCategorySharedPtr GetCategory(int key) const;
        NODISCARD Container GetContainer() const;

        NODISCARD int GetContainerSize() const;

        template <typename Function>
        NODISCARD ConstCategorySharedPtr GetFirstCategory(Function function) const;

        template <typename Function>
        NODISCARD Container GetCategory(Function function) const;

    private:
        void Parsing(const CSVContent& csvContent);
        void Load(const CSVContent& csvContent);
        void Unique();

    private:
        Container category;
    };
}

#endif  // ANCIENT_BOOKS_CATEGORY_CONTAINER_H
