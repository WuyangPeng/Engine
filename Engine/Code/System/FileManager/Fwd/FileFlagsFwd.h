/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/05 09:26)

#ifndef SYSTEM_FILE_MANAGER_FILE_FLAGS_FWD_H
#define SYSTEM_FILE_MANAGER_FILE_FLAGS_FWD_H

#include "System/Helper/ConfigMacro.h"

namespace System
{
    /// CFile
    enum class FileSeek;
    enum class FileSetVBuffer;

    /// File
    enum class FileHandleDesiredAccess : uint32_t;
    enum class FileHandleShareMode;
    enum class FileHandleCreationDisposition;
    enum class FileHandleAttribute;
    enum class FileHandleOther : uint32_t;
    enum class FileHandleSecurity;
    enum class FilePointer;

    /// FileTime
    enum class ComparesFileTimeReturn;
}

#endif  // SYSTEM_FILE_MANAGER_FILE_FLAGS_FWD_H