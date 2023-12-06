/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_VERSION_BASE_H
#define ANCIENT_BOOKS_VERSION_BASE_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace AncientBooks
{
    class VersionBase
    {
    public:
        using ClassType = VersionBase;

        using String = System::String;
        using StringContainer = std::vector<String>;
        using StringContainerConstIter = StringContainer::const_iterator;
        using IntContainer = std::vector<int>;
        using IntContainerConstIter = IntContainer::const_iterator;
        using ConstBookSharedPtr = std::shared_ptr<const BookMappingType>;
        using ConstCountrySharedPtr = std::shared_ptr<const CountryMappingType>;
        using ConstReignTitleSharedPtr = std::shared_ptr<const ReignTitleMappingType>;
        using ConstYearSharedPtr = std::shared_ptr<const YearMappingType>;
        using ConstCharacterSharedPtr = std::shared_ptr<const CharacterMappingType>;
        using CharacterContainer = std::vector<ConstCharacterSharedPtr>;

    public:
        VersionBase() noexcept = default;
        explicit VersionBase(int key) noexcept;

        virtual ~VersionBase() noexcept = default;
        VersionBase(const VersionBase& rhs) noexcept = default;
        VersionBase& operator=(const VersionBase& rhs) noexcept = default;
        VersionBase(VersionBase&& rhs) noexcept = default;
        VersionBase& operator=(VersionBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual int GetKey() const noexcept;

        NODISCARD virtual int GetId() const noexcept;

        NODISCARD virtual int GetBook() const noexcept;
        NODISCARD virtual ConstBookSharedPtr GetBook(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetSource() const noexcept;

        NODISCARD virtual String GetSourceName() const;

        NODISCARD virtual int GetCountry() const noexcept;
        NODISCARD virtual ConstCountrySharedPtr GetCountry(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int64_t GetReignTitle() const noexcept;
        NODISCARD virtual ConstReignTitleSharedPtr GetReignTitle(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual int GetYear() const noexcept;
        NODISCARD virtual ConstYearSharedPtr GetYear(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual String GetVersion() const;

        NODISCARD virtual IntContainer GetOtherAuthor() const;
        NODISCARD virtual int GetOtherAuthorCount() const;
        NODISCARD virtual int GetOtherAuthor(int index) const;
        NODISCARD virtual IntContainerConstIter GetOtherAuthorBegin() const;
        NODISCARD virtual IntContainerConstIter GetOtherAuthorEnd() const;
        NODISCARD virtual CharacterContainer GetOtherAuthor(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual StringContainer GetAuthorNotes() const;
        NODISCARD virtual int GetAuthorNotesCount() const;
        NODISCARD virtual String GetAuthorNotes(int index) const;
        NODISCARD virtual StringContainerConstIter GetAuthorNotesBegin() const;
        NODISCARD virtual StringContainerConstIter GetAuthorNotesEnd() const;

    private:
        int key{};
    };
}

#endif  // ANCIENT_BOOKS_VERSION_BASE_H
