///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/07 16:53)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_IMPL_H
#define CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Contract/FunctionDescribed.h"
#include "CoreTools/LogManager/LogManagerFwd.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE LogMessageImpl final
    {
    public:
        using ClassType = LogMessageImpl;
        using String = System::String;

    public:
        LogMessageImpl(LogLevel level, LogFilter filter, const String& message, const FunctionDescribed& functionDescribed);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetMessageDescribe() const;
        NODISCARD LogLevel GetLogLevel() const noexcept;
        NODISCARD LogFilter GetLogFilterType() const noexcept;
        NODISCARD int GetMessageSize() const;
        NODISCARD FunctionDescribed GetFunctionDescribed() const noexcept;

    private:
        LogLevel logLevel;
        LogFilter filter;
        String message;
        FunctionDescribed functionDescribed;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_IMPL_H
