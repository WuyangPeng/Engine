///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/07 17:05)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_PREFIX_IMPL_H
#define CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_PREFIX_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/LogManager/LogManagerFwd.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE LogMessagePrefixImpl final
    {
    public:
        using ClassType = LogMessagePrefixImpl;
        using String = System::String;

    public:
        LogMessagePrefixImpl(AppenderPrint appenderFlags, LogLevel level, LogFilter filter);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetPrefix() const;
        NODISCARD int GetPrefixSize() const;

    private:
        void GeneratePrefix();
        void GenerateTimestampPrefix();
        void GenerateLogLevelPrefix();
        void GenerateLogFilterPrefix();

    private:
        String prefix;
        AppenderPrint appenderPrint;
        LogLevel level;
        LogFilter filter;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_PREFIX_IMPL_H
