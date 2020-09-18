//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.2 (2020/09/17 16:15)

#ifndef CORE_TOOLS_FILE_MANAGER_FWD_H
#define CORE_TOOLS_FILE_MANAGER_FWD_H

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
}

#endif  // CORE_TOOLS_FILE_MANAGER_FWD_H