///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.4 (2022/11/19 15:01)

#ifndef SYSTEM_MEMORY_TOOLS_MEMORY_HELPER_H
#define SYSTEM_MEMORY_TOOLS_MEMORY_HELPER_H

#include "System/SystemDll.h"

#include "Fwd/MemoryToolsFlagsFwd.h"
#include "Using/MemoryHelperUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    // �ڴ湤�ߺ�����

    void SYSTEM_DEFAULT_DECLARE MemorySet(void* bytes, int value, int byteSize) noexcept;
    void SYSTEM_DEFAULT_DECLARE MemoryCopy(void* dst, const void* src, uint32_t count) noexcept;
    MAYBE_NULLPTR SYSTEM_DEFAULT_DECLARE void* MallocMemory(size_t size) noexcept;
    void SYSTEM_DEFAULT_DECLARE FreeMemory(void* memory) noexcept;

    template <typename T>
    void FillMemoryToZero(T& value) noexcept;

    template <typename T>
    NODISCARD T GetWindowsStructDefaultSize() noexcept;
}

#endif  // SYSTEM_MEMORY_TOOLS_MEMORY_HELPER_H