///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/23 14:52)

#ifndef CORE_TOOLS_TEXT_PARSING_COMMAND_ADD_CHART_SHEET_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_COMMAND_ADD_CHART_SHEET_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_HIDDEN_DECLARE CommandAddChartSheetImpl final
    {
    public:
        using ClassType = CommandAddChartSheetImpl;

    public:
        CommandAddChartSheetImpl(std::string sheetName, int sheetIndex) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetSheetName() const;
        NODISCARD int GetSheetIndex() const noexcept;

    private:
        std::string sheetName;
        int sheetIndex;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_COMMAND_ADD_CHART_SHEET_IMPL_H