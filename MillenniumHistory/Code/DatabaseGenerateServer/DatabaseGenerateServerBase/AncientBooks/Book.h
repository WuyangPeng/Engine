/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

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

        NODISCARD StringContainer GetAuthorNotes() const override;
        NODISCARD int GetAuthorNotesCount() const override;
        NODISCARD String GetAuthorNotes(int index) const override;
        NODISCARD StringContainerConstIter GetAuthorNotesBegin() const noexcept override;
        NODISCARD StringContainerConstIter GetAuthorNotesEnd() const noexcept override;

        NODISCARD IntContainer GetAnnotator() const override;
        NODISCARD int GetAnnotatorCount() const override;
        NODISCARD int GetAnnotator(int index) const override;
        NODISCARD IntContainerConstIter GetAnnotatorBegin() const noexcept override;
        NODISCARD IntContainerConstIter GetAnnotatorEnd() const noexcept override;
        NODISCARD CharacterContainer GetAnnotator(const AncientBooksContainer& csvContainer) const override;

        NODISCARD StringContainer GetAnnotateNotes() const override;
        NODISCARD int GetAnnotateNotesCount() const override;
        NODISCARD String GetAnnotateNotes(int index) const override;
        NODISCARD StringContainerConstIter GetAnnotateNotesBegin() const noexcept override;
        NODISCARD StringContainerConstIter GetAnnotateNotesEnd() const noexcept override;

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
        int genus;  // ��
        String name;  // ���Q
        StringContainer alias;  // �e��
        int volume;  // �픵
        IntContainer author;  // ����
        StringContainer authorNotes;  // ��������
        IntContainer annotator;  // �]������
        StringContainer annotateNotes;  // �]������
        IntContainer country;  // ����
        IntContainer person;  // ��
        StringContainer unansweredQuestion;  // ����
    };
}

#endif  // ANCIENT_BOOKS_BOOK_H
