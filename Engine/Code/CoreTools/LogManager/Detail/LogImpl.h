///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:46)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_IMPL_H
#define CORE_TOOLS_LOG_MANAGER_LOG_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/LogManager/AppenderManager.h"
#include "CoreTools/LogManager/LogAppenderIOManager.h"
#include "CoreTools/LogManager/LogManagerInternalFwd.h"

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

        CLASS_INVARIANT_DECLARE;

        void LoadConfiguration(const AnalysisAppenderManager& analysis) noexcept;

        NODISCARD LogLevel GetMinLogLevelType(LogFilter filter) const;

        void Write(const LogMessage& logMessage);

    private:
        using LogAppenderIOManagerSharedPtr = std::shared_ptr<LogAppenderIOManager>;
        using AppenderManagerSharedPtr = std::shared_ptr<AppenderManager>;
        using LogAppenderIOManagerContainer = std::map<LogLevel, LogAppenderIOManagerSharedPtr>;

    private:
        void InitIOManager();
        void ResetIOManager() noexcept;
        NODISCARD LogAppenderIOManager& Find(LogLevel type);

    private:
        AppenderManagerSharedPtr appenderManager;
        LogAppenderIOManagerContainer logAppenderIOManagerContainer;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_IMPL_H
