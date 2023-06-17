/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_CATEGORY_BASE_H
#define ANCIENT_BOOKS_CATEGORY_BASE_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
namespace AncientBooks
{
    class CategoryBase
    {
    public:
        using ClassType = CategoryBase;

    public:
        CategoryBase() noexcept = default;
        explicit CategoryBase(int key) noexcept;

        virtual ~CategoryBase() noexcept = default;
        CategoryBase(const CategoryBase& rhs) noexcept = default;
        CategoryBase& operator=(const CategoryBase& rhs) noexcept = default;
        CategoryBase(CategoryBase&& rhs) noexcept = default;
        CategoryBase& operator=(CategoryBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual int GetKey() const noexcept;

        NODISCARD virtual int GetId() const noexcept;

        NODISCARD virtual int GetGather() const noexcept;
        NODISCARD virtual std::shared_ptr<const GatherMappingType> GetGather(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual System::String GetCategory() const;

    private:
        int key{};
    };
}

#endif  // ANCIENT_BOOKS_CATEGORY_BASE_H
