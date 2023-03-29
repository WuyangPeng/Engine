///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/23 15:29)

#ifndef CORE_TOOLS_FILE_MANAGER_WRITE_FILE_HANDLE_H
#define CORE_TOOLS_FILE_MANAGER_WRITE_FILE_HANDLE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/FileManager/File.h"
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
