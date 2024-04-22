/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 17:41)

#ifndef CORE_TOOLS_TEXT_PARSING_RELATIONSHIP_FLAGS_H
#define CORE_TOOLS_TEXT_PARSING_RELATIONSHIP_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace CoreTools::SimpleCSV
{
    enum class RelationshipType
    {
        CoreProperties,
        ExtendedProperties,
        CustomProperties,
        Workbook,
        Worksheet,
        ChartSheet,
        CalculationChain,
        ExternalLink,
        ExternalLinkPath,
        Theme,
        Styles,
        Chart,
        ChartStyle,
        ChartColorStyle,
        Image,
        Drawing,
        VmlDrawing,
        SharedStrings,
        PrinterSettings,
        VbaProject,
        ControlProperties,
        Unknown,
        DialogSheet,
        MacroSheet,
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_RELATIONSHIP_FLAGS_H