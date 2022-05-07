///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 19:41)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_EXCEPTION_FLAGS_H
#define CORE_TOOLS_TEXT_PARSING_CSV_EXCEPTION_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace CoreTools
{
    namespace SimpleCSV
    {
        enum class CSVExceptionType
        {
            Overflow = 1,
            ValueType,
            CellAddress,
            Input,
            Internal,
            Property,
            Sheet,
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_EXCEPTION_FLAGS_H