/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "Genus.h"
#include "GenusContainerDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

AncientBooks::GenusContainer::GenusContainer(const CSVContent& csvContent)
    : genus{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void AncientBooks::GenusContainer::Parsing(const CSVContent& csvContent)
{
    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("genus表开始载入……"));

    Load(csvContent);
    Unique();

    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("genus表结束载入……"));
}

void AncientBooks::GenusContainer::Load(const CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    const auto csvHead = csvContent.GetCSVHead();

    for (auto index = 0; index < size; ++index)
    {
        CoreTools::CSVRow csvRow{ csvHead, csvContent.GetContent(index) };

        genus.emplace_back(std::make_shared<Genus>(csvRow));
    }

    std::ranges::sort(genus, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });
}

void AncientBooks::GenusContainer::Unique()
{
    const auto iter = std::ranges::unique(genus, [](const auto& lhs, const auto& rhs) noexcept {
        if((*lhs).GetKey() == (*rhs).GetKey())
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, User, SYSTEM_TEXT("genus表存在重复主键，key = "), (*lhs).GetKey(), SYSTEM_TEXT("。\n"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

            return true;
        }
        else
        {
            return false;
        }
    });

    if (iter.begin() != iter.end())
    {
        genus.erase(iter.begin(), iter.end());
    }

    genus.shrink_to_fit();
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, GenusContainer)

AncientBooks::GenusContainer::ConstGenusSharedPtr AncientBooks::GenusContainer::GetFirstGenus() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return genus.at(0);
}

AncientBooks::GenusContainer::ConstGenusSharedPtr AncientBooks::GenusContainer::GetGenus(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    };

    const auto iter = std::ranges::lower_bound(genus, std::make_shared<GenusBase>(key), function);

    if (iter != genus.cend() && (*iter)->GetKey() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("genus表未找到key = "s) + System::ToString(key) + SYSTEM_TEXT("的配置信息。"s))
    }
}

AncientBooks::GenusContainer::Container AncientBooks::GenusContainer::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return genus;
}

int AncientBooks::GenusContainer::GetContainerSize() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(genus.size());
}

