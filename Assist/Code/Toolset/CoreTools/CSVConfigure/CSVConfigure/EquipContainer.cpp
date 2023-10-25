/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#include "Equip.h"
#include "EquipContainerDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

CSVConfigure::EquipContainer::EquipContainer(const CSVContent& csvContent)
    : equip{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void CSVConfigure::EquipContainer::Parsing(const CSVContent& csvContent)
{
    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("equip��ʼ���롭��"));

    Load(csvContent);

    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("equip��������롭��"));
}

void CSVConfigure::EquipContainer::Load(const CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    const auto csvHead = csvContent.GetCSVHead();

    for (auto index = 0; index < size; ++index)
    {
        CoreTools::CSVRow csvRow{ csvHead, csvContent.GetContent(index) };

        equip.emplace_back(std::make_shared<Equip>(csvRow));
    }

    std::ranges::sort(equip, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });

    equip.shrink_to_fit();

}



CLASS_INVARIANT_STUB_DEFINE(CSVConfigure, EquipContainer)

CSVConfigure::EquipContainer::ConstEquipSharedPtr CSVConfigure::EquipContainer::GetFirstEquip(int key) const
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
        THROW_EXCEPTION(SYSTEM_TEXT("equip��δ�ҵ�key = "s) + System::ToString(key) + SYSTEM_TEXT("��������Ϣ��"s))
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

int CSVConfigure::EquipContainer::GetContainerSize() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(equip.size());
}

