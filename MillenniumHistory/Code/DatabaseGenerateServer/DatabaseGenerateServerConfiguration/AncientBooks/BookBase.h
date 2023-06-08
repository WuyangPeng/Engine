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
        NODISCARD virtual std::shared_ptr<const GenusMappingType> GetGenus(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const;

        NODISCARD virtual System::String GetName() const;

        NODISCARD virtual std::vector<System::String> GetAlias() const;
        NODISCARD virtual int GetAliasCount() const;
        NODISCARD virtual System::String GetAlias(MAYBE_UNUSED int index) const;
        NODISCARD virtual std::vector<System::String>::const_iterator GetAliasBegin() const;
        NODISCARD virtual std::vector<System::String>::const_iterator GetAliasEnd() const;

        NODISCARD virtual int GetVolume() const noexcept;

        NODISCARD virtual std::vector<int> GetAuthor() const;
        NODISCARD virtual int GetAuthorCount() const;
        NODISCARD virtual int GetAuthor(MAYBE_UNUSED int index) const;
        NODISCARD virtual std::vector<int>::const_iterator GetAuthorBegin() const;
        NODISCARD virtual std::vector<int>::const_iterator GetAuthorEnd() const;

        NODISCARD virtual std::vector<System::String> GetAuthorDescribe() const;
        NODISCARD virtual int GetAuthorDescribeCount() const;
        NODISCARD virtual System::String GetAuthorDescribe(MAYBE_UNUSED int index) const;
        NODISCARD virtual std::vector<System::String>::const_iterator GetAuthorDescribeBegin() const;
        NODISCARD virtual std::vector<System::String>::const_iterator GetAuthorDescribeEnd() const;

        NODISCARD virtual std::vector<int> GetAnnotator() const;
        NODISCARD virtual int GetAnnotatorCount() const;
        NODISCARD virtual int GetAnnotator(MAYBE_UNUSED int index) const;
        NODISCARD virtual std::vector<int>::const_iterator GetAnnotatorBegin() const;
        NODISCARD virtual std::vector<int>::const_iterator GetAnnotatorEnd() const;

        NODISCARD virtual std::vector<System::String> GetAnnotateDescribe() const;
        NODISCARD virtual int GetAnnotateDescribeCount() const;
        NODISCARD virtual System::String GetAnnotateDescribe(MAYBE_UNUSED int index) const;
        NODISCARD virtual std::vector<System::String>::const_iterator GetAnnotateDescribeBegin() const;
        NODISCARD virtual std::vector<System::String>::const_iterator GetAnnotateDescribeEnd() const;

        NODISCARD virtual std::vector<int> GetCountry() const;
        NODISCARD virtual int GetCountryCount() const;
        NODISCARD virtual int GetCountry(MAYBE_UNUSED int index) const;
        NODISCARD virtual std::vector<int>::const_iterator GetCountryBegin() const;
        NODISCARD virtual std::vector<int>::const_iterator GetCountryEnd() const;

        NODISCARD virtual std::vector<int> GetPerson() const;
        NODISCARD virtual int GetPersonCount() const;
        NODISCARD virtual int GetPerson(MAYBE_UNUSED int index) const;
        NODISCARD virtual std::vector<int>::const_iterator GetPersonBegin() const;
        NODISCARD virtual std::vector<int>::const_iterator GetPersonEnd() const;

        NODISCARD virtual std::vector<System::String> GetUnansweredQuestion() const;
        NODISCARD virtual int GetUnansweredQuestionCount() const;
        NODISCARD virtual System::String GetUnansweredQuestion(MAYBE_UNUSED int index) const;
        NODISCARD virtual std::vector<System::String>::const_iterator GetUnansweredQuestionBegin() const;
        NODISCARD virtual std::vector<System::String>::const_iterator GetUnansweredQuestionEnd() const;

    private:
        int key{};
    };
}

#endif  // ANCIENT_BOOKS_BOOK_BASE_H
