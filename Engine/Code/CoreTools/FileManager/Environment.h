//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/13 20:27)

#ifndef CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_H
#define CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "CoreTools/Threading/ThreadingFwd.h"

#include <shared_mutex>

CORE_TOOLS_EXPORT_UNIQUE_PTR(Environment);
CORE_TOOLS_EXPORT_SHARED_PTR(EnvironmentImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Environment final : public Singleton<Environment>
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(Environment);
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

        SINGLETON_GET_PTR_DECLARE(Environment);

        CLASS_INVARIANT_DECLARE;

        // 支持使用路径来定位文件。对于平台无关性，使用“/”作为路径分隔符。
        // 并以“/”结束输入“目录”的值。插入/删除函数返回“真”当且仅当操作成功。
        [[nodiscard]] int GetNumDirectories() const;

        [[nodiscard]] bool InsertDirectory(const String& directory);
        [[nodiscard]] bool EraseDirectory(const String& directory);
        void EraseAllDirectories();

        // GetPath*函数搜索目录列表，假设它满足所要求的条件，它返回完全修饰的文件名，如果条件不具备，它抛出一个异常。
        // GetPathReading成功时，可以打开进行读取的文件。
        // GetPathWriting成功时，可以打开用于写入的文件。
        // GetPathReadingAndWriting成功时，可以打开用于读取和/或写入的文件。
        [[nodiscard]] String GetPathReading(const String& fileName) const;
        [[nodiscard]] String GetPathWriting(const String& fileName) const;
        [[nodiscard]] String GetPathReadingAndWriting(const String& fileName) const;

        void SetConfigurationPath(const String& configurationPath);
        [[nodiscard]] const String GetConfigurationPath() const;

    private:
        using EnvironmentUniquePtr = std::unique_ptr<Environment>;

    private:
        static EnvironmentUniquePtr sm_Environment;
        IMPL_TYPE_DECLARE(Environment);
    };
}

#define ENVIRONMENT_SINGLETON CoreTools::Environment::GetSingleton()

#endif  // CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_H
