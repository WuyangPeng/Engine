/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/04 15:57)

#ifndef SYSTEM_MEMORY_TOOLS_LOCAL_TOOLS_H
#define SYSTEM_MEMORY_TOOLS_LOCAL_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/MemoryToolsFlagsFwd.h"
#include "System/Windows/Using/WindowsUsing.h"

/// Local函数具有更大的开销并且提供比其他存储器管理函数更少的特征。
namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE LocalMemoryFree(WindowsHLocal& memory) noexcept;
    NODISCARD WindowsHLocal SYSTEM_DEFAULT_DECLARE LocalMemoryAlloc(LocalMemory flags, WindowsSize bytes) noexcept;
    NODISCARD WindowsSize SYSTEM_DEFAULT_DECLARE GetLocalMemorySize(WindowsHLocal& memory) noexcept;
}

#endif  // SYSTEM_MEMORY_TOOLS_LOCAL_TOOLS_H
