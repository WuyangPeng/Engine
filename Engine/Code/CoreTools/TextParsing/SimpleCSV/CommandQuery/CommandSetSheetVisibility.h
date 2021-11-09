///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.4 (2021/09/29 23:01)

#ifndef CORE_TOOLS_TEXT_PARSING_COMMAND_SET_SHEET_VISIBILITY_H
#define CORE_TOOLS_TEXT_PARSING_COMMAND_SET_SHEET_VISIBILITY_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"

#include <string>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<const CoreTools::SimpleCSV::CommandSetSheetVisibilityImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<CoreTools::SimpleCSV::CommandSetSheetVisibilityImpl>;

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_DEFAULT_DECLARE CommandSetSheetVisibility final
        {
        public:
            PERFORMANCE_UNSHARED_TYPE_DECLARE(CommandSetSheetVisibility);

        public:
            CommandSetSheetVisibility(const std::string& sheetID, const std::string& sheetName, const std::string& sheetVisibility);

            CLASS_INVARIANT_DECLARE;

            NODISCARD std::string GetSheetID() const;
            NODISCARD std::string GetSheetName() const;
            NODISCARD std::string GetSheetVisibility() const;

        private:
            PackageType impl;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_COMMAND_SET_SHEET_VISIBILITY_H
