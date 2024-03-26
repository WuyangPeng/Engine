/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/04 15:58)

#ifndef SYSTEM_MEMORY_TOOLS_MEMORY_HELPER_H
#define SYSTEM_MEMORY_TOOLS_MEMORY_HELPER_H

#include "System/SystemDll.h"

#include "Fwd/MemoryToolsFlagsFwd.h"
#include "System/Windows/Using/WindowsUsing.h"

/// �ڴ湤�ߺ�����
namespace System
{
    void SYSTEM_DEFAULT_DECLARE MemorySet(void* bytes, int value, int byteSize) noexcept;
    void SYSTEM_DEFAULT_DECLARE MemoryCopy(void* dst, const void* src, size_t count) noexcept;
    MAYBE_NULLPTR SYSTEM_DEFAULT_DECLARE void* MallocMemory(size_t size) noexcept;
    void SYSTEM_DEFAULT_DECLARE FreeMemory(void* memory) noexcept;

    template <typename T>
    requires(std::is_trivial_v<T> && std::is_standard_layout_v<T>)
    void FillMemoryToZero(T& value) noexcept;

    template <typename T>
    requires(std::is_nothrow_default_constructible_v<T> && std::is_nothrow_copy_constructible_v<T> && std::is_nothrow_move_constructible_v<T>)
    NODISCARD constexpr T GetWindowsStructDefaultSize() noexcept
    {
        T result{};

        result.cbSize = sizeof(T);

        return result;
    }
}

#endif  // SYSTEM_MEMORY_TOOLS_MEMORY_HELPER_H