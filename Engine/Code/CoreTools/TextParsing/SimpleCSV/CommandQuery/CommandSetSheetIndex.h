///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 19:08)

#ifndef CORE_TOOLS_TEXT_PARSING_COMMAND_SET_SHEET_INDEX_H
#define CORE_TOOLS_TEXT_PARSING_COMMAND_SET_SHEET_INDEX_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"

#include <string>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<const CoreTools::SimpleCSV::CommandSetSheetIndexImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<CoreTools::SimpleCSV::CommandSetSheetIndexImpl>;

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_DEFAULT_DECLARE CommandSetSheetIndex final
        {
        public:
            PERFORMANCE_UNSHARED_TYPE_DECLARE(CommandSetSheetIndex);

        public:
            CommandSetSheetIndex(const std::string& sheetID, int sheetIndex);

            CLASS_INVARIANT_DECLARE;

            NODISCARD std::string GetSheetID() const;
            NODISCARD int GetSheetIndex() const noexcept;

        private:
            PackageType impl;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_COMMAND_SET_SHEET_INDEX_H
