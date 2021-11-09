///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.4 (2021/09/28 14:38)

#ifndef CORE_TOOLS_TEXT_PARSING_SHEET_FLAGS_H
#define CORE_TOOLS_TEXT_PARSING_SHEET_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace CoreTools
{
    namespace SimpleCSV
    {
        // SheetState �ǿɼ���״̬��ö�٣�����ɼ������ء�
        enum class SheetState
        {
            Visible,
            Hidden,
            VeryHidden
        };

        enum class SheetType
        {
            Worksheet,
            Chartsheet,
            Dialogsheet,
            Macrosheet
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_SHEET_FLAGS_H