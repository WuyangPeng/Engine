/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++17
/// �Զ�����

#include "Equip.h"
#include "EquipContainerDetail.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

using std::make_shared;

CSVConfigure::EquipContainer::EquipContainer(const CoreTools::CSVContent& csvContent)
    : equip{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void CSVConfigure::EquipContainer::Parsing(const CoreTools::CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    for (auto i = 0; i < size; ++i)
    {
        CoreTools::CSVRow csvRow{ csvContent.GetCSVHead(), csvContent.GetContent(i) };

        equip.emplace_back(make_shared<Equip>(csvRow));
    }

    std::sort(equip.begin(), equip.end(), [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });
}

CLASS_INVARIANT_STUB_DEFINE(CSVConfigure, EquipContainer)

CSVConfigure::EquipContainer::ConstEquipBaseSharedPtr CSVConfigure::EquipContainer::GetFirstEquip(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    };

    const auto range = equal_range(equip.begin(), equip.end(), make_shared<EquipBase>(key), function);

    if (range.first != equip.cend())
    {
        return *range.first;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("equip��δ�ҵ�key = "s) + System::ToString(key) + SYSTEM_TEXT("��������Ϣ��"s));
    }
}

CSVConfigure::EquipContainer::Container CSVConfigure::EquipContainer::GetEquip(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    };

    const auto range = equal_range(equip.begin(), equip.end(), make_shared<EquipBase>(key), function);

    return Container{ range.first, range.second };
}

CSVConfigure::EquipContainer::Container CSVConfigure::EquipContainer::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return equip;
}

