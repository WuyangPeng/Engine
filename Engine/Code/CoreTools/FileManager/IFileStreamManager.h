/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 22:56)

#ifndef CORE_TOOLS_FILE_MANAGER_I_FILE_STREAM_MANAGER_H
#define CORE_TOOLS_FILE_MANAGER_I_FILE_STREAM_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

#include <string>

CORE_TOOLS_NON_COPY_EXPORT_IMPL(IFileStreamManagerImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE IFileStreamManager final
    {
    public:
        NON_COPY_TYPE_DECLARE(IFileStreamManager);

        using String = System::String;
        using IFileStream = System::IFileStream;
        using FileContent = std::vector<String>;

    public:
        explicit IFileStreamManager(const String& fileName);

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

#endif  // CORE_TOOLS_FILE_MANAGER_I_FILE_STREAM_MANAGER_H
