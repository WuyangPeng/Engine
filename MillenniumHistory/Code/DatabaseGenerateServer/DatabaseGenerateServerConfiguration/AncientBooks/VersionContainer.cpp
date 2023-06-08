/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "Version.h"
#include "VersionContainerDetail.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

AncientBooks::VersionContainer::VersionContainer(const CoreTools::CSVContent& csvContent)
    : version{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void AncientBooks::VersionContainer::Parsing(const CoreTools::CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    for (auto i = 0; i < size; ++i)
    {
        CoreTools::CSVRow csvRow{ csvContent.GetCSVHead(), csvContent.GetContent(i) };

        version.emplace_back(std::make_shared<Version>(csvRow));
    }

    std::ranges::sort(version, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });

    const auto iter = std::ranges::unique(version, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() == (*rhs).GetKey();
    });

    if (iter.begin() != iter.end())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, User,  SYSTEM_TEXT("version表存在重复主键。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

        version.erase(iter.begin(), iter.end());
    }
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, VersionContainer)

AncientBooks::VersionContainer::ConstVersionBaseSharedPtr AncientBooks::VersionContainer::GetFirstVersion() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return version.at(0);
}

AncientBooks::VersionContainer::ConstVersionBaseSharedPtr AncientBooks::VersionContainer::GetVersion(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    };

    const auto iter = std::ranges::lower_bound(version, std::make_shared<VersionBase>(key), function);

    if (iter != version.cend() && (*iter)->GetKey() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("version表未找到key = "s) + System::ToString(key) + SYSTEM_TEXT("的配置信息。"s))
    }
}

AncientBooks::VersionContainer::Container AncientBooks::VersionContainer::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return version;
}

