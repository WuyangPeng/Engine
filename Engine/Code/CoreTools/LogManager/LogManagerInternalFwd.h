///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/28 14:53)

#ifndef CORE_TOOLS_LOG_LOG_MANAGER_INTERNAL_FWD_H
#define CORE_TOOLS_LOG_LOG_MANAGER_INTERNAL_FWD_H

#include "LogManagerFwd.h"

namespace CoreTools
{
    class AppenderFactory;
    class LogConsoleTextColorsManagerFactory;

    class AppenderImpl;
    class LogConsoleTextColorsManagerImpl;

    class LogMessageImpl;
    class LogMessageFactory;

    class AnalysisAppenderManager;
}

#endif  // CORE_TOOLS_LOG_LOG_MANAGER_INTERNAL_FWD_H