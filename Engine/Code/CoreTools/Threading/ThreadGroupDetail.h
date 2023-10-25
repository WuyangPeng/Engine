///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/20 14:25)

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
