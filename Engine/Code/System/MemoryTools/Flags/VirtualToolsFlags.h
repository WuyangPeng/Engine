///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/19 14:52)

#ifndef SYSTEM_MEMORY_TOOLS_VIRTUAL_FLAGS_H
#define SYSTEM_MEMORY_TOOLS_VIRTUAL_FLAGS_H

#include "System/Helper/EnumMacro.h"
#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class MemoryAllocation : uint32_t
    {
        Zero = 0,
        Commit = MEM_COMMIT,
        Reserve = MEM_RESERVE,
        ReserveAndCommit = Reserve | Commit,
        Reset = MEM_RESET,
        ResetUndo = MEM_RESET_UNDO,

        Physical = MEM_PHYSICAL | Reserve,
        LargePages = MEM_LARGE_PAGES | ReserveAndCommit,
        TopDown = MEM_TOP_DOWN,
        WriteWatch = MEM_WRITE_WATCH | Reserve,

        DeCommit = MEM_DECOMMIT,
        Release = MEM_RELEASE,

        Free = MEM_FREE,
        Private = MEM_PRIVATE,
        Mapped = MEM_MAPPED,
        Rotate = MEM_ROTATE,
        Mem4mbPages = MEM_4MB_PAGES,
    };

    enum class MemoryProtect
    {
        Zero = 0,
        NoAccess = PAGE_NOACCESS,

        ReadOnly = PAGE_READONLY,
        ReadWrite = PAGE_READWRITE,
        WriteCopy = PAGE_WRITECOPY,  // AllocateVirtual不支持此标志

        Execute = PAGE_EXECUTE,
        ExecuteRead = PAGE_EXECUTE_READ,
        ExecuteReadWrite = PAGE_EXECUTE_READWRITE,
        ExecuteWriteCopy = PAGE_EXECUTE_WRITECOPY,  // AllocateVirtual不支持此标志

        Guard = PAGE_GUARD,
        Nocache = PAGE_NOCACHE,
        WriteCombine = PAGE_WRITECOMBINE,

        TargetsNoUpdate = PAGE_TARGETS_NO_UPDATE,
        TargetsInvalid = PAGE_TARGETS_INVALID,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class MemoryAllocation : uint32_t
    {
        Zero = 0,
        Commit = 0x1000,
        Reserve = 0x2000,
        ReserveAndCommit = Reserve | Commit,
        Reset = 0x80000,
        ResetUndo = 0x01000000,

        Physical = 0x400000 | Reserve,
        LargePages = 0x20000000 | ReserveAndCommit,
        TopDown = 0x100000,
        WriteWatch = 0x200000 | Reserve,

        DeCommit = 0x4000,
        Release = 0x8000,

        Free = 0x10000,
        Private = 0x20000,
        Mapped = 0x40000,
        Rotate = 0x800000,
        Mem4mbPages = 0x80000000,
    };

    enum class MemoryProtect
    {
        Zero = 0,
        NoAccess = 0x01,
        ReadOnly = 0x02,
        ReadWrite = 0x04,
        WriteCopy = 0x08,
        Execute = 0x10,
        ExecuteRead = 0x20,
        ExecuteReadWrite = 0x40,
        ExecuteWriteCopy = 0x80,
        Guard = 0x100,
        Nocache = 0x200,
        WriteCombine = 0x400,
        TargetsNoUpdate = 0x40000000,
        TargetsInvalid = 0x40000000,
    };

#endif  // SYSTEM_PLATFORM_WIN32

    ENUM_ORABLE_OPERATOR_DEFINE(MemoryAllocation);
    ENUM_ORABLE_OPERATOR_DEFINE(MemoryProtect);
    ENUM_ANDABLE_OPERATOR_DEFINE(MemoryProtect);
}

#endif  // SYSTEM_MEMORY_TOOLS_VIRTUAL_FLAGS_H
