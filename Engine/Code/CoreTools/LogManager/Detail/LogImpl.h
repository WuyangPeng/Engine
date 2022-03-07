///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/07 16:23)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_IMPL_H
#define CORE_TOOLS_LOG_MANAGER_LOG_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/LogManager/AppenderManager.h"
#include "CoreTools/LogManager/LogAppenderIOManager.h"

#include <map>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE LogImpl final
    {
    public:
        using ClassType = LogImpl;
        using String = System::String;

    public:
        explicit LogImpl(DisableNotThrow disableNotThrow);

#ifdef OPEN_CLASS_INVARIANT
        CLASS_INVARIANT_DECLARE;
        bool DisabledIsNotExist() const;
#endif  // OPEN_CLASS_INVARIANT

        void InsertAppender(const String& name, const Appender& appender);
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
        using LogAppenderIOManagerSharedPtr = std::shared_ptr<LogAppenderIOManager>;
        using AppenderManagerSharedPtr = std::shared_ptr<AppenderManager>;
        using LogAppenderIOManagerContainer = std::map<LogLevel, LogAppenderIOManagerSharedPtr>;

    private:
        void InitIOManager();
        void ResetIOManager() noexcept;
        LogAppenderIOManager& Find(LogLevel type) noexcept;

    private:
        AppenderManagerSharedPtr appenderManager;
        LogAppenderIOManagerContainer logAppenderIOManagerContainer;
        LogAppenderIOManager errorLogAppenderIOManager;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_IMPL_H
