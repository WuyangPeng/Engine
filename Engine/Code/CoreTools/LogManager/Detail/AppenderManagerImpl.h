//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/15 10:08)

// ���λ�ù��������ڲ��ӿ�
#ifndef CORE_TOOLS_LOG_MANAGER_APPENDER_MANAGER_IMPL_H
#define CORE_TOOLS_LOG_MANAGER_APPENDER_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/LogManager/LogManagerFwd.h"

#include <boost/noncopyable.hpp>
#include <map>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE AppenderManagerImpl final : private boost::noncopyable
    {
    public:
        using ClassType = AppenderManagerImpl;
        using String = System::String;

    public:
        AppenderManagerImpl(MAYBE_UNUSED int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] bool IsAppenderExist(const String& name) const;

        [[nodiscard]] bool InsertLogger(const Logger& logger);
        [[nodiscard]] bool RemoveLogger(LogFilter logFilter);
        [[nodiscard]] bool InsertAppender(const String& name, const Appender& appender);
        [[nodiscard]] bool InsertConsoleAppender(const Appender& appender);
        [[nodiscard]] bool RemoveAppender(const String& name);
        void Clear() noexcept;

        void Write(const LogMessage& message);
        void Write(const String& name, const LogMessage& message);
        void WriteToConsole(const LogMessage& message);

        void ReloadAppenderFile();

        [[nodiscard]] static const String GetConsoleAppenderName();
        [[nodiscard]] static const String GetDefaultAppenderName();

    private:
        using LoggerContainer = std::map<LogFilter, Logger>;
        using AppenderContainer = std::map<String, Appender>;

    private:
        [[nodiscard]] LogLevel GetLogLevelType(const LogMessage& message) const;
        void DoWrite(const LogMessage& message);
        void DoWrite(const String& name, const LogMessage& message);
        [[nodiscard]] bool CreateFileAppender(const String& fileName); 

    private:
        LoggerContainer m_Loggers;
        AppenderContainer m_Appenders;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_APPENDER_MANAGER_IMPL_H
