//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/15 11:38)

// 输出位置管理器类外部接口
#ifndef CORE_TOOLS_LOG_MANAGER_APPENDER_MANAGER_H
#define CORE_TOOLS_LOG_MANAGER_APPENDER_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "LogManagerFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
 
#include <string>

CORE_TOOLS_NON_COPY_EXPORT_IMPL(AppenderManagerImpl);


namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE AppenderManager final  
    {
    public:
        NON_COPY_TYPE_DECLARE(AppenderManager);
        using String = System::String;

    public:
        explicit AppenderManager(DisableNotThrow disableNotThrow);
        ~AppenderManager() noexcept = default;
        AppenderManager(const AppenderManager& rhs) noexcept = delete;
        AppenderManager& operator=(const AppenderManager& rhs) noexcept = delete;
        AppenderManager(AppenderManager&& rhs) noexcept = delete;
        AppenderManager& operator=(AppenderManager&& rhs) noexcept = delete;

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
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_APPENDER_MANAGER_H
