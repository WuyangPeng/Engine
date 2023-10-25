/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_GATHER_CONTAINER_DETAIL_H
#define ANCIENT_BOOKS_GATHER_CONTAINER_DETAIL_H

#include "GatherContainer.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Function>
AncientBooks::GatherContainer::ConstGatherSharedPtr AncientBooks::GatherContainer::GetFirstGather(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto iter = std::ranges::find_if(gather, function);

    if (iter != gather.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("gather��δ�ҵ�����������������Ϣ��"s))
}

template <typename Function>
AncientBooks::GatherContainer::Container AncientBooks::GatherContainer::GetGather(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    Container result{};

    for (const auto& element : gather)
    {
        if (function(element))
        {
            result.emplace_back(element);
        }
    }

    return result;
}

#endif  // ANCIENT_BOOKS_GATHER_CONTAINER_DETAIL_H
