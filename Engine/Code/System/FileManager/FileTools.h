///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.4 (2022/11/18 21:28)

#ifndef SYSTEM_FILE_MANAGE_FILE_TOOLS_H
#define SYSTEM_FILE_MANAGE_FILE_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/FileFlagsFwd.h"
#include "Using/FileToolsUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"

#include <string>

namespace System
{
    // �ļ�����������

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

#endif  // SYSTEM_FILE_MANAGE_FILE_TOOLS_H