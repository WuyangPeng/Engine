/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 00:35)

#ifndef CORE_TOOLS_LOG_MANAGER_APPENDER_MANAGER_IMPL_H
#define CORE_TOOLS_LOG_MANAGER_APPENDER_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/LogManager/LogManagerFwd.h"

#include <map>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE AppenderManagerImpl final
    {
    public:
        using ClassType = AppenderManagerImpl;

        using String = System::String;

    public:
        AppenderManagerImpl() noexcept;
        ~AppenderManagerImpl() noexcept = default;
        AppenderManagerImpl(const AppenderManagerImpl& rhs) = delete;
        AppenderManagerImpl& operator=(const AppenderManagerImpl& rhs) = delete;
        AppenderManagerImpl(AppenderManagerImpl&& rhs) noexcept = delete;
        AppenderManagerImpl& operator=(AppenderManagerImpl&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsAppenderExist(const String& name) const;

        NODISCARD bool InsertLogger(const Logger& logger);
        NODISCARD bool RemoveLogger(LogFilter logFilter) noexcept;
        NODISCARD bool InsertAppender(const String& name, const Appender& appender);
        NODISCARD bool InsertConsoleAppender(const Appender& appender);
        NODISCARD bool RemoveAppender(const String& name) noexcept;
        void Clear() noexcept;

        void Write(const LogMessage& message) const;
        void Write(const String& name, const LogMessage& message);

        NODISCARD static String GetConsoleAppenderName();
        NODISCARD static String GetDefaultAppenderName();

        NODISCARD LogLevel GetMinLogLevelType(LogFilter logFilter) const;

    private:
        using LoggerContainer = std::map<LogFilter, Logger>;
        using AppenderContainer = std::map<String, Appender>;

    private:
        NODISCARD LogLevel GetLogLevelType(const LogMessage& message) const;
        void DoWrite(const LogMessage& message) const;
        void DoWrite(const String& name, const LogMessage& message);
        NODISCARD bool CreateFileAppender(const String& fileName);

    private:
        LoggerContainer loggers;
        AppenderContainer appenders;
        LogLevel minLogLevel;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_APPENDER_MANAGER_IMPL_H
