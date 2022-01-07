///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 19:08)

#ifndef CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_NAME_H
#define CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_NAME_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"

#include <string>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<const CoreTools::SimpleCSV::QuerySheetNameImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<CoreTools::SimpleCSV::QuerySheetNameImpl>;

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_DEFAULT_DECLARE QuerySheetName final
        {
        public:
            PERFORMANCE_UNSHARED_TYPE_DECLARE(QuerySheetName);

        public:
            explicit QuerySheetName(const std::string& sheetID);
            QuerySheetName(const std::string& sheetID, const std::string& sheetName);

            CLASS_INVARIANT_DECLARE;

            NODISCARD std::string GetSheetID() const;
            NODISCARD std::string GetSheetName() const;

        private:
            PackageType impl;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_NAME_H
