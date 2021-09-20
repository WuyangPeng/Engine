//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/13 20:30)

#ifndef CORE_TOOLS_FILE_MANAGER_WRITE_FILE_HANDLE_H
#define CORE_TOOLS_FILE_MANAGER_WRITE_FILE_HANDLE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
 
#include <string>

CORE_TOOLS_NON_COPY_EXPORT_IMPL(WriteFileHandleImpl);


namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE WriteFileHandle final  
    {
    public:
        NON_COPY_TYPE_DECLARE(WriteFileHandle);
        using String = System::String;
        using FileHandleCreationDisposition = System::FileHandleCreationDisposition;

    public:
        explicit WriteFileHandle(const String& fileName, FileHandleCreationDisposition creation = FileHandleCreationDisposition::CreateAlways);
        ~WriteFileHandle() noexcept = default;
        WriteFileHandle(const WriteFileHandle& rhs) noexcept = delete;
        WriteFileHandle& operator=(const WriteFileHandle& rhs) noexcept = delete;
        WriteFileHandle(WriteFileHandle&& rhs) noexcept = delete;
        WriteFileHandle& operator=(WriteFileHandle&& rhs) noexcept = delete;
        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] int GetFileByteSize() const;

        void Write(size_t itemSize, const void* data);
        void Write(size_t itemSize, size_t itemsNumber, const void* data);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_WRITE_FILE_HANDLE_H
