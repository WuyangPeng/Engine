/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/28 16:47)

#ifndef CORE_TOOLS_BASE_UNIQUE_ID_MANAGER_DETAIL_H
#define CORE_TOOLS_BASE_UNIQUE_ID_MANAGER_DETAIL_H

#include "UniqueIdManager.h"
#include "System/Helper/EnumCast.h"

template <typename E>
void CoreTools::UniqueIdManager::Create(E count) requires(std::is_enum_v<E>)
{
    /// 由于锁定义没有导出，这里不使用全局锁，Create函数中会使用全局锁。

    return Create(System::EnumCastUnderlying<int>(count));
}

template <typename E>
int64_t CoreTools::UniqueIdManager::NextUniqueId(E index) requires(std::is_enum_v<E>)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_9;

    return NextUniqueId(System::EnumCastUnderlying<int>(index));
}

template <typename E>
void CoreTools::UniqueIdManager::SetUniqueId(E index, int64_t latestIndex) requires(std::is_enum_v<E>)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_9;

    return SetUniqueId(System::EnumCastUnderlying(index), latestIndex);
}

#endif  // CORE_TOOLS_BASE_UNIQUE_ID_MANAGER_DETAIL_H
