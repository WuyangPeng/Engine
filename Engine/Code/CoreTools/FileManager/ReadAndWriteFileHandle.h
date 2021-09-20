//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/13 20:29)

#ifndef CORE_TOOLS_FILE_MANAGER_READ_AND_WRITE_FILE_HANDLE_H
#define CORE_TOOLS_FILE_MANAGER_READ_AND_WRITE_FILE_HANDLE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"
 #include "CoreTools/Helper/Export/NonCopyMacro.h"
#include <string>

CORE_TOOLS_NON_COPY_EXPORT_IMPL(ReadAndWriteFileHandleImpl);


namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE ReadAndWriteFileHandle final  
    {
    public:
        NON_COPY_TYPE_DECLARE(ReadAndWriteFileHandle);
        using String = System::String;
       
    public:
        explicit ReadAndWriteFileHandle(const String& fileName);
        ~ReadAndWriteFileHandle() noexcept = default;
        ReadAndWriteFileHandle(const ReadAndWriteFileHandle& rhs) noexcept = delete;
        ReadAndWriteFileHandle& operator=(const ReadAndWriteFileHandle& rhs) noexcept = delete;
        ReadAndWriteFileHandle(ReadAndWriteFileHandle&& rhs) noexcept = delete;
        ReadAndWriteFileHandle& operator=(ReadAndWriteFileHandle&& rhs) noexcept = delete;
        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] uint64_t GetFileLength() const;

        void Read(size_t itemSize, void* data);
        void Read(size_t itemSize, size_t itemsNumber, void* data);
        void Write(size_t itemSize, const void* data);
        void Write(size_t itemSize, size_t itemsNumber, const void* data);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_READ_AND_WRITE_FILE_HANDLE_H