/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++17
/// 自动生成

#include "Chapter.h"
#include "ChapterContainerDetail.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

using std::make_shared;

CSVConfigure::ChapterContainer::ChapterContainer(const CoreTools::CSVContent& csvContent)
    : chapter{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void CSVConfigure::ChapterContainer::Parsing(const CoreTools::CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    for (auto i = 0; i < size; ++i)
    {
        CoreTools::CSVRow csvRow{ csvContent.GetCSVHead(), csvContent.GetContent(i) };

        chapter.emplace_back(make_shared<Chapter>(csvRow));
    }

    std::sort(chapter.begin(), chapter.end(), [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });

    auto iter = unique(chapter.begin(), chapter.end(), [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() == (*rhs).GetKey();
    });

    if (iter != chapter.cend())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, User)
            << SYSTEM_TEXT("chapter表存在重复主键。")
            << LOG_SINGLETON_TRIGGER_ASSERT;

        chapter.erase(iter, chapter.end());
    }
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

    const auto iter = lower_bound(chapter.begin(), chapter.end(), make_shared<ChapterBase>(key), function);

    if (iter != chapter.cend() && (*iter)->GetKey() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("chapter表未找到key = "s) + System::ToString(key) + SYSTEM_TEXT("的配置信息。"s));
    }
}

CSVConfigure::ChapterContainer::Container CSVConfigure::ChapterContainer::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return chapter;
}

