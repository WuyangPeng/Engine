/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "SexagenaryCycle.h"
#include "SexagenaryCycleContainerDetail.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

AncientBooks::SexagenaryCycleContainer::SexagenaryCycleContainer(const CoreTools::CSVContent& csvContent)
    : sexagenaryCycle{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void AncientBooks::SexagenaryCycleContainer::Parsing(const CoreTools::CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    for (auto i = 0; i < size; ++i)
    {
        CoreTools::CSVRow csvRow{ csvContent.GetCSVHead(), csvContent.GetContent(i) };

        sexagenaryCycle.emplace_back(std::make_shared<SexagenaryCycle>(csvRow));
    }

    std::ranges::sort(sexagenaryCycle, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });

    const auto iter = std::ranges::unique(sexagenaryCycle, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() == (*rhs).GetKey();
    });

    if (iter.begin() != iter.end())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, User,  SYSTEM_TEXT("sexagenaryCycle表存在重复主键。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

        sexagenaryCycle.erase(iter.begin(), iter.end());
    }
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, SexagenaryCycleContainer)

AncientBooks::SexagenaryCycleContainer::ConstSexagenaryCycleBaseSharedPtr AncientBooks::SexagenaryCycleContainer::GetFirstSexagenaryCycle() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return sexagenaryCycle.at(0);
}

AncientBooks::SexagenaryCycleContainer::ConstSexagenaryCycleBaseSharedPtr AncientBooks::SexagenaryCycleContainer::GetSexagenaryCycle(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    };

    const auto iter = std::ranges::lower_bound(sexagenaryCycle, std::make_shared<SexagenaryCycleBase>(key), function);

    if (iter != sexagenaryCycle.cend() && (*iter)->GetKey() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("sexagenaryCycle表未找到key = "s) + System::ToString(key) + SYSTEM_TEXT("的配置信息。"s))
    }
}

AncientBooks::SexagenaryCycleContainer::Container AncientBooks::SexagenaryCycleContainer::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return sexagenaryCycle;
}

