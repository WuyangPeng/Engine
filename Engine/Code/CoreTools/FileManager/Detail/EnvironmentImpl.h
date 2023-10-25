///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/22 11:33)

#ifndef CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <set>
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

        // 支持使用路径来定位文件。 对于平台无关性，使用“/”作为路径分隔符。
        // 并以“/”结束输入“目录”的值。 插入/删除函数返回“真”当且仅当操作成功。
        NODISCARD int GetNumDirectories() const;
        NODISCARD bool InsertDirectory(const String& directory);
        NODISCARD bool EraseDirectory(const String& directory);
        void EraseAllDirectories() noexcept;

        // GetPath*函数搜索目录列表，假设它满足所要求的条件，它返回完全修饰的文件名，如果条件不具备，它抛出一个异常。
        // GetPathReading成功时，可以打开进行读取的文件。
        // GetPathWriting成功时，可以打开用于写入的文件。
        // GetPathReadingAndWriting成功时，可以打开用于读取和/或写入的文件。
        NODISCARD String GetPathReading(const String& fileName) const;
        NODISCARD String GetPathWriting(const String& fileName) const;
        NODISCARD String GetPathReadingAndWriting(const String& fileName) const;

        void SetConfigurationPath(const String& aConfigurationPath);
        NODISCARD const String GetConfigurationPath() const;

    private:
        // 当不需要路径而文件名存在时，不返回该文件！
        NODISCARD String GetPath(const String& fileName, const String& attributes) const;
        NODISCARD static bool IsFileInPathExist(const String& decorated, const String& attributes);

    private:
        using DirectoriesContainer = std::set<String>;

    private:
        DirectoriesContainer directories;
        String configurationPath;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_IMPL_H
