///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/07 21:44)

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
