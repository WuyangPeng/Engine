//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/15 11:39)

// 日志类外部接口
#ifndef CORE_TOOLS_LOG_MANAGER_LOG_H
#define CORE_TOOLS_LOG_MANAGER_LOG_H

#include "CoreTools/CoreToolsDll.h"

#include "LogManagerFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"

CORE_TOOLS_EXPORT_UNIQUE_PTR(Log);
CORE_TOOLS_EXPORT_SHARED_PTR(LogImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Log final : public CoreTools::Singleton<Log>
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(Log);
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

        SINGLETON_GET_PTR_DECLARE(Log);

        CLASS_INVARIANT_DECLARE;

        void InsertAppender(const String& name, const Appender& appenderPtr);
        void RemoveAppender(const String& name);
        void LoadConfiguration(const std::string& fileName);
        void ReloadAppenderFile();

        LogAppenderIOManager& OutTrace() noexcept;
        LogAppenderIOManager& OutDebug() noexcept;
        LogAppenderIOManager& OutInfo() noexcept;
        LogAppenderIOManager& OutWarn() noexcept;
        LogAppenderIOManager& OutError() noexcept;
        LogAppenderIOManager& OutFatal() noexcept;

    private:
        using LogUniquePtr = std::unique_ptr<Log>;

    private:
        static LogUniquePtr sm_Log;
        IMPL_TYPE_DECLARE(Log);
    };
}

#define LOG_SINGLETON CoreTools::Log::GetSingleton()

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_H
