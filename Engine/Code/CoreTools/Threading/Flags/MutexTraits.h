/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/30 18:02)

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
