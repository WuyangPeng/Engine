/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 17:59)

#ifndef CORE_TOOLS_THREADING_THREAD_GROUP_DETAIL_H
#define CORE_TOOLS_THREADING_THREAD_GROUP_DETAIL_H

#include "ThreadGroup.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <thread>

template <typename Function, typename... Args>
void CoreTools::ThreadGroup::AddThread(Function&& function, Args&&... args)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    AddThread(std::thread{ std::forward<Function>(function), std::forward<Args>(args)... });
}

#endif  // CORE_TOOLS_THREADING_THREAD_GROUP_DETAIL_H
