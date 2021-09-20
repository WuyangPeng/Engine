//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/13 20:25)

#ifndef CORE_TOOLS_FILE_MANAGER_DELETE_FILE_TOOLS_H
#define CORE_TOOLS_FILE_MANAGER_DELETE_FILE_TOOLS_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"
 #include "CoreTools/Helper/Export/NonCopyMacro.h"
#include <string>

CORE_TOOLS_NON_COPY_EXPORT_IMPL(DeleteFileToolsImpl);

 
namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE DeleteFileTools final 
    {
    public:
        NON_COPY_TYPE_DECLARE(DeleteFileTools);
        using String = System::String;

    public:
        explicit DeleteFileTools(const String& fileName);
        ~DeleteFileTools() noexcept = default;
        DeleteFileTools(const DeleteFileTools& rhs) noexcept = delete;
        DeleteFileTools& operator=(const DeleteFileTools& rhs) noexcept = delete;
        DeleteFileTools(DeleteFileTools&& rhs) noexcept = delete;
        DeleteFileTools& operator=(DeleteFileTools&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_DELETE_FILE_TOOLS_H