///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 14:50)

#ifndef CORE_TOOLS_TEXT_PARSING_COMMAND_ADD_WORKSHEET_H
#define CORE_TOOLS_TEXT_PARSING_COMMAND_ADD_WORKSHEET_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"

#include <string>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<const CoreTools::SimpleCSV::CommandAddWorksheetImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<CoreTools::SimpleCSV::CommandAddWorksheetImpl>;

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_DEFAULT_DECLARE CommandAddWorksheet final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(CommandAddWorksheet);

    public:
        CommandAddWorksheet(const std::string& sheetName, const std::string& sheetPath);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetSheetName() const;
        NODISCARD std::string GetSheetPath() const;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_COMMAND_ADD_WORKSHEET_H
