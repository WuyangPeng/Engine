/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef C_S_V_CONFIGURE_EQUIP_CONTAINER_DETAIL_H
#define C_S_V_CONFIGURE_EQUIP_CONTAINER_DETAIL_H

#include "EquipContainer.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Function>
CSVConfigure::EquipContainer::ConstEquipBaseSharedPtr CSVConfigure::EquipContainer::GetFirstEquip(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto iter = std::ranges::find_if(equip, function);

    if (iter != equip.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("equip��δ�ҵ�����������������Ϣ��"s))
}

template <typename Function>
CSVConfigure::EquipContainer::Container CSVConfigure::EquipContainer::GetEquip(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    Container result{};

    for (const auto& value : equip)
    {
        if (function(value))
        {
            result.emplace_back(value);
        }
    }

    return result;
}

#endif  // C_S_V_CONFIGURE_EQUIP_CONTAINER_DETAIL_H
