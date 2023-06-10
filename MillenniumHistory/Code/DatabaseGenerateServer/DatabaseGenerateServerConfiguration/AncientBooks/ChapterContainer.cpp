/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#include "Chapter.h"
#include "ChapterContainerDetail.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

AncientBooks::ChapterContainer::ChapterContainer(const CoreTools::CSVContent& csvContent)
    : chapter{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void AncientBooks::ChapterContainer::Parsing(const CoreTools::CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    for (auto i = 0; i < size; ++i)
    {
        CoreTools::CSVRow csvRow{ csvContent.GetCSVHead(), csvContent.GetContent(i) };

        chapter.emplace_back(std::make_shared<Chapter>(csvRow));
    }

    std::ranges::sort(chapter, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });

    const auto iter = std::ranges::unique(chapter, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() == (*rhs).GetKey();
    });

    if (iter.begin() != iter.end())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, User,  SYSTEM_TEXT("chapter�������ظ�������"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

        chapter.erase(iter.begin(), iter.end());
    }
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, ChapterContainer)

AncientBooks::ChapterContainer::ConstChapterBaseSharedPtr AncientBooks::ChapterContainer::GetFirstChapter() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return chapter.at(0);
}

AncientBooks::ChapterContainer::ConstChapterBaseSharedPtr AncientBooks::ChapterContainer::GetChapter(int key) const
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
        THROW_EXCEPTION(SYSTEM_TEXT("chapter��δ�ҵ�key = "s) + System::ToString(key) + SYSTEM_TEXT("��������Ϣ��"s))
    }
}

AncientBooks::ChapterContainer::Container AncientBooks::ChapterContainer::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return chapter;
}
