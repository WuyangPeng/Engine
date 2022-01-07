///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 18:48)

#ifndef SYSTEM_FILE_MANAGE_FILE_TIME_H
#define SYSTEM_FILE_MANAGE_FILE_TIME_H

#include "System/SystemDll.h"

#include "Fwd/FileFlagsFwd.h"
#include "Using/FileUsing.h"

namespace System
{
    // 文件时间的获取和设置

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

#endif  // SYSTEM_FILE_MANAGE_FILE_TIME_H