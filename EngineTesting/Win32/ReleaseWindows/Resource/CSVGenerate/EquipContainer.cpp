/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "Equip.h"
#include "EquipContainerDetail.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

CSVConfigure::EquipContainer::EquipContainer(const CoreTools::CSVContent& csvContent)
    : equip{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void CSVConfigure::EquipContainer::Parsing(const CoreTools::CSVContent& csvContent)
{
    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("equip表开始载入……"));

    const auto size = csvContent.GetCount();
    const auto csvHead = csvContent.GetCSVHead();

    for (auto i = 0; i < size; ++i)
    {
        CoreTools::CSVRow csvRow{ csvHead, csvContent.GetContent(i) };

        equip.emplace_back(std::make_shared<Equip>(csvRow));
    }

    std::ranges::sort(equip, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });

    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("equip表结束载入……"));
}

CLASS_INVARIANT_STUB_DEFINE(CSVConfigure, EquipContainer)

CSVConfigure::EquipContainer::ConstEquipBaseSharedPtr CSVConfigure::EquipContainer::GetFirstEquip(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    };

    const auto range = equal_range(equip.begin(), equip.end(), std::make_shared<EquipBase>(key), function);

    if (range.first != equip.cend())
    {
        return *range.first;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("equip表未找到key = "s) + System::ToString(key) + SYSTEM_TEXT("的配置信息。"s))
    }
}

CSVConfigure::EquipContainer::Container CSVConfigure::EquipContainer::GetEquip(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    };

    const auto range = equal_range(equip.begin(), equip.end(), std::make_shared<EquipBase>(key), function);

    return Container{ range.first, range.second };
}

CSVConfigure::EquipContainer::Container CSVConfigure::EquipContainer::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return equip;
}

