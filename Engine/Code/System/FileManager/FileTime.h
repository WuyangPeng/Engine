//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 12:59)

#ifndef SYSTEM_FILE_MANAGE_FILE_TIME_H
#define SYSTEM_FILE_MANAGE_FILE_TIME_H

#include "System/SystemDll.h"

#include "Fwd/FileFlagsFwd.h"
#include "Using/FileUsing.h"
#include "System/Threading/Using/ThreadPoolUsing.h"

namespace System
{
    // 文件时间的获取和设置

    [[nodiscard]] ComparesFileTimeReturn SYSTEM_DEFAULT_DECLARE FileTimeCompare(const FileTime* lhsFileTime, const FileTime* rhsFileTime) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE FileTimeConvertLocalFileTime(const FileTime* fileTime, FileTimePtr localFileTime) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemFileTime(WindowHandle file, FileTimePtr creationTime, FileTimePtr lastAccessTime, FileTimePtr lastWriteTime) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE LocalFileTimeConvertFileTime(const FileTime* localFileTime, FileTimePtr fileTime) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemFileTime(WindowHandle file, const FileTime* creationTime, const FileTime* lastAccessTime, const FileTime* lastWriteTime) noexcept;
}

#endif  // SYSTEM_FILE_MANAGE_FILE_TIME_H