///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/28 17:15)

#ifndef SYSTEM_FILE_MANAGER_FILE_TOOLS_H
#define SYSTEM_FILE_MANAGER_FILE_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/FileFlagsFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"

// 文件管理辅助工具
namespace System
{
    void SYSTEM_DEFAULT_DECLARE DeleteFileDirectory(const String& pathName);
    void SYSTEM_DEFAULT_DECLARE CreateFileDirectory(const String& pathName) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE CreateFileDirectory(const String& pathName, WindowSecurityAttributesPtr securityAttributes) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE RemoveSystemDirectory(const TChar* pathName) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetDiskFreeSpaceWithRoot(const TChar* rootPathName,
                                                                   WindowsDWordPtr sectorsPerCluster,
                                                                   WindowsDWordPtr bytesPerSector,
                                                                   WindowsDWordPtr numberOfFreeClusters,
                                                                   WindowsDWordPtr totalNumberOfClusters) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetDiskFreeSpaceWithRoot(const TChar* directoryName,
                                                                   WindowsULargeIntegerPtr freeBytesAvailableToCaller,
                                                                   WindowsULargeIntegerPtr totalNumberOfBytes,
                                                                   WindowsULargeIntegerPtr totalNumberOfFreeBytes) noexcept;
}

#endif  // SYSTEM_FILE_MANAGER_FILE_TOOLS_H