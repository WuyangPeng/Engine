/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/04 15:57)

#ifndef SYSTEM_MEMORY_TOOLS_MEMORY_TOOLS_FLAGS_FWD_H
#define SYSTEM_MEMORY_TOOLS_MEMORY_TOOLS_FLAGS_FWD_H

#include "System/Helper/ConfigMacro.h"

namespace System
{
    /// HeapTools
    enum class HeapCreate;
    enum class ProcessHeap;

    /// LocalMemory
    enum class LocalMemory;

    /// ViewOfFile
    enum class FileMapDesiredAccess;
    enum class FileMapProtection : uint32_t;

    /// VirtualTools
    enum class MemoryAllocation : uint32_t;
    enum class MemoryProtect : uint32_t;
}

#endif  // SYSTEM_MEMORY_TOOLS_MEMORY_TOOLS_FLAGS_FWD_H