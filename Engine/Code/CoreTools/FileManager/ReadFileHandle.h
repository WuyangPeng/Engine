//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/13 20:29)

#ifndef CORE_TOOLS_FILE_MANAGER_READ_FILE_HANDLE_H
#define CORE_TOOLS_FILE_MANAGER_READ_FILE_HANDLE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"
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
        ~ReadFileHandle() noexcept = default;
        ReadFileHandle(const ReadFileHandle& rhs) noexcept = delete;
        ReadFileHandle& operator=(const ReadFileHandle& rhs) noexcept = delete;
        ReadFileHandle(ReadFileHandle&& rhs) noexcept = delete;
        ReadFileHandle& operator=(ReadFileHandle&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] int GetFileByteSize() const;

        void Read(size_t itemSize, void* data);
        void Read(size_t itemSize, size_t itemsNumber, void* data);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_READ_FILE_HANDLE_H
