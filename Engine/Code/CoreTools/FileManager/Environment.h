/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 22:54)

#ifndef CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_H
#define CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"

CORE_TOOLS_NON_COPY_EXPORT_IMPL(EnvironmentImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Environment final
    {
    public:
        NON_COPY_TYPE_DECLARE(Environment);

        using String = System::String;

    private:
        enum class EnvironmentCreate
        {
            Init,
        };

    public:
        NODISCARD static Environment Create();

        explicit Environment(EnvironmentCreate environmentCreate);

        CLASS_INVARIANT_DECLARE;

        /// 支持使用路径来定位文件。对于平台独立性，使用“/”作为路径分隔符。
        /// 如果输入的“目录”的值未以“/”或“\\”结尾，则它将自动附加一个尾随的“/”。
        /// 如果操作成功，插入/删除函数返回“真”。
        NODISCARD int GetNumDirectories() const;
        NODISCARD String GetDirectory(int index) const;
        NODISCARD bool InsertDirectory(const String& directory);
        NODISCARD bool EraseDirectory(const String& directory);
        void EraseAllDirectories() noexcept;

        /// GetPath*函数搜索目录列表，假设它满足所要求的条件，它返回完全修饰的文件名，如果条件不具备，它抛出一个异常。
        /// GetPathReading成功时，可以打开用于读取的文件。
        /// GetPathWriting成功时，可以打开用于写入的文件。
        /// GetPathReadingAndWriting成功时，可以打开用于读取和/或写入的文件。
        NODISCARD String GetPathReading(const String& fileName) const;
        NODISCARD String GetPathWriting(const String& fileName) const;
        NODISCARD String GetPathReadingAndWriting(const String& fileName) const;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_H
