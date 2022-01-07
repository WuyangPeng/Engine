///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/13 14:42)

#ifndef SYSTEM_MEMORY_TOOLS_MEMORY_TOOLS_FLAGS_FWD_H
#define SYSTEM_MEMORY_TOOLS_MEMORY_TOOLS_FLAGS_FWD_H

#include "System/Helper/ConfigMacro.h"

namespace System
{
    // HeapTools
    enum class HeapCreate;
    enum class ProcessHeap;

    // LocalMemory
    enum class LocalMemory;

    // MemoryHelper
    enum class WorkingSetSizesQuotaLimits;
    enum class FileCache;
    enum class WriteWatch;

    // ViewOfFile
    enum class FileMapDesiredAccess;
    enum class FileMapProtection : uint32_t;

    // VirtualTools
    enum class MemoryAllocation : uint32_t;
    enum class MemoryProtect;
}

#endif  // SYSTEM_MEMORY_TOOLS_MEMORY_TOOLS_FLAGS_FWD_H