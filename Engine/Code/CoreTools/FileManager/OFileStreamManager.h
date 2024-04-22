/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 22:56)

#ifndef CORE_TOOLS_FILE_MANAGER_O_FILE_STREAM_MANAGER_H
#define CORE_TOOLS_FILE_MANAGER_O_FILE_STREAM_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/FileManager/Using/CFileUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

#include <fstream>
#include <string>

CORE_TOOLS_NON_COPY_EXPORT_IMPL(OFileStreamManagerImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE OFileStreamManager final
    {
    public:
        NON_COPY_TYPE_DECLARE(OFileStreamManager);

        using String = System::String;
        using PosType = System::OFileStream::pos_type;

    public:
        OFileStreamManager(const String& fileName, bool addition);

        CLASS_INVARIANT_DECLARE;

        NODISCARD PosType GetStreamSize() const;

        OFileStreamManager& operator<<(const String& message);
        void SetSimplifiedChinese();

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_O_FILE_STREAM_MANAGER_H
