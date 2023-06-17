/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_GENUS_BASE_H
#define ANCIENT_BOOKS_GENUS_BASE_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
namespace AncientBooks
{
    class GenusBase
    {
    public:
        using ClassType = GenusBase;

    public:
        GenusBase() noexcept = default;
        explicit GenusBase(int key) noexcept;

        virtual ~GenusBase() noexcept = default;
        GenusBase(const GenusBase& rhs) noexcept = default;
        GenusBase& operator=(const GenusBase& rhs) noexcept = default;
        GenusBase(GenusBase&& rhs) noexcept = default;
        GenusBase& operator=(GenusBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual int GetKey() const noexcept;

        NODISCARD virtual int GetId() const noexcept;

        NODISCARD virtual int GetCategory() const noexcept;
        NODISCARD virtual std::shared_ptr<const CategoryMappingType> GetCategory(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual System::String GetName() const;

        NODISCARD virtual int GetFather() const noexcept;
        NODISCARD virtual std::shared_ptr<const GenusMappingType> GetFather(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual System::String GetBegin() const;

        NODISCARD virtual System::String GetEnd() const;

    private:
        int key{};
    };
}

#endif  // ANCIENT_BOOKS_GENUS_BASE_H
