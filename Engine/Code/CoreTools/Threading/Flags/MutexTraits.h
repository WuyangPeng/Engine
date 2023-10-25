///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/20 14:27)

#ifndef CORE_TOOLS_THREADING_MUTEX_TRAITS_H
#define CORE_TOOLS_THREADING_MUTEX_TRAITS_H

#include "MutexFlags.h"
#include "CoreTools/Threading/Mutex.h"

#include <mutex>

namespace CoreTools
{
    template <MutexCreate MutexCreate>
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
