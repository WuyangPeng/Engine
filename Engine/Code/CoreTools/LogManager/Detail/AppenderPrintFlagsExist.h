///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/07 14:53)

#ifndef CORE_TOOLS_LOG_MANAGER_APPENDER_PRINT_FLAGS_EXIST_H
#define CORE_TOOLS_LOG_MANAGER_APPENDER_PRINT_FLAGS_EXIST_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/LogManager/LogManagerFwd.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE AppenderPrintFlagsExist final
    {
    public:
        NODISCARD static bool IsExist(AppenderPrint lhsAppenderPrintFlags, AppenderPrint rhsAppenderPrintFlags) noexcept;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_APPENDER_PRINT_FLAGS_EXIST_H
