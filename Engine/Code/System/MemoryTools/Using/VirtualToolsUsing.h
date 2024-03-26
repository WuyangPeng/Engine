/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/04 15:57)

#ifndef SYSTEM_MEMORY_TOOLS_VIRTUAL_TOOLS_USING_H
#define SYSTEM_MEMORY_TOOLS_VIRTUAL_TOOLS_USING_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using MemoryBasicInformation = MEMORY_BASIC_INFORMATION;
    using MemoryBasicInformationPtr = PMEMORY_BASIC_INFORMATION;

#else  // !SYSTEM_PLATFORM_WIN32

    struct MemoryBasicInformation
    {
        void* BaseAddress;
        void* AllocationBase;
        uint32_t AllocationProtect;
        size_t RegionSize;
        uint32_t State;
        uint32_t Protect;
        uint32_t Type;
    };
    using MemoryBasicInformationPtr = MemoryBasicInformation*;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_MEMORY_TOOLS_VIRTUAL_TOOLS_USING_H