/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 10:42)

#ifndef CORE_TOOLS_TEXT_PARSING_COMMAND_ADD_CHART_SHEET_H
#define CORE_TOOLS_TEXT_PARSING_COMMAND_ADD_CHART_SHEET_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"

#include <string>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<const CoreTools::SimpleCSV::CommandAddChartSheetImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<CoreTools::SimpleCSV::CommandAddChartSheetImpl>;

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_DEFAULT_DECLARE CommandAddChartSheet final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(CommandAddChartSheet);

    public:
        CommandAddChartSheet(const std::string& sheetName, int sheetIndex);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetSheetName() const;
        NODISCARD int GetSheetIndex() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_COMMAND_ADD_CHART_SHEET_H
