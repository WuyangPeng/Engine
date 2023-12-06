/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

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

        using String = System::String;
        using ConstGatherSharedPtr = std::shared_ptr<const GatherMappingType>;

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
        NODISCARD virtual ConstGatherSharedPtr GetGather(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual String GetCategory() const;

    private:
        int key{};
    };
}

#endif  // ANCIENT_BOOKS_CATEGORY_BASE_H
