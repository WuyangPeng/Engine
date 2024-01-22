/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/10 21:45)

#ifndef CORE_TOOLS_FILE_MANAGER_WRITE_FILE_HANDLE_H
#define CORE_TOOLS_FILE_MANAGER_WRITE_FILE_HANDLE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/FileManager/Flags/FileFlags.h"
#include "System/Helper/UnicodeUsing.h"
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

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetFileByteSize() const;

        void Write(size_t itemSize, const void* data);
        void Write(size_t itemSize, size_t itemsNumber, const void* data);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_WRITE_FILE_HANDLE_H
