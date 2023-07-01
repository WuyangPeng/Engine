/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_BOOK_H
#define ANCIENT_BOOKS_BOOK_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "BookBase.h"
#include "System/Helper/UnicodeUsing.h"

namespace AncientBooks
{
    class Book final : public BookBase
    {
    public:
        using ClassType = Book;
        using ParentType = BookBase;

        using CSVRow = CoreTools::CSVRow;

    public:
        explicit Book(const CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD int GetGenus() const noexcept override;
        NODISCARD ConstGenusSharedPtr GetGenus(const AncientBooksContainer& csvContainer) const override;

        NODISCARD String GetName() const override;

        NODISCARD StringContainer GetAlias() const override;
        NODISCARD int GetAliasCount() const override;
        NODISCARD String GetAlias(int index) const override;
        NODISCARD StringContainerConstIter GetAliasBegin() const noexcept override;
        NODISCARD StringContainerConstIter GetAliasEnd() const noexcept override;

        NODISCARD int GetVolume() const noexcept override;

        NODISCARD IntContainer GetAuthor() const override;
        NODISCARD int GetAuthorCount() const override;
        NODISCARD int GetAuthor(int index) const override;
        NODISCARD IntContainerConstIter GetAuthorBegin() const noexcept override;
        NODISCARD IntContainerConstIter GetAuthorEnd() const noexcept override;
        NODISCARD CharacterContainer GetAuthor(const AncientBooksContainer& csvContainer) const override;

        NODISCARD StringContainer GetAuthorDescribe() const override;
        NODISCARD int GetAuthorDescribeCount() const override;
        NODISCARD String GetAuthorDescribe(int index) const override;
        NODISCARD StringContainerConstIter GetAuthorDescribeBegin() const noexcept override;
        NODISCARD StringContainerConstIter GetAuthorDescribeEnd() const noexcept override;

        NODISCARD IntContainer GetAnnotator() const override;
        NODISCARD int GetAnnotatorCount() const override;
        NODISCARD int GetAnnotator(int index) const override;
        NODISCARD IntContainerConstIter GetAnnotatorBegin() const noexcept override;
        NODISCARD IntContainerConstIter GetAnnotatorEnd() const noexcept override;
        NODISCARD CharacterContainer GetAnnotator(const AncientBooksContainer& csvContainer) const override;

        NODISCARD StringContainer GetAnnotateDescribe() const override;
        NODISCARD int GetAnnotateDescribeCount() const override;
        NODISCARD String GetAnnotateDescribe(int index) const override;
        NODISCARD StringContainerConstIter GetAnnotateDescribeBegin() const noexcept override;
        NODISCARD StringContainerConstIter GetAnnotateDescribeEnd() const noexcept override;

        NODISCARD IntContainer GetCountry() const override;
        NODISCARD int GetCountryCount() const override;
        NODISCARD int GetCountry(int index) const override;
        NODISCARD IntContainerConstIter GetCountryBegin() const noexcept override;
        NODISCARD IntContainerConstIter GetCountryEnd() const noexcept override;
        NODISCARD CountryContainer GetCountry(const AncientBooksContainer& csvContainer) const override;

        NODISCARD IntContainer GetPerson() const override;
        NODISCARD int GetPersonCount() const override;
        NODISCARD int GetPerson(int index) const override;
        NODISCARD IntContainerConstIter GetPersonBegin() const noexcept override;
        NODISCARD IntContainerConstIter GetPersonEnd() const noexcept override;
        NODISCARD CharacterContainer GetPerson(const AncientBooksContainer& csvContainer) const override;

        NODISCARD StringContainer GetUnansweredQuestion() const override;
        NODISCARD int GetUnansweredQuestionCount() const override;
        NODISCARD String GetUnansweredQuestion(int index) const override;
        NODISCARD StringContainerConstIter GetUnansweredQuestionBegin() const noexcept override;
        NODISCARD StringContainerConstIter GetUnansweredQuestionEnd() const noexcept override;

    private:
        int id;  // Id
        int genus;  // 屬
        String name;  // 名稱
        StringContainer alias;  // 別名
        int volume;  // 卷數
        IntContainer author;  // 作者
        StringContainer authorDescribe;  // 作者描述
        IntContainer annotator;  // 註解作者
        StringContainer annotateDescribe;  // 註解描述
        IntContainer country;  // 國家
        IntContainer person;  // 人
        StringContainer unansweredQuestion;  // 存疑
    };
}

#endif  // ANCIENT_BOOKS_BOOK_H
