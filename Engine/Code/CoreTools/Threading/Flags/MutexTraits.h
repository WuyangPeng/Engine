/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 18:02)

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
