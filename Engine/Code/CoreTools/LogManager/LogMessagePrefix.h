//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.2 (2020/10/15 11:47)

// 日志消息前缀类外部接口
#ifndef CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_PREFIX_H
#define CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_PREFIX_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/LogManager/LogManagerFwd.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include <string>

CORE_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(LogMessagePrefixImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE LogMessagePrefix final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(LogMessagePrefix);
        using String = System::String;

    public:
        LogMessagePrefix(AppenderPrint appenderFlags, LogLevel level, LogFilter filter);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] String GetPrefix() const;
        [[nodiscard]] int GetPrefixSize() const;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_PREFIX_H
