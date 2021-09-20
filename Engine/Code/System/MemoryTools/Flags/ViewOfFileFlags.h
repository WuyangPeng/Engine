///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.2 (2021/04/19 11:41)

#ifndef SYSTEM_MEMORY_TOOLS_VIEW_OF_FILE_FLAGS_H
#define SYSTEM_MEMORY_TOOLS_VIEW_OF_FILE_FLAGS_H

#include "System/Helper/EnumMacro.h"
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
        Default = 0x000000,
        Commit = SEC_COMMIT,

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
        File = 0x800000,
        Image = 0x1000000,
        ProtectedImage = 0x2000000,
        Reserve = 0x4000000,
        Commit = 0x8000000,
        Nocache = 0x10000000,
        WriteCombine = 0x40000000,
        LargePages = 0x80000000,

        ImageNoExecute = Image | Nocache,
    };

#endif  // SYSTEM_PLATFORM_WIN32

    ENUM_ORABLE_OPERATOR_DEFINE(FileMapDesiredAccess);
}

#endif  // SYSTEM_MEMORY_TOOLS_VIEW_OF_FILE_FLAGS_H
