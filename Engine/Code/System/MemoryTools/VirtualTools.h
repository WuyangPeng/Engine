///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/29 17:01)

#ifndef SYSTEM_MEMORY_TOOLS_VIRTUAL_TOOLS_H
#define SYSTEM_MEMORY_TOOLS_VIRTUAL_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/MemoryToolsFlagsFwd.h"
#include "Using/VirtualToolsUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

// 虚拟内存工具。
namespace System
{
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