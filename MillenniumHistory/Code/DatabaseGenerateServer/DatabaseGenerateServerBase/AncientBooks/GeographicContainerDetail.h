/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_GEOGRAPHIC_CONTAINER_DETAIL_H
#define ANCIENT_BOOKS_GEOGRAPHIC_CONTAINER_DETAIL_H

#include "GeographicContainer.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Function>
AncientBooks::GeographicContainer::ConstGeographicSharedPtr AncientBooks::GeographicContainer::GetFirstGeographic(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto iter = std::ranges::find_if(geographic, function);

    if (iter != geographic.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("geographic��δ�ҵ�����������������Ϣ��"s))
}

template <typename Function>
AncientBooks::GeographicContainer::Container AncientBooks::GeographicContainer::GetGeographic(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    Container result{};

    for (const auto& element : geographic)
    {
        if (function(element))
        {
            result.emplace_back(element);
        }
    }

    return result;
}

#endif  // ANCIENT_BOOKS_GEOGRAPHIC_CONTAINER_DETAIL_H
