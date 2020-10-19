//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.2 (2020/10/15 19:01)

#include "CoreTools/CoreToolsExport.h"

#include "LogLevelManager.h"
#include "Flags/LogManagerFlags.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

using namespace std::literals;

System::String CoreTools::LogLevelManager::GetLogLevelDescribe(LogLevel logLevelType)
{
    switch (logLevelType)
    {
        case LogLevel::Disabled:
            return SYSTEM_TEXT("禁用"s);
        case LogLevel::Trace:
            return SYSTEM_TEXT("跟踪"s);
        case LogLevel::Debug:
            return SYSTEM_TEXT("调试"s);
        case LogLevel::Info:
            return SYSTEM_TEXT("一般"s);
        case LogLevel::Warn:
            return SYSTEM_TEXT("警告"s);
        case LogLevel::Error:
            return SYSTEM_TEXT("错误"s);
        case LogLevel::Fatal:
            return SYSTEM_TEXT("致命错误"s);
        default:
            CORE_TOOLS_ASSERTION_2(false, "未找到日志等级的相关描述！");
            return SYSTEM_TEXT(""s);
    }
}
