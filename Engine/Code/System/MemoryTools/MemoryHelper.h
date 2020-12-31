//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 1:00)

#ifndef SYSTEM_MEMORY_TOOLS_MEMORY_HELPER_H
#define SYSTEM_MEMORY_TOOLS_MEMORY_HELPER_H

#include "System/SystemDll.h"

#include "Fwd/MemoryToolsFlagsFwd.h"
#include "Using/MemoryHelperUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
    // 内存工具函数。

    void SYSTEM_DEFAULT_DECLARE MemorySet(void* bytes, int value, int byteSize) noexcept;
    void SYSTEM_DEFAULT_DECLARE MemoryCopy(void* dst, const void* src, uint32_t count) noexcept;
    [[nodiscard]] SYSTEM_DEFAULT_DECLARE void* MallocMemory(size_t size) noexcept;
    void SYSTEM_DEFAULT_DECLARE FreeMemory(void* memory) noexcept;

    template <typename T>
    void FillMemoryToZero(T& value) noexcept;

    template <typename T>
    [[nodiscard]] T GetWindowsStructDefaultSize() noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE ReadMemoryOnProcess(WindowHandle process, WindowConstVoidPtr baseAddress, WindowVoidPtr buffer, WindowSize size, WindowSize* numberOfBytesRead) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE WriteMemoryOnProcess(WindowHandle process, WindowVoidPtr baseAddress, WindowConstVoidPtr buffer, WindowSize size, WindowSize* numberOfBytesWritten) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetProcessWorkingSize(WindowHandle process, WindowSizePtr minimumWorkingSetSize, WindowSizePtr maximumWorkingSetSize, WorkingSetSizesQuotaLimits* flags) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetProcessWorkingSize(WindowHandle process, WindowSize minimumWorkingSetSize, WindowSize maximumWorkingSetSize, WorkingSetSizesQuotaLimits flags) noexcept;
    [[nodiscard]] WindowSize SYSTEM_DEFAULT_DECLARE GetMinimumLargePageSize() noexcept;
    [[nodiscard]] WindowHandle SYSTEM_DEFAULT_DECLARE CreateMemoryResourceNotificationUseNotificationType(MemoryResourceNotificationType notificationType) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE QueryMemoryResourceNotificationState(WindowHandle resourceNotificationHandle, bool* resourceState) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE CloseMemoryResourceNotificationHandle(WindowHandle handle) noexcept;
}

#endif  // SYSTEM_MEMORY_TOOLS_MEMORY_HELPER_H