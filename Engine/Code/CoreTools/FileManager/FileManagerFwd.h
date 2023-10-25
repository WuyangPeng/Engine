///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/22 13:34)

#ifndef CORE_TOOLS_FILE_MANAGER_FWD_H
#define CORE_TOOLS_FILE_MANAGER_FWD_H

#include "CoreTools/Helper/SharedPtrMacro.h"

#include <memory>

namespace CoreTools
{
    enum class BufferIO;

    class Endian;

    template <typename T, size_t Size>
    class ByteSwapper;

    template <typename From, typename To>
    class TypeAliaser;

    class FileBuffer;
    class CFileManagerHelper;
    class CReadFileManager;
    class CWriteFileManager;
    class IFStreamManager;
    class OFStreamManager;
    class DeleteFileTools;
    class CopyFileTools;
    class FileHandleHelper;
    class ReadFileHandle;
    class WriteFileHandle;
    class ReadAndWriteFileHandle;
    class FileManagerHelper;
    class ReadFileManager;
    class WriteFileManager;
    class ReadBufferIO;
    class WriteBufferIO;
    class EnvironmentVariable;
    class Environment;
    class FileEventInterface;
    class FileAsynchronous;
    class FileAsynchronousParameter;
    class Directory;
    class GenerateRandomName;

    CORE_TOOLS_SHARED_PTR_DECLARE(FileBuffer);
}

#endif  // CORE_TOOLS_FILE_MANAGER_FWD_H