///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.2 (2021/08/26 19:11)

#ifndef CORE_TOOLS_BASE_UNIQUEID_MANAGER_DETAIL_H
#define CORE_TOOLS_BASE_UNIQUEID_MANAGER_DETAIL_H

#include "UniqueIDManager.h"
#include "System/Helper/EnumCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"

template <typename E>
void CoreTools::UniqueIDManager::Create(E count)
{
    static_assert(std::is_enum_v<E>, "E must be an enum.");

    // 由于锁定义没有导出，这里不使用全局锁，Create函数中会使用全局锁。

    return Create(System::EnumCastUnderlying<int>(count));
}

template <typename E>
uint64_t CoreTools::UniqueIDManager::NextUniqueID(E index)
{
    static_assert(std::is_enum_v<E>, "E must be an enum.");

    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_9;

    return NextUniqueID(System::EnumCastUnderlying<int>(index));
}

#endif  // CORE_TOOLS_BASE_UNIQUEID_MANAGER_DETAIL_H
