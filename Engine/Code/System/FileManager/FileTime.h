/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 19:04)

#ifndef SYSTEM_FILE_MANAGER_FILE_TIME_H
#define SYSTEM_FILE_MANAGER_FILE_TIME_H

#include "System/SystemDll.h"

#include "Fwd/FileFlagsFwd.h"
#include "Using/FileUsing.h"

// 文件时间的获取和设置
namespace System
{
    NODISCARD ComparesFileTimeReturn SYSTEM_DEFAULT_DECLARE FileTimeCompare(const FileTime* lhsFileTime, const FileTime* rhsFileTime) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE FileTimeConvertLocalFileTime(const FileTime* fileTime, FileTimePtr localFileTime) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE LocalFileTimeConvertFileTime(const FileTime* localFileTime, FileTimePtr fileTime) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemFileTime(WindowsHandle file,
                                                            FileTimePtr creationTime,
                                                            FileTimePtr lastAccessTime,
                                                            FileTimePtr lastWriteTime) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemFileTime(WindowsHandle file,
                                                            const FileTime* creationTime,
                                                            const FileTime* lastAccessTime,
                                                            const FileTime* lastWriteTime) noexcept;
}

#endif  // SYSTEM_FILE_MANAGER_FILE_TIME_H