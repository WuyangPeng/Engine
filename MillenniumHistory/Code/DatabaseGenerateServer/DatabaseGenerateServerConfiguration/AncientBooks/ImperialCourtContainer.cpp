/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "ImperialCourt.h"
#include "ImperialCourtContainerDetail.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

AncientBooks::ImperialCourtContainer::ImperialCourtContainer(const CoreTools::CSVContent& csvContent)
    : imperialCourt{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void AncientBooks::ImperialCourtContainer::Parsing(const CoreTools::CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    const auto csvHead = csvContent.GetCSVHead();

    for (auto i = 0; i < size; ++i)
    {
        CoreTools::CSVRow csvRow{ csvHead, csvContent.GetContent(i) };

        imperialCourt.emplace_back(std::make_shared<ImperialCourt>(csvRow));
    }

    std::ranges::sort(imperialCourt, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });

    const auto iter = std::ranges::unique(imperialCourt, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() == (*rhs).GetKey();
    });

    if (iter.begin() != iter.end())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, User,  SYSTEM_TEXT("imperialCourt表存在重复主键。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

        imperialCourt.erase(iter.begin(), iter.end());
    }
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, ImperialCourtContainer)

AncientBooks::ImperialCourtContainer::ConstImperialCourtBaseSharedPtr AncientBooks::ImperialCourtContainer::GetFirstImperialCourt() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return imperialCourt.at(0);
}

AncientBooks::ImperialCourtContainer::ConstImperialCourtBaseSharedPtr AncientBooks::ImperialCourtContainer::GetImperialCourt(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    };

    const auto iter = std::ranges::lower_bound(imperialCourt, std::make_shared<ImperialCourtBase>(key), function);

    if (iter != imperialCourt.cend() && (*iter)->GetKey() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("imperialCourt表未找到key = "s) + System::ToString(key) + SYSTEM_TEXT("的配置信息。"s))
    }
}

AncientBooks::ImperialCourtContainer::Container AncientBooks::ImperialCourtContainer::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return imperialCourt;
}

