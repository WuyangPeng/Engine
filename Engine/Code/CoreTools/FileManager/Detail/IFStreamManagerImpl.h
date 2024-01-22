/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 21:39)

#ifndef CORE_TOOLS_FILE_MANAGER_IF_STREAM_MANAGER_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_IF_STREAM_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <fstream>
#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE IFStreamManagerImpl final
    {
    public:
        using ClassType = IFStreamManagerImpl;

        using String = System::String;
        using OStream = System::OStream;
        using IFileStream = System::IFileStream;
        using FileContent = std::vector<String>;

    public:
        explicit IFStreamManagerImpl(const String& fileName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetFileContent() const;
        NODISCARD String BackupFile() const;

        void SetSimplifiedChinese();

        NODISCARD IFileStream& GetFileStream() noexcept;
        NODISCARD FileContent GetFileContent(System::StringView separate) const;

    private:
        NODISCARD String GetBackupName() const;
        void CopyContentToStream(OStream* stream) const;

    private:
        IFileStream iStream;
        String fileName;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_IF_STREAM_MANAGER_IMPL_H
