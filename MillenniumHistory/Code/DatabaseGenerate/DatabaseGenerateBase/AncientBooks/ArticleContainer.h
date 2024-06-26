/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_ARTICLE_CONTAINER_H
#define ANCIENT_BOOKS_ARTICLE_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace AncientBooks
{
    class ArticleContainer final
    {
    public:
        using ClassType = ArticleContainer;

        using ConstArticleSharedPtr = std::shared_ptr<const ArticleMappingType>;
        using Container = std::vector<ConstArticleSharedPtr>;
        using CSVContent = CoreTools::CSVContent;

    public:
        explicit ArticleContainer(const CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstArticleSharedPtr GetFirstArticle() const;
        NODISCARD ConstArticleSharedPtr GetArticle(int64_t key) const;
        NODISCARD Container GetContainer() const;

        NODISCARD int GetContainerSize() const;

        template <typename Function>
        NODISCARD ConstArticleSharedPtr GetFirstArticle(Function function) const;

        template <typename Function>
        NODISCARD Container GetArticle(Function function) const;

    private:
        void Parsing(const CSVContent& csvContent);
        void Load(const CSVContent& csvContent);
        void Unique();

    private:
        Container article;
    };
}

#endif  // ANCIENT_BOOKS_ARTICLE_CONTAINER_H
