///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 19:39)

#ifndef CORE_TOOLS_TEXT_PARSING_CONTENT_FLAGS_H
#define CORE_TOOLS_TEXT_PARSING_CONTENT_FLAGS_H

#include "System/Helper/EnumMacro.h"

namespace CoreTools
{
    namespace SimpleCSV
    {
        enum class ContentType
        {
            Workbook,
            WorkbookMacroEnabled,
            Worksheet,
            Chartsheet,
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
}

#endif  // CORE_TOOLS_TEXT_PARSING_CONTENT_FLAGS_H