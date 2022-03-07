///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/08 23:42)

#ifndef CORE_TOOLS_FILE_MANAGER_IFSTREAM_MANAGER_H
#define CORE_TOOLS_FILE_MANAGER_IFSTREAM_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

#include <string>

CORE_TOOLS_NON_COPY_EXPORT_IMPL(IFStreamManagerImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE IFStreamManager final
    {
    public:
        NON_COPY_TYPE_DECLARE(IFStreamManager);
        using String = System::String;

    public:
        explicit IFStreamManager(const String& fileName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetFileContent() const;
        NODISCARD String BackupFile() const;

        void SetSimplifiedChinese();

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_IFSTREAM_MANAGER_H
