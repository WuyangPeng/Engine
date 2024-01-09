/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 19:01)

#ifndef SYSTEM_FILE_MANAGER_FILE_FLAGS_FWD_H
#define SYSTEM_FILE_MANAGER_FILE_FLAGS_FWD_H

#include "System/Helper/ConfigMacro.h"

namespace System
{
    // CFile
    enum class FileSeek;
    enum class FileSetVBuffer;

    // File
    enum class FileHandleDesiredAccess : uint32_t;
    enum class FileHandleShareMode;
    enum class FileHandleCreationDisposition;
    enum class FileHandleAttributes;
    enum class FileHandleOther : uint32_t;
    enum class FileHandleSecurity;
    enum class FilePointer;

    // FileTime
    enum class ComparesFileTimeReturn;

    // FileTools
    enum class DefineDosDeviceControllable;
    enum class Drive;
    enum class FileType;
    enum class GetFinalPathName;
    enum class LockFile;
    enum class FileSystem;
}

#endif  // SYSTEM_FILE_MANAGER_FILE_FLAGS_FWD_H