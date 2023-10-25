/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_BOOK_BASE_H
#define ANCIENT_BOOKS_BOOK_BASE_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>


namespace AncientBooks
{
    class BookBase
    {
    public:
        using ClassType = BookBase;

        using String = System::String;
        using StringContainer = std::vector<String>;
        using StringContainerConstIter = StringContainer::const_iterator;
        using IntContainer = std::vector<int>;
        using IntContainerConstIter = IntContainer::const_iterator;
        using ConstGenusSharedPtr = std::shared_ptr<const GenusMappingType>;
        using ConstCharacterSharedPtr = std::shared_ptr<const CharacterMappingType>;
        using CharacterContainer = std::vector<ConstCharacterSharedPtr>;
        using ConstCharacterSharedPtr = std::shared_ptr<const CharacterMappingType>;
        using CharacterContainer = std::vector<ConstCharacterSharedPtr>;
        using ConstCountrySharedPtr = std::shared_ptr<const CountryMappingType>;
        using CountryContainer = std::vector<ConstCountrySharedPtr>;
        using ConstCharacterSharedPtr = std::shared_ptr<const CharacterMappingType>;
        using CharacterContainer = std::vector<ConstCharacterSharedPtr>;

    public:
        BookBase() noexcept = default;
        explicit BookBase(int key) noexcept;

        virtual ~BookBase() noexcept = default;
        BookBase(const BookBase& rhs) noexcept = default;
        BookBase& operator=(const BookBase& rhs) noexcept = default;
        BookBase(BookBase&& rhs) noexcept = default;
        BookBase& operator=(BookBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual int GetKey() const noexcept;

        NODISCARD virtual int GetId() const noexcept;

        NODISCARD virtual int GetGenus() const noexcept;
        NODISCARD virtual ConstGenusSharedPtr GetGenus(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual String GetName() const;

        NODISCARD virtual StringContainer GetAlias() const;
        NODISCARD virtual int GetAliasCount() const;
        NODISCARD virtual String GetAlias(int index) const;
        NODISCARD virtual StringContainerConstIter GetAliasBegin() const;
        NODISCARD virtual StringContainerConstIter GetAliasEnd() const;

        NODISCARD virtual int GetVolume() const noexcept;

        NODISCARD virtual IntContainer GetAuthor() const;
        NODISCARD virtual int GetAuthorCount() const;
        NODISCARD virtual int GetAuthor(int index) const;
        NODISCARD virtual IntContainerConstIter GetAuthorBegin() const;
        NODISCARD virtual IntContainerConstIter GetAuthorEnd() const;
        NODISCARD virtual CharacterContainer GetAuthor(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual StringContainer GetAuthorNotes() const;
        NODISCARD virtual int GetAuthorNotesCount() const;
        NODISCARD virtual String GetAuthorNotes(int index) const;
        NODISCARD virtual StringContainerConstIter GetAuthorNotesBegin() const;
        NODISCARD virtual StringContainerConstIter GetAuthorNotesEnd() const;

        NODISCARD virtual IntContainer GetAnnotator() const;
        NODISCARD virtual int GetAnnotatorCount() const;
        NODISCARD virtual int GetAnnotator(int index) const;
        NODISCARD virtual IntContainerConstIter GetAnnotatorBegin() const;
        NODISCARD virtual IntContainerConstIter GetAnnotatorEnd() const;
        NODISCARD virtual CharacterContainer GetAnnotator(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual StringContainer GetAnnotateNotes() const;
        NODISCARD virtual int GetAnnotateNotesCount() const;
        NODISCARD virtual String GetAnnotateNotes(int index) const;
        NODISCARD virtual StringContainerConstIter GetAnnotateNotesBegin() const;
        NODISCARD virtual StringContainerConstIter GetAnnotateNotesEnd() const;

        NODISCARD virtual IntContainer GetCountry() const;
        NODISCARD virtual int GetCountryCount() const;
        NODISCARD virtual int GetCountry(int index) const;
        NODISCARD virtual IntContainerConstIter GetCountryBegin() const;
        NODISCARD virtual IntContainerConstIter GetCountryEnd() const;
        NODISCARD virtual CountryContainer GetCountry(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual IntContainer GetPerson() const;
        NODISCARD virtual int GetPersonCount() const;
        NODISCARD virtual int GetPerson(int index) const;
        NODISCARD virtual IntContainerConstIter GetPersonBegin() const;
        NODISCARD virtual IntContainerConstIter GetPersonEnd() const;
        NODISCARD virtual CharacterContainer GetPerson(const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual StringContainer GetUnansweredQuestion() const;
        NODISCARD virtual int GetUnansweredQuestionCount() const;
        NODISCARD virtual String GetUnansweredQuestion(int index) const;
        NODISCARD virtual StringContainerConstIter GetUnansweredQuestionBegin() const;
        NODISCARD virtual StringContainerConstIter GetUnansweredQuestionEnd() const;

    private:
        int key{};
    };
}

#endif  // ANCIENT_BOOKS_BOOK_BASE_H
