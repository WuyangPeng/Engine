/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

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
        using ConstCategoryBaseSharedPtr = std::shared_ptr<const CategoryBase>;
        using Container = std::vector<ConstCategoryBaseSharedPtr>;

    public:
        explicit CategoryContainer(const CoreTools::CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstCategoryBaseSharedPtr GetFirstCategory() const;
        NODISCARD ConstCategoryBaseSharedPtr GetCategory(int key) const;
        NODISCARD Container GetContainer() const;

        template <typename Function>
        NODISCARD ConstCategoryBaseSharedPtr GetFirstCategory(Function function) const;

        template <typename Function>
        NODISCARD Container GetCategory(Function function) const;

    private:
        void Parsing(const CoreTools::CSVContent& csvContent);

    private:
        Container category;
    };
}

#endif  // ANCIENT_BOOKS_CATEGORY_CONTAINER_H
