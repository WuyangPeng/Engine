/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "Identity.h"
#include "IdentityContainerDetail.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

AncientBooks::IdentityContainer::IdentityContainer(const CoreTools::CSVContent& csvContent)
    : identity{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void AncientBooks::IdentityContainer::Parsing(const CoreTools::CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    for (auto i = 0; i < size; ++i)
    {
        CoreTools::CSVRow csvRow{ csvContent.GetCSVHead(), csvContent.GetContent(i) };

        identity.emplace_back(std::make_shared<Identity>(csvRow));
    }

    std::ranges::sort(identity, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });

    const auto iter = std::ranges::unique(identity, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() == (*rhs).GetKey();
    });

    if (iter.begin() != iter.end())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, User,  SYSTEM_TEXT("identity表存在重复主键。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

        identity.erase(iter.begin(), iter.end());
    }
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, IdentityContainer)

AncientBooks::IdentityContainer::ConstIdentityBaseSharedPtr AncientBooks::IdentityContainer::GetFirstIdentity() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return identity.at(0);
}

AncientBooks::IdentityContainer::ConstIdentityBaseSharedPtr AncientBooks::IdentityContainer::GetIdentity(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    };

    const auto iter = std::ranges::lower_bound(identity, std::make_shared<IdentityBase>(key), function);

    if (iter != identity.cend() && (*iter)->GetKey() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("identity表未找到key = "s) + System::ToString(key) + SYSTEM_TEXT("的配置信息。"s))
    }
}

AncientBooks::IdentityContainer::Container AncientBooks::IdentityContainer::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return identity;
}

