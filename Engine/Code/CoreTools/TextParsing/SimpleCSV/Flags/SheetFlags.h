/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 17:41)

#ifndef CORE_TOOLS_TEXT_PARSING_SHEET_FLAGS_H
#define CORE_TOOLS_TEXT_PARSING_SHEET_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace CoreTools::SimpleCSV
{
    /// SheetState 是可见性状态的枚举，例如可见或隐藏。
    enum class SheetState
    {
        Visible,
        Hidden,
        VeryHidden
    };

    enum class SheetType
    {
        Worksheet,
        ChartSheet,
        DialogSheet,
        MacroSheet
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SHEET_FLAGS_H