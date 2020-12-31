//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/21 10:18)

#ifndef CORE_TOOLS_FILE_MANAGER_FWD_H
#define CORE_TOOLS_FILE_MANAGER_FWD_H

#include "CoreTools/Helper/SharedPtrMacro.h"

#include <memory>

namespace CoreTools
{
    enum class BufferIO;

    class Endian;
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

    CORE_TOOLS_SHARED_PTR_DECLARE(FileBuffer);

    template <typename T, size_t Size>
    class ByteSwapper;

    template <typename From, typename To>
    class TypeAliaser;
}

#endif  // CORE_TOOLS_FILE_MANAGER_FWD_H