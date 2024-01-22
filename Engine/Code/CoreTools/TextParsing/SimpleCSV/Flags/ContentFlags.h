/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 10:47)

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