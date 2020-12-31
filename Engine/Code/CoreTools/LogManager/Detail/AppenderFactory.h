//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/15 9:48)

#ifndef CORE_TOOLS_LOG_MANAGER_APPENDER_FACTORY_H
#define CORE_TOOLS_LOG_MANAGER_APPENDER_FACTORY_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/LogManager/LogManagerInternalFwd.h"

#include <memory>
#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE AppenderFactory final
    {
    public:
        using ClassType = AppenderFactory;
        using AppenderImplPtr = std::shared_ptr<AppenderImpl>;
        using String = System::String;

    public:
        [[nodiscard]] static AppenderImplPtr CreateAppenderConsole(AppenderPrint appenderFlags, LogLevel logLevel);

        [[nodiscard]] static AppenderImplPtr CreateAppenderFile(const String& directory, const String& fileName, AppenderPrint appenderFlags, LogLevel logLevel,
                                                                int maxFileSize, bool backup, const String& extensionName);

        [[nodiscard]] static AppenderImplPtr CreateAppenderFile(const String& directory, AppenderPrint appenderFlags, LogLevel logLevel,
                                                                int maxFileSize, bool backup, const String& extensionName);
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_APPENDER_FACTORY_H
