///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 14:55)

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
        VBAProject,
        CoreProperties,
        ExtendedProperties,
        CustomProperties,
        Comments,
        Table,
        VMLDrawing,
        Unknown
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CONTENT_FLAGS_H