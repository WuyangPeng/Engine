//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 12:56)

#ifndef SYSTEM_FILE_FILE_FLAGS_FWD_H
#define SYSTEM_FILE_FILE_FLAGS_FWD_H

#include "System/Helper/ConfigMacro.h"

namespace System
{
    // CFile
    enum class FileSeek;
    enum class FileSetvBuf;

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

    // FindFile
    enum class FileNotifyFilter;
    enum class FindFirstFileAdditional;
}

#endif  // SYSTEM_FILE_FILE_FLAGS_FWD_H