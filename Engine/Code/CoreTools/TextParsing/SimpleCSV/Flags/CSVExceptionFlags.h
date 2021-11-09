///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.3 (2021/09/14 14:44)

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