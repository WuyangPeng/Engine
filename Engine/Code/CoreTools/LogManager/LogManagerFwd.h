//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/15 9:39)

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
}

#endif  // CORE_TOOLS_LOG_MANAGER_FWD_H