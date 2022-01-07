///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 19:07)

#ifndef CORE_TOOLS_TEXT_PARSING_COMMAND_CLONE_SHEET_H
#define CORE_TOOLS_TEXT_PARSING_COMMAND_CLONE_SHEET_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"

#include <string>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<const CoreTools::SimpleCSV::CommandCloneSheetImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<CoreTools::SimpleCSV::CommandCloneSheetImpl>;

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_DEFAULT_DECLARE CommandCloneSheet final
        {
        public:
            PERFORMANCE_UNSHARED_TYPE_DECLARE(CommandCloneSheet);

        public:
            CommandCloneSheet(const std::string& sheetID, const std::string& cloneName);

            CLASS_INVARIANT_DECLARE;

            NODISCARD std::string GetSheetID() const;
            NODISCARD std::string GetCloneName() const;

        private:
            PackageType impl;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_COMMAND_CLONE_SHEET_H
