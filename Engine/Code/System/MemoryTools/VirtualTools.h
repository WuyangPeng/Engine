///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 14:44)

#ifndef SYSTEM_MEMORY_TOOLS_VIRTUAL_TOOLS_H
#define SYSTEM_MEMORY_TOOLS_VIRTUAL_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/MemoryToolsFlagsFwd.h"
#include "Using/HeapToolsUsing.h"
#include "Using/VirtualToolsUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    // 虚拟内存工具。

    MAYBE_NULLPTR WindowsVoidPtr SYSTEM_DEFAULT_DECLARE AllocateVirtual(WindowsVoidPtr address,
                                                                        WindowsSize size,
                                                                        MemoryAllocation allocationType,
                                                                        MemoryProtect protect) noexcept;
    MAYBE_NULLPTR WindowsVoidPtr SYSTEM_DEFAULT_DECLARE AllocateVirtual(WindowsHandle process,
                                                                        WindowsVoidPtr address,
                                                                        WindowsSize size,
                                                                        MemoryAllocation allocationType,
                                                                        MemoryProtect protect) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE FreeVirtual(WindowsVoidPtr address) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE FreeVirtual(WindowsHandle process, WindowsVoidPtr address) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetVirtualProtect(WindowsVoidPtr address,
                                                            WindowsSize size,
                                                            MemoryProtect newProtect,
                                                            MemoryProtect* oldProtect) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetVirtualProtect(WindowsHandle process,
                                                            WindowsVoidPtr address,
                                                            WindowsSize size,
                                                            MemoryProtect newProtect,
                                                            MemoryProtect* oldProtect) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetVirtualQuery(WindowsVoidPtr address, MemoryBasicInformationPtr buffer) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetVirtualQuery(WindowsHandle process, WindowsVoidPtr address, MemoryBasicInformationPtr buffer) noexcept;
}

#endif  // SYSTEM_MEMORY_TOOLS_VIRTUAL_TOOLS_H