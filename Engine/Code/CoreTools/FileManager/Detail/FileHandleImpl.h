///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/22 11:36)

#ifndef CORE_TOOLS_FILE_MANAGER_FILE_HANDLE_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_FILE_HANDLE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/FileManager/Fwd/FileFlagsFwd.h"
#include "System/FileManager/Using/FileUsing.h"
#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE FileHandleImpl
    {
    public:
        using ClassType = FileHandleImpl;

        using String = System::String;
        using FileHandle = System::WindowsHandle;
        using FileHandleShareMode = System::FileHandleShareMode;
        using FileHandleDesiredAccess = System::FileHandleDesiredAccess;
        using FileHandleCreationDisposition = System::FileHandleCreationDisposition;

    public:
        FileHandleImpl(const System::String& fileName, FileHandleDesiredAccess access, FileHandleShareMode shareMode, FileHandleCreationDisposition creation);
        virtual ~FileHandleImpl() noexcept;

        FileHandleImpl(const FileHandleImpl& rhs) = delete;
        FileHandleImpl operator=(const FileHandleImpl& rhs) = delete;
        FileHandleImpl(FileHandleImpl&& rhs) noexcept = delete;
        FileHandleImpl operator=(FileHandleImpl&& rhs) noexcept = delete;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD uint64_t GetFileLength() const;

        virtual void ReadFromFile(size_t itemSize, size_t itemsNumber, void* data);
        virtual void WriteToFile(size_t itemSize, size_t itemsNumber, const void* data);
        virtual void AppendToFile(size_t itemSize, size_t itemsNumber, const void* data);

    private:
        String fileName;
        FileHandle file;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_FILE_HANDLE_IMPL_H