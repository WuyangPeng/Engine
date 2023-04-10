///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/03/31 16:36)

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
