///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/03/31 16:36)

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
