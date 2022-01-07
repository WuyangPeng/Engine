///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 19:09)

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
