//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/23 1:00)

#ifndef SYSTEM_MEMORY_TOOLS_LOCAL_TOOLS_H
#define SYSTEM_MEMORY_TOOLS_LOCAL_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/MemoryToolsFlagsFwd.h"
#include "System/CharacterString/Using/CodePageUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
    // Local�������и���Ŀ��������ṩ�������洢�����������ٵ�������

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE LocalMemoryFree(WindowHLocal& memory) noexcept;
    [[nodiscard]] WindowHLocal SYSTEM_DEFAULT_DECLARE LocalMemoryAlloc(LocalMemory flags, WindowSize bytes) noexcept;
    [[nodiscard]] WindowVoidPtr SYSTEM_DEFAULT_DECLARE LocalMemoryLock(WindowHLocal& memory) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE LocalMemoryUnlock(WindowHLocal& memory) noexcept;
    [[nodiscard]] WindowHLocal SYSTEM_DEFAULT_DECLARE GetLocalMemoryHandle(WindowConstVoidPtr memory) noexcept;
    [[nodiscard]] WindowSize SYSTEM_DEFAULT_DECLARE GetLocalMemorySize(WindowHLocal& memory) noexcept;

    // ����ֵ�ĵ�λ�ֽڰ������������������Ҫ�ӷ���ֵ����������������ʹ��&�������LockCount���롣
    // ��Fixed������ڴ�����������������Ϊ�㡣����ֵ�ĸ�λ�ֽ�ָʾ�洢������ķ���ֵ��������Ϊ���Discardable��
    [[nodiscard]] WindowUInt SYSTEM_DEFAULT_DECLARE GetLocalMemoryFlags(WindowHLocal& memory) noexcept;
}

#endif  // SYSTEM_MEMORY_TOOLS_LOCAL_TOOLS_H
