///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/06 14:43)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_EXCEPTION_FLAGS_H
#define CORE_TOOLS_TEXT_PARSING_CSV_EXCEPTION_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace CoreTools::SimpleCSV
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

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_EXCEPTION_FLAGS_H