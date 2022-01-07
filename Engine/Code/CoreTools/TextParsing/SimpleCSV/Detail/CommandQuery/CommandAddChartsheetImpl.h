///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 19:09)

#ifndef CORE_TOOLS_TEXT_PARSING_COMMAND_ADD_CHARTSHEET_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_COMMAND_ADD_CHARTSHEET_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_HIDDEN_DECLARE CommandAddChartsheetImpl final
        {
        public:
            using ClassType = CommandAddChartsheetImpl;

        public:
            CommandAddChartsheetImpl(const std::string& sheetName, int sheetIndex);

            CLASS_INVARIANT_DECLARE;

            NODISCARD std::string GetSheetName() const;
            NODISCARD int GetSheetIndex() const noexcept;

        private:
            std::string sheetName;
            int sheetIndex;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_COMMAND_ADD_CHARTSHEET_IMPL_H
