/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 14:06)

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
            return SYSTEM_TEXT("禁用");
        case LogLevel::Trace:
            return SYSTEM_TEXT("跟踪");
        case LogLevel::Debug:
            return SYSTEM_TEXT("调试");
        case LogLevel::Info:
            return SYSTEM_TEXT("一般");
        case LogLevel::Warn:
            return SYSTEM_TEXT("警告");
        case LogLevel::Error:
            return SYSTEM_TEXT("错误");
        case LogLevel::Fatal:
            return SYSTEM_TEXT("致命错误");
        default:
            CORE_TOOLS_ASSERTION_2(false, "未找到日志等级的相关描述！");
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
