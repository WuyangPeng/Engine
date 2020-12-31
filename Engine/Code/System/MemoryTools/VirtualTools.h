//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/23 1:00)

#ifndef SYSTEM_MEMORY_TOOLS_VIRTUAL_TOOLS_H
#define SYSTEM_MEMORY_TOOLS_VIRTUAL_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/MemoryToolsFlagsFwd.h"
#include "Using/HeapToolsUsing.h"
#include "Using/VirtualToolsUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
    // �����ڴ湤�ߡ�

    [[nodiscard]] WindowVoidPtr SYSTEM_DEFAULT_DECLARE AllocateVirtual(WindowVoidPtr address, WindowSize size, MemoryAllocation allocationType, MemoryProtect protect) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE FreeVirtual(WindowVoidPtr address) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetVirtualProtect(WindowVoidPtr address, WindowSize size, MemoryProtect newProtect, MemoryProtect* oldProtect) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetVirtualQuery(WindowVoidPtr address, MemoryBasicInformationPtr buffer) noexcept;

    [[nodiscard]] WindowVoidPtr SYSTEM_DEFAULT_DECLARE AllocateVirtual(WindowHandle process, WindowVoidPtr address, WindowSize size,
                                                                       MemoryAllocation allocationType, MemoryProtect protect) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE FreeVirtual(WindowHandle process, WindowVoidPtr address) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetVirtualProtect(WindowHandle process, WindowVoidPtr address, WindowSize size,
                                                                MemoryProtect newProtect, MemoryProtect* oldProtect) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetVirtualQuery(WindowHandle process, WindowVoidPtr address, MemoryBasicInformationPtr buffer) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE LockVirtual(WindowVoidPtr address, WindowSize size) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE UnlockVirtual(WindowVoidPtr address, WindowSize size) noexcept;

    [[nodiscard]] WindowVoidPtr SYSTEM_DEFAULT_DECLARE GetVirtualAllocNuma(WindowHandle process, WindowVoidPtr address, WindowSize size,
                                                                           MemoryAllocation allocationType, MemoryProtect protect, WindowDWord preferred) noexcept;
}

#endif  // SYSTEM_MEMORY_TOOLS_VIRTUAL_TOOLS_H