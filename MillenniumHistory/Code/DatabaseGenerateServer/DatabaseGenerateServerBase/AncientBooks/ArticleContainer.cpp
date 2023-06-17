/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#include "Article.h"
#include "ArticleContainerDetail.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

AncientBooks::ArticleContainer::ArticleContainer(const CoreTools::CSVContent& csvContent)
    : article{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void AncientBooks::ArticleContainer::Parsing(const CoreTools::CSVContent& csvContent)
{
    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("article��ʼ���롭��"));

    const auto size = csvContent.GetCount();
    const auto csvHead = csvContent.GetCSVHead();

    for (auto i = 0; i < size; ++i)
    {
        CoreTools::CSVRow csvRow{ csvHead, csvContent.GetContent(i) };

        article.emplace_back(std::make_shared<Article>(csvRow));
    }

    std::ranges::sort(article, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });

    const auto iter = std::ranges::unique(article, [](const auto& lhs, const auto& rhs) noexcept {
        if((*lhs).GetKey() == (*rhs).GetKey())
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, User, SYSTEM_TEXT("article������ظ�������key = "), (*lhs).GetKey(), SYSTEM_TEXT("��\n"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

            return true;
        }
        else
        {
            return false;
        }
    });

    if (iter.begin() != iter.end())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, User,  SYSTEM_TEXT("article������ظ�������"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

        article.erase(iter.begin(), iter.end());
    }

    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("article��������롭��"));
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, ArticleContainer)

AncientBooks::ArticleContainer::ConstArticleBaseSharedPtr AncientBooks::ArticleContainer::GetFirstArticle() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return article.at(0);
}

AncientBooks::ArticleContainer::ConstArticleBaseSharedPtr AncientBooks::ArticleContainer::GetArticle(int64_t key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    };

    const auto iter = std::ranges::lower_bound(article, std::make_shared<ArticleBase>(key), function);

    if (iter != article.cend() && (*iter)->GetKey() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("article��δ�ҵ�key = "s) + System::ToString(key) + SYSTEM_TEXT("��������Ϣ��"s))
    }
}

AncientBooks::ArticleContainer::Container AncientBooks::ArticleContainer::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return article;
}

