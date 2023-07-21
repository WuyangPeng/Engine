/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

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
        int version;  // 版本
        int chapter;  // 章
        String chapterName;  // 章節名字
        int volume;  // 卷
        int chapterVolume;  // 章節卷
        IntContainer otherAuthor;  // 其他作者
        StringContainer authorNotes;  // 作者描述
        String title;  // 標題
        String abbreviation;  // 標題（簡稱）
        String directory;  // 目錄
    };
}

#endif  // ANCIENT_BOOKS_ARTICLE_H
