/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef JSON_CONFIGURE_PARTS_DETAIL_H
#define JSON_CONFIGURE_PARTS_DETAIL_H

#include "Parts.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Function>
JsonConfigure::PartsContainer::ConstDataSharedPtr JsonConfigure::PartsContainer::GetFirstData(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto iter = std::ranges::find_if(data, function);

    if (iter != data.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("parts��data�ֶ�δ�ҵ�����������������Ϣ��"s))
}

template <typename Function>
JsonConfigure::PartsContainer::DataContainer JsonConfigure::PartsContainer::GetData(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    DataContainer result{};

    for (const auto& element : data)
    {
        if (function(element))
        {
            result.emplace_back(element);
        }
    }

    return result;
}

template <typename Function>
JsonConfigure::Parts::Data::ConstScenesSharedPtr JsonConfigure::Parts::Data::GetFirstScenes(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto iter = std::ranges::find_if(scenes, function);

    if (iter != scenes.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("parts��scenes�ֶ�δ�ҵ�����������������Ϣ��"s))
}

template <typename Function>
JsonConfigure::Parts::Data::ScenesContainer JsonConfigure::Parts::Data::GetScenes(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    ScenesContainer result{};

    for (const auto& element : scenes)
    {
        if (function(element))
        {
            result.emplace_back(element);
        }
    }

    return result;
}

#endif  // JSON_CONFIGURE_PARTS_DETAIL_H
