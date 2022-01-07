///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/18 1:20)

#ifndef CORE_TOOLS_THREADING_MUTEX_TRAITS_H
#define CORE_TOOLS_THREADING_MUTEX_TRAITS_H

#include "MutexFlags.h"
#include "CoreTools/Threading/Mutex.h"

#include <mutex>

namespace CoreTools
{
    template <MutexCreate mutexCreate>
    struct MutexTraits
    {
        using MutexType = Mutex;
    };

    template <>
    struct MutexTraits<MutexCreate::UseOriginalStdRecursive>
    {
        using MutexType = std::recursive_mutex;
    };

    template <>
    struct MutexTraits<MutexCreate::UseOriginalStd>
    {
        using MutexType = std::mutex;
    };
}

#endif  // CORE_TOOLS_THREADING_MUTEX_TRAITS_H
