/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_VERSION_H
#define ANCIENT_BOOKS_VERSION_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "VersionBase.h"
#include "System/Helper/UnicodeUsing.h"

namespace AncientBooks
{
    class Version final : public VersionBase
    {
    public:
        using ClassType = Version;
        using ParentType = VersionBase;

        using CSVRow = CoreTools::CSVRow; 

    public:
        explicit Version(const CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD int GetBook() const noexcept override;
        NODISCARD ConstBookSharedPtr GetBook(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetSource() const noexcept override;

        NODISCARD String GetSourceName() const override;

        NODISCARD int GetCountry() const noexcept override;
        NODISCARD ConstCountrySharedPtr GetCountry(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int64_t GetReignTitle() const noexcept override;
        NODISCARD ConstReignTitleSharedPtr GetReignTitle(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetYear() const noexcept override;
        NODISCARD ConstYearSharedPtr GetYear(const AncientBooksContainer& csvContainer) const override;

        NODISCARD String GetVersion() const override;

        NODISCARD IntContainer GetOtherAuthor() const override;
        NODISCARD int GetOtherAuthorCount() const override;
        NODISCARD int GetOtherAuthor(int index) const override;
        NODISCARD IntContainerConstIter GetOtherAuthorBegin() const noexcept override;
        NODISCARD IntContainerConstIter GetOtherAuthorEnd() const noexcept override;
        NODISCARD CharacterContainer GetOtherAuthor(const AncientBooksContainer& csvContainer) const override;

        NODISCARD StringContainer GetAuthorNotes() const override;
        NODISCARD int GetAuthorNotesCount() const override;
        NODISCARD String GetAuthorNotes(int index) const override;
        NODISCARD StringContainerConstIter GetAuthorNotesBegin() const noexcept override;
        NODISCARD StringContainerConstIter GetAuthorNotesEnd() const noexcept override;


    private:
        int id;  // Id
        int book;  // ��
        int source;  // ��̎
        String sourceName;  // ��̎����
        int country;  // �r��
        int64_t reignTitle;  // ��̖
        int year;  // ��
        String version;  // �汾
        IntContainer otherAuthor;  // ��������
        StringContainer authorNotes;  // ��������
    };
}

#endif  // ANCIENT_BOOKS_VERSION_H
