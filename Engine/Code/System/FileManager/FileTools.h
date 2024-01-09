/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 19:04)

#ifndef SYSTEM_FILE_MANAGER_FILE_TOOLS_H
#define SYSTEM_FILE_MANAGER_FILE_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/FileFlagsFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"

// �ļ�����������
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