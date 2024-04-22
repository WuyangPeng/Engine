/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 17:40)

#ifndef CORE_TOOLS_TEXT_PARSING_VALUE_TYPE_FLAGS_H
#define CORE_TOOLS_TEXT_PARSING_VALUE_TYPE_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace CoreTools::SimpleCSV
{
    /// 定义Excel电子表格单元格的有效值类型的枚举。
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