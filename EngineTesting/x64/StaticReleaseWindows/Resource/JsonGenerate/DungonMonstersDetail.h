/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++17
/// �Զ�����

#ifndef JSON_CONFIGURE_DUNGON_MONSTERS_DETAIL_H
#define JSON_CONFIGURE_DUNGON_MONSTERS_DETAIL_H

#include "DungonMonsters.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Function>
JsonConfigure::DungonMonstersContainer::ConstDatasSharedPtr JsonConfigure::DungonMonstersContainer::GetFirstDatas(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto iter = std::find_if(datas.cbegin(), datas.cend(), function);

    if (iter != datas.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("dungonMonsters��datas�ֶ�δ�ҵ�����������������Ϣ��"s));
}

template <typename Function>
JsonConfigure::DungonMonstersContainer::DatasContainer JsonConfigure::DungonMonstersContainer::GetDatas(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    DatasContainer result{};

    for (const auto& value : datas)
    {
        if (function(value))
        {
            result.emplace_back(value);
        }
    }

    return result;
}

template <typename Function>
JsonConfigure::DungonMonsters::Datas::ConstElementsSharedPtr JsonConfigure::DungonMonsters::Datas::GetFirstElements(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto iter = std::find_if(elements.cbegin(), elements.cend(), function);

    if (iter != elements.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("dungonMonsters��elements�ֶ�δ�ҵ�����������������Ϣ��"s));
}

template <typename Function>
JsonConfigure::DungonMonsters::Datas::ElementsContainer JsonConfigure::DungonMonsters::Datas::GetElements(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    ElementsContainer result{};

    for (const auto& value : elements)
    {
        if (function(value))
        {
            result.emplace_back(value);
        }
    }

    return result;
}

#endif  // JSON_CONFIGURE_DUNGON_MONSTERS_DETAIL_H
