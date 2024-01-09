/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 17:31)

#ifndef SYSTEM_MEMORY_TOOLS_VIRTUAL_FLAGS_H
#define SYSTEM_MEMORY_TOOLS_VIRTUAL_FLAGS_H

#include "System/Helper/EnumOperator.h"
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
        Mem4MbPages = MEM_4MB_PAGES,

        ReplacePlaceholder = MEM_REPLACE_PLACEHOLDER,
        ReservePlaceholder = MEM_RESERVE_PLACEHOLDER,
        DifferentImageBaseOk = MEM_DIFFERENT_IMAGE_BASE_OK,
        Pages64K = MEM_64K_PAGES,
        UnMapWithTransientBoost = MEM_UNMAP_WITH_TRANSIENT_BOOST,
        CoalescePlaceholders = MEM_COALESCE_PLACEHOLDERS,
        PreservePlaceholder = MEM_PRESERVE_PLACEHOLDER,
    };

    enum class MemoryProtect : uint32_t
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

        GraphicsNoAccess = PAGE_GRAPHICS_NOACCESS,
        GraphicsReadonly = PAGE_GRAPHICS_READONLY,
        GraphicsReadwrite = PAGE_GRAPHICS_READWRITE,
        GraphicsExecute = PAGE_GRAPHICS_EXECUTE,
        GraphicsExecuteRead = PAGE_GRAPHICS_EXECUTE_READ,
        GraphicsExecuteReadwrite = PAGE_GRAPHICS_EXECUTE_READWRITE,
        GraphicsCoherent = PAGE_GRAPHICS_COHERENT,
        GraphicsNocache = PAGE_GRAPHICS_NOCACHE,
        EnclaveThreadControl = PAGE_ENCLAVE_THREAD_CONTROL,
        RevertToFileMap = PAGE_REVERT_TO_FILE_MAP,

        TargetsNoUpdate = PAGE_TARGETS_NO_UPDATE,
        TargetsInvalid = PAGE_TARGETS_INVALID,

        EnclaveUnvalidated = PAGE_ENCLAVE_UNVALIDATED,
        EnclaveMask = PAGE_ENCLAVE_MASK,
        EnclaveDeCommit = PAGE_ENCLAVE_DECOMMIT,
        EnclaveSsFirst = PAGE_ENCLAVE_SS_FIRST,
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
        Mem4MbPages = 0x80000000,

        ReplacePlaceholder = 0x00004000,
        ReservePlaceholder = 0x00040000,
        DifferentImageBaseOk = 0x00800000,
        Pages64K = LargePages | Physical,
        UnMapWithTransientBoost = 0x00000001,
        CoalescePlaceholders = 0x00000001,
        PreservePlaceholder = 0x00000002,
    };

    enum class MemoryProtect : uint32_t
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

        GraphicsNoAccess = 0x0800,
        GraphicsReadonly = 0x1000,
        GraphicsReadwrite = 0x2000,
        GraphicsExecute = 0x4000,
        GraphicsExecuteRead = 0x8000,
        GraphicsExecuteReadwrite = 0x10000,
        GraphicsCoherent = 0x20000,
        GraphicsNocache = 0x40000,
        EnclaveThreadControl = 0x80000000,
        RevertToFileMap = 0x80000000,

        TargetsNoUpdate = 0x40000000,
        TargetsInvalid = 0x40000000,

        EnclaveUnvalidated = 0x20000000,
        EnclaveMask = 0x10000000,
        EnclaveDeCommit = (EnclaveMask | 0),
        EnclaveSsFirst = (EnclaveMask | 1),
        EnclaveSsRest = (EnclaveMask | 2),
    };

#endif  // SYSTEM_PLATFORM_WIN32

}

#endif  // SYSTEM_MEMORY_TOOLS_VIRTUAL_FLAGS_H
