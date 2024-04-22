/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/11 14:06)

#include "CoreTools/CoreToolsExport.h"

#include "LogLevelManager.h"
#include "Flags/LogManagerFlags.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

#include <map>

System::String CoreTools::LogLevelManager::GetLogLevelDescribe(LogLevel logLevelType)
{
    switch (logLevelType)
    {
        case LogLevel::Disabled:
            return SYSTEM_TEXT("����");
        case LogLevel::Trace:
            return SYSTEM_TEXT("����");
        case LogLevel::Debug:
            return SYSTEM_TEXT("����");
        case LogLevel::Info:
            return SYSTEM_TEXT("һ��");
        case LogLevel::Warn:
            return SYSTEM_TEXT("����");
        case LogLevel::Error:
            return SYSTEM_TEXT("����");
        case LogLevel::Fatal:
            return SYSTEM_TEXT("��������");
        default:
            CORE_TOOLS_ASSERTION_2(false, "δ�ҵ���־�ȼ������������");
            return SYSTEM_TEXT("");
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
