//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/15 11:07)

// 日志消息前缀类内部接口
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

        [[nodiscard]] String GetPrefix() const;
        [[nodiscard]] int GetPrefixSize() const;

    private:
        void GeneratePrefix();
        void GenerateTimestampPrefix();
        void GenerateLogLevelPrefix();
        void GenerateLogFilterPrefix();

    private:
        String m_Prefix;
        AppenderPrint m_AppenderPrint;
        LogLevel m_Level;
        LogFilter m_Filter;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_PREFIX_IMPL_H
