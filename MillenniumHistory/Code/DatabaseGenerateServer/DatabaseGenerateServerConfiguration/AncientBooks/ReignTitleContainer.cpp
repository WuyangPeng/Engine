/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "ReignTitle.h"
#include "ReignTitleContainerDetail.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

AncientBooks::ReignTitleContainer::ReignTitleContainer(const CoreTools::CSVContent& csvContent)
    : reignTitle{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void AncientBooks::ReignTitleContainer::Parsing(const CoreTools::CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    for (auto i = 0; i < size; ++i)
    {
        CoreTools::CSVRow csvRow{ csvContent.GetCSVHead(), csvContent.GetContent(i) };

        reignTitle.emplace_back(std::make_shared<ReignTitle>(csvRow));
    }

    std::ranges::sort(reignTitle, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });

    const auto iter = std::ranges::unique(reignTitle, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() == (*rhs).GetKey();
    });

    if (iter.begin() != iter.end())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, User,  SYSTEM_TEXT("reignTitle表存在重复主键。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

        reignTitle.erase(iter.begin(), iter.end());
    }
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, ReignTitleContainer)

AncientBooks::ReignTitleContainer::ConstReignTitleBaseSharedPtr AncientBooks::ReignTitleContainer::GetFirstReignTitle() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return reignTitle.at(0);
}

AncientBooks::ReignTitleContainer::ConstReignTitleBaseSharedPtr AncientBooks::ReignTitleContainer::GetReignTitle(int64_t key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    };

    const auto iter = std::ranges::lower_bound(reignTitle, std::make_shared<ReignTitleBase>(key), function);

    if (iter != reignTitle.cend() && (*iter)->GetKey() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("reignTitle表未找到key = "s) + System::ToString(key) + SYSTEM_TEXT("的配置信息。"s))
    }
}

AncientBooks::ReignTitleContainer::Container AncientBooks::ReignTitleContainer::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return reignTitle;
}

