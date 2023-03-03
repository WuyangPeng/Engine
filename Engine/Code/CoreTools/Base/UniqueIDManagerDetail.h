///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/12 14:23)

#ifndef CORE_TOOLS_BASE_UNIQUEID_MANAGER_DETAIL_H
#define CORE_TOOLS_BASE_UNIQUEID_MANAGER_DETAIL_H

#include "UniqueIdManager.h"
#include "System/Helper/EnumCast.h"

template <typename E>
void CoreTools::UniqueIdManager::Create(E count)
{
    static_assert(std::is_enum_v<E>, "E must be an enum.");

    // 由于锁定义没有导出，这里不使用全局锁，Create函数中会使用全局锁。

    return Create(System::EnumCastUnderlying<int>(count));
}

template <typename E>
uint64_t CoreTools::UniqueIdManager::NextUniqueId(E index)
{
    static_assert(std::is_enum_v<E>, "E must be an enum.");

    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_9;

    return NextUniqueId(System::EnumCastUnderlying<int>(index));
}

template <typename E>
void CoreTools::UniqueIdManager::SetUniqueId(E index, uint64_t latestIndex)
{
    static_assert(std::is_enum_v<E>, "E must be an enum.");

    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_9;

    return SetUniqueId(System::EnumCastUnderlying<int>(index), latestIndex);
}

#endif  // CORE_TOOLS_BASE_UNIQUEID_MANAGER_DETAIL_H
