///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/19 15:01)

#ifndef SYSTEM_MEMORY_TOOLS_LOCAL_TOOLS_H
#define SYSTEM_MEMORY_TOOLS_LOCAL_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/MemoryToolsFlagsFwd.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    // Local函数具有更大的开销并且提供比其他存储器管理函数更少的特征。

    NODISCARD bool SYSTEM_DEFAULT_DECLARE LocalMemoryFree(WindowsHLocal& memory) noexcept;
    NODISCARD WindowsHLocal SYSTEM_DEFAULT_DECLARE LocalMemoryAlloc(LocalMemory flags, WindowsSize bytes) noexcept;
    NODISCARD WindowsSize SYSTEM_DEFAULT_DECLARE GetLocalMemorySize(WindowsHLocal& memory) noexcept;
}

#endif  // SYSTEM_MEMORY_TOOLS_LOCAL_TOOLS_H
