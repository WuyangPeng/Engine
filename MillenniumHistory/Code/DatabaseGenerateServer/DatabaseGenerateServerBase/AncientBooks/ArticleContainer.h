/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

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

        using ConstArticleBaseSharedPtr = std::shared_ptr<const ArticleBase>;
        using Container = std::vector<ConstArticleBaseSharedPtr>;
        using CSVContent = CoreTools::CSVContent;

    public:
        explicit ArticleContainer(const CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstArticleBaseSharedPtr GetFirstArticle() const;
        NODISCARD ConstArticleBaseSharedPtr GetArticle(int64_t key) const;
        NODISCARD Container GetContainer() const;

        template <typename Function>
        NODISCARD ConstArticleBaseSharedPtr GetFirstArticle(Function function) const;

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