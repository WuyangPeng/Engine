///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.4 (2021/09/29 23:01)

#ifndef CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_RELS_TARGET_H
#define CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_RELS_TARGET_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"

#include <string>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<const CoreTools::SimpleCSV::QuerySheetRelsTargetImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<CoreTools::SimpleCSV::QuerySheetRelsTargetImpl>;

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_DEFAULT_DECLARE QuerySheetRelsTarget final
        {
        public:
            PERFORMANCE_UNSHARED_TYPE_DECLARE(QuerySheetRelsTarget);

        public:
            explicit QuerySheetRelsTarget(const std::string& sheetID);
            QuerySheetRelsTarget(const std::string& sheetID, const std::string& sheetTarget);

            CLASS_INVARIANT_DECLARE;

            NODISCARD std::string GetSheetID() const;
            NODISCARD std::string GetSheetTarget() const;

        private:
            PackageType impl;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_RELS_TARGET_H
