/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 22:32)

#ifndef CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/FileManager/Environment.h"
#include "CoreTools/FileManager/FileManagerFwd.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE EnvironmentImpl final
    {
    public:
        using ClassType = EnvironmentImpl;

        using String = System::String;

    public:
        EnvironmentImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetNumDirectories() const;
        NODISCARD String GetDirectory(int index) const;
        NODISCARD bool InsertDirectory(const String& directory);
        NODISCARD bool EraseDirectory(const String& directory);
        void EraseAllDirectories() noexcept;

        NODISCARD String GetPathReading(const String& fileName) const;
        NODISCARD String GetPathWriting(const String& fileName) const;
        NODISCARD String GetPathReadingAndWriting(const String& fileName) const;

    private:
        NODISCARD String GetPath(const String& fileName, const String& attributes) const;
        NODISCARD static bool IsFileInPathExist(const String& decorated, const String& attributes);
        NODISCARD static String GetReplaceBackslash(String directory);

    private:
        using DirectoriesContainer = std::vector<String>;

    private:
        /// GetPath*要搜索的目录列表。
        DirectoriesContainer directories;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_IMPL_H
