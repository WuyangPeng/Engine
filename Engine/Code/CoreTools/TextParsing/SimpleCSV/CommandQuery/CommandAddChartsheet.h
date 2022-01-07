///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 13:42)

#ifndef CORE_TOOLS_TEXT_PARSING_COMMAND_ADD_CHARTSHEET_H
#define CORE_TOOLS_TEXT_PARSING_COMMAND_ADD_CHARTSHEET_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"

#include <string>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<const CoreTools::SimpleCSV::CommandAddChartsheetImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<CoreTools::SimpleCSV::CommandAddChartsheetImpl>;

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_DEFAULT_DECLARE CommandAddChartsheet final
        {
        public:
            PERFORMANCE_UNSHARED_TYPE_DECLARE(CommandAddChartsheet);

        public:
            CommandAddChartsheet(const std::string& sheetName, int sheetIndex);

            CLASS_INVARIANT_DECLARE;

            NODISCARD std::string GetSheetName() const;
            NODISCARD int GetSheetIndex() const noexcept;

        private:
            PackageType impl;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_COMMAND_ADD_CHARTSHEET_H
