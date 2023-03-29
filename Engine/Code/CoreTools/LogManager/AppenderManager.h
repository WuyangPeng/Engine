///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/28 16:07)

#ifndef CORE_TOOLS_LOG_MANAGER_APPENDER_MANAGER_H
#define CORE_TOOLS_LOG_MANAGER_APPENDER_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "LogManagerFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>

CORE_TOOLS_NON_COPY_EXPORT_IMPL(AppenderManagerImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE AppenderManager final
    {
    public:
        NON_COPY_TYPE_DECLARE(AppenderManager);
        using String = System::String;
        using AppenderManagerSharedPtr = std::shared_ptr<AppenderManager>;

    public:
        NODISCARD static AppenderManagerSharedPtr Create();

    private:
        enum class AppenderManagerCreate
        {
            Init,
        };

    public:
        explicit AppenderManager(AppenderManagerCreate appenderManagerCreate);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsAppenderExist(const String& name) const;

        NODISCARD bool InsertLogger(const Logger& logger);
        NODISCARD bool RemoveLogger(LogFilter logFilter);
        NODISCARD bool InsertAppender(const String& name, const Appender& appender);
        NODISCARD bool InsertConsoleAppender(const Appender& appender);
        NODISCARD bool RemoveAppender(const String& name);
        void Clear() noexcept;

        void Write(const LogMessage& message) const;
        void Write(const String& name, const LogMessage& message);
        void WriteToConsole(const LogMessage& message)  ;

        NODISCARD static String GetConsoleAppenderName();
        NODISCARD static String GetDefaultAppenderName();

        NODISCARD LogLevel GetMinLogLevelType(LogFilter logFilter) const;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_APPENDER_MANAGER_H
