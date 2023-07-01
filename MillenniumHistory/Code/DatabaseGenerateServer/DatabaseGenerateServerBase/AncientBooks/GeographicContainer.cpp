/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "Geographic.h"
#include "GeographicContainerDetail.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

AncientBooks::GeographicContainer::GeographicContainer(const CSVContent& csvContent)
    : geographic{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void AncientBooks::GeographicContainer::Parsing(const CSVContent& csvContent)
{
    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("geographic表开始载入……"));

    Load(csvContent);
    Unique();

    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("geographic表结束载入……"));
}

void AncientBooks::GeographicContainer::Load(const CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    const auto csvHead = csvContent.GetCSVHead();

    for (auto i = 0; i < size; ++i)
    {
        CoreTools::CSVRow csvRow{ csvHead, csvContent.GetContent(i) };

        geographic.emplace_back(std::make_shared<Geographic>(csvRow));
    }

    std::ranges::sort(geographic, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });
}

void AncientBooks::GeographicContainer::Unique()
{
    const auto iter = std::ranges::unique(geographic, [](const auto& lhs, const auto& rhs) noexcept {
        if((*lhs).GetKey() == (*rhs).GetKey())
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, User, SYSTEM_TEXT("geographic表存在重复主键，key = "), (*lhs).GetKey(), SYSTEM_TEXT("。\n"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

            return true;
        }
        else
        {
            return false;
        }
    });

    if (iter.begin() != iter.end())
    {
        geographic.erase(iter.begin(), iter.end());
    }

    geographic.shrink_to_fit();
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, GeographicContainer)

AncientBooks::GeographicContainer::ConstGeographicBaseSharedPtr AncientBooks::GeographicContainer::GetFirstGeographic() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return geographic.at(0);
}

AncientBooks::GeographicContainer::ConstGeographicBaseSharedPtr AncientBooks::GeographicContainer::GetGeographic(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    };

    const auto iter = std::ranges::lower_bound(geographic, std::make_shared<GeographicBase>(key), function);

    if (iter != geographic.cend() && (*iter)->GetKey() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("geographic表未找到key = "s) + System::ToString(key) + SYSTEM_TEXT("的配置信息。"s))
    }
}

AncientBooks::GeographicContainer::Container AncientBooks::GeographicContainer::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return geographic;
}

