///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/19 14:52)

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