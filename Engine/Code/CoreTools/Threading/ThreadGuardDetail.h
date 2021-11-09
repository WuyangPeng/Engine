///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.3 (2021/09/01 18:01)

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
