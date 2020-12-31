//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 1:00)

#ifndef SYSTEM_MEMORY_TOOLS_LOCAL_TOOLS_H
#define SYSTEM_MEMORY_TOOLS_LOCAL_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/MemoryToolsFlagsFwd.h"
#include "System/CharacterString/Using/CodePageUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
    // Local函数具有更大的开销并且提供比其他存储器管理函数更少的特征。

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE LocalMemoryFree(WindowHLocal& memory) noexcept;
    [[nodiscard]] WindowHLocal SYSTEM_DEFAULT_DECLARE LocalMemoryAlloc(LocalMemory flags, WindowSize bytes) noexcept;
    [[nodiscard]] WindowVoidPtr SYSTEM_DEFAULT_DECLARE LocalMemoryLock(WindowHLocal& memory) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE LocalMemoryUnlock(WindowHLocal& memory) noexcept;
    [[nodiscard]] WindowHLocal SYSTEM_DEFAULT_DECLARE GetLocalMemoryHandle(WindowConstVoidPtr memory) noexcept;
    [[nodiscard]] WindowSize SYSTEM_DEFAULT_DECLARE GetLocalMemorySize(WindowHLocal& memory) noexcept;

    // 返回值的低位字节包含对象的锁定计数。要从返回值检索锁定计数，请使用&运算符和LockCount掩码。
    // 用Fixed分配的内存对象的锁定计数总是为零。返回值的高位字节指示存储器对象的分配值。它可以为零或Discardable。
    [[nodiscard]] WindowUInt SYSTEM_DEFAULT_DECLARE GetLocalMemoryFlags(WindowHLocal& memory) noexcept;
}

#endif  // SYSTEM_MEMORY_TOOLS_LOCAL_TOOLS_H
