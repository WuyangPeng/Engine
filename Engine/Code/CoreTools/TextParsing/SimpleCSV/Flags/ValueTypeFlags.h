///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 14:55)

#ifndef CORE_TOOLS_TEXT_PARSING_VALUE_TYPE_FLAGS_H
#define CORE_TOOLS_TEXT_PARSING_VALUE_TYPE_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace CoreTools::SimpleCSV
{
    // 定义Excel电子表格单元格的有效值类型的枚举。
    enum class ValueType
    {
        Empty,
        Boolean,
        Integer,
        Float,
        Error,
        String
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_VALUE_TYPE_FLAGS_H