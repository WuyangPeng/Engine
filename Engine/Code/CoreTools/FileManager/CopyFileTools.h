///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/08 23:34)

#ifndef CORE_TOOLS_FILE_MANAGER_COPY_FILE_TOOLS_H
#define CORE_TOOLS_FILE_MANAGER_COPY_FILE_TOOLS_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

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

        CLASS_INVARIANT_DECLARE;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_COPY_FILE_TOOLS_H
