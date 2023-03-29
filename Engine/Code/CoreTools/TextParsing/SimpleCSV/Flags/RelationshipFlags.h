///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/06 14:44)

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
        VMLDrawing,
        SharedStrings,
        PrinterSettings,
        VBAProject,
        ControlProperties,
        Unknown,
        DialogSheet,
        MacroSheet,
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_RELATIONSHIP_FLAGS_H