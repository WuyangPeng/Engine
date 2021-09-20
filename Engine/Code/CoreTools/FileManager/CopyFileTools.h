//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/13 20:24)

#ifndef CORE_TOOLS_FILE_MANAGER_COPY_FILE_TOOLS_H
#define CORE_TOOLS_FILE_MANAGER_COPY_FILE_TOOLS_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include <string>

CORE_TOOLS_NON_COPY_EXPORT_IMPL(CopyFileToolsImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE CopyFileTools final
    {
    public:
        NON_COPY_TYPE_DECLARE(CopyFileTools);
        using String = System::String;

    public:
        CopyFileTools(const String& inFileName, const String& outFileName);
        ~CopyFileTools() noexcept = default;
        CopyFileTools(const CopyFileTools& rhs) noexcept = delete;
        CopyFileTools& operator=(const CopyFileTools& rhs) noexcept = delete;
        CopyFileTools(CopyFileTools&& rhs) noexcept = delete;
        CopyFileTools& operator=(CopyFileTools&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_COPY_FILE_TOOLS_H
