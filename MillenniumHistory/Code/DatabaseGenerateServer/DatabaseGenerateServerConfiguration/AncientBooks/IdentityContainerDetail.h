/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_IDENTITY_CONTAINER_DETAIL_H
#define ANCIENT_BOOKS_IDENTITY_CONTAINER_DETAIL_H

#include "IdentityContainer.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Function>
AncientBooks::IdentityContainer::ConstIdentityBaseSharedPtr AncientBooks::IdentityContainer::GetFirstIdentity(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto iter = std::ranges::find_if(identity, function);

    if (iter != identity.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("identity��δ�ҵ�����������������Ϣ��"s))
}

template <typename Function>
AncientBooks::IdentityContainer::Container AncientBooks::IdentityContainer::GetIdentity(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    Container result{};

    for (const auto& value : identity)
    {
        if (function(value))
        {
            result.emplace_back(value);
        }
    }

    return result;
}

#endif  // ANCIENT_BOOKS_IDENTITY_CONTAINER_DETAIL_H
