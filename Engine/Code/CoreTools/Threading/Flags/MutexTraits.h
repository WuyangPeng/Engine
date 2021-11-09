///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.3 (2021/08/31 22:59)

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
