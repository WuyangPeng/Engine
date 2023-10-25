///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:44)

#ifndef CORE_TOOLS_LOG_MANAGER_APPENDER_CONSOLE_H
#define CORE_TOOLS_LOG_MANAGER_APPENDER_CONSOLE_H

#include "CoreTools/CoreToolsDll.h"

#include "AppenderImpl.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE AppenderConsole final : public AppenderImpl
    {
    public:
        using ClassType = AppenderConsole;
        using ParentType = AppenderImpl;

    public:
        explicit AppenderConsole(AppenderPrint appenderFlags, LogLevel logLevel = LogLevel::Disabled);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD AppenderType GetAppenderType() const noexcept override;

        NODISCARD const AppenderImplSharedPtr Clone() const override;

    private:
        void DoWrite(const LogMessage& message, const LogMessagePrefix& prefix, const LogMessagePostfix& postfix) const override;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_APPENDER_CONSOLE_H
