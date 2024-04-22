/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 17:45)

#ifndef CORE_TOOLS_TEXT_PARSING_CONTENT_FLAGS_H
#define CORE_TOOLS_TEXT_PARSING_CONTENT_FLAGS_H

#include "System/Helper/EnumOperator.h"

namespace CoreTools::SimpleCSV
{
    enum class ContentType
    {
        Workbook,
        WorkbookMacroEnabled,
        Worksheet,
        ChartSheet,
        ExternalLink,
        Theme,
        Styles,
        SharedStrings,
        Drawing,
        Chart,
        ChartStyle,
        ChartColorStyle,
        ControlProperties,
        CalculationChain,
        VbaProject,
        CoreProperties,
        ExtendedProperties,
        CustomProperties,
        Comments,
        Table,
        VmlDrawing,
        Unknown
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CONTENT_FLAGS_H