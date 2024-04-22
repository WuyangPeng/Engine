/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/30 22:55)

#ifndef CORE_TOOLS_FILE_MANAGER_FWD_H
#define CORE_TOOLS_FILE_MANAGER_FWD_H

#include "CoreTools/Helper/SharedPtrMacro.h"

#include <memory>

namespace CoreTools
{
    enum class BufferIO;

    class Endian;

    template <typename T, int Size>
    class ByteSwapper;

    template <typename From, typename To>
    requires(sizeof(From) == sizeof(To))
    class TypeAlias;

    class FileBuffer;
    class CFileManagerHelper;
    class CReadFileManager;
    class CWriteFileManager;
    class IFileStreamManager;
    class OFileStreamManager;
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