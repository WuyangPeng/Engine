//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/23 0:59)

#ifndef SYSTEM_MEMORY_TOOLS_GLOBAL_TOOLS_H
#define SYSTEM_MEMORY_TOOLS_GLOBAL_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/MemoryToolsFlagsFwd.h"
#include "System/DynamicLink/Using/LoadResourceToolsUsing.h"

namespace System
{
    // ȫ�ֶѷ��亯��

    [[nodiscard]] DynamicLinkGlobal SYSTEM_DEFAULT_DECLARE GlobalAllocBytes(GlobalMemory flags, WindowSize bytes) noexcept;
    [[nodiscard]] DynamicLinkGlobal SYSTEM_DEFAULT_DECLARE GlobalReAllocBytes(DynamicLinkGlobal mem, WindowSize bytes, GlobalMemory flags) noexcept;
    [[nodiscard]] WindowSize SYSTEM_DEFAULT_DECLARE GetGlobalSize(DynamicLinkGlobal mem) noexcept;
    [[nodiscard]] GlobalMemory SYSTEM_DEFAULT_DECLARE GetGlobalFlags(DynamicLinkGlobal mem) noexcept;

    [[nodiscard]] WindowVoidPtr SYSTEM_DEFAULT_DECLARE GetGlobalLock(DynamicLinkGlobal mem) noexcept;
    [[nodiscard]] DynamicLinkGlobal SYSTEM_DEFAULT_DECLARE GetGlobalHandle(WindowVoidPtr mem) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetGlobalUnlock(DynamicLinkGlobal mem) noexcept;
    [[nodiscard]] DynamicLinkGlobal SYSTEM_DEFAULT_DECLARE GetGlobalFree(DynamicLinkGlobal mem) noexcept;
}

#endif  // SYSTEM_MEMORY_TOOLS_GLOBAL_TOOLS_H