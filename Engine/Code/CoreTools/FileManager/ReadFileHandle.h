/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 21:44)

#ifndef CORE_TOOLS_FILE_MANAGER_READ_FILE_HANDLE_H
#define CORE_TOOLS_FILE_MANAGER_READ_FILE_HANDLE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

#include <string>

CORE_TOOLS_NON_COPY_EXPORT_IMPL(ReadFileHandleImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE ReadFileHandle final
    {
    public:
        NON_COPY_TYPE_DECLARE(ReadFileHandle);

        using String = System::String;

    public:
        explicit ReadFileHandle(const String& fileName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetFileByteSize() const;

        void Read(size_t itemSize, void* data);
        void Read(size_t itemSize, size_t itemsNumber, void* data);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_READ_FILE_HANDLE_H
