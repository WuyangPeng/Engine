/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/02 17:41)

#ifndef CORE_TOOLS_TEXT_PARSING_SHEET_FLAGS_H
#define CORE_TOOLS_TEXT_PARSING_SHEET_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace CoreTools::SimpleCSV
{
    /// SheetState �ǿɼ���״̬��ö�٣�����ɼ������ء�
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