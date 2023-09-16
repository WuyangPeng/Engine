///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/29 17:00)

#ifndef SYSTEM_MEMORY_TOOLS_LOCAL_TOOLS_H
#define SYSTEM_MEMORY_TOOLS_LOCAL_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/MemoryToolsFlagsFwd.h"
#include "System/Windows/Using/WindowsUsing.h"

// Local�������и���Ŀ��������ṩ�������洢�����������ٵ�������
namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE LocalMemoryFree(WindowsHLocal& memory) noexcept;
    NODISCARD WindowsHLocal SYSTEM_DEFAULT_DECLARE LocalMemoryAlloc(LocalMemory flags, WindowsSize bytes) noexcept;
    NODISCARD WindowsSize SYSTEM_DEFAULT_DECLARE GetLocalMemorySize(WindowsHLocal& memory) noexcept;
}

#endif  // SYSTEM_MEMORY_TOOLS_LOCAL_TOOLS_H
