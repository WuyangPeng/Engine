//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/13 20:26)

#ifndef CORE_TOOLS_FILE_MANAGER_DIRECTORY_H
#define CORE_TOOLS_FILE_MANAGER_DIRECTORY_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
 
CORE_TOOLS_NON_COPY_EXPORT_IMPL(DirectoryImpl);


namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Directory final  
    {
    public:
        NON_COPY_TYPE_DECLARE(Directory);

    public:
        explicit Directory(const System::String& directoryName);
        ~Directory() noexcept = default;
        Directory(const Directory& rhs) noexcept = delete;
        Directory& operator=(const Directory& rhs) noexcept = delete;
        Directory(Directory&& rhs) noexcept = delete;
        Directory& operator=(Directory&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_DIRECTORY_H
