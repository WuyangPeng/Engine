///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/23 15:28)

#ifndef CORE_TOOLS_FILE_MANAGER_IF_STREAM_MANAGER_H
#define CORE_TOOLS_FILE_MANAGER_IF_STREAM_MANAGER_H

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
        using IFileStream = System::IFileStream;
        using FileContent = std::vector<String>;

    public:
        explicit IFStreamManager(const String& fileName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetFileContent() const;
        NODISCARD String BackupFile() const;

        void SetSimplifiedChinese();

        NODISCARD IFileStream& GetFileStream() noexcept;
        NODISCARD FileContent GetFileContent(System::StringView separate) const;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_IF_STREAM_MANAGER_H
