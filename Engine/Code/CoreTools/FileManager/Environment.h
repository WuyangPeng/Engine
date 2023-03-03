///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/03/02 10:05)

#ifndef CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_H
#define CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/SingletonMacro.h" 

CORE_TOOLS_EXPORT_UNIQUE_PTR(Environment);
CORE_TOOLS_NON_COPY_EXPORT_IMPL(EnvironmentImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Environment final : public Singleton<Environment>
    {
    public:
        NON_COPY_TYPE_DECLARE(Environment);
        using ParentType = Singleton<Environment>;
        using String = System::String;

    private:
        enum class EnvironmentCreate
        {
            Init,
        };

    public:
        explicit Environment(EnvironmentCreate environmentCreate);

        static void Create();
        static void Destroy() noexcept;

        SINGLETON_GET_PTR_DECLARE(Environment)

        CLASS_INVARIANT_DECLARE;

        // 支持使用路径来定位文件。对于平台无关性，使用“/”作为路径分隔符。
        // 并以“/”结束输入“目录”的值。插入/删除函数返回“真”当且仅当操作成功。
        NODISCARD int GetNumDirectories() const;

        NODISCARD bool InsertDirectory(const String& directory);
        NODISCARD bool EraseDirectory(const String& directory);
        void EraseAllDirectories();

        // GetPath*函数搜索目录列表，假设它满足所要求的条件，它返回完全修饰的文件名，如果条件不具备，它抛出一个异常。
        // GetPathReading成功时，可以打开进行读取的文件。
        // GetPathWriting成功时，可以打开用于写入的文件。
        // GetPathReadingAndWriting成功时，可以打开用于读取和/或写入的文件。
        NODISCARD String GetPathReading(const String& fileName) const;
        NODISCARD String GetPathWriting(const String& fileName) const;
        NODISCARD String GetPathReadingAndWriting(const String& fileName) const;

        void SetConfigurationPath(const String& configurationPath);
        NODISCARD const String GetConfigurationPath() const;

    private:
        using EnvironmentUniquePtr = std::unique_ptr<Environment>;

    private:
        static EnvironmentUniquePtr environment;
        PackageType impl;
    };
}

#define ENVIRONMENT_SINGLETON CoreTools::Environment::GetSingleton()

#endif  // CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_H
