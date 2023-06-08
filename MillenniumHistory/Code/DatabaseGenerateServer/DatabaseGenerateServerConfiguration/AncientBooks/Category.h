/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_CATEGORY_H
#define ANCIENT_BOOKS_CATEGORY_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "CategoryBase.h"
#include "System/Helper/UnicodeUsing.h"

namespace AncientBooks
{
    class Category final : public CategoryBase
    {
    public:
        using ClassType = Category;
        using ParentType = CategoryBase;

    public:
        explicit Category(const CoreTools::CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD int GetGather() const noexcept override;
        NODISCARD std::shared_ptr<const GatherMappingType> GetGather(const AncientBooksContainer& csvContainer) const override;

        NODISCARD System::String GetCategory() const override;

    private:
        int id;  // Id
        int gather;  // 集
        System::String category;  // 名称
    };
}

#endif  // ANCIENT_BOOKS_CATEGORY_H
