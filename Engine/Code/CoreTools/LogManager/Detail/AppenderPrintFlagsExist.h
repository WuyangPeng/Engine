/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/11 13:49)

#ifndef CORE_TOOLS_LOG_MANAGER_APPENDER_PRINT_FLAGS_EXIST_H
#define CORE_TOOLS_LOG_MANAGER_APPENDER_PRINT_FLAGS_EXIST_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/EnumOperator.h"
#include "CoreTools/LogManager/Flags/LogManagerFlags.h"
#include "CoreTools/LogManager/LogManagerFwd.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE AppenderPrintFlagsExist final
    {
    public:
        NODISCARD static constexpr bool IsExist(AppenderPrint lhsAppenderPrintFlags, AppenderPrint rhsAppenderPrintFlags) noexcept
        {
            using System::operator&;

            return (lhsAppenderPrintFlags & rhsAppenderPrintFlags) != AppenderPrint::None;
        }
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_APPENDER_PRINT_FLAGS_EXIST_H
