///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/10 10:34)

#ifndef CORE_TOOLS_MEMORY_TOOLS_ATOMIC_MIN_MAX_H
#define CORE_TOOLS_MEMORY_TOOLS_ATOMIC_MIN_MAX_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <typename T>
    T AtomicMin(std::atomic<T>& atomic, const T& value) noexcept;

    template <typename T>
    T AtomicMax(std::atomic<T>& atomic, const T& value) noexcept;
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_ATOMIC_MIN_MAX_H
