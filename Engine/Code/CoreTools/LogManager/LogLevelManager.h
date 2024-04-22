/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 13:53)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_LEVEL_MANAGER_H
#define CORE_TOOLS_LOG_MANAGER_LOG_LEVEL_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/LogManager/LogManagerFwd.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE LogLevelManager final
    {
    public:
        using ClassType = LogLevelManager;

        using String = System::String;

    public:
        NODISCARD static String GetLogLevelDescribe(LogLevel logLevelType);
        NODISCARD static LogLevel GetLogLevel(const std::string& describe);
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_LEVEL_MANAGER_H
