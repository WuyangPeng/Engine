/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 13:52)

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
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_APPENDER_MANAGER_H
