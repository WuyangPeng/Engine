/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 17:59)

#ifndef CORE_TOOLS_THREADING_THREAD_GUARD_DETAIL_H
#define CORE_TOOLS_THREADING_THREAD_GUARD_DETAIL_H

#include "ThreadGuard.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <thread>

template <typename Function, typename... Args>
CoreTools::ThreadGuard::ThreadGuard(Function&& function, Args&&... args)
    : ThreadGuard{ std::thread{ std::forward<Function>(function), std::forward<Args>(args)... } }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#endif  // CORE_TOOLS_THREADING_THREAD_GUARD_DETAIL_H
