//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/13 20:21)

#ifndef CORE_TOOLS_FILE_MANAGER_WRITE_FILE_HANDLE_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_WRITE_FILE_HANDLE_IMPL_H

#include "FileHandleImpl.h"
#include "WriteFileManagerInterface.h"
#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE WriteFileHandleImpl final : public FileHandleImpl, public WriteFileManagerInterface
    {
    public:
        using ClassType = WriteFileHandleImpl;
        using ParentType = FileHandleImpl;
        using InterfaceType = WriteFileManagerInterface;
          using String = System::String;
    public:
        explicit WriteFileHandleImpl(const String& fileName, FileHandleCreationDisposition creation = FileHandleCreationDisposition::CreateAlways);

        CLASS_INVARIANT_FINAL_DECLARE;

        [[nodiscard]] int GetFileByteSize() const final;

        void Write(size_t itemSize, const void* data) final;
        void Write(size_t itemSize, size_t itemsNumber, const void* data) final;

        void ReadFromFile(size_t itemSize, size_t itemsNumber, void* data) final;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_WRITE_FILE_HANDLE_IMPL_H