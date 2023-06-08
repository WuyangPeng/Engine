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

    public:
        explicit Article(const CoreTools::CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int64_t GetKey() const noexcept override;

        NODISCARD int64_t GetId() const noexcept override;

        NODISCARD int GetVersion() const noexcept override;
        NODISCARD std::shared_ptr<const VersionMappingType> GetVersion(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetChapter() const noexcept override;
        NODISCARD std::shared_ptr<const ChapterMappingType> GetChapter(const AncientBooksContainer& csvContainer) const override;

        NODISCARD System::String GetChapterName() const override;

        NODISCARD int GetVolume() const noexcept override;

        NODISCARD std::vector<int> GetOtherAuthor() const override;
        NODISCARD int GetOtherAuthorCount() const override;
        NODISCARD int GetOtherAuthor(int index) const override;
        NODISCARD std::vector<int>::const_iterator GetOtherAuthorBegin() const noexcept override;
        NODISCARD std::vector<int>::const_iterator GetOtherAuthorEnd() const noexcept override;

        NODISCARD std::vector<System::String> GetAuthorDescribe() const override;
        NODISCARD int GetAuthorDescribeCount() const override;
        NODISCARD System::String GetAuthorDescribe(int index) const override;
        NODISCARD std::vector<System::String>::const_iterator GetAuthorDescribeBegin() const noexcept override;
        NODISCARD std::vector<System::String>::const_iterator GetAuthorDescribeEnd() const noexcept override;

        NODISCARD System::String GetTitle() const override;

        NODISCARD System::String GetAbbreviation() const override;

        NODISCARD System::String GetDirectory() const override;

    private:
        int64_t id;  // Id
        int version;  // 版本
        int chapter;  // 章
        System::String chapterName;  // 章節名字
        int volume;  // 卷
        std::vector<int> otherAuthor;  // 其他作者
        std::vector<System::String> authorDescribe;  // 作者描述
        System::String title;  // 標題
        System::String abbreviation;  // 標題
        System::String directory;  // 目錄
    };
}

#endif  // ANCIENT_BOOKS_ARTICLE_H
