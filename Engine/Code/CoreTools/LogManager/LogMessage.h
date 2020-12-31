//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/15 11:46)

// 日志消息类外部接口
#ifndef CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_H
#define CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Contract/FunctionDescribed.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/LogManager/LogManagerFwd.h"

#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(LogMessageImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE LogMessage final
    {
    public:
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(LogMessage);
        using String = System::String;

    public:
        LogMessage(LogLevel level, LogFilter filter, const String& message, const FunctionDescribed& functionDescribed);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] String GetMessageDescribe() const;
        [[nodiscard]] LogLevel GetLogLevel() const noexcept;
        [[nodiscard]] LogFilter GetLogFilterType() const noexcept;
        [[nodiscard]] int GetMessageSize() const;
        [[nodiscard]] FunctionDescribed GetFunctionDescribed() const noexcept;

    private:
        IMPL_TYPE_DECLARE(LogMessage);
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_H
