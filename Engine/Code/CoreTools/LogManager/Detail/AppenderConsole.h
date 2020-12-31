//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/15 9:47)

// ���λ�ã�����̨��
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

        [[nodiscard]] AppenderType GetAppenderType() const noexcept final;

        [[nodiscard]] const AppenderImplPtr Clone() const final;

    private:
        void DoWrite(const LogMessage& message, const LogMessagePrefix& prefix, const LogMessagePostfix& postfix) final;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_APPENDER_CONSOLE_H
