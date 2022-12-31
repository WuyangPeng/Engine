///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.5 (2022/12/11 20:38)

#ifndef SYSTEM_FILE_MANAGER_FILE_TOOLS_H
#define SYSTEM_FILE_MANAGER_FILE_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/FileFlagsFwd.h"
#include "Using/FileToolsUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"

#include <string>

// 文件管理辅助工具
namespace System
{
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