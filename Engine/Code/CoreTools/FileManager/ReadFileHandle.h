///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/08 23:42)

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
