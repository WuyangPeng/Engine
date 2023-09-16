///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/28 17:15)

#ifndef SYSTEM_FILE_MANAGER_FILE_TIME_H
#define SYSTEM_FILE_MANAGER_FILE_TIME_H

#include "System/SystemDll.h"

#include "Fwd/FileFlagsFwd.h"
#include "Using/FileUsing.h"

// �ļ�ʱ��Ļ�ȡ������
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