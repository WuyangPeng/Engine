/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

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

    THROW_EXCEPTION(SYSTEM_TEXT("identity表未找到满足条件的配置信息。"s))
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
