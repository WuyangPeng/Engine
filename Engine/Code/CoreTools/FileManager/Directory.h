/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 21:43)

#ifndef CORE_TOOLS_FILE_MANAGER_DIRECTORY_H
#define CORE_TOOLS_FILE_MANAGER_DIRECTORY_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

CORE_TOOLS_NON_COPY_EXPORT_IMPL(DirectoryImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Directory final
    {
    public:
        NON_COPY_TYPE_DECLARE(Directory);

        using String = System::String;

    public:
        explicit Directory(const String& directoryName);

        CLASS_INVARIANT_DECLARE;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_DIRECTORY_H
