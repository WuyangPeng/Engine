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

    public:
        explicit Book(const CoreTools::CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD int GetGenus() const noexcept override;
        NODISCARD std::shared_ptr<const GenusMappingType> GetGenus(const AncientBooksContainer& csvContainer) const override;

        NODISCARD System::String GetName() const override;

        NODISCARD std::vector<System::String> GetAlias() const override;
        NODISCARD int GetAliasCount() const override;
        NODISCARD System::String GetAlias(int index) const override;
        NODISCARD std::vector<System::String>::const_iterator GetAliasBegin() const noexcept override;
        NODISCARD std::vector<System::String>::const_iterator GetAliasEnd() const noexcept override;

        NODISCARD int GetVolume() const noexcept override;

        NODISCARD std::vector<int> GetAuthor() const override;
        NODISCARD int GetAuthorCount() const override;
        NODISCARD int GetAuthor(int index) const override;
        NODISCARD std::vector<int>::const_iterator GetAuthorBegin() const noexcept override;
        NODISCARD std::vector<int>::const_iterator GetAuthorEnd() const noexcept override;

        NODISCARD std::vector<System::String> GetAuthorDescribe() const override;
        NODISCARD int GetAuthorDescribeCount() const override;
        NODISCARD System::String GetAuthorDescribe(int index) const override;
        NODISCARD std::vector<System::String>::const_iterator GetAuthorDescribeBegin() const noexcept override;
        NODISCARD std::vector<System::String>::const_iterator GetAuthorDescribeEnd() const noexcept override;

        NODISCARD std::vector<int> GetAnnotator() const override;
        NODISCARD int GetAnnotatorCount() const override;
        NODISCARD int GetAnnotator(int index) const override;
        NODISCARD std::vector<int>::const_iterator GetAnnotatorBegin() const noexcept override;
        NODISCARD std::vector<int>::const_iterator GetAnnotatorEnd() const noexcept override;

        NODISCARD std::vector<System::String> GetAnnotateDescribe() const override;
        NODISCARD int GetAnnotateDescribeCount() const override;
        NODISCARD System::String GetAnnotateDescribe(int index) const override;
        NODISCARD std::vector<System::String>::const_iterator GetAnnotateDescribeBegin() const noexcept override;
        NODISCARD std::vector<System::String>::const_iterator GetAnnotateDescribeEnd() const noexcept override;

        NODISCARD std::vector<int> GetCountry() const override;
        NODISCARD int GetCountryCount() const override;
        NODISCARD int GetCountry(int index) const override;
        NODISCARD std::vector<int>::const_iterator GetCountryBegin() const noexcept override;
        NODISCARD std::vector<int>::const_iterator GetCountryEnd() const noexcept override;

        NODISCARD std::vector<int> GetPerson() const override;
        NODISCARD int GetPersonCount() const override;
        NODISCARD int GetPerson(int index) const override;
        NODISCARD std::vector<int>::const_iterator GetPersonBegin() const noexcept override;
        NODISCARD std::vector<int>::const_iterator GetPersonEnd() const noexcept override;

        NODISCARD std::vector<System::String> GetUnansweredQuestion() const override;
        NODISCARD int GetUnansweredQuestionCount() const override;
        NODISCARD System::String GetUnansweredQuestion(int index) const override;
        NODISCARD std::vector<System::String>::const_iterator GetUnansweredQuestionBegin() const noexcept override;
        NODISCARD std::vector<System::String>::const_iterator GetUnansweredQuestionEnd() const noexcept override;

    private:
        int id;  // Id
        int genus;  // 屬
        System::String name;  // 名稱
        std::vector<System::String> alias;  // 別名
        int volume;  // 卷數
        std::vector<int> author;  // 作者
        std::vector<System::String> authorDescribe;  // 作者描述
        std::vector<int> annotator;  // 註解作者
        std::vector<System::String> annotateDescribe;  // 註解描述
        std::vector<int> country;  // 國家
        std::vector<int> person;  // 人
        std::vector<System::String> unansweredQuestion;  // 存疑
    };
}

#endif  // ANCIENT_BOOKS_BOOK_H
