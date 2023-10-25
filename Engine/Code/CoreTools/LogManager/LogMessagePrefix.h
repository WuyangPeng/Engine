///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:48)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_PREFIX_H
#define CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_PREFIX_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/LogManager/LogManagerFwd.h"

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

        NODISCARD String GetPrefix() const;
        NODISCARD int GetPrefixSize() const;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_PREFIX_H
