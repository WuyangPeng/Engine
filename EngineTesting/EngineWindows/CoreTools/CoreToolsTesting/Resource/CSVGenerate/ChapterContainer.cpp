/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "Chapter.h"
#include "ChapterContainerDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

CSVConfigure::ChapterContainer::ChapterContainer(const CSVContent& csvContent)
    : chapter{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void CSVConfigure::ChapterContainer::Parsing(const CSVContent& csvContent)
{
    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("chapter表开始载入……"));

    Load(csvContent);
    Unique();

    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("chapter表结束载入……"));
}

void CSVConfigure::ChapterContainer::Load(const CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    const auto csvHead = csvContent.GetCSVHead();

    for (auto i = 0; i < size; ++i)
    {
        CoreTools::CSVRow csvRow{ csvHead, csvContent.GetContent(i) };

        chapter.emplace_back(std::make_shared<Chapter>(csvRow));
    }

    std::ranges::sort(chapter, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });
}

void CSVConfigure::ChapterContainer::Unique()
{
    const auto iter = std::ranges::unique(chapter, [](const auto& lhs, const auto& rhs) noexcept {
        if((*lhs).GetKey() == (*rhs).GetKey())
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, User, SYSTEM_TEXT("chapter表存在重复主键，key = "), (*lhs).GetKey(), SYSTEM_TEXT("。\n"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

            return true;
        }
        else
        {
            return false;
        }
    });

    if (iter.begin() != iter.end())
    {
        chapter.erase(iter.begin(), iter.end());
    }

    chapter.shrink_to_fit();
}

CLASS_INVARIANT_STUB_DEFINE(CSVConfigure, ChapterContainer)

CSVConfigure::ChapterContainer::ConstChapterBaseSharedPtr CSVConfigure::ChapterContainer::GetFirstChapter() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return chapter.at(0);
}

CSVConfigure::ChapterContainer::ConstChapterBaseSharedPtr CSVConfigure::ChapterContainer::GetChapter(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    };

    const auto iter = std::ranges::lower_bound(chapter, std::make_shared<ChapterBase>(key), function);

    if (iter != chapter.cend() && (*iter)->GetKey() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("chapter表未找到key = "s) + System::ToString(key) + SYSTEM_TEXT("的配置信息。"s))
    }
}

CSVConfigure::ChapterContainer::Container CSVConfigure::ChapterContainer::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return chapter;
}

int CSVConfigure::ChapterContainer::GetContainerSize() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(chapter.size());
}

