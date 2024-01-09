/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 19:01)

#ifndef SYSTEM_FILE_MANAGER_FIND_FILE_USING_H
#define SYSTEM_FILE_MANAGER_FIND_FILE_USING_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using FileWin32FindData = WIN32_FIND_DATA;
    using FileWin32FindDataPtr = LPWIN32_FIND_DATA;
    using FileInfoLevels = FINDEX_INFO_LEVELS;
    using FileSearchOps = FINDEX_SEARCH_OPS;

#else  // !SYSTEM_PLATFORM_WIN32

    struct FileWin32FindData
    {
        uint32_t dwFileAttributes;
        FileTime ftCreationTime;
        FileTime ftLastAccessTime;
        FileTime ftLastWriteTime;
        uint32_t nFileSizeHigh;
        uint32_t nFileSizeLow;
        uint32_t dwReserved0;
        uint32_t dwReserved1;
        TChar cFileName[260];
        TChar cAlternateFileName[14];
    };
    using FileWin32FindDataPtr = FileWin32FindData*;

    enum FileInfoLevels
    {
        FindExInfoStandard,
        FindExInfoBasic,
        FindExInfoMaxInfoLevel,
    };

    enum FileSearchOps
    {
        FindExSearchNameMatch,
        FindExSearchLimitToDirectories,
        FindExSearchLimitToDevices,
        FindExSearchMaxSearchOp
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_FILE_MANAGER_FIND_FILE_USING_H