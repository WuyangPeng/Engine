/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 17:30)

#ifndef SYSTEM_MEMORY_TOOLS_VIEW_OF_FILE_FLAGS_H
#define SYSTEM_MEMORY_TOOLS_VIEW_OF_FILE_FLAGS_H

#include "System/Helper/EnumOperator.h"
#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class FileMapDesiredAccess
    {
        Write = FILE_MAP_WRITE,
        Read = FILE_MAP_READ,
        AllAccess = FILE_MAP_ALL_ACCESS,
        Execute = FILE_MAP_EXECUTE,
        Copy = FILE_MAP_COPY,
    };

    enum class FileMapProtection : uint32_t
    {
        Default = 0x00000000,
        Commit = SEC_COMMIT,

        PartitionOwnerHandle = SEC_PARTITION_OWNER_HANDLE,
        Pages64K = SEC_64K_PAGES,
        File = SEC_FILE,
        Image = SEC_IMAGE,
        ProtectedImage = SEC_PROTECTED_IMAGE,
        Reserve = SEC_RESERVE,
        Nocache = SEC_NOCACHE,
        WriteCombine = SEC_WRITECOMBINE,
        LargePages = SEC_LARGE_PAGES,

        ImageNoExecute = SEC_IMAGE_NO_EXECUTE,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class FileMapDesiredAccess
    {
        Write = 0x0002,
        Read = 0x0004,
        AllAccess = 0x000F0000L | 0x0001 | 0x0002 | 0x0004 | 0x0008 | 0x0010,
        Execute = 0x0020,
        Copy = 0x00000001,
    };

    enum class FileMapProtection : uint32_t
    {
        Default = 0x000000,
        Commit = 0x8000000,

        PartitionOwnerHandle = 0x00040000,
        Pages64K = 0x00080000,
        File = 0x800000,
        Image = 0x1000000,
        ProtectedImage = 0x2000000,
        Reserve = 0x4000000,
        Nocache = 0x10000000,
        WriteCombine = 0x40000000,
        LargePages = 0x80000000,

        ImageNoExecute = Image | Nocache,
    };

#endif  // SYSTEM_PLATFORM_WIN32

}

#endif  // SYSTEM_MEMORY_TOOLS_VIEW_OF_FILE_FLAGS_H
