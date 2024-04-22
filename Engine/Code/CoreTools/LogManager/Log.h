/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 13:52)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_H
#define CORE_TOOLS_LOG_MANAGER_LOG_H

#include "CoreTools/CoreToolsDll.h"

#include "LogAppenderIOManager.h"
#include "LogManagerFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"

CORE_TOOLS_EXPORT_UNIQUE_PTR(Log);
CORE_TOOLS_NON_COPY_EXPORT_IMPL(LogImpl);

/// 日志库
/// Log类是一个单例，会使用锁保证线程安全。
/// 日志写入线程只存在一个，日志消息队列有锁保护，写入操作保证单线程。
/// LoadConfiguration函数会重置AppenderManager，但由于写入日志线程保存的AppenderManager可能是旧的，可以保证线程安全。
/// 写入日志时有可能会对AppenderManager进行修改，但因为在同一线程处理，所以可以保证线程安全。
namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Log final : public Singleton<Log, MutexCreate::UseStdRecursive>
    {
    public:
        NON_COPY_TYPE_DECLARE(Log);
        using ParentType = Singleton<Log>;

        using String = System::String;

    private:
        enum class LogCreate
        {
            Init,
        };

    public:
        explicit Log(LogCreate logCreate);

        static void Create();
        static void Destroy() noexcept;

        SINGLETON_GET_PTR_DECLARE(Log)

        CLASS_INVARIANT_DECLARE;

        void LoadConfiguration(const std::string& fileName);

        NODISCARD LogLevel GetMinLogLevelType(LogFilter filter) const;

        void Write(const LogMessage& logMessage);

    private:
        using LogUniquePtr = std::unique_ptr<Log>;

    private:
        static LogUniquePtr log;
        PackageType impl;
    };
}

#define LOG_SINGLETON CoreTools::Log::GetSingleton()

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_H
