/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "Article.h"
#include "ArticleContainerDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

AncientBooks::ArticleContainer::ArticleContainer(const CSVContent& csvContent)
    : article{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void AncientBooks::ArticleContainer::Parsing(const CSVContent& csvContent)
{
    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("article表开始载入……"));

    Load(csvContent);
    Unique();

    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("article表结束载入……"));
}

void AncientBooks::ArticleContainer::Load(const CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    const auto csvHead = csvContent.GetCSVHead();

    for (auto index = 0; index < size; ++index)
    {
        CoreTools::CSVRow csvRow{ csvHead, csvContent.GetContent(index) };

        article.emplace_back(std::make_shared<Article>(csvRow));
    }

    std::ranges::sort(article, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });
}

void AncientBooks::ArticleContainer::Unique()
{
    const auto iter = std::ranges::unique(article, [](const auto& lhs, const auto& rhs) noexcept {
        if((*lhs).GetKey() == (*rhs).GetKey())
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, User, SYSTEM_TEXT("article表存在重复主键，key = "), (*lhs).GetKey(), SYSTEM_TEXT("。\n"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

            return true;
        }
        else
        {
            return false;
        }
    });

    if (iter.begin() != iter.end())
    {
        article.erase(iter.begin(), iter.end());
    }

    article.shrink_to_fit();
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, ArticleContainer)

AncientBooks::ArticleContainer::ConstArticleSharedPtr AncientBooks::ArticleContainer::GetFirstArticle() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return article.at(0);
}

AncientBooks::ArticleContainer::ConstArticleSharedPtr AncientBooks::ArticleContainer::GetArticle(int64_t key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    };

    if (const auto iter = std::ranges::lower_bound(article, std::make_shared<ArticleBase>(key), function);
        iter != article.cend() && (*iter)->GetKey() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("article表未找到key = "s) + System::ToString(key) + SYSTEM_TEXT("的配置信息。"s))
    }
}

AncientBooks::ArticleContainer::Container AncientBooks::ArticleContainer::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return article;
}

int AncientBooks::ArticleContainer::GetContainerSize() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(article.size());
}

