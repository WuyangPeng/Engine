///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/28 14:53)

#ifndef CORE_TOOLS_LOG_MANAGER_FWD_H
#define CORE_TOOLS_LOG_MANAGER_FWD_H

namespace CoreTools
{
    enum class LogFilter;
    enum class LogLevel;
    enum class AppenderType;
    enum class AppenderPrint;
    enum class LogAppenderIOManageSign;

    class LogFilterManager;
    class LogLevelManager;
    class LogMessagePrefix;
    class LogMessagePostfix;
    class LogMessage;
    class LogConsoleTextColorsManager;
    class Appender;
    class Logger;
    class AppenderManager;
    class LogFileName;
    class LogAppenderIOManager;
    class Log;
    class LogAsynchronous;

    class LogHelper;
}

#endif  // CORE_TOOLS_LOG_MANAGER_FWD_H