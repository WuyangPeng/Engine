/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_ARTICLE_H
#define ANCIENT_BOOKS_ARTICLE_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "ArticleBase.h"
#include "System/Helper/UnicodeUsing.h"

namespace AncientBooks
{
    class Article final : public ArticleBase
    {
    public:
        using ClassType = Article;
        using ParentType = ArticleBase;

        using CSVRow = CoreTools::CSVRow;

    public:
        explicit Article(const CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int64_t GetKey() const noexcept override;

        NODISCARD int64_t GetId() const noexcept override;

        NODISCARD int GetVersion() const noexcept override;
        NODISCARD ConstVersionSharedPtr GetVersion(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetChapter() const noexcept override;

        NODISCARD String GetChapterName() const override;

        NODISCARD int GetVolume() const noexcept override;

        NODISCARD int GetChapterVolume() const noexcept override;

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

        NODISCARD String GetTitle() const override;

        NODISCARD String GetAbbreviation() const override;

        NODISCARD String GetDirectory() const override;

    private:
        int64_t id;  // Id
        int version;  // �汾
        int chapter;  // ��
        String chapterName;  // �¹�����
        int volume;  // ��
        int chapterVolume;  // �¹���
        IntContainer otherAuthor;  // ��������
        StringContainer authorNotes;  // ��������
        String title;  // ���}
        String abbreviation;  // ���}�����Q��
        String directory;  // Ŀ�
    };
}

#endif  // ANCIENT_BOOKS_ARTICLE_H
