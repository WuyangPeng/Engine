/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/11 13:51)

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
