///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/21 09:45)

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
