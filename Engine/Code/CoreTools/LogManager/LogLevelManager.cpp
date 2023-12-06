///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/21 10:02)

#include "CoreTools/CoreToolsExport.h"

#include "LogLevelManager.h"
#include "Flags/LogManagerFlags.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

#include <map>

using namespace std::literals;

System::String CoreTools::LogLevelManager::GetLogLevelDescribe(LogLevel logLevelType)
{
    switch (logLevelType)
    {
        case LogLevel::Disabled:
            return SYSTEM_TEXT("����"s);
        case LogLevel::Trace:
            return SYSTEM_TEXT("����"s);
        case LogLevel::Debug:
            return SYSTEM_TEXT("����"s);
        case LogLevel::Info:
            return SYSTEM_TEXT("һ��"s);
        case LogLevel::Warn:
            return SYSTEM_TEXT("����"s);
        case LogLevel::Error:
            return SYSTEM_TEXT("����"s);
        case LogLevel::Fatal:
            return SYSTEM_TEXT("��������"s);
        default:
            CORE_TOOLS_ASSERTION_2(false, "δ�ҵ���־�ȼ������������");
            return SYSTEM_TEXT(""s);
    }
}

CoreTools::LogLevel CoreTools::LogLevelManager::GetLogLevel(const std::string& describe)
{
    static const std::map<std::string, LogLevel> container{ { "Disabled", LogLevel::Disabled },
                                                            { "Trace", LogLevel::Trace },
                                                            { "Debug", LogLevel::Debug },
                                                            { "Info", LogLevel::Info },
                                                            { "Warn", LogLevel::Warn },
                                                            { "Error", LogLevel::Error },
                                                            { "Fatal", LogLevel::Fatal } };

    if (const auto iter = container.find(describe);
        iter != container.cend())
    {
        return iter->second;
    }

    return LogLevel::MaxLogLevels;
}
