/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "Source.h"
#include "SourceContainerDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

AncientBooks::SourceContainer::SourceContainer(const CSVContent& csvContent)
    : source{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void AncientBooks::SourceContainer::Parsing(const CSVContent& csvContent)
{
    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("source表开始载入……"));

    Load(csvContent);
    Unique();

    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("source表结束载入……"));
}

void AncientBooks::SourceContainer::Load(const CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    const auto csvHead = csvContent.GetCSVHead();

    for (auto index = 0; index < size; ++index)
    {
        CoreTools::CSVRow csvRow{ csvHead, csvContent.GetContent(index) };

        source.emplace_back(std::make_shared<Source>(csvRow));
    }

    std::ranges::sort(source, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });
}

void AncientBooks::SourceContainer::Unique()
{
    const auto iter = std::ranges::unique(source, [](const auto& lhs, const auto& rhs) noexcept {
        if((*lhs).GetKey() == (*rhs).GetKey())
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, User, SYSTEM_TEXT("source表存在重复主键，key = "), (*lhs).GetKey(), SYSTEM_TEXT("。\n"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

            return true;
        }
        else
        {
            return false;
        }
    });

    if (iter.begin() != iter.end())
    {
        source.erase(iter.begin(), iter.end());
    }

    source.shrink_to_fit();
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, SourceContainer)

AncientBooks::SourceContainer::ConstSourceSharedPtr AncientBooks::SourceContainer::GetFirstSource() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return source.at(0);
}

AncientBooks::SourceContainer::ConstSourceSharedPtr AncientBooks::SourceContainer::GetSource(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    };

    const auto iter = std::ranges::lower_bound(source, std::make_shared<SourceBase>(key), function);

    if (iter != source.cend() && (*iter)->GetKey() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("source表未找到key = "s) + System::ToString(key) + SYSTEM_TEXT("的配置信息。"s))
    }
}

AncientBooks::SourceContainer::Container AncientBooks::SourceContainer::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return source;
}

int AncientBooks::SourceContainer::GetContainerSize() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(source.size());
}

